#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#define EXIT_CODE 0
#define BUFF_SIZE 1024
extern char **environ;
/**
 * struct funct - struct element
 *
 * @name: name
 * @function: the function to be returned
 */
struct funct
{
	char *name;
	int (*function)(char **array_tokens);
};
void _itoa(int n, char buffer[], int buflen);
int error_hand(char **token, char **arvg, int len);
int chdir_cmd(char **array_tokens);
int execute(char *command, char **array_tokens);
int env_cmd(char **array_tokens);
int exit_cmd(char **array_tokens);
ssize_t my_getline(char **input, size_t *num_alloced);
void prompt(void);
void handle_signal(int signal);
size_t token_count(char *input, char *delimeter);
char **tokenize(char *input, char *delimeter);
void free_main(char **tokens);
int check_builtin(char **array_tokens);
int is_builtin(char **array_tokens);
int path_valid(char *command);
char *found_path(char *command);
void create_path(char **file_path, char **array_tokens,
		char *filename, int tok_cnt);
char *char_maker(char **input, size_t len);
char **array_maker(char **input, size_t len);
void free_path(char **path_str, char **array_tokens);
#endif

