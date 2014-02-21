The following lines were used to generate the test files via the instructor's
sample solution:

./schedprint_plus.py --start=11/10/2013 --end=12/10/2013 --tz=-8 --file=deborah_developer.ics > test01.txt
./schedprint_plus.py --start=5/11/2013 --end=11/11/2013 --tz=-8 --file=deborah_developer.ics > test02.txt
./schedprint_plus.py --start=30/10/2013 --end=30/10/2013 --tz=-8 --file=deborah_developer.ics > test03.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics > test04.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics > test05.txt
./schedprint_plus.py --start=31/10/2013 --end=31/10/2013 --tz=-8 --file=deborah_developer.ics > test06.txt
./schedprint_plus.py --start=1/11/2013 --end=30/11/2013 --tz=-8 --file=deborah_developer.ics > test07.txt
./schedprint_plus.py --start=1/12/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics > test08.txt
./schedprint_plus.py --start=8/9/2013 --end=3/12/2013 --tz=-8 --file=deborah_developer.ics > test09.txt
./schedprint_plus.py --start=28/9/2013 --end=25/9/2013 --tz=-8 --file=deborah_developer.ics > test10.txt
./schedprint_plus.py --start=11/10/2013 --end=12/10/2013 --tz=-8 --file=nhl_canada.ics > test11.txt
./schedprint_plus.py --start=5/11/2013 --end=11/11/2013 --tz=-8 --file=nhl_canada.ics > test12.txt
./schedprint_plus.py --start=30/10/2013 --end=30/10/2013 --tz=-8 --file=nhl_canada.ics > test13.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=nhl_canada.ics > test14.txt
./schedprint_plus.py --start=01/01/2013 --end=31/12/2013 --tz=-8 --file=nhl_canada.ics > test15.txt
./schedprint_plus.py --start=31/10/2013 --end=31/10/2013 --tz=-8 --file=nhl_canada.ics > test16.txt
./schedprint_plus.py --start=1/11/2013 --end=30/11/2013 --tz=-8 --file=nhl_canada.ics > test17.txt
./schedprint_plus.py --start=1/12/2013 --end=31/12/2013 --tz=-8 --file=nhl_canada.ics > test18.txt
./schedprint_plus.py --start=8/9/2013 --end=3/4/2014 --tz=-8 --file=nhl_canada.ics > test19.txt
./schedprint_plus.py --start=28/9/2013 --end=25/9/2013 --tz=-8 --file=nhl_canada.ics > test20.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-8 --file=one.ics,many.ics > test21.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-4 --file=one.ics,many.ics > test22.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-3 --file=one.ics,many.ics > test23.txt
./schedprint_plus.py --start=1/11/2013 --end=12/12/2013 --tz=-5 --file=nhl_canada.ics > test24.txt
./schedprint_plus.py --start=1/11/2013 --end=12/12/2013 --tz=1 --file=nhl_canada.ics > test25.txt
./schedprint_plus.py --start=1/9/2013 --end=15/12/2013 --tz=-5 --file=deborah_developer.ics > test26.txt
./schedprint_plus.py --start=1/9/2013 --end=15/12/2013 --tz=1 --file=deborah_developer.ics > test27.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-8 --file=deborah_developer.ics,one.ics > test28.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=1 --file=deborah_developer.ics,one.ics,nhl_canada.ics > test29.txt
./schedprint_plus.py --start=1/1/2013 --end=31/12/2013 --tz=-5 --file=deborah_developer.ics,one.ics,nhl_canada.ics > test30.txt

Although the locations of files in your account may differ, the "--start",
and "--end" values you need to run your tests must be given when you run
your own program from the command line.
