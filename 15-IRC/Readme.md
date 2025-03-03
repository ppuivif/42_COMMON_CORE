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
Port is a number between 0 and 65535 included (ports are represented using a 16-bit unsigned integer in networking so there are 2^16 possibilities).</br>
There isn't any restriction on the password. //is "" permitted ? Very longggggggg password to be tested.

## Input signals
The program could receive :
  - a Signal Interrupt (SIGINT) with CTRL C,
  - a Signal Quit (SIGQUIT) with CTRL \.
To handle signals, signal function must be set (<signal.h>).</br>
This function specifies a way to handle the signals with the signal number specified by sig (2 for SIGINT, 3 for SIQUIT).
```C++
signal(SIGINT, signalHandler);
```
where signalHandler is a pointer to a function which will be used to manage action on signal (displaying a message, exit, ...).</br>
This function should follow the following prototype :
```C++
void signalHandler (int signal);
```
where signal will take the signal number.

## Creation of the server
A class Server could be created.</br>
Its constructor could take 2 parameters :
  - the port number,
  - the password.

### Server initialization
To run a server need sockets.
A socket is an endpoint for communication between two machines over a network. It allows processes to send and receive data, whether they are on the same device or different devices across the internet.
A server side socket is defined by 3 elements :
  - IP address to identify the server on the network,
  - port number* to identify the specific service or application on the device,
  - protocol to define how the data is transmitted (TCP or UDP**).

* On a device, several applications could use the network at the same time. The port number is a numerical identifier used to ensure that data is delivered to the correct application on the device.
** TCP (Transmission Control Protocol) and UDP (User Datagram Protocol) are the two main transport layer protocols used for sending data over the internet. They define how data is sent and received between devices.</br>
TCP establishes a connection before sending data and ensures it is delivered accurately and in order.</br>
It is used for :
  - web browsing (HTTP, HTTPS on ports 80, 443),
  - file transfert (FTP on port 21),
  - email (SMTP, IMAP, POP3),
  - Secure Shell (SSH on port 22).
UDP is a connectionless protocol, meaning it sends data without ensuring delivery. It’s faster but less reliable.</br>
It is used for :
  - online gaming,
  - VoIP (Skype, Zoom, WhatsApp calls),
  - live video streaming (YouTube, Twitch, Netflix, ...),
  - DNS lookups.
A socket using TCP is called stream socket.</br>
A socket using UDP is called datagram socket.</br>


Socket function is used.
Socket() is a system call function used to create an endpoint to establish a connection between two processes allowing them to exchange data.

