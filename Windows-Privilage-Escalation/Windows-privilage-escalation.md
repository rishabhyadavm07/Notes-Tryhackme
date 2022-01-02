<h1 align="center">Windows-Privilage-Escalation</h1>

## 1.Enumeration

`whoami /priv`-Current user privilages  

`net user (username)`-List details of the user  

`qwinsta`-Show other users logged in simultaneously  

`net localgroup`-Usergroups defined on the system  

`net localgroup (localgroup)`-List members of specific group  
#### System information
`systeminfo`-Overview of the target system  
Show Filtered output of above command-  
```bash
`systeminfo | findstr /B /C:"OS Name" /C:"OS Version"
```
`hostname`-r

#### Finding files

```bash
findstr /si password *.txt
```
`findstr`-searchs for patterns in files
  
`/si`-current directory and sub directory

`password`-searchs for string passowrd in files  
`*.txt`-cover files with txt extension  

#### Patch level
To list updates installed-
```bash
wmic qfe get Caption,Description,HotFixID,InstalledOn
``` 
#### Network connection
Shows all the listning ports of the system-
```bash
netstat -ano
```
`a`-all active connections
`n`-prevents name resolution
`o`-process ID

#### Scheduled tasks
To query scheduled tasks-
```bash
schtasks /query /fo LIST
```
#### Drivers
`driver query`-lists drivers installed on the system  

#### Antivirus
`sc query (process name)`-find processes with name  
`windefend`-service name for windows defender  
`sc queryex type=service`-query for services  

## Tools of trade
#### [WinPEAS](https://github.com/carlospolop/PEASS-ng/tree/master/winPEAS)

#### [PowerUp](https://github.com/PowerShellMafia/PowerSploit/tree/master/Privesc)
  
`Invoke-AllChecks`-perform all possible checks  

`Get-UnquotedService`-only look for potential inquoted service path vulnerablities
  
`Import-Module .\PowerUp.ps1`-run script 

#### Windows exploit suggester
Use-
```bash
windows-exploit-suggester.py --database (database) ---systeminfo (file)
```
`file`-file with output of systeminfo command

#### Metasploit
```bash
multi/recon/local_exploit_suggester
```

## Vulnerable software

