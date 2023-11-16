#ifndef SHELL_H
#define SHELL_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#define MAX 10

/* prompt.c */
void prompt(void);

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



#endif
