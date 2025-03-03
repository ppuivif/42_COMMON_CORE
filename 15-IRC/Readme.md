in progress
# 42School : creating an Internet Relay Chat in ft_irc project

## Purpose of the project
This is a light description of the project.</br>
The subject says :</br>
Internet Relay Chat is a text communication protocol on the Internet. It is used for instantaneous communication, mainly in the form of group discussions chat channels, but can also be used for direct com- munication between two people.</br>
IRC clients connect to IRC servers to access channels. The IRC servers are connected to each other to create networks.</br>

The main of the project is to create an IRC server only, not any client.</br>
Handling communication between two servers is not required.</br>

The program will be named "ircserv".</br>
It will take 2 arguments :
  - the port as first argument, which on server will allow incoming calls,
  - the password as second one, with which clients will identify themselves when trying to connect on server.

## Parsing on arguments
The number of arguments is limited to 2.</br>
Port is a number between 0 and 65535 included (ports are represented using a 16-bit unsigned integer in networking so there are 2^16 possibilities).

## Input signals
The program could receive :
  - a Signal Interrupt (SIGINT) with CTRL C,
  - a Signal Quit (SIGQUIT) with CTRL \.
To handle signals, signal function must be set (<signal.h>).</br>
This function specifies a way to handle the signals with the signal number specified by sig (2 for SIGINT, 3 for SIQUIT).



