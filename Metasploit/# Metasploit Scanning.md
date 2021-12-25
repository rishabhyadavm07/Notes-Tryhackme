# Metasploit: Scanning
1. metasploit exploitation scanning room machine [Solved ]
2. got the ip of the machine and first thought was to hit a nmap scan 
3. ip_machine-10.10.59.80                                 
4. found 4 ports open and saw that netbios and smb are open 
5. as they thought how to scan udp services in this task so thought of hitting it--scanner/discovery/udp-sweep 
6. the results showed that netbios was open in udp also 
7. opened metasploit and started the auxilary modules 
8. started netbios scanner 
9. and found the answer to the 2nd question 
10. as the question 3 asks for the service running on port 8000 ,hit a nmap defining the port as 8000 and boom got the answer  ! 
11. question 4 asks for the smb password for the user penny 
12. thought of enumerating smb a bit more so searched for a nse script for smb 
13. ran smb_enum_users.nse and found 2 users penny and madmin (confirmed that there exists a user named penny )
14. fired up hydra to bruteforce the smb login but no luck or maybe i dint wrote the cammand well defined cause hydra is a hell good tool.
15. googled a smb bruteforce module in metasploit 
16. and found scanner/smb/smb_login and provided it with RHOST,SMBuser,PASS_FILE and “RUN”
17. started running and after 2min GOTCHA ! 
18. here is the password for the penny user (leo1234)
19. question 4 also completed 
