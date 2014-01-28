# Project Euler Problem: 17
# Goal: find the sum of the number of letters of the number words from 1-1000.
# Author: Cooper Bell

numbers = {0:'', 1:'one',2:'two',3:'three',4:'four',5:'five',6:'six',7:'seven',8:'eight',9:'nine',10:'ten',11:'eleven',12:'twelve',13:'thirteen',14:'fourteen',15:'fifteen',16:'sixteen',17:'seventeen',18:'eighteen',19:'nineteen'}
tens_prefixes = {10:'', 20:'twenty',30:'thirty',40:'forty',50:'fifty',60:'sixty',70:'seventy',80:'eighty',90:'ninety'}
hundreds_prefixes = {100:'onehundred',200:'twohundred',300:'threehundred',400:'fourhundred',500:'fivehundred',600:'sixhundred',700:'sevenhundred',800:'eighthundred',900:'ninehundred'} 

letters = [numbers[i] for i in range(1,20)] # Add number-words 1-19

for i in range(20,100,10): # Add number-words 20-99
	for j in range(0,10):
		letters += [tens_prefixes[i] + numbers[j]]

for k in range(100,1000,100): # Add number-words 100-999
	for l in range(10,100,10):
		if l == 10:
			letters += [hundreds_prefixes[k]]	
			for n in range(1,20):
				letters += [hundreds_prefixes[k] + 'and' + numbers[n]]
		else:
			for m in range(0,10):
				letters += [hundreds_prefixes[k] + 'and' + tens_prefixes[l] + numbers[m]]
				
letters += ['onethousand'] # Can't forget 1000 :)

word_sum = 0
for word in letters:
	word_sum += len(word)
	
print word_sum