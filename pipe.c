#include <stdio.h>
#include <stdlib.h>


void my_pipe(char **cmds){
  FILE *left = popen(cmds[0], "r");
  FILE *right = popen(cmds[1], "w");
  char st[600];
  char out[256];
  while(fgets(out, 256, left)){
    strcat(st, out);
  }
  //printf("%s\n", st);
  fprintf(right, "%s", st);
  fclose(left);
  fclose(right);
  return 0;
}