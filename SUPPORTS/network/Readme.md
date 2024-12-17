https://learn.microsoft.com/fr-fr/troubleshoot/windows-client/networking/tcpip-addressing-and-subnetting

- **IP address :**<br>

    * An IP adress is a 32bytes number.<br>

    * It is use to identify a host (computer or other device, such as a printer or router) on a TCP/IP network.<br>

    * The 32-bit number 11000000101010000111101110000100 could be difficult to interpret. So it is divided into four parts of eight binary digits.<br>

    * The example IP address then becomes 11000000.10101000.01111011.10000100.<br>

    * For most purposes, the binary address is converted to dotted decimal (192.168.123.132).<br>

- **WAN:**<br>

    A Wide Area Network (WAN) is a collection of local-area networks (LANs).<br>
    A WAN is essentially a network of networks, with the Internet the world's largest WAN.

![image](https://github.com/user-attachments/assets/0646f614-4275-41c4-8aa8-d83f3eac0c5f)
    Features of WANs :<br>
      * They could be based on the TCP/IP protocol.<br>
      * They use routers to pass data packets between networks.<br>
      * A router does not know the exact location of a host.<br>
      * It only knows the location of the network to which the host belongs, thanks to the information stored in the route table.<br>

This is why an IP address has two parts:
  - the first part of an IP address is used as the network address,
  - the last part is used as the host address.<br>
 
In addition to the IP adress, the TCP/IP protocol need to know the subnet mask to deliver the data packets.

- **subnet mask:**
    * The subnet mask is used by TCP/IP to determine whether a host is on the local subnet or on a remote network.<br>
    * The subnet mask is a 32-bit number, just like an IP address.<br>
    * It looks similar to an IP address, such as 255.255.255.0, but it takes 255 value, which is not allowed in an IP adress.<br>
    * The 255s represent the network part of the address, and the 0 represents the host part.<br>

For example, we could take the IP address 192.168.123.132 and the subnet address 255.255.255.0.<br>
The subnet address indicate that :
  * the first three numbers represent the network part : 192.168.123. (network address = 192.168.123.0) because we have three 255 values,
  * the last number represent the host : .132 (host address = 0.0.0.132) because we have a 0 value on the last position.

This means all devices with IPs like 192.168.123.x are on the same network.

Another way to understand the distribution of the differents parts would be to compare numbers in binary bits format. 




ressources :
- [WAN](https://www.cisco.com/c/en/us/products/switches/what-is-a-wan-wide-area-network.html#:~:text=In%20its%20simplest%20form%2C%20a,Internet%20the%20world's%20largest%20WAN)
