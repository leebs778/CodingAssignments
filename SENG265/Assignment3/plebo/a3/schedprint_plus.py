#!/usr/bin/python
import re
import sys
from datetime import datetime
from datetime import timedelta


def main():
	total = len(sys.argv)
	if (total <= 1):
		print "no args given. The program will now crash and burn. Thank you"
		return
	#acquire all the necessary command line arguments
	filehold = sys.argv[4]
	filehold = filehold[7:]
	files = re.split(',',filehold)
	eventListing = []
	eventItem = eventStorage()
	for i in range(len(files)):
		input_file = open(files[i], "r")
		firstline = input_file.readline()
		if firstline[0:15] != "BEGIN:VCALENDAR":
			print "improper file input, please give me a specified .ics file"
			return
		nextline = input_file.readline()
		
		'''
		iterate through the entire input file, categorizing each individual event with
		each event getting it's own call of the occupyEvents function.
		After this while loop, each individual event has it's own index value in 
		'''
		while nextline[0:13] != "END:VCALENDAR":
			occupyEvents(input_file, nextline, eventItem,eventListing)
			nextline = input_file.readline()
			eventItem = eventStorage()

	#Acquires the unclean command line date arguments and cleans em up into datetime
	#objects
	starthold = sys.argv[1]
	startArgument = starthold[8:]
	endhold = sys.argv[2]
	endArgument = endhold[6:]
	startArgument = cleanUpDateArguments(startArgument)
	endArgument = cleanUpDateArguments(endArgument)
	tzHold = sys.argv[3]
	tzArgument = tzHold[5:]
	hourDiff = timedelta(hours=int(tzArgument))

	for i in range(len(eventListing)):
		cleanUpEventDateTime(eventListing[i])

	for i in range(len(eventListing)):
		eventListing[i].DateStart = eventListing[i].DateStart + hourDiff
		eventListing[i].DateEnd = eventListing[i].DateEnd + hourDiff
		if eventListing[i].RRule != None:
			eventListing[i].RRule = eventListing[i].RRule + hourDiff
	
	#debug(eventListing)
	accomodatingRepeatingEvents(eventListing)				#adds RRule items where necessary

	#cleans up eventList according to the proper start and end argument dates
	eventListing = acquireProperCalendarEvents(startArgument,endArgument, eventListing)

	eventListing = sorted(eventListing, key=lambda date: date.DateStart)	#sorts the datestart classitems
	output(eventListing)							#outputs result

#this is the grandaddy method used for printing out all the events
def output(eventListing):
	newGuap = []
	firstComp = -1
	secondComp = 0
	eventListing = sorted(eventListing, key=lambda date: (date.DateStart, date.DateEnd, date.Location, date.Summary))
	for i in range(len(eventListing)):
		eventListing[i].NotPrinted = True
		eventListing[i].endOfListIndicator = False
	if (len(eventListing) != 0):
		eventListing[(len(eventListing))-1].endOfListIndicator = True
	for i in range(len(eventListing)):
		if eventListing[i].NotPrinted:
			initialComp = eventListing[i].DateStart.strftime('%m%d')
		for j in range(len(eventListing)):
			if eventListing[j].NotPrinted :
				secondComp = eventListing[j].DateStart.strftime('%m%d')
			if initialComp == secondComp:
				eventListing[j].NotPrinted = False
				newGuap.append(eventListing[j])
		if len(newGuap) != 0:
			topOfOutput(newGuap[0].DateStart)
		newGuap = sorted(newGuap, key=lambda date: (date.DateStart, date.DateEnd, date.Location, date.Summary))
		#debug(newGuap)
		for z in range(len(newGuap)):
			eventEntry(newGuap[z])
			if newGuap[z].endOfListIndicator == True:
				print "end ofList indicator"
				return
		if (z == len(newGuap)-1):
				print ""

		newGuap[:] = []
		firstComp = -1
		secondComp = 0


#basic function used for creating the top line of output for each day with an event on it
def topOfOutput(StartDate):
	dateOutput = StartDate.strftime('%B %d, %Y (%a)')
	print dateOutput
	print "-"*len(dateOutput)

#a iteratable method used for printing out a single event line entry in the output
def eventEntry(eventStorage):
	plusFlag = ' '
	if eventStorage.DateStart.day != eventStorage.DateEnd.day:
		plusFlag = '+'

	startTimeAMPM = eventStorage.DateStart.strftime('%p').lower()
	endTimeAMPM = eventStorage.DateEnd.strftime('%p').lower()
	startHour = eventStorage.DateStart.strftime('%I')
	if int(startHour[0]) == 0:
		startHour = " " + startHour[1]
	endHour = eventStorage.DateEnd.strftime('%I')
	if int(endHour[0]) == 0:
		endHour = " " + endHour[1]
	startTimeSlot = startHour + ":" + eventStorage.DateStart.strftime('%M') + " " + startTimeAMPM
	endTimeSlot = endHour + ":" + eventStorage.DateEnd.strftime('%M') + " " + endTimeAMPM
	if eventStorage.Location != None:
		locLength = len(eventStorage.Location)
		location = eventStorage.Location[:locLength-1]
	else:
		location = ""

	if location != "":
		secondPortion = location + " --- " + eventStorage.Summary
	else:
		secondPortion = eventStorage.Summary
	output = startTimeSlot + " to " + endTimeSlot + " " + plusFlag + " | " + secondPortion
	#implement the + if events overlap
	
	print output[:len(output)-1]


