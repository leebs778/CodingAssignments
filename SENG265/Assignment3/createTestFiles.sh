#!/bin/bash
echo "-------------------------------"
echo "Creating new batch of python outputs"
echo "-------------------------------"
echo " "
./schedprint_plus.py --start=11/10/2013 --end=12/10/2013 --tz=-8 --file=deborah_developer.ics > mytest01.txt
./schedprint_plus.py --start=5/11/2013 --end=11/11/2013 --tz=-8 --file=deborah_developer.ics > mytest02.txt
./schedprint_plus.py --start=30/10/2013 --end=30/10/2013 --tz=-8 --file=deborah_developer.ics > mytest03.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics > mytest04.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics > mytest05.txt
./schedprint_plus.py --start=31/10/2013 --end=31/10/2013 --tz=-8 --file=deborah_developer.ics > mytest06.txt
./schedprint_plus.py --start=1/11/2013 --end=30/11/2013 --tz=-8 --file=deborah_developer.ics > mytest07.txt
./schedprint_plus.py --start=1/12/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics > mytest08.txt
./schedprint_plus.py --start=8/9/2013 --end=3/12/2013 --tz=-8 --file=deborah_developer.ics > mytest09.txt
./schedprint_plus.py --start=28/9/2013 --end=25/9/2013 --tz=-8 --file=deborah_developer.ics > mytest10.txt
./schedprint_plus.py --start=11/10/2013 --end=12/10/2013 --tz=-8 --file=nhl_canada.ics > mytest11.txt
./schedprint_plus.py --start=5/11/2013 --end=11/11/2013 --tz=-8 --file=nhl_canada.ics > mytest12.txt
./schedprint_plus.py --start=30/10/2013 --end=30/10/2013 --tz=-8 --file=nhl_canada.ics > mytest13.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=nhl_canada.ics > mytest14.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=nhl_canada.ics > mytest15.txt
./schedprint_plus.py --start=31/10/2013 --end=31/10/2013 --tz=-8 --file=nhl_canada.ics > mytest16.txt
./schedprint_plus.py --start=1/11/2013 --end=30/11/2013 --tz=-8 --file=nhl_canada.ics > mytest17.txt
./schedprint_plus.py --start=1/12/2013 --end=31/12/2013 --tz=-8 --file=nhl_canada.ics > mytest18.txt
./schedprint_plus.py --start=8/9/2013 --end=3/4/2014 --tz=-8 --file=nhl_canada.ics > mytest19.txt
./schedprint_plus.py --start=28/9/2013 --end=25/9/2013 --tz=-8 --file=nhl_canada.ics > mytest20.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-8 --file=one.ics,many.ics > mytest21.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-4 --file=one.ics,many.ics > mytest22.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-3 --file=one.ics,many.ics > mytest23.txt
./schedprint_plus.py --start=1/11/2013 --end=12/12/2013 --tz=-5 --file=nhl_canada.ics > mytest24.txt
./schedprint_plus.py --start=1/11/2013 --end=12/12/2013 --tz=1 --file=nhl_canada.ics > mytest25.txt
./schedprint_plus.py --start=1/9/2013 --end=15/12/2013 --tz=-5 --file=deborah_developer.ics > mytest26.txt
./schedprint_plus.py --start=1/9/2013 --end=15/12/2013 --tz=1 --file=deborah_developer.ics > mytest27.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics,one.ics > mytest28.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=1 --file=deborah_developer.ics,one.ics,nhl_canada.ics > mytest29.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-5 --file=deborah_developer.ics,one.ics,nhl_canada.ics > mytest30.txt
echo " "
echo "-------------------------------"
echo "done!"
echo "-------------------------------"