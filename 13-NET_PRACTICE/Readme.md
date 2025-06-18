https://learn.microsoft.com/fr-fr/troubleshoot/windows-client/networking/tcpip-addressing-and-subnetting

- **IP ADDRESS :**

    * An IP address is a 32 bytes number.<br>

    * It is use to identify a host (computer or other device, such as a printer or router) on a TCP/IP network.<br>

    * The 32-bit number 11000000101010000111101110000100 could be difficult to interpret. So it is divided into four parts of eight binary digits.<br>

    * The example IP address then becomes 11000000.10101000.01111011.10000100.<br>

    * For most purposes, the binary address is converted to dotted decimal (192.168.123.132).<br>

- **WAN:**<br>

    A Wide Area Network (WAN) is a collection of local-area networks (LANs).<br>
    A WAN is essentially a network of networks, with the Internet the world's largest WAN.
  
  ![image](https://github.com/user-attachments/assets/0646f614-4275-41c4-8aa8-d83f3eac0c5f)

   Features of WANs :<br>
   <ul>
      <li> They could be based on the TCP/IP protocol.</li><br>
      <li> They use routers to pass data packets between networks.</li><br>
      <li> A router does not know the exact location of a host.</li><br>
      <li> The router only knows the location of the network to which the host belongs, thanks to the information stored in the route table.</li><br>
   </ul>

- **IP ADDRESS in WAN:**

   This is why an IP address has two parts:
     <ul>
         <li> The first part of an IP address is used as the network address.</li><br>
         <li> The last part is used as the host address.</li><br>
     </ul>

   In TCP/IP, the parts of the IP address used as the network and host addresses are not fixed.<br>
 
   That's why, in addition to the IP address, the TCP/IP protocol needs to know the subnet mask to deliver the data packets.<br><br>


- **SUBNET MASK:**
  <ul>
     <li> The subnet mask is used by TCP/IP to determine whether a host is on the local subnet or on a remote network.</li><br>
     <li> The subnet mask is a 32-bit number, just like an IP address.</li><br>
     <li> It looks similar to an IP address, such as 255.255.254.0, but it takes 255 and/or 0 values, which is not allowed in an IP address.</li><br>
     <li> The non zero numbers (255 and 254 in the previous example) represent the network part of the address, and the 0 represents the host part.</li><br>
  </ul>

   For example, we could take the IP address 192.168.123.132 and the subnet address 255.255.254.0.<br>
   The subnet address indicate that :
   <ul>
      <li> the first three numbers represent the network part : 192.168.123. (network address = 192.168.123.0) because we have three non zero values (255 and 254) at the first three positions in subnet address,</li><br>
      <li>the last number represent the host : .132 (host address = 0.0.0.132) because we have a 0 value on the last position in subnet address.</li><br>
   </ul>

   This means all devices with IPs like 192.168.123.x are on the same network.<br><br>

   Another way to understand the distribution of the differents parts would be to compare numbers in binary bits format.<br><br>


- **NETWORK CLASS:**<br>
   IP addresses are allocated by the internic, the organization that administers the Internet.<br>
   These IP addresses are divided into classes. Classes A, B, and C are the most common.<br>
   Classes D and E exist, but are not used by end users.<br>
   Each of the address classes has a different default subnet mask.<br>

   Internet RFC 1878 describes valid subnets and subnet masks that can be used on TCP/IP networks.<br>
                              Table<br><br>

   You can identify the class of an IP address by looking at its first octet.<br>
   Here are the class A, B, and C IP address ranges, each with an example address:<br>

   - Class A networks use a default subnet mask of 255.0.0.0 and the first octet of their IP address is between 0 and 127.<br>
     e.g. : the address 10.52.36.11 is a Class A address because its first octet is 10 (between 0 and 127, inclusive).

   - Class B networks use a default subnet mask of 255.255.0.0 and the first octet of their IP address is between 128 and 191.<br>
     e.g. : the address 172.16.52.63 is a Class B address because its first octet is 172 (between 128 and 191, inclusive).

   - Class C networks use a default subnet mask of 255.255.255.0 and the first octet of their IP address is between 192 and 223.<br>
     e.g. : the address 192.168.123.132 is a Class C address because its first octet is 192 (between 192 and 223, inclusive).

- **SUBNETTING:**<br>
   A Class A, B, or C TCP/IP network can be further divided, or subnetted, by a system administrator.<br>
   It could be used, for example, if computer are on several separate physical networks.<br>
   Instead of requesting more blocks of addresses for each network, you divide your network into subnets, which allows you to use one block of addresses across multiple physical networks.<br>
   In this case, you divide your network into four subnets using a subnet mask that expands the network address and narrows the possible range of host addresses. In other words, you "borrow" some of the bits used for the host address and use them for the network portion of the address.<br>
  The subnet mask 255.255.255.192 gives you four networks of 62 hosts each.<br>
  This works because in binary notation, 255.255.255.192 equals 11111111.11111111.1111111.11000000. The first two digits of the last octet become network addresses.<br>
  So you get the additional networks 00000000 (0), 01000000 (64), 10000000 (128), and 11000000 (192). (Some administrators use only two of the subnets using 255.255.255.192 as the subnet mask. For more information on this topic, see RFC 1878.)<br>
  In all four of these networks, the last six binary digits can be used for host addresses.

Using a subnet mask of 255.255.255.192, your 192.168.123.0 network would then become the four networks 192.168.123.0, 192.168.123.64, 192.168.123.128, and 192.168.123.192. These four networks would have valid host addresses:

192.168.123.1-62, 192.168.123.65-126, 192.168.123.129-190 and 192.168.123.193-254

Remember, again, that binary host addresses that are all ones or all zeros are invalid. So you cannot use addresses whose last octet is 0, 63, 64, 127, 128, 191, 192, or 255.

You can see how this works by looking at two host addresses, 192.168.123.71 and 192.168.123.133.<br>
If you used the default Class C subnet mask of 255.255.255.0, both addresses are on the 192.168.123.0 network.<br>
However, if you use the subnet mask of 255.255.255.192, they are on different networks:<br>
   - 192.168.123.71 is on the 192.168.123.64 network,<br>
   - 192.168.123.133 is on the 192.168.123.128 network.<br><br>




ressources :
- [WAN](https://www.cisco.com/c/en/us/products/switches/what-is-a-wan-wide-area-network.html#:~:text=In%20its%20simplest%20form%2C%20a,Internet%20the%20world's%20largest%20WAN)
