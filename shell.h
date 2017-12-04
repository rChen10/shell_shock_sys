#define READ 0
#define WRITE 1

/*====== char **parse_args() ============
  Inputs: char *line
  Returns: Array of strings where every token is separated by a single whitespace

  Does not check for bad arguments.
  Depends on user to trim beforehand.
  ===========*/
char **parse_args(char * line);

/*====== int parent(int *fd) ============
  Inputs: 
    int *fd: The pipe 
  Returns: 0
  
  Closes pipe read, and waits for child.
  ===========*/
int parent(int *fd);

/*====== int child(int *fd, char **args) ============
  Inputs:
    int *fd: The pipe
    char **args: Command line as an array of strings where every token is separated by a single whitespace
  Returns: 0
  
  Closes pipe write, and executes the command line.
  ===========*/
int child(int *fd, char **args);

/*====== void reader(char **buffy) ============
  Inputs:
    char **buffy: A pointer to an empty array of char *
  Returns: nothing

  Reads from stdin into buffy.
  ===========*/
void reader(char **buffy);

/*====== char **parse_commands(char *line, char *delim) ============
  Inputs:
    char *line: Array of strings where every token is separated by a single whitespace
    char *delim: The delimiter to parse line
  Returns: An array of command lines

  Reads from stdin into buffy.
  ===========*/
char **parse_commands(char *line, char *delim);

/*====== int redirect_in(char *args) ============
  Inputs:
    char *args:
  Returns: 


  ===========*/
int redirect_in(char *args);

/*====== int redirect_out(char *args) ============
  Inputs:
    char *args:
  Returns: 


  ===========*/
int redirect_out(char *args);

/*====== int rm_space(char *line) ============
  Inputs:
    char *line:
  Returns: 

  Removes extraneous spaces from line
  ===========*/
char * rm_space(char * line);

/*====== void cd() ============
  Inputs:
    char **line: Array of strings where every token is separated by a single whitespace
  Returns: nothing

  Our implementation of cd
  ===========*/
void cd(char **line);

/*====== void my_exit() ============
  Inputs:
    char **line: Array of strings where every token is separated by a single whitespace
  Returns: nothing

  Our implementation of exit
  ===========*/
void my_exit(char ** line);
/*======  ============

  ===========*/
