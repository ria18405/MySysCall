#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
int pid=3;
if(pid<0){
printf("pid negative");
}
else{
         long int a = syscall(318,3,"abc.txt");
         printf(“System call returned %ld\n”, a);
}
         return 0;
}