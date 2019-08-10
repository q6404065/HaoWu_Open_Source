#! /usr/bin/env python3
from os import system
from termcolor import colored
from time import sleep

""" The author is Hao Wu,
    If you have any question, Please
    contact hao.wu81@du.edu, it is an academic e-mail.
    Thank You. """


def main():
    """Main is just main as i said many times -v-"""
print(colored('\nplease ensure that you have installed dnsmasq!!','red'))
print(colored('\nYou need to edit dnsmap.conf if your ap name'
              ' or your host ip is different','red'))
print(colored('\nYou should run it after ap created','red'))
sleep(5)
system('ifconfig -a')
sleep(3)
ap = input(colored('What is your ap name? Hint: at0 something ','blue'))
system('ifconfig {0} 10.0.0.1 up'.format(ap))
eth = input(colored('What is your upload network name? Hint: eth0 something ','blue'))
system('iptables --flush')
sleep(1)
system('iptables --table nat --append POSTROUTING --out-interface {0} -j MASQUERADE '.format(eth))
sleep(1)
system('iptables --append FORWARD --in-interface {0} -j ACCEPT '.format(ap))
sleep(1)
system('iptables -t nat -A PREROUTING -p tcp --dport 80 -j DNAT --to-destination 10.0.0.1:80 ')
sleep(1)
system('iptables -t nat -A POSTROUTING -j MASQUERADE')
sleep(1)
system('echo 1 > /proc/sys/net/ipv4/ip_forward')
sleep(1)
system('dnsmasq -C ./dnsmasq.conf -d')
print(colored('\nYou are all set please let it run','green'))
