# Gobuster

### gobuster [mode] -u [target ip] -w [path to the wordlist]
#### DIR mode
`gobuster dir -u <IP> -w <path to wordlist>`

#### DNS mode
`gobuster dns -d <IP> -w <path to wordlist> -i`
-i - to show ip addresses
**NOTE-DNS mode is used for subdomain enumeration**

#### VHOST mode
`gobuster vhost -u <IP> -w <path to wordlist>`



```
GLOBAL FLAGS

-h : (--help) Print the global help menu.

-z : (--noprogress) Don't display progress.

-o : (--output [filename]) Output results to a file.

-q : (--quiet) Don't print banner and other noise.

-t : (--threads [number]) Number of concurrent threads (default 10).

-v : (--verbose) Verbose output (errors).

-w : (--wordlist [wordlist]) Path to wordlist.

DIR mode flags

-h : (--help) Print the DIR mode help menu.

-f : (--addslash) Append "/" to each request.

-c : (--cookies [string]) Cookies to use for the requests.

-e : (--expanded) Expanded mode, print full URLs.

-x : (--extensions [string]) File extension(s) to search for.

-r : (--followredirect) Follow redirects.

-H : (--headers [stringArray]) Specify HTTP headers, -H 'Header1: val1' -H 'Header2: val2'.

-l : (--includelength) Include the length of the body in the output.

-k : (--insecuressl) Skip SSL certificate verification.

-n : (--nostatus) Don't print status codes.

-U : (--username [string]) Username for Basic Auth.

-P : (--password [string]) Password for Basic Auth.

-p : (--proxy [string]) Proxy to use for requests [http(s)://host:port].

-s : (--statuscodes [string])Positive status codes (will be overwritten with statuscodesblacklist if set) (default "200,204,301,302,307,401,403").

-b : (--statuscodesblacklist [string]) Negative status codes (will override statuscodes if set).

-u : (--url [string]) The target URL.

-a : (--useragent [string]) Set the User-Agent string (default "gobuster/3.0.1").

--timeout [duration] : HTTP Timeout (default 10s).

--wildcard : Force continued operation when wildcard found.

DNS mode flags

-h : (--help) Print the DNS mode help menu.

-d : (--domain [string]) The target domain.

-r : (--resolver [string]) Use custom DNS server (format server.com or server.com:port).

-c : (--showcname) Show CNAME records (cannot be used with '-i' option).

-i : (--showips) Show IP addresses.

--timeout [duration] : DNS resolver timeout (default 1s).

--wildcard : Force continued operation when wildcard found.

VHOST mode flags

-h : (--help) Print the VHOST mode help menu.

-r : (--followredirect) Follow redirects.

-H : (--headers [stringArray]) Specify HTTP headers, -H 'Header1: val1' -H 'Header2: val2'.

-c : (--cookies [string]) Cookies to use for the requests.

-k : (--insecuressl) Skip SSL certificate verification.

-U : (--username [string]) Username for Basic Auth.

-P : (--password [string]) Password for Basic Auth.

-u : (--url [string]) The target URL.

-p : (--proxy [string]) Proxy to use for requests [http(s)://host:port].

-a : (--useragent [string]) Set the User-Agent string (default "gobuster/3.0.1").

--timeout [duration] : HTTP Timeout (default 10s).
```