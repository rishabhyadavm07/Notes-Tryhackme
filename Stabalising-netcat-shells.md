# Stabalising netcat shells

<br>

> Rishabh Yadav | 28th Jan 2022

## Spawn TTY with python

This shell is supports commands such as su and ssh
```
python -c ‘import pty;pty.spawn(“/bin/bash”)’

-----------------------------------------------
echo os.system('/bin/bash')

/bin/sh -i
  
perl —e 'exec "/bin/sh";'
  
perl: exec "/bin/sh";
  
ruby: exec "/bin/sh"
   
lua: os.execute('/bin/sh')
   
(From within IRB)
exec "/bin/sh"
  
(From within vi)
:!bash
  
(From within vi)
:set shell=/bin/bash:shell
  
(From within nmap)
!sh
```

## Tab Completion with STTY

```
First, background your netcat shell by typing:
Ctrl+z
  
This will appear as though you’ve lost your shell. Don’t worry! We’ll get it back. Next, in your local shell type:
stty raw -echo
  
Finally, foreground the netcat shell by typing:
fg + [Enter x 2]
  
This should return your shell with tab auto-completion!
```

## Keep It Clean; Clear The Screen

```
In a shell on your local machine, type:
`echo $TERM`
  
In the netcat shell type:
`export TERM=screen`

Now you can clear your screen!
```

## History Lesson

```
This will be giving shell the functionality of getting the previous executed command back by typing a up arrow.  
export SHELL=bash

```

## Big Screen

Usefull when we type a long oneliner and the words at the first get skipped due to no word wrap

```
To see the size of your local machine type:
stty size

To make the netcat terminal larger -
stty rows 100 cols 100
```