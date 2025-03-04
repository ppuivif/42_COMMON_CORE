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
  - the port number as first argument, which on server will allow incoming calls,
  - the password as second one, with which clients will identify themselves when trying to connect on server.

## Parsing on arguments
The number of arguments is limited to 2.</br>
Port is a number between 0 and 65535 included (ports are represented using a 16-bit unsigned integer in networking so there are 2^16 possibilities).</br>
There isn't any restriction on the password. //is "" permitted ? Very longggggggg password to be tested.

## Input signals
The program could receive :
  - a Signal Interrupt (SIGINT) with CTRL C,
  - a Signal Quit (SIGQUIT) with CTRL \\.</br>
To handle signals, signal function must be set.</br>
This function specifies a way to handle the signals with the signal number specified (2 for SIGINT, 3 for SIQUIT).
```C++
#include <signal.h>

signal(SIGINT, signalHandler);
```
where signalHandler is a pointer to a function which will be used to manage action on signal (displaying a message, exit, ...).</br>
This function should follow the following prototype :
```C++
void signalHandler(int signal);
```
where signal will take the signal number.

## Creation of the server
To connect to a server, a client need to know :
  - the port number(1),
  - the password.

(1)The port number is used to identify the specific service or application to reach on the device.</br>
Indeed, on a device, several applications could use the network at the same time. The port number is a numerical identifier used to ensure that data is delivered to the correct application on the device.</br>

### Server initialization
To run a server need sockets.
A socket is an endpoint for communication between two machines over a network. It allows processes to send and receive data, whether they are on the same device or different devices across the internet.

Server side, a socket is created (server socket) for listening incoming connections.</br>
This socket does not directly communicate with clients.</br>
A server socket is defined by 3 elements :
  - IP address to identify the server on the network,
  - port number,
  - protocol to define how the data is transmitted (TCP or UDP)(2).

(2) TCP (Transmission Control Protocol) and UDP (User Datagram Protocol) are the two main transport layer protocols used for sending data over the internet. They define how data is sent and received between devices.</br>
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

#### Server socket creation :
A server socket is created once at the start using the function socket(). Its prototype is defined as following :
```C++
<sys/socket.h>

int socket(int domain, int type, int protocol)
```
where "domain" specifies the address family. It could take different values as :
  - AF_INET for IPv4,
  - AF_INET6 for IPv6, ...

where "type" specifies the socket type. It could take the values :
  - SOCK_STREAM for a stream socket,
  - SOCK_DGRAM for a datagram socket.

where "protocol" defines the protocol type. If "protocol" is set at 0, the system choose the default protocol for the given type.</br>

The function return an integer which is a file descriptor. If it fails, it returns -1.

#### Server socket options :
setsockopt() is a function used to configure options for a socket.</br>
It could be used to allow the socket to reuse the address, especially for restarting a server quickly.</br>
With this option, the server will be allowed to reuse the same port immediately after restarting, rather than waiting for the OS to release it.</br>
Its prototype is defined as following :
```C++
#include <sys/socket.h>

int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
```
where "socket" is the file descriptor of the socket to configure.</br>
where "level" indicate if the option applies to the socket level or to a specific protocol. If it concerns the socket level only, "level" will take the value "SOL_SOCKET".</br>
where option_name is the option to set. To reuse the address, the option_name will be set at SO_REUSEADDR.</br>
where option_value is a pointer to the value being set (typically it will point to the address of a variable enable set at 1).</br>
where option_len specifies the size of the option_value (here sizeof(enable)).</br>

