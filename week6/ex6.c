#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"
#include "sys/wait.h"


int main(int argc, char const *argv[])
{
	int pips[2];
	int status;
	int pid1,pid2;
	int pid_child;


	if (fork() == 0) //child1 proccess
	{
		pid1 = getpid();
		read(pips[0],&pid_child,sizeof(pid_child));

		printf("child will be terminated\n");
		sleep(1);

		printf("pid_child - %d\n", pid_child);
		kill(pid_child,SIGKILL);
		/* I use SIGKILL because SIGSTOP doesn't kill proccess
		   and parent proccess will not terminate. But with SIGKILL, it kills and
		   parent proccess terminates.
		*/
		exit(0);
	}else{
		pid2 = fork();
		if (pid2 == 0) //child2 proccess
		{
			for(;;){
				printf("progress\n");
				sleep(1);
			}
		}else{
			//the parent proccess
			write(pips[1],&pid2,sizeof(pid2));
			pid_t t = waitpid(pid2, &status, 0);
			printf("child exited with status - %d\n", status);
			exit(1);
		}
	}
	return 0;
}