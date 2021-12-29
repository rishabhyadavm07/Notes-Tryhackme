<h2 align="center">Linux Privilage Escalation : Capstone</h2>

1. Got the id and pass to connect to the machine via ssh with privilages of leonard

2. when thinking of privilage escalation the firlst thing that came to my mind was to check for the cammands 

3. that we can run with sudo permissions.

4. but no luck there 

5. then i checked for `/etc/exports` to see if there is any sharedfolder  [failed]

6. then i was just thinking of some more ways to escalate privs 

7. thought of checking for files with suid bit set so that we can exploit it 

```bash
find / -perm -u=s -type f 2> /dev/null
```

9. and get a intresting binary with suid bit set that was `base64`

10. went right in and specified 
```bash
LFILE=(file to read)
base64 "$LFILE"| base64 --decode
```
11.  read `/etc/passwd` and `/etc/shadow` file with this vector 

12. then coppied the hash of the other user thinking that it would have higher privilages 

13. cracked the hashes via johntheripper and boom got the password

14. changed the user to missy and tried to traverse through some files 

15. realised that it also does not have root privs to read flags file so we need to escalate the privilages more 

16. tried to look for commands that we can run with sudo 

17. this time i got one and that was find 

18. used the below vector to run find cammand with sudo privs and spawn a root shell 

```bash
sudo find . -exec /bin/sh -p \; -quit
```

**boom I AM ROOT**

Now just traversed the file system to read the flags and got all the flags.

### [DONE]