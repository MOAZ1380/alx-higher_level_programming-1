#!/usr/bin/python3
def print_last_digit(number):
    lastDigit = int(str(number)[-1])
    print("{:d}".format(lastDigit), end='')
    return lastDigit
