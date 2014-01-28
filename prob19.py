# Project Euler Problem: 19
# Goal: find the number of Sundays that fall on the first of the month from 1 Jan 1901 to 31 Dec 2000 
# Author: Cooper Bell

def lookup(d,v):
	for k in d:
		 if d[k] == v:
			return k
	raise ValueError
	
def Calender(start_day, year):
	month_name = {1:[], 2:[], 3:[], 4:[], 5:[], 6:[], 7:[], 8:[], 9:[], 10:[], 11:[], 12:[]}
	months = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
	months_leap = {1:31, 2:29, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
	days = {1:'Sunday',2:'Monday',3:'Tuesday',4:'Wednesday',5:'Thursday',6:'Friday',7:'Saturday'}
	
	day = start_day
	for i in range(1,13):
		if year%4 == 0:
			for j in range(months_leap[i]):
				if day > 7:
					day = 1
				month_name[i].append(days[day])
				day += 1
		else:
			for j in range(months[i]):
				if day > 7:
					day = 1
				month_name[i].append(days[day])
				day += 1
	a = lookup(days, month_name[12][30])
	if a == 7:
		end_day = 1
	else:
		end_day = a + 1
	return month_name, end_day			

def num_day(day, year, dict):
	count = 0
	for i in range(1,13):
		if dict[year][i][0] == day:
			count += 1
		else:
			continue
	return count

years = dict()	
start_day = 3 # The year 1901 starts on a Tuesday

for year in range(1901,2001):
	years[year] = Calender(start_day, year)[0]
	start_day = Calender(start_day, year)[1]
	
sundays = 0

for yr in range(1901, 2001):
	sundays += num_day('Sunday', yr, years)
	
print sundays