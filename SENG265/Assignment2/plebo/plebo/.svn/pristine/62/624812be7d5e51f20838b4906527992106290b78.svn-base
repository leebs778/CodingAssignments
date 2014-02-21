#!/usr/bin/python
import sys
from datetime import datetime
from datetime import timedelta


'''
To do List:
		extra space after allmy output
			this problem isnt happening b/c of the output function  - its happening for some
			other reason...
			Hack solution - if we're at the last event date entry, DONT print a new line after
		entries at the same time slot are switched - is this a problem?

'''

def main():
	total = len(sys.argv)
	if (total <= 1):
		print "no args given. The program will now crash and burn. Thank you"
		return
	#acquire all the necessary command line arguments
	filehold = sys.argv[3]
	filehold = filehold[7:]
	input_file = open(filehold, "r")	
	firstline = input_file.readline()
	if firstline[0:15] != "BEGIN:VCALENDAR":
		print "improper file input, please give me a specified .ics file"
		return
	nextline = input_file.readline()
	eventListing = []
	eventItem = eventStorage()
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
	
	for i in range(len(eventListing)):
		cleanUpEventDateTime(eventListing[i])
	eventListing = acquireProperCalendarEvents(startArgument,endArgument, eventListing)
	accomodatingRepeatingEvents(eventListing)
	eventListing = sorted(eventListing, key=lambda date: date.DateStart)
	#debug(eventListing)
	output(eventListing)
	#need to clean up output to make each day appear only once


def output(eventListing):
	newGuap = []
	firstComp = -1
	secondComp = 0
	for i in range(len(eventListing)):
		eventListing[i].NotPrinted = True
		eventListing[i].endOfListIndicator = False
	eventListing[len(eventListing)-1].endOfListIndicator = True
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
		for z in range(len(newGuap)):
			eventEntry(newGuap[z])
			endOfListIndicator = False
			if newGuap[z].endOfListIndicator == True:
				return
		if (z == len(newGuap)-1):
				print ""

		newGuap[:] = []
		firstComp = -1
		secondComp = 0
	


def topOfOutput(StartDate):
	dateOutput = StartDate.strftime('%B %d, %Y (%a)')
	print dateOutput
	print "-"*len(dateOutput)

def eventEntry(eventStorage):
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
	output = startTimeSlot + " to " + endTimeSlot + " | " + secondPortion
	print output[:len(output)-1]

def accomodatingRepeatingEvents(eventListing):
	for i in range(len(eventListing)):
		if eventListing[i].RRule != None:
			dS = eventListing[i].DateStart
			until = eventListing[i].RRule
			deltaTime = until - dS 		#84
			#print "deltaTime " + str(deltaTime)
			response = int(deltaTime.days / 7)	#12
			#print "reponse   " + str(response)
	
			for j in range(response):
				deltaSeven = timedelta(days=7*(j+1))
				repetitionEvent = eventStorage()
				repetitionEvent.DateStart = eventListing[i].DateStart + deltaSeven
				repetitionEvent.DateEnd = eventListing[i].DateEnd + deltaSeven
				repetitionEvent.Summary = eventListing[i].Summary
				repetitionEvent.Location = eventListing[i].Location
				repetitionEvent.RRule = None
				eventListing.append(repetitionEvent)

def acquireProperCalendarEvents(startArgument, endArgument, eventListing):
	#print "startArgument " + str(startArgument.date())
	#print "endArgument   " + str(endArgument.date())
	newEventListing = []
 	for i in range(len(eventListing)):
 		#print "eventListing[i].DateStart.date() " + str(eventListing[i].DateStart.date())
 		#print "eventListing[i].DateEnd.date()   " + str(eventListing[i].DateEnd.date())
		if (startArgument.date() <= eventListing[i].DateStart.date()) and (endArgument.date() >= eventListing[i].DateEnd.date()):
			newEventListing.append(eventListing[i])

	return newEventListing

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