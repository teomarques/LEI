### Course Contents
- *Computer Networks and the internet*
- *Application Layer*
- *Transport Layer*
- *Network Layer*
- *Link Layer*
- *Network Security*
- *Wireless and Mobile*
- *Multimedia Network*
- *Network Management*

*pl*
## Configure Terminal

in the terminal, type 

`gnome-terminal --tab -t "{name}" -- telnet {host} {port}`

and replace the {name} by the desired, the {host}{port} by the indicated. For example, 


```gnome-terminal --tab -t "{name}" -- telnet localhost 5000```


*teórico-prática*
## IP Addressing

- ***What is an IP Address?***
	- IP Addresses allow to uniquely identify and communicate with **hosts** (servers, laptops, smartphones, etc) in the internet.
	- IPv4 addresses are written as four numbers sepparated by periods ("."), each number can be from **0** to **255**
	- Alternatively, can be written in hexadecimal notation

**IPV4** -> <u>32 bit</u> used for addresses and provides a total of <u>4,294,967,296</u> addresses

**IPv6** -> <u>128 bits</u> used fot addresses and provides a total of <u>340,282,366,920,938,463,374,607,431,768,211,456</u> addresses

#### Classful Addressing
	32 bit are divided into subclasses: A, B, C, D and E
	Each class has a valid range of IP addresses
	The order of he bits in the first byte / octet determines the classes of the IP addresses
	Each IP address is divided in Network ID and Host ID
	The class of the IP address determines the number of total networks and hosts possible in that particular class
	IP addresses are globally managed by the Internet Registries Numbers Authority (IANA) and Regional Internet Registries (RIR)
	Each ISP or Network Administrator assigns IP address to each device that is connected to its network

![[Pasted image 20250207160702.png]]


#### IPv4 classful addressing 
- **Class A** IPv4 addresses
	- *(Nº OF HOSTS)* assigned to networks that contain a *large number of hosts* 
	- *(BITS ORGANIZATION)* network ID is **8 bits (1 byte)** long, host ID is **3 bytes (24 bits)** long 
	- *(PREFIX BIT)* higher order bit (left to right) of the first byte is always ***0*** 
	- *(RANGE)* Goes from **1.0.0.1** to **126.255.255.254** 
![[Pasted image 20250207172003.png]]

- **Class B** IPv4 addresses
	- *(Nº OF HOSTS)* Assigned to medium-sized to large-sized networks
	- *(BITS ORGANIZATION)* Network ID is **16 bits (2 bytes)** long, host ID is **16 bits (2 bytes)** long
	- *(PREFIX BITS)* higher order bit (left to right) of the first byte is always ***10***
	- *(RANGE)* From **128.1.0.1** to **191.255.255.254**
![[Pasted image 20250207173343.png]]

- **Class C** IPv4 addresses:
	- *(Nº OF HOSTS)* Assigned to medium-sized to large-sized networks
	- (BITS ORGANIZATION) Network ID is **24 bits (3 bytes)** long, Host ID is **8 bits (1 byte)** long
	- (PREFIX BITS) Higher order bits of the first byte is always ***110***
	- *(RANGE)* From **192.0.1.1** to **223.255.255.254**
![[Pasted image 20250207174537.png]]

- **Class D** IPv4 addresses:
	- () // Multicast uses multiple devices to send data to a single destination through distinct streams or channels.

- *IPV4 vs IPV6*
- *IPV4 classful addressing*
- *IP addresses and netmasks*
- *Special addresses*
- *Reserved IP Addresses*

---

# PL 2

255 . 255 . 252 . 0

| **Network**                  | **HOST**      |
| ---------------------------- | ------------- |
| 11111111 . 11111111 . 111111 | 00 . 00000000 |

(that's because the *DHCP* given is *10 . 20 . 192 . 0 / 22* which means that it's *mask* is *22* so the IP address will have *22 bits for the network* and 32 - 22 = *10* bits for the *host* )

| Network Address | Mask          |
| --------------- | ------------- |
| 10.20.192.0     | 255.255.255.0 |

*(Dynamic host config protocol)*
**DHCP** -> **00001010 . 000101000 . 110000 | 00 .00000000**

