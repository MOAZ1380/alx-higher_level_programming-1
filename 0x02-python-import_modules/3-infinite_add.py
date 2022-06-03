#!/usr/bin/python3
from sys import argv


def add(args):
    result = 0
    if len(args) > 0:
        for arg in args:
            result += int(arg)
    return result


if (__name__ == '__main__'):
    print(add(argv[1:]))
