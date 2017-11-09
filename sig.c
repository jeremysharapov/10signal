#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if (signo == SIGUSR1){
    printf("Oh you good. It just a SIGNUSR1. Continue! Oh btw the PPID is %d\n", getppid());
  }
  if (signo == SIGINT){
    int fd = open("log", O_CREAT | O_WRONLY | O_APPEND, 0644);
    char err[] = "SIGINT, how terrible! I'm killing this program right now!\n";
    write(fd, err, sizeof(err));
    printf("%s\n", err);
    close(fd);
    exit(1);
  } 
}

void main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("The PID is %d\n", getpid());
    sleep(1);
  }
}
