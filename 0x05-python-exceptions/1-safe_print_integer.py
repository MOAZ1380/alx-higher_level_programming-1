#!/usr/bin/python3


def safe_print_integer(value):
    result = True
    try:
        print("{:d}".format(value))
    except ValueError:
        result = False
    finally:
        return result