- ***First valid usable network address***
	- -> 00 . 00000001        <u>(don't use 00.00000000 because it is the Network Address)</u>

- ***Last valid usable network address*** 
	- -> the rest keeps the same | 11.11111110        <u>(don´t use 11.11111111 because it is the *broadcast* address)</u>

PS: **Broadcast address** is when **all HOST bits are 1**, it is used to **send data to all devices** on a  specific network

- **Classless Inter Domain Routing**  

###### Range
i.e. 

| *subnet*                 | 10.20.192.10                              |
| ------------------------ | ----------------------------------------- |
| *subnet mask*            | 255.255.255.0 /24                         |
| *subnet mask* (notation) | /24                                       |
| *network address*        | 10.20.192.0                               |
| *range*                  | 10.20.192.1 to 10.20.195.254              |
| *broadcast address*      | 10.20.192.255                             |
| *b.a. binary*            | 11000000 . 10101000 . 00000001 . 11111111 |

- Now we have the network = 193.136.224.0/20

for the problem we have 2 networks, we need 1 bit to *identify which one* --> **SR**

| subNetwork 1                   | subNetwork 2                   | SR     | HOST |
| ------------------------------ | ------------------------------ | ------ | ---- |
| 10001000.1110.*0*.000.00000000 | 10001000.1110.*1*.000.00000000 | 0 \| 1 |      |

At this moment we have **2 subNetworks**: it gets the mask **/21** now because **we need the 20 plus the 1 bit borrowed from the HOST** that is used to **identify the subNetwork (SR)**

1. 10001000 . 1110 |  0  | 000 . 00000000

2. *subNetworks* -> 11000001 . 10001000 . 1110 | 0 | 000 . 00000000
$$until$$
				11000001 . 10001000 . 1110 | 1 | 000 . 00000000


See the IP in the console: **ipconfig**

---

# T 1

## What is the Internet?

-> billions of connected computing devices:
- *hosts* = *end systems*
- running *network apps*

-> *communication links*
- fiber, copper, radio, satellite
- transmission rate: **bandwidth**

-> *packet switches*: forward packets (chunk of data)
- *routers* and *switches*

> **Internet: "network of networks"**
> 	interconnected ISPs
> **protocols**
> 	control sending, receiving of messages
> 	e.g., TCP, IP, HTTP, Skype, 802.11
>  **Internet standards**
> 	 *RFC*: Request For Comments
> 	 *IETF*: Internet Engineering Task Force

## What's a protocol?

> specific messages sent
> specific actions taken when messages received, or other events

- **Network protocols:**
	- machines rather than humans
	- all communication activity in Internet governed by protocols

**Protocols** define a *format*, *order* of *messages sent and received* among network entities and *actions taken* on message transmission, receipt

![[Pasted image 20250315000103.png]]

==Network 

---
# PL 3

> Introduction to **NAT**
- ==Private Networks== start by 10. ...
- **SNAT** -> (*Source NAT*) who initiates connection in private network (uses NAT)
- **DNAT** -> (*Destination NAT*)who initiates connection in public network (uses NAT)

## GNS3 Tutorial

![[Pasted image 20250218184636.png]]
![[Pasted image 20250218184743.png]]
![[Pasted image 20250218184809.png]]

==ROUTES== -> Defined for the routers to know there to send the packets. They can be:
	**Static**: Configured manually in the equipment
	**Dynamic**: Added to the router configuration automatically, by referral routing protocols

==STATIC ROUTES==
defining static routes
![[Pasted image 20250218190331.png]]
removing static routes
![[Pasted image 20250218190347.png]]
referral router configuration is shown through
![[Pasted image 20250218190508.png]]
- **Running Configuration**: is being *executed at the moment* and reflects *all the commands* executed to the moment. Stored in the *RAM* memory. Lost in shutdown.
- **Startup Configuration**: *executed in startup*, stored in *non-volatile router memory*. If the admin wants to *set the running config to permanent router config*, must *copy it from the RAM to the non-volatile memory*. 
Copy the Running Configuration to the Startup Configuration
![[Pasted image 20250218191501.png]]
![[Pasted image 20250218192551.png]]
***tab*** completes the commands
shortcuts:
![[Pasted image 20250218192704.png]]
**sh run** --> see all the configurations inside the routers


## Assignment 1
$$1$$
R_2A-) 

	R1 e R2
	CIDR: 193.136.224.0
	Mask: 255.255.248.0
	Broadcast: 193.136.231.255
	Gama: 193.136.224.1 - 193.136.231.254

	R2 e R3
	CIDR: 193.136.232.0
	Mask: 255.255.248.0
	Broadcast: 193.136.232.0
	Gama: 193.136.232.1 - 193.136.239.254

