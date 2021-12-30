#include<unistd.h>
void main(){
    setuid(0);
    setgid(0);
    system("Thm");//the system binary to be called 
}