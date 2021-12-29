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