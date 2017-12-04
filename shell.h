#define READ 0
#define WRITE 1

/*====== char **parse_args() ============
  Inputs: char *line
  Returns: Array of strings where every token is seperated by a single whitespace

  Does not check for bad arguments.
  Depends on user to trim beforehand.
  ===========*/
char **parse_args(char * line);

/*====== int parent(int *fd) ============

  ===========*/
int parent(int *fd);

/*====== int child(int *fd, char **args) ============

  ===========*/
int child(int *fd, char **args);

/*====== void reader(char **buffy) ============

  ===========*/
void reader(char **buffy);

char **parse_commands(char *line);

char * rm_space(char * line);

/*====== void cd() ============

  ===========*/
void cd(char **line);
/*====== void my_exit() ============

  ===========*/
void my_exit(char ** line);
/*======  ============

  ===========*/
