#ifndef FOUNDATION_H
# define FOUNDATION_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int         f_absval(int n);
char        **f_array_append(char **array, char *item);
char        f_array_cmp(char **a1, char **a2, int (*cmp) (char*, char*));
size_t      f_array_len(char **arr);
char        **f_array_resize(char ***array, size_t incr);
char        *f_bzero(void *s, size_t n);
char        f_dtoc(int n);
int         f_isalnum(char c);
int         f_isalpha(char c);
int         f_isascii(int c);
int         f_isdigit(char c);
int         f_isprint(int c);
int         f_iswhitespace(char c);
void        *f_memalloc(size_t size);
char        *f_memcpy(char *dst, const char *src, size_t n);
void        *f_memset(void *s, int c, size_t n);
void        f_putchar(char c);
void        f_putchar_fd(char c, int fd);
int         f_putendl(char *s);
void        f_putnbr_fd(long long n, int fd);
void        f_putnbr(long long n);
int         f_putstr(char *s);
char        *f_stralloc(char *src);
char        *f_strcat(char* s1, const char* s2);
char        *f_strncat(char *s1, const char *s2, size_t n);
char        *f_strchr(const char *s, int c);
int         f_strcmp(const char *s1, const char *s2);
int         f_strncmp(const char *s1, const char *s2, size_t n);
int         f_strcount(char *s, char c);
char        *f_strcpy(char *dst, const char *src);
int         f_strlen(char *str);
char        *f_strcpy(char *dst, const char *src);
char        *f_strncpy(char *dst, const char *src, size_t len);
char        *f_strnew(int l);
char        *f_strnstr(const char *big, const char *sm, size_t len);
char        **f_strsplit(char const *s, char c);
char        *f_strstr(const char *big, const char *little);
int         f_gnl(const int fd, char **line);

#endif