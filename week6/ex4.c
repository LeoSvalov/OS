#include "stdio.h"
#include "signal.h"
#include "unistd.h"
#include "stdlib.h"


void sig_kill(int sig){
	printf("sigkill\n");
}

void sig_stop(int sig){
	printf("sigstop\n");
}

void sig_usr(int sig){
	printf("sigusr\n");
}
int main() {

   	signal(SIGKILL, sig_kill);
	signal(SIGSTOP, sig_stop);
	signal(SIGUSR1, sig_usr);

    for(;;) {
    	sleep(1);
    }
    // the kill of the signal is sending, then it handles by the program and provides the output.
    return 0;
}

