#!/usr/bin/python3

"""
A python script that fetches https://alx-intranet.hbtn.io/status
"""

if __name__ == '__main__':
    import urllib.request
    url = 'https://alx-intranet.hbtn.io/status'
    req = urllib.request.Request(url)
    with urllib.request.urlopen(req) as response:
        content = response.read()
        print("Body response:\n\
        - type: {}\n\
        - content: {}\n\
        - utf8 content: {}".format(
            type(content), content, content.decode('utf-8'))
        )
