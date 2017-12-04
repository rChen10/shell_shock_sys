## Shell Shock by Ricky Chen and Michael Cheng

**Features**
  * Forks and executes commands
  * Parses multiple commands on one line
  * Changing directories 
  * Redirects >
  * Implements pipes

**Attempted**
  * Redirecting < technically works, but has a major bug
  * exit has appeared to have broken along the way

**Bugs**
  * Redirecting input does not work
  * Parsing multiple commands require no spaces between ;
  * Using < loops newlines and adds entries to the file table
  * There is no safe way to exit cat > or < because signals are not handled.

**Files & Function Headers**
```
shell.c
/*====== char **parse_args() ============
  Inputs: char *line
  Returns: Array of strings where every token is separated by a single whitespace

  Does not check for bad arguments.
  Depends on user to trim beforehand.
  ===========*/

/*====== int parent(int *fd) ============
  Inputs: 
    int *fd: The pipe 
  Returns: 0
  
  Closes pipe read, and waits for child.
  ===========*/

/*====== int child() ============
  Inputs:
    int *fd: The pipe
    char **args: Command line as an array of strings where every token is separated by a single whitespace
  Returns: 0
  
  Closes pipe write, and executes the command line.
  ===========*/

/*====== void reader() ============
  Inputs:
    char **buffy: A pointer to an empty array of char *
  Returns: 1 on success

  Reads from stdin into buffy.
  ===========*/

/*====== char **parse_commands() ============
  Inputs:
    char *line: Array of strings where every token is separated by a single whitespace
    char *delim: The delimiter to parse line
  Returns: An array of command lines

  Reads from stdin into buffy.
  ===========*/

/*====== int redirect_in() ============
  Inputs:
    char *args: everything following the and including the <
  Returns: The file descriptor for stdin

  Places a null before <.
  Relies on helper function redirector_in to open the file path given by the second argument.
  The file descriptor for stdin is copied first.
  ===========*/

/*====== int redirect_out() ============
  Inputs:
    char *args: everything following the and including the <
  Returns: The file descriptor for stdout

  Places a null before <.
  Relies on helper function redirector_out to open the file path given by the second argument.
  The file descriptor for stdout is copied first.

  ===========*/

/*====== char * rm_space() ============
  Inputs:
    char *line: the buffer
    char delim: the char to be removed
  Returns: A pointer to the start of the trimmed string.

  Removes extraneous delims from line.
  ===========*/

/*====== void cd() ============
  Inputs:
    char **line: Array of strings where every token is separated by a single whitespace
  Returns: nothing

  Our implementation of cd
  ===========*/

/*====== void my_exit() ============
  Inputs:
    char **line: Array of strings where every token is separated by a single whitespace
  Returns: nothing

  Our implementation of exit
  ===========*/

redirect.c
/*====== redirector_in/out() ============
  Inputs:
    char *path: filepath
  Returns: The file descriptor for stdin/out

  Helper function for redirect_in/out

  ===========*/

/*====== my_pipe() ============
  Inputs:
    char **cmds: Parsed arguments
  Returns: none

  Opens a pipe between the commands specified in cmds.

  ===========*/
  ```

