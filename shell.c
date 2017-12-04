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

char **parse_commands(char *line, char *delim){
  char ** cmds = (char **)calloc(6, sizeof(line));
  int i = 0;
  while(line){
    cmds[i] = strsep(&line, delim);
    i++;
  }
  return cmds;
}

char * rm_space(char * line){
  char * next = strchr(line, ' ');
  if(line[0] == ' '){
    if(line[1] == ' '){
      strcpy(line, line + 1);
      return rm_space(line);
    }
    else{
      rm_space(line + 1);
      return line + 1 ;
    }
  }
  else if(next == 0)
    return line;
  else if(next[1] == 0){
    next[0] = 0;
    return line;
  }
  else if(next[1] == ' '){
    next[0] = 0;
    strcat(line, next + 1);
    rm_space(next);
    return line;
  }
  else{
    rm_space(next + 1);
    return line;
  }
}

/*
  @line: the command line
  First tests if the line's first element is cd, 
  then changes the directory to the argument
*/
void cd(char **line){
  if( strcmp(line[0], "cd") == 0 && line[1]){
    chdir(line[1]);   
  }
}

void my_exit(char ** line){
  if(strcmp(line[0], "exit") == 0){
    exit(0);
  }
}

int parent(int *fd){
  close(fd[READ]);
  int *status;
  wait(status);
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
