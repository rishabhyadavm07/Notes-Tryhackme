<h1 align="center">Windows-Privilage-Escalation</h1>

## 1.Enumeration

`whoami /priv`-Current user privilages  

`net user (username)`-List details of the user  

`qwinsta`-Show other users logged in simultaneously  

`net localgroup`-Usergroups defined on the system  

`net localgroup (localgroup)`-List members of specific group  

`systeminfo`-Overview of the target system  
Show Filtered output of above command-  
```bash
`systeminfo | findstr /B /C:"OS Name" /C:"OS Version"
```
`hostname`-r
