#define READ 0
#define WRITE 1

char **parse_args(char * line);
int parent(int *fd);
int child(int *fd, char **args);
void reader(char **buffy);
char **parse_commands(char *line);
char **parse_commands(char *line);