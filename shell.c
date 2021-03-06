#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"
#include "redirect.c"

char **parse_args(char *line){
  //line = rm_space(line);
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

int redirect_in(char *args){
  args[-1] = 0;
  char ** p = parse_args(args);
  return redirector_in(p[1]);
}

int redirect_out(char *args){
  args[-1] = 0;
  char ** p = parse_args(args);
  return redirector_out(p[1]);
}

char * rm_delim(char * line, char delim){
  char * next = strchr(line, delim);
  if(next == 0)
    return line;
  else if(next[1] == 0){
    next[0] = 0;
    return line;
  }
  else if(line[0] == delim){
    if(line[1] == delim){
      strcpy(line, line + 1);
      return rm_delim(line, delim);
    }
    else{
      rm_delim(line + 1, delim);
      return line + 1 ;
    }
  }
  else if(next[1] == delim){
    next[0] = 0;
    strcat(line, next + 1);
    rm_delim(next, delim);
    return line;
  }
  else{
    rm_delim(next + 1, delim);
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
  int status;
  wait(&status);
  return 0;
}

int child(int *fd, char **args){
  close(fd[WRITE]);
  execvp(args[0], args);

  return 0;
}
int reader(char **buffy){
  **buffy = 0;
  fgets(*buffy, 256, stdin);
  if(strchr(*buffy, '\n')){
    (*strchr(*buffy, '\n')) = 0;
  }
  return 1;
  /* int nl = strlen(*buffy) - 1; */
  /* if ( (*buffy)[nl] == '\n' ){ */
  /*   (*buffy)[nl] = 0; */
  //}
}

/* int main(){ */
/*   int i = 0; */
/*   char a[] = "ls -l -a"; */
/*   char **b = parse_args(a); */
/*   for (i = 0; i < 3; i++){ */
/*     printf("%s\n", b[i]); */
/*   } */
/* } */