R_2B-)

## Assignment 2

==NAT==
- *WHAT* ->Allows to **map IP addresses** in the **communications in between networks**
- *HOW* -> Through **altering the origin or destiny address** in the **heather of the IP packets during its passage through a router**

==SNAT== is one of the most used techniques
- *WHEN* -> The Source NAT is used in the **communications between private IP addresses and the internet**
- *HOW* -> it **forces** the use of **public IP addresses**
- **used to change the private addresses to the public address**

![[Pasted image 20250218171059.png]]

==DNAT== 
- *WHAT* -> The Destination NAT allows the translation of the destination addresses of the IP packets.
- *WHY* -> Commonly used for port forwarding or hosting public services on internal servers

==key differences==

| SNAT                                               | DNAT                                                            |
| -------------------------------------------------- | --------------------------------------------------------------- |
| applied to **outgoing traffic**                    | applied to **incoming traffic**                                 |
| changes the **source address**                     | changes the **destination address**                             |
| used for **internet access from private networks** | used for **hosting services accessible from the internet**      |
| **hides internal network structure**               | **exposes** specific internal **services to the outside world** |




> comments
- there are no routs to private networks (private networks don't go to the internet)

---

# TP 3

## DHCP

- The own Router can serve as a DHCP server

#### DHCP Configuration Example

![[Pasted image 20250221122156.png]]

$$remember$$
==Reserved vs Official IP Addresses==

- ==*Reserved IP Addresses*== are those that are set aside for **specific purposes** and **cannot be used for general public internet communication**. 

![[Pasted image 20250221122944.png]]

- ==Official IP Addresses== are those allocated by the Internet Assigned Numbers Authority (IANA) or regional internet registries (RIRs) for use on the public internet.

![[Pasted image 20250221123208.png]]

**NAT (SNAT) translation table**
![[Pasted image 20250221123416.png]]

key aspects
- the router 10.0.0.4 knows the PC 10.0.0.1 wants to send a packet to the destination D: 128.119.40.186, port 80 (which is the HTTP address)
- the origin port of the PC is 3345, the origin port of the router is 5001, and it will search for the line in the translation table that matches the address of the router (S: 138.76.29.7) and will switch both the WAN (Wide Address Network) side address (Router S: 138.76.29.7, port 5001) and the LAN (Local Address Network) side address (PC S: 10.0.0.1, port 3345), so that the PC becomes the destination of the receiving packet. 
- Then the source becomes the IP of the Server (S: 128.119.40.186, port 80) and the destination becomes the IP of the router (138.76.29.7, port 5001) and after the router, the source becomes the router and the destination becomes the client (PC)

#### SNAT Configuration Example

![[Pasted image 20250221125005.png]]

**NAT (DNAT) translation table**
![[Pasted image 20250225150152.png]]

key aspects
- The router with the public IP address **193.137.203.225** receives a packet from the external server **193.136.239.10**, destined for its public address (D: 193.137.203.225, port 80). The router identifies this as a DNAT scenario and checks its translation table to map the destination to an internal private address.
    
- Based on the translation table, the router modifies the destination address from **193.137.203.225** to the private IP address of the internal server (D: **10.1.0.1**, port 80). The source remains as **193.136.239.10**.
    
- The packet is then forwarded to the internal server **10.1.0.1**, which processes it and sends a response back to the router (S: 10.1.0.1, port 80; D: 193.136.239.10).
    
- Upon receiving the response, the router reverses the DNAT process by changing the source address from **10.1.0.1** back to its public IP (S: 193.137.203.225, port 80), while keeping the destination as **193.136.239.10**.
    
- Finally, the packet is sent back to the external server with these updated addresses, making it appear as if it originated from the public IP of the router, while maintaining seamless communication between internal and external networks through DNAT translation rules.
![[Pasted image 20250225151331.png]]

---
NOTES

- DNAT no R1
- SNAT no R3
(para a ficha 2)

---

# T 2

*Information in the routing tables (Tabelas de Encaminhamento)* -> **Routers**

## Principles of Network Application

>**Application Layers**

#### **TCP/IP** Protocol Stack

> 	An *application* supports many *protocols* in many *layers*

#### Heather

-> the point of a heather is **transport many information from an application by a protocol**, and the **protocol adds information in the heather** (it is control info). Then the *packet* (with the frame heather, packet heather, segment heather, data and frame trailer) arrives in the *physical layer*.

-> **Encapsulation** 
![[Pasted image 20250221141737.png]]

==payload== -> packet (transported packet info)

- *Application:* supporting network applications
	- FTP, SMTP, HTTP, ...

| Application |
| ----------- |
| Transport   |
| Network     |
| Data Link   |
| Physical    |
==Application Layer==

-> *Data Generation*
- The process begins at the **application layer**, where user data is **generated by applications** (e.g., HTTP, FTP, SMTP). This data is often referred to as the ***"payload"***

-> *Example*
`A user sends HTTP request to a Web Server`

==**Client-server Architecture**==
> **Server**
> 	Always on-host
> 	Permanent IP address
> 	Data centers for scaling
> **Client**
> 	Communicate with the server
> 	May be intermittently connected
> 	May have dynamic IP addresses
> 	Do not communicate with each other
> 	Examples: WEB ; FTP ; SSH ; E-Mail
> ![[Pasted image 20250221142959.png]]


==**P2P Architecture**==

> *no* always-on server
> arbitrary end systems communicate directly
> peers request service from other peers, provide service in return to other peers
> 	self scalability:
> 	new peers bring new service capacity, as well as new service demands
> peers are intermittently connected and change IP addresses
> 	Complex Management
> Example: BitTorrent, Skype, IPTV
> Also, some applications use hybrid architectures (e.g. in messaging)
> ![[Pasted image 20250221143336.png]]

==Processes== -> program running within a *host*

| Client Processes                         | Server Processes                       |
| ---------------------------------------- | -------------------------------------- |
| Process that **initiates** communication | Process that **waits** to be contacted |

==**SOCKETS**==

- process *sends/receives* messages *to/from* its **socket**
- A socket is the **software interface** between the *process* and the *computer network* (between the application layer and the transport layer)
- Also called Application Programming Interface (***API***)
- The application *chooses* the **transport protocol** (e.g. UDP or TCP) to *use the transport-layer services provided* by the protocol

![[Pasted image 20250221144044.png]]

### Addressing Processes

- To receive processes, *applications* must have an **identifier**
- Host device has *unique* ***32-bit*** IP address
>*Q*: does IP address of host on which process runs suffice for identifying the process?
>	*R*: no, many processes can be running on same host

- ==identifier== includes both **IP address** and **port numbers** associated with process (the *socket*) on host.
> *Example* of port numbers
>	HTTP server: 80 	
>	Mail server: 25 	

-> Example of addressing processes
![[Pasted image 20250221150126.png]]

> **Types of messages exchanged**
> 	e.g., request, response
>  **Message syntax**
> 	 what fields in messages & how fields are delineated
>  **Message Semantics**
> 	 meaning of information in fields
>  **Rules**
> 	 for when and how processes send & respond to messages
>  **Open protocolsr**
> 	 defined in RFCs (documents)
> 	 allows for interoperability
> 	 e.g., HTTP (HyperText Transfer Protocol), SMTP (Simple Mail Transfer Protocol)
>  **proprietary protocols**
> 	 e.g. Skype

### What transport service does an app need?

> **Data integrity**
> 	some apps require 100% reliable data transfer
> 	 e.g., file transfer, web transactions
> 	 other apps can tolerate some loss
> 	 e.g., audio
>  **timing**
> 	 some apps require low delay to be “effective”
> 	 e.g., Internet telephony, interactive games
>  **throughput**
> 	 some apps require minimum amount of throughput to be “effective”
> 	 e.g. multimedia
> 	 other apps make use of whatever throughput they get
> 	 called “elastic apps”: e.g. e- mail, web, file transfer
>  **Security**
> 	 Encryption, data integrity, ...

![[Pasted image 20250221151349.png]]

**==(TCP / UDP) Internet Transport Protocol Services==**

-> *Segmentation (TCP) or Datagram Creation (UDP)* --> ==PROTOCOL SERVICES==
- The data from the application layer is passed to the **transport layer**, where it is **divided into smaller chunks** called **segments** (for TCP) or **datagrams** (for UDP)

-> *Header Addition*
- ***TCP (segmentation)*** 
	- Adds a *TCP Header* which includes *source and destination port numbers*, *sequence numbers*, *acknowledgment numbers*, and other control information
- ***UDP (datagram creation)***
	- Adds a *UDP header*, which includes *source and destination* and a *checksum*

- ***example***: If using TCP, a **TCP segment is created with a header** containing the **source port** (e.g. 80) and a **destination port** (e.g. 54321)

==Internet Layer (IP)==

-> *Encapsulation into IP Packet*
-  The **segment or datagram** from the transport layer is **passed to the internet layer** where it is **encapsulated into an IP packet**

-> *Header Addition*
- **An IP header is added**, which includes **source and destination IP addresses, protocol type (e.g., TCP, UDP)** and other information such as *time-to-live (TTL)* and *fragmentation control*

-> **Example**: The **TCP segment** is **encapsulated into an IP packet with the source IP address** (e.g., 192.168.1.1) and **destination IP address** (e.g., 192.168.1.2)

IP packets cannot be fully trusted to be sent and received successfully because the Internet Protocol (IP) operates on a **best-effort delivery model**, which means it does not guarantee packet delivery, order, or integrity. There is the possibility of **packet loss**. That is why TCP protocol is used (is reliable and safe, but slower than UDP)

## Security Mechanisms

why are they needed?

> *TCP* & *UDP*
> 	No encryption
> 	Cleartext passwords sent into socket traverse internet in cleartext
> ***SSL***
> 	Provides *encrypted* TCP connection
> 	Data integrity
> 	End-point authentication

### SSL

What is it?

- *SSL* is an *app layer*
- apps use SSL libraries, that "talk" to TCP
- *SSL socket API*
	- cleartext passwords sent into socket traverse internet **encrypted**

## Web and HTTP



---

# PL 4
%(falta - 3 ou 4?)%

---

# TP 4

![[TP04 - Programming with sockets and UDP.pdf]]
## Multiplexing / demultiplexing

A process (part of an application) can have one or more sockets "doors" through which they exchange data with the network

- **multiplexing at sender**: handle data from multiple sockets, add transport header (later used for demultiplexing)
- **demultiplexing at receiver**: use header info to deliver received segments to correct socket

### How demultiplexing works

- host receives IP datagrams

*datagrams*:
- **HAS** *source* IP address, *destination* IP address (in the protocols, they are in the heather transported through encapsulation layers)
- **CARRIES** one transport-segment layer

### Connectionless demux (example)

![[Pasted image 20250307123209.png]]

> in the socket API of UDP, we need to (as a server):
> 	create a UDP socket
> 	understand the port associated with the application and register it
> 	send the packet to the respective destination IP and destination port

### Connection-oriented demux

| UDP socket                                                          | TCP socket                                                                                                |
| ------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| Identification:<br>- dest IP address<br>- dest port number          | Identification:<br>- source IP address<br>- source port number<br>- dest IP address<br>- dest port number |
| each socket received has a port                                     | can receive multiple connections to<br>the same port                                                      |
| connectionless                                                      | creates a new socket for each connection<br>to talk with multiple clients                                 |
| needs to note the destination port to <br>receive and send a packet | knows the destination port and destination IPs                                                            |


$$IMPORTANT$$
``since the TCP protocol identifies the source port number and IP address, together with the destination port number and IP address.``
``For example a website, has a fixed IP address and port number, and has one socket called WELCOMING SOCKET.
``But having only one socket and receiving multiple client requests simultaneously, how to deal with it?
``The TCP automatically creates a copy of the welcoming socket when a new request is identified, and that way the welcoming socket stays free and other clients don't have to wait for the previous connection to end to request a connection!``

__UDP
![[Pasted image 20250307123331.png]]

__TCP
![[Pasted image 20250307123400.png]]

#### Socket programming in C (functions)

- The application invokes the *socket* function to **create** a UDP or TCP socket
```c
int socket(int domain, int type, int protocol);

# int socket: 
# - returns socket file descriptor
# domain:
# - communication domain:
	# AF_INET -> IPv4
	# AF_INET6 -> IPv6
# type:
# - type of socket to be created:
	# SOCK_STREAM -> TCP
	# SOCK_DGRAM -> UDP
# protocol:
# - protocol to be used by socket:
	# IPROTO_UDP -> UDP
	# IPROTO_TCP -> TCP
```

- The *bind* function is used by the server to **assign an address** to the **unbound socket**
```c
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

# sockfd:
# - file descriptor of socket to be binded
# *addr:
# - structure in which address to be binded to is specified
# addrlen:
# - size of addr structure
```

- Most socket functions require a pointer to a socket address structure
- The names of these structures begin with sockaddr_ and end with a unique suffix for each protocol suite

```c
#include <arpa/inet.h>

struct in_addr
{
	in_addr_t s_addr; 
};

struct sockaddr_in
{
	uint8            sin_len;           // length of structure (16)
	sa_family_t      sin_family;        // AF_INET
	in_port_t        sin_port;          // 16-bit TCP or UDP port number
	                                    // network byte ordered
	struct in_addr   sin_addr;          // 32-bit IPv4 address
		                                // network byte ordered
	char             sin_zero[8]        // unused
}
```

- the **sendto** function is used to send a message to a socket
```c
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags, const struct sockaddr *dest addr, socklen:t addrlen);

/*
sockfd:
- file descriptor of socket
*buf:
- application buffer containing the data to be sent
len:
- size of application buffer
flags:
- bitwise OR of flags to modify socket behavior
*dest_addr:
- structure containing address of destination
addrlen:
- size of dest_addr structure
*/
```

- the **recvfrom** function is used to receive a message from the socket
```c
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);

/*
sockfd:
- file descriptor of socket
*buf:
- application buffer in which to receive data
len:
- size of buf application buffer
flags:
- bitwise OR of flags to modify socket behaviour
*src_addr:
- sstructure containing source address is returned
*addrlen:
- variable in which size of src_addr structure is returned
*/
```

- the **close** function is use to close a file descriptor
```c
int close(int fd);

/*
int close -> return code (0 if success)
fd -> file descriptor to close 
*/
```

![[Pasted image 20250307144542.png]]
![[Pasted image 20250307144607.png]]


 ---

# TP 5

## Socket programming (TCP)

- A TCP Server uses two different types of sockets:
	- A *welcoming socket*, where new connections are received by the server -> **remains open** so what **server** can **receive connections from multiple clients**
	- A *connection socket* is created/opened and closed as required, to **handle communication** with clients

![[Pasted image 20250307203158.png]]

==**TCP Heather**==

![[Pasted image 20250312222717.png]]

*TCP connection walkthrough:*
https://www.youtube.com/watch?v=F27PLin3TV0

![[TP05 - Programming with sockets and TCP.pdf]]

%keep going from there%

---

# PL 4
## Server (commands)

*before response:*
1. ==socket()==
-> creates new socket

2. ==bind()==
-> only executed by the server

3. ==listen()==
-> listens for a response from the client

*after response:*
3. ==accept()==
-> accept request to connect

4. ==read/write()==
-> modify info

5. ==close()==
-> close connection

**N2P (Network to Peer)**
- search and see code in pdf

**P2N (Peer to Network)**
- search and see code in pdf
## Client (commands)

*to send request to connect to server*
1. ==socket()==
-> create socket to send to server

2. ==connect()==
-> request to connect to server

*after connecting to server*
1. ==read()/write()==
-> interact with server

2. ==close()==
-> close connection

# Notes about Assignment 3

![[PL-Ficha03.pdf]]

==What to do?==
- simulate the process of a client getting a registered IP address to a certain Domain Name

==How to make the server deal with multiple clients at **the same time?**==

# Basic Function of `fork()`

It creates a copy of the current process (a child process). In the context of a TCP server, this functionality is used strategically to allow processing of multiple clients simultaneously. Let's understand in detail:

```c
if (client > 0)
{
	if (fork() == 0)
	{  
		// Close the listening socket in the child (it doesn't need it)
		close(fd);
		// Process the client
	    process_client(client);
	    // Terminate the child process after processing
	    exit(0);
    }
    // Parent process closes the client socket (doesn't need it)
    close(client);
}
```

## Why Use `fork()` in the Server?

When the server uses `fork()` after accepting a connection, it's implementing a concurrency model known as "one process per connection." Here's how it works:

1. The main server accepts a connection through the `accept()` function
2. When a connection is established, the server calls `fork()`, which **creates an exact copy of the server process**
3. Now there are *two processes*: the **parent process** (***original server***) and the **child process** (***copy***)
4. The ==child process== takes charge of *processing the specific client connection*, while the ==parent process== immediately *returns to accept new connections*

This allows the server to serve multiple clients simultaneously because:

- -> <u>Each client is served by a separate process</u> <-
- The main server never gets blocked processing an individual client
- The child processes operate independently, each with its own copy of process resources (including the client socket descriptor)

#### Random notes from the class

- use domain -> AF_INET
- SOCK_STREAM -> tcp
- SOCK_DGRAM -> udp 
- standard format to networks at the moments of reading and writing messages (to avoid little endian / big endian conflicts)
- ex 3: send messages via NETCAT
- ex 4: client sends decimal number and server converts to binary and sends via socket (make UDP client send message instead of NETCAT, because we need to implement who is the UDP client, but can still send via NETCAT)
- ex 5: use www.wireshark.org; don't send messages via shared data structures (processes), so try between different machines to verify if it works
- grow timer to avoid traffic congesting in router

**Important**:
- In the i80x86 architecture, the order of the bytes is *little-endian* (the first stored in the memory is the least significative byte), while the communications in the network use (send) first the most significative bytes (*big-endian*).

## Project

![[RC2024_2025-Projeto.pdf]]

- Search if it is best to manage parallel communications with sockets or threads

---

# TP 6

![[TP06 - IP Multicast.pdf]]
## Communications with IP - Multicast

![[Pasted image 20250314123536.png]]

1. ==Unicast== -> cast (communicate) only to one host (host bytes are 1)
2. ==Broadcast== -> cast (communicate) to all hosts (host bytes are all 255)
3. ==Multicast== -> cast (communicate) to multiple selected hosts (host *higher order bits* of the *first byte* are always ***1110***)
### IPv4 classful addressing

![[Pasted image 20250314124047.png]]

==**Class D** IPv4 addresses==
- Reserved for multicast communications
- Higher order bits of the first byte is always 1110
- Range from:
	- 224.0.0.0 to 239.255.255.255

![[Pasted image 20250314124557.png]]

## Network Programming (Linux)

- **IP multicasting** provides the capability for an application to send a single IP datagram that a group of hosts in a network can receive. The ***hosts*** in the group may reside on a *single subnet* or may be on *different subnets* (connected by multicast capable routers).

- **Hosts may join and leave groups at any time**. There are no restrictions on the location or number of members in a host group. A class D Internet address in the *range 224.0.0.1 to 239.255.255.255* identifies a ***host group***.

```c
sokcet()
```
- An *application* program can <u>send</u> or <u>receive</u> *multicast datagrams* by using the ==socket()== API and connectionless ==SOCK_DGRAM== type sockets.
```c
setsockopt()
```
- When a *socket of type* ==SOCK_DGRAM== is created, an application can use the ==setsockopt()== function to **control the multicast characteristics** associated with that socket.
- `setsockopt()` accepts the following ==IPPROTO_IP== level flags:
> **IP_ADD_MEMBERSHIP**
	- Joins the multicast group specified
>**IP_DROP_MEMBERSHIP**
>	Leaves the multicast group specified
> **IP_MULTICAST_IF**
> 	Sets the interface over which outgoing multicast datagrams are sent

#### Notes

- <u>Multicast ALWAYS use UDP</u>
- TTL is used to make sure a packet doesn't travel indefinitely in the network

---

# T 6 (slide T 2)

![[T02 - Application Layer.pdf]]

(slides 3-76 onward)
## Application Layer

<u>Challenge 1:</u> -> Scalability with client-server connections
<u>Challenge 2:</u> -> Heterogeneity (different users have different capabilities)

![[Pasted image 20250314142831.png]]

<u>Solution:</u> -> **distributed, application-level infrastructure**

### Multimedia: Video

***Spatial coding***

- Instead of sending N values of the same color (e.g. purple sky), send only two values: color value (purple) and number of repeated values (N)
- **Within image**

***Temporal coding***

- Instead of sending complete frame at i+1, send only differences from frame i
- **from one image to the next**

Spatial: ![[Pasted image 20250314141932.png]]  and Temporal: ![[Pasted image 20250314141955.png]]

> *Video:*
> 	sequence of images displayed at constant rate
> *Image:*
> 	array of pixels
> *Pixel:*
> 	represented by bits
> *Coding:*
> 	use redundancy **within** and **between** images to decrease #bits used to encode image

==CBR (constant bit rate)==
- video encoding rate fixed
==VBR (variable bit rate)==
- video encoding rate changes as amount of spatial and temporal coding changes

## Streaming multimedia: DASH

==**DASH**==: **D**ynamic, **A**daptative **S**treaming over **H**TTP

| *Server*                                            | *Client*                                                                                                   | *Intelligence at client*                                                                                                      |
| --------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| divides video file into multiple chunks             | periodically measures server-to-client bandwidth                                                           | determines **when** to request chunk (so that buffer starvation or overflow doesn't occur)                                    |
| each chunk stored, encoded at different rates       | consulting manifest, requests one chunk at a time                                                          | determines **what encoding rate** to request (higher quality when more bandwidth available)                                   |
| *manifest file*: provides URLs for different chunks | - chooses maximum coding rate sustainable given current bandwidth                                          | determines **where** to request chunk (can request from URL server that is "close" to client or has high available bandwidth) |
|                                                     | - can choose different coding rates at different points in time (depending on available bandwidth at time) |                                                                                                                               |
examples: MPEG-DASH in YouTube and Netflix

## CDN - Content Distribution Networks

***challenge***
- how to stream content (selected from millions of videos) to hundreds of thousands of simultaneous users around the world?
***Option 1***
-> single, larger "mega-server"
- single point of failure
- point of network congestion
- long path to distant clients (bottleneck links)
- multiple copies of video (e.g. popular videos) sent over outgoing link, which Internet video company has to pay
***Option 2***
-> store/serve multiple video copies at multiple geographically distributed sites (CDN).
1. **enter deep** - push CDN servers deep into many access networks
2. **bring home** - smaller number (10's) of larger clusters in POPs near (but not within) access networks (Tier-1 ISPs)

CDN may be:

| Private                                                                             | Third-Party                                                                                                     |
| ----------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- |
| CDN is owned by the content provider (e.g. Google's CDN distributes YouTube videos) | CDN distributes content on behalf of multiple content-providers (e.g. Limelight or Akamai for Netflix and Hulu) |
![[Pasted image 20250314145552.png]]
![[Pasted image 20250314145602.png]]
> end of protocols study
![[Pasted image 20250314150659.png]]

#### Notes

- the enter deep and bring home methods to solve scalability and heterogeneity challenges are purely procedural and depend more on corporate interests
- Routers implement IP, connection and network layers. They don't have to implement either UDP or TCP protocols

- UDP and TCP transport protocols are implemented by the sending computer:
(example with TCP encapsulation)
![[Pasted image 20250314150206.png]]
-  the association between the socket and application is the PORT (source port and destination port)
- the data sent, before the receiver does read, are stored in a *buffer* until read, by arrival order. That's order delivery
- if the IP packets arrive in a different order to the destination, so does the UDP packets. Differently from the TCP packets that have their own mechanisms

### Error checking in UDP

- IP is supposed to run over just about any layer-2 protocol 
- UDP does nothing to recover from an error, segment may be discarded or passed to the application with a warning