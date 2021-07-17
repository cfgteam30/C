#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
 
    if ((pid=fork())==0) {
 
	printf("hello im child\n");
    }
    else {
 
	printf("hello im parent with child of pid %d\n",pid);
 
    }
 
    return 0;
}
