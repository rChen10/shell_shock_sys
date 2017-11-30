#include "shell.c"
int run(){
  char *buffy = (char *) calloc(256 ,sizeof(char));
  reader(&buffy);
  char **args = parse_args(buffy);
  
  int fd[2];
  if(pipe( fd )){
    printf("%s\n", strerror(errno));
    exit(0);
  }
  
  int f = fork();
  if (f){ //parent
    parent(fd);
  }
  else{ //child
    child(fd, args);
  }

  char *print = calloc(256, sizeof(char));
  fread(print, 256, 1, stdout);
  printf("%s\n", print);
}

int *initialize(){
  mkfifo("./ssin", 466);
  mkfifo("./ssout", 466);
  int fd[2];
  fd[0] = fopen("./ssin", "w+");
  fd[1] = fopen("./ssout", "w+");
  return fd;
}

int main(){
  int in_out[2] = initialize();
  run();
  
}
