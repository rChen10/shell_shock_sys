#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

char **parse_args(char *line){
  char **args = calloc(15, sizeof(char *));
  char **pos = args;
  while(line){
    *pos = strsep(&line, " ");
    pos++;
  }
  return args;
}

int parent(int *fd){
  close(fd[READ]);
  int *status;
  wait(status);

  char *output = calloc( 256, sizeof(char) );
  fgets(output, 255, stdout);
  printf("%s\n", output);
  free(output);
  return 0;
}

int child(int *fd, char **args){
  close(fd[WRITE]);
  execvp(args[0], args);
  return 0;
}
void reader(char **buffy){
  fgets(*buffy, 256, stdin);
  int nl = strlen(*buffy) - 1;
  if ( (*buffy)[nl] == '\n' ){
    (*buffy)[nl] = 0;
  }
}

/* int main(){ */
/*   int i = 0; */
/*   char a[] = "ls -l -a"; */
/*   char **b = parse_args(a); */
/*   for (i = 0; i < 3; i++){ */
/*     printf("%s\n", b[i]); */
/*   } */
/* } */
