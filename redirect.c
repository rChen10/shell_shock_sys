#include <fcntl.h>

int redirector_in(char *path){
  int sin = dup(0);
  int target = open(path, O_RDONLY);
  dup2(target, 0);
  return sin;
}

int redirector_out(char *path){
  int sout = dup(1);
  int target = open(path, O_WRONLY);
  dup2(target, 1);
  return sout;
}

/* int main(){ */
/*   redirector_in("./zz"); */
/*   redirector_out("./lol"); */
/*   char *args[3] = {"cat"}; */
/*   execvp("cat", args); */
/* } */
