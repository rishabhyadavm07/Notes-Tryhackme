# Vulnerablity Capstone room TryhackMe
1. started the machine and waited for 5 min as stated in the question.
2. question also stated that it is recommended to use attackbox for this room but my name is rishabh and i will never ever do something as stated.
3. machine ip - 10.10.221.244
4. thought of running a nmap scan but just randomly thought of surfing the ip in browser ie. <ip>:80. 
5. found a web page hosted and found the name and version of the webapp hosted ..[COMPLETED A TASK]
6. FOUND a fuel dashboard with username and password stated and was able to log in in the dashboard.
7. searched the title and version of the web app and found a cve and poc (github).task was to find out the cve [TASK COMPLETED]
8. found the exploit on exploit-db and downloaded it and ran it.
9. HARD LUCK !
10. downloaded more exploits that i found on github and searchsploit. STILL NO LUCK 
11.frustation ya right ! searched for the room walkthrough 
12. read the walkthrough and saw the questions again
13. finally found why the question was suggesting me to use attackbox becz it already had the exploit made and ready to use.
14. the author of the walkthrough had also uploaded the exploit file on his github 
15. then,just cloned the exploit from github and as told to start the netcat listening on port of choice 
16. ran the exploit with the ip of the webapp and provided it with the attckerip and port on which the listener is listening on 
17. GOTCHA  !
18. got the shell and easily traversed to the home/ubuntu folder and concatenated the flag.txt file 
19. COPY + PASTE = SATISFACTION !
_________________________________
• the flag was situated in the folder usr/share/exploits/vulnerabilitiescapstone on the attackbox
here is the link of the walkthrough i read and went with-
https://classroom.anir0y.in/post/tryhackme-vulnerabilitycapstone/
