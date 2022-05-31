#!/usr/bin/python3
import random
number = random.randint(-10000, 10000)

if number > 0:
    lastDigit = int(str(number)[-1])
else:
    lastDigit = int(str(number)[-1])
    lastDigit *= -1

if lastDigit > 5:
    print(f"Last digit of {number:d} is {lastDigit:d} and \
is greater than 5")
elif lastDigit == 0:
    print(f"Last digit of {number:d} is {lastDigit:d} and is 0")
else:
    print(f"Last digit of {number:d} is {lastDigit:d} and is less than 6 and \
not 0")
