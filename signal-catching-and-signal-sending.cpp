//signal sending and signal catching 

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_handler(int s){
    printf(" Signal catching %d\n",s);
}
int main(int argc, char** argv){
    pid_t pid;
    pid = getpid();
    struct sigaction sig;
    sig.sa_handler = my_handler;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    sigaction(SIGINT,&sig,NULL);
    for(int i= 0;i<10;i++){
        printf("in main\n");
        sleep(1);
        kill(pid,SIGINT); // kill(pid,2);
    }
    puts("Terminated");
    return 0;
}