#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CMD_NORM 0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE  ".simple_shell_history"
#define HIST_MAX   4096

extern char **environ;

/**
 * struct liststr - Singly linked list
 * @str: A string
 * @num: The number field
 * @next: Points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - Contains pseudo-arguments to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @argv: An array of strings generated from arg
 * @arg: A string generated from getline containing arguments
 * @argc: The argument count
 * @path: A string path for the current command
 * @line_count: The error count
 * @lincount_flag: If on count this lineof input
 * @err_num: The error code for exit()s
 * @fname: The program filemane
 * @environ: Custom modified copy of environ from LL env
 * @env: linked list local copy of environ
 * @history: The history code
 * @env_changed: On if environ was changed
 * @alias: The alias node
 * @status: The return status of the last exec'd command
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @cmd_buf: Address of pointer to cmd_buf, on if chaining
 * @histcount: The history line number count
 * @readfd: The fd from which to read line input
 */
typedef struct passinfo
{
	char **argv;
	char *arg;
	int argc;
	char *path;
	unsigned int line_count;
	int linecount_flag;
	int err_num;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int histcount;
	int readfd;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - Contains a builtin string and related function
 * @type: The builtin command flag
 * @func: The function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

int loophsh(char **);

void _eputs(char *);
int _putchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strtow(char *, char *);
char **strtow2(char *, char);

char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

int bfree(void **);

int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_commands(char *);

int _myexit(info_t *);
int mycd(info_t *);
int myalias(info_t *);

ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *, char *buf, int linecount);
int renumber_history(info_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

void _myexit(info_t *info);
void _myenv(info_t *info);
void myhelp(info_t *info);
void myhistory(info_t *info);
void _mysetenv(info_t *info);
void _myunsetenv(info_t *info);
void mycd(info_t *info);
void myalias(info_t *info);

#endif

