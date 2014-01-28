import datetime

def print_day_of_week(year, month, day):
	days = {0:'Monday', 1:'Tuesday', 2:'Wednesday', 3:'Thursday', 4:'Friday', 5:'Saturday', 6:'Sunday'}
	return days[datetime.date(year, month, day).weekday()]
	
def birthday(year, month, day):
	bday = datetime.datetime(year, month, day)
	today = datetime.datetime.utcnow()
	next_bday = datetime.datetime(today.year, month, day)
	
	age = (today - bday).days/365
	next = (next_bday - today)
	min, seconds = divmod(next.seconds, 60)
	hours, minutes = divmod(min, 60)
	
	delta = (next.days, hours, minutes, seconds)
	
	print "You are %s years old." % age
	print "Your birthday is %s days, %s hours, %s minutes and %s seconds away!" % delta
	
def double_day(bday1, bday2):
	assert type(bday1) == 'datetime.datetime' and type(bday2) == 'datetime.datetime'
	
	
bday1 = datetime.datetime(1986, 4, 2)
bday2 = datetime.datetime(1990, 3, 7)