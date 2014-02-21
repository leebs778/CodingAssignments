
#	
#	Show a nice use of the datetime module
#	Shows how to compare some dates and wait until one has past
#	

from datetime import datetime, timedelta
from time import sleep


end_dt = datetime.now() + timedelta(seconds=10)


print '\nStarting test...\n============================='

# While we haven't hit the end time yet, continue...
while datetime.now() < end_dt:
	# Have to convert the datetime objects to strings to print them
	print 'TARGET TIME: ' + str(end_dt) + ', not yet: ' + str(datetime.now())

	# Just so that we're not spamming to the screen
	sleep(1)


print '=============================\n\nDone.'



