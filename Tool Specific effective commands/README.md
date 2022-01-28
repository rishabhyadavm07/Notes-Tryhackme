# Tools effective commands

**This will be the file where i will be storing all my daily use commands sorted out with respect to genre of the tool.**
  
*All the tools sections will be containing the meaning/role of a perticular flag within the code block itself.*  
*Also, some tools can contain more than one command and I hope it is acceptable.*
  
### NMAP :)

 Nmap are pretty important, actully not important its compulsary.
```
-->sudo nmap -sT -A -vvvv -p- -T4 --stats-every 20 10.10.93.9

-st = to perform a connect scan
-A = to perform all the basic script scans and the service scan together without giving a seprate flag for it
-vvvv = sets the verbosity level to 4 which verboses all the steps performed by the tool
-p- = perform the scan on all the ports not just default ports(ie. 0-1000)
-T4 = sets the threads to 4 (Max is 5 and default is 3) for speedy scan
--stats-every [ ] = how the stats every 20 seconds (ie. percent completed) 
[IP] = the IP of the target you want to run the scan on
```
<br>

### Hydra

i use hydra to bruteforce any service that i find intresting and hydra is able to bruteforce, most commonly SSH with rockyou wordlist because this wordlist really rocks ;)
```
-->sudo hydra -L /home/rishabhslinuxmachine/userlist.lst -P /usr/share/wordlists/rockyou.txt ssh://10.10.234.71 -vv -t 16

-L/-l = to define the list of usernames to try or only a single username to try passwords on
-P/-p = to define the list  of passwords to try of a single password if you are confident enough, i mostly use rockyou list of passwords
[ssh://<IP>] = service to run bruteforce on with the ip in the IP field
-vv = to set the verbosity level to 2 so that we can see what the tool is doing
-t [] = to set the threads to the desired number to make it a bit faster (default is 4 threads)
```

<br>

### Python server

This is a simple alternative to apache localserver and provides ease of use
```
-->sudo python -m SimpleHTTPServer 80

[80] = set the port to your desired port
```

<br>

### John

when i hear of some passoword cracking or some hash cracking or some ssh passphrase cracking the first tool to come to mymind is JTR

```
--------this is the command for ssh passphrase cracking-------------
-->/usr/share/john/ssh2john [id_rsa] > [hash]
[id_rsa] = the ssh key to crack the passphrase of
[hash] = the file to contain the cracking value that will be cracked by john
-->sudo john -w /usr/share/wordlists/rockyou.txt [hash]
[hash] = the hash file created in the previous step
-w = specifies the wordlist to use for cracking of the passphrase

```