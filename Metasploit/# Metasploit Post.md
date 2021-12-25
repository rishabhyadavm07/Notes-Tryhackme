# Metasploit: Post 

1. it is a pretty easy machine all you have to care about is to get started and evetually you will be finding answers to the questions given 
2. smb username and password is given 
3. fire up metasploit and set the exploit to the one given 
4. set the rhost ,lhost and the smbuser and smbpass fields 
5. RUN	 , got a meterpreter shell 
6. get the name of the system by using cammand sysinfo 
7. to answer the next question we have to enumerate the domains 
8. googled for the modules in metasploit to enumerate domains and found one 
9. /post/windows/gather/enum_domains 
10. worked very well for me 
11. to find share we need to use the module /windows/gather/enum_shares
12. and boom all in front of you 
13. according to the next question we need to take out ntlm hashes which is pretty easy 
14. but for some wierd reason it was not working so i quichly searched for the processid for meterpreter 
15. decided to migrate to some same privilage process selected one randomly and migrated using cammand 
16. migrate <processID>
17. then tried to run hashdump and it worked 
18. and to solve the next question i quickly web to hashes.com and decoded the hash and here we take down one more 
19. now remains the 4 questions which are based on traversing the machine  using meterpreter 
20. search for the given files by using search command
21. and easily traverse to the location and concatenate the txt file to get the answer
22. [DONE]