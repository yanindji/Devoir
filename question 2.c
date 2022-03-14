#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
/*#include <sys/wait.h>*/
#include <unistd.h>
int main(int argc, char *argv [])
{
    int pid;
    pid = fork();
    if(pid < 0)

   {
    printf("Erreur de fork\n");
    /*execlp("ls", "ls", "-l", NULL);*/
     return 1;
    }
if(pid == 0)
    {
     printf("je suis le fils (%d), mon père\n", getpid());

     }
else
    {
    printf("je suis le père (%d), mon fils\n", getpid());

    }
return 0;
}
