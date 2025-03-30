## What?

- A DNS (Domain Name System) server is a computer that helps convert human-readable domain names (like www.example.com) into IP addresses (like 192.0.2.1) that computers can use to identify each other on the internet. To understand how a DNS server works, imagine it as a large phonebook for the internet. When a website address (URL) is typed into the browser, the DNS server looks up the domain name and returns the corresponding IP address. It allows device to connect to the correct server hosting the website.
- the cloudflare (more privacy alternative) dns is 1.1.1.1
- the google (less secure) is 8.8.8.8

## How?

- ![[Pasted image 20250311145358.png]]

1. You enter a website address in your browser (for example, www.example.com).
2. The browser sends a request to a DNS server to get the IP address of the website.
3. The DNS server checks its records to find the IP address that matches the domain name.
4. The server sends the IP address back to your device.
5. Your device connects to the website’s server using the IP address and loads the page.
6. This process happens so quickly that you don’t even notice it, but without DNS servers, browsing the web would be much more complicated, as you’d have to remember the IP address of every website.

---
# Notes

![[Exploring DNS Essentials (March 11, 2025).pdf]]

- Client -> Server
- Registers of DNS are following "zones", and read from right to left 
	- (e.g. www.example.com.) 
	- is read zone .com, then example.com inside .com, then www.example.com inside example.com
- Recursive resolver
- over 80% query's are UDP non-ciphered in DNS
- when a response is too big and doesn't fit the UDP packet, the query tries again using *unenctypted TCP* 
- ciphered: DNS-over-TLS
- for traffic between recursive resolvers and authoritative nameservers, the *only* option is to use *unencrypted TCP* or *UDP*
- problems: cypher security

==Recursive Lookup Process==

- resolvers have a pre-selected IP lists (nameserver and IP);
- any-cast: request gets to the closest datacenter - most efficient route

---

```bash
dig *nord A www.cloudflare.com @162.159.0.33                                                                                    ─╯

; <<>> DiG 9.18.30-0ubuntu0.24.04.2-Ubuntu <<>> i3wm-nord A www.cloudflare.com @162.159.0.33
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: SERVFAIL, id: 59901
;; flags: qr aa rd ra; QUERY: 1, ANSWER: 0, AUTHORITY: 0, ADDITIONAL: 1

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 65494
;; QUESTION SECTION:
;i3wm-nord.			IN	A

;; Query time: 0 msec
;; SERVER: 127.0.0.53#53(127.0.0.53) (UDP)
;; WHEN: Tue Mar 11 14:48:04 WET 2025
;; MSG SIZE  rcvd: 38

;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 7825
;; flags: qr aa rd; QUERY: 1, ANSWER: 2, AUTHORITY: 0, ADDITIONAL: 1
;; WARNING: recursion requested but not available

;; OPT PSEUDOSECTION:
; EDNS: version: 0, flags:; udp: 1232
;; QUESTION SECTION:
;www.cloudflare.com.		IN	A

;; ANSWER SECTION:
www.cloudflare.com.	300	IN	A	104.16.123.96
www.cloudflare.com.	300	IN	A	104.16.124.96

;; Query time: 14 msec
;; SERVER: 162.159.0.33#53(162.159.0.33) (UDP)
;; WHEN: Tue Mar 11 14:48:04 WET 2025
;; MSG SIZE  rcvd: 79
```

learn more:
https://www.cloudflare.com/learning/dns/what-is-dns/
radar.cloudflare.com/dns

[^1]

[^1]: DNS is programmed in Rust (?)
