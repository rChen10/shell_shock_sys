#include "shell.c"
#include <sys/types.h>
#include <sys/stat.h>

int run(){
  while(1){
    char *buffy = (char *) calloc(256 ,sizeof(char));
    reader(&buffy);
    char **args = parse_args(buffy);
    
    my_exit(args);

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
      cd(args);

      child(fd, args);
    }

    char *print = calloc(256, sizeof(char));
    fread(print, 256, 1, stdout);
    printf("%s\n", print);
  }
}

FILE **initer(){
  mkfifo("./ssin", 466);
  mkfifo("./ssout", 466);
  FILE **f = malloc( 2 * sizeof(FILE *) );
  f[0] = fopen("./ssin", "w+");
  f[1] = fopen("./ssout", "w+");
  return f;
}

int main(){
  FILE **in_out = initer();
  run();
  
}
