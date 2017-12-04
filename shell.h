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

/*====== int child() ============
  Inputs:
    int *fd: The pipe
    char **args: Command line as an array of strings where every token is separated by a single whitespace
  Returns: 0
  
  Closes pipe write, and executes the command line.
  ===========*/
int child(int *fd, char **args);

/*====== void reader() ============
  Inputs:
    char **buffy: A pointer to an empty array of char *
  Returns: 1 on success

  Reads from stdin into buffy.
  ===========*/
int reader(char **buffy);

/*====== char **parse_commands() ============
  Inputs:
    char *line: Array of strings where every token is separated by a single whitespace
    char *delim: The delimiter to parse line
  Returns: An array of command lines

  Reads from stdin into buffy.
  ===========*/
char **parse_commands(char *line, char *delim);

/*====== int redirect_in() ============
  Inputs:
    char *args: everything following the and including the <
  Returns: The file descriptor for stdin

  Places a null before <.
  Relies on helper function redirector_in to open the file path given by the second argument.
  The file descriptor for stdin is copied first.
  ===========*/
int redirect_in(char *args);

/*====== int redirect_out() ============
  Inputs:
    char *args: everything following the and including the <
  Returns: The file descriptor for stdout

  Places a null before <.
  Relies on helper function redirector_out to open the file path given by the second argument.
  The file descriptor for stdout is copied first.

  ===========*/
int redirect_out(char *args);

/*====== char * rm_space() ============
  Inputs:
    char *line: the buffer
    char delim: the char to be removed
  Returns: A pointer to the start of the trimmed string.

  Removes extraneous delims from line.
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