#if any event has an "RRule" rule, this function, when called will append another event (with its date fixed) to #the end of the eventListing list 
def accomodatingRepeatingEvents(eventListing):
	for i in range(len(eventListing)):
		if eventListing[i].RRule != None:
			dS = eventListing[i].DateStart
			until = eventListing[i].RRule
			deltaTime = until - dS 		
			response = int(deltaTime.days / 7)
			for j in range(response):
				deltaSeven = timedelta(days=7*(j+1))
				repetitionEvent = eventStorage()
				repetitionEvent.DateStart = eventListing[i].DateStart + deltaSeven
				repetitionEvent.DateEnd = eventListing[i].DateEnd + deltaSeven
				repetitionEvent.Summary = eventListing[i].Summary
				repetitionEvent.Location = eventListing[i].Location
				repetitionEvent.RRule = None
				eventListing.append(repetitionEvent)

#This skims down the current list of classes to items only within the indicated arguments
def acquireProperCalendarEvents(startArgument, endArgument, eventListing):
	newEventListing = []
 	for i in range(len(eventListing)):
		if (startArgument.date() <= eventListing[i].DateStart.date()) and (endArgument.date() >= eventListing[i].DateEnd.date()):
			newEventListing.append(eventListing[i])
	return newEventListing

#iterates through the StartDate, EndDate, and RRule items in the classes making them into datetime objects where
#approppriate and turns the RRule field (if present) into something digestable by other functions
def cleanUpEventDateTime(eventStorage):
	DateST = eventStorage.DateStart
	beg = DateST[0:11]
	end = DateST[11:15]
	DateST = beg + end
	format = "%Y%m%dT%H" + "%M%S"
	eventStorage.DateStart = datetime.strptime(DateST,format)

	DateND = eventStorage.DateEnd
	beg = DateND[0:11]
	end = DateND[11:15]
	DateND = beg + end
	eventStorage.DateEnd = datetime.strptime(DateND,format)

	if eventStorage.RRule != None:
		RR = eventStorage.RRule
		RR = RR[18:32]
		eventStorage.RRule = datetime.strptime(RR,format)

#cleans up the input command arguments to be digestable by other methods
def cleanUpDateArguments(dirtyDate):
	timeFormat = '%d/%m/%Y'
	cleanDate = datetime.strptime(dirtyDate,timeFormat)
	return cleanDate

def occupyEvents(input_file, nextline, eventItem, eventListing):
# This function finds each individual data field and occupies an instance of the class
# eventstorage with that particular event's information
# ---
# this results in a list of dataStorage objects with each object containing an events info
	eventItem.RRule = None
	while nextline[0:10] != "END:VEVENT":
		
		if nextline[0:8] == "DTSTART:":
			eventItem.DateStart = nextline[8:]
			#print "Date start " + eventItem.DateStart
		if nextline[0:6] == "DTEND:":
			eventItem.DateEnd = nextline[6:]
			#print "Date end   " + eventItem.DateEnd
		if nextline[0:9] == "LOCATION:":
			eventItem.Location = nextline[9:]
			#print "Location   " + eventItem.Location
		if nextline[0:8] == "SUMMARY:":
			eventItem.Summary = nextline[8:]
			#print "Summary    " + eventItem.Summary
		if nextline[0:6] == "RRULE:":
			eventItem.RRule = nextline[6:]
			#print "RRule   " + eventItem.RRule
		nextline = input_file.readline()

	eventListing.append(eventItem)
	return	

#Class for storing data values for each event
class eventStorage():
	def __init__(self):
		DateStart = None
		DateEnd = None
		Location = None
		Summary = None
		RRule = None
		NotPrinted = True
		endOfListIndicator = False

#debug method used for printing out the current list and it's items in order
def debug(eventListing):
	for i in range(len(eventListing)):
		print "-"*20
		print "List Event " + str(i+1)
		print "-"*20
		print "DateStart : " + str(eventListing[i].DateStart)
		print "DateEnd   : " + str(eventListing[i].DateEnd)
		print "Location  : " + str(eventListing[i].Location)
		print "Summary   : " + str(eventListing[i].Summary)
		print "RRule     : " + str(eventListing[i].RRule)
	return

if __name__ == "__main__":
	main()
