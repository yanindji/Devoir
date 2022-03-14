#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
/*#include <sys/wait.h>*/
#include <unistd.h>
int main(int argc, char *argv [])

{
    int fid[2], ret;
    ret = pipe(fid);
    if (ret < 0)
    {
       printf(stderr,"Erreur de creation du pipe (%d)\n", errno);
       return 1;
        }
        int pid = fork();
        if (pid <0)
              {
       printf("Fork sans succes\n");
       return 2;
        }
        if (pid == 0)
            {
                char buf [ BUFSIZ + 1];
               close(fid[1]);
               while(read(fid[0], buf, BUFSIZ) != 0)
               printf("l'enfant lire %S", buf);
               close(fid[0]);

        }
        else
              {
                char buf [ BUFSIZ + 1];
               close(fid[0]);
               strcpy(buf,"un nombre secret\n");
               write(fid[1], buf, strlen(buf)+ 1);
               close(fid[1]);

        }
        int status;
        int pid2=wait(&status);

}
