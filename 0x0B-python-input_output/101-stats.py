#!/usr/bin/python3

"""
A script: Reads standard input line by line and computes metrics
"""


def parseLogs():
    """
    Reads logs from standard input and generates reports

    Reports:
        * Prints log size after reading every 10 lines & at KeyboardInterrupt

    Raises:
        KeyboardInterrupt (Exception): handles this exception and raises it
    """
    stdin = __import__('sys').stdin
    lineNumber = 0
    fileSize = 0
    statusCodes = {}

    try:

        for line in stdin:
            lineNumber += 1
            line = line.rstrip().split()
            try:
                fileSize += int(line[-1])

                try:
                    if statusCodes[line[-2]]:
                        statusCodes[line[-2]] += 1
                except KeyError:
                    statusCodes[line[-2]] = 1

            except (IndexError, ValueError):
                pass

            if lineNumber == 10:
                report(fileSize, statusCodes)
                lineNumber = 0

    except KeyboardInterrupt as e:
        report(fileSize, statusCodes)
        raise


def report(fileSize, statusCodes):
    """
    Prints generated report to standard output

    Args:
        fileSize (int): total log size after every 10 successfully read line
        statusCodes (dict): dictionary of status codes and counts
    """
    print("File size: {:d}".format(fileSize))

    for key in sorted(statusCodes):
        print("{}: {}".format(key, statusCodes[key]))


if __name__ == '__main__':
    parseLogs()
