#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define MAX 10


/*int main(int argc, char **argv, char **env);*/
void sign_handler(int signum);
int stringlen(const char *str);
size_t _strlen(const char *str);
char *_strcpy(char *dest, char *src, int n);
void getpiddd(char **rvg, char *cmd);
/*char *get_path(char *arg);*/
/*char *get_loc(char *path, char *arg);*/
char *get_path(const char *command);
char *handle_path(char **rgv, const char *cmd);
char *_strddup(const char *str);
/*char *path_handle(char **rgv, char *cmd)*/
/*char *handle_path(char **rgv, char *cmd);*/

#endif
