#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>
#define MAX 10



void sign_handler(int signum);
int stringlen(const char *str);
size_t _strlen(const char *str);
void getpiddd(char **rvg, char *cmd);
char *get_path(const char *command);
char *handle_path(char **rgv, const char *cmd);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strdup(const char *str);
void handle_exit(char *input);
int _strcmp(const char *s1, const char *s2);
void _env(char **env);

/* built-in funcs */
void shell_cd(char **args)
void shell_exit(char **args);

#endif
