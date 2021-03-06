#include "shell.c"
#include <sys/types.h>
#include <sys/stat.h>
#include "pipe.c"

int run(){
  int sin = 0;
  int sout = 1;
  char *buffy = (char *) calloc(256 ,sizeof(char));
  
  while(reader(&buffy)){
    //dup2(redirector_in("./input"), 0);
    //dup2(sin, 0);
    //dup2(sout, 1);
    //printf("%d\n", sin);
    buffy = rm_delim(buffy, ' ');
    //printf("parsed args: %s\n", buffy);
    char **cmds = parse_commands(buffy, ";");

    int i = 0;
    while(cmds[i]){
      //printf("%s\n", cmds[i]);
      if(strchr(cmds[i], '<')){
	      sin = redirect_in(strchr(cmds[i], '<'));
      }
      if(strchr(cmds[i], '>')){
	      sout = redirect_out(strchr(cmds[i], '>'));
      }
      
     

   

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
        
        //printf("%s\n", cmds[i]);
        if (strstr(cmds[i], "|")) {
          //printf("Piping\n" );
          char **args = parse_commands(cmds[i], "|");
          my_pipe(args);
        }
        
        else{
          char **args = parse_args(cmds[i]);
          child(fd, args);
          cd(args);
          my_exit(args);
        }
      }

      char *print = calloc(256, sizeof(char));
      fread(print, 256, 1, stdout);
      printf("%s\n", print);
      i++;
    }
  }
}

int main(){
  run();
  
}
