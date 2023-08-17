#include "foundation.h"

void    test_strsplit( ) {
    char    *input = "This is a string";
    char    **res;
    int     i;
    char    *test[] = {
        "This",
        "is",
        "a",
        "string",
        NULL
    };

    res = f_strsplit(input, ' ');
    i = 0; 
    while (test[i] != NULL) {
        assert(f_strcmp(res[i], test[i]) == 0);
        i++;
    }
    f_putstr("f_strsplit test successful");
}

void    test_strnstr() {
    char    *s1 = "thebiggestlittlestring";
    char    *s2 = "little";
    int     res;

    res = f_strcmp(f_strnstr(s1, s2, 23), "littlestring");
    if (!(res == 0 )) {
        f_putstr("strnstr fails");
        return ;
    }
    f_putstr("strnstr passes");
}

void    test_strstr() {
    char *s1 = "thebiggestlittlestring";
    char *s2 = "little";

    assert(f_strcmp(f_strstr(s1, s2), "littlestring") == 0);
    f_putstr("strstr passes");
}

void    test_absval() {
    assert(f_absval(1) == 1);
    assert(f_absval(-1) == 1);
    assert(f_absval(10) == 10);
    assert(f_absval(-10) == 10);
    f_putstr("absval tests passed");
}

int     test_dtoc() {
    assert(f_dtoc(0) == '0');
    assert(f_dtoc(1) == '1');
    assert(f_dtoc(10) == '\0');
    //printf("dtoc tests passed successfully!\n");
    return (0);
}

int     test_isalnum(void) {
    assert(f_isalnum('a') == 1);
    assert(f_isalnum('Z') == 1);
    assert(f_isalnum('5') == 1);
    assert(f_isalnum(' ') == 0);
    printf("isalnum tests passed successfully!\n");
    return (0);
}

int     test_isalpha(void) {
    assert(f_isalpha('a') == 1);
    assert(f_isalpha('b') == 1);
    assert(f_isalpha('5') == 0);
    assert(f_isalpha('z') == 1);
    printf("isalpha tests passed successfully!\n");
    return (0);
}

int     test_isdigit(void) {
    assert(f_isdigit('a') == 0);
    assert(f_isdigit('b') == 0);
    assert(f_isdigit('5') == 1);
    assert(f_isdigit('z') == 0);
    printf("isdigit tests passed successfully!\n");
    return (0);
}

int     test_isascii(void) {
    assert(f_isascii('a') == 1);
    assert(f_isascii('b') == 1);
    assert(f_isascii('5') == 1);
    assert(f_isascii('z') == 1);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int     test_is_whitespace(void) {
    assert(f_isascii('a') == 0);
    assert(f_isascii('1') == 0);
    assert(f_isascii(' ') == 1);
    assert(f_isascii('\n') == 1);
    assert(f_isascii('\t') == 1);
    assert(f_isascii('\r') == 1);
    assert(f_isascii('\v') == 1);
    assert(f_isascii('\f') == 1);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int     test_isprint(void) {
    assert(f_isprint('a') == 1);
    assert(f_isprint('b') == 1);
    assert(f_isprint('5') == 1);
    assert(f_isprint(' ') == 0);
    assert(f_isprint('\t') == 0);
    assert(f_isprint('\n') == 0);
    printf("is_ascii tests passed successfully!\n");
    return (0);
}

int test_iswhitespace(void) {
    assert(f_iswhitespace('a') == 0);
    assert(f_iswhitespace('b') == 0);
    assert(f_iswhitespace('5') == 0);
    assert(f_iswhitespace(' ') == 1);
    assert(f_iswhitespace('\t') == 1);
    assert(f_iswhitespace('\n') == 1);
    assert(f_iswhitespace('\0') == 0);

    printf("is_whitespace tests passed successfully!\n");
    return (0);
}

int test_strlen(void) {
    assert(f_strlen("") == 0);
    assert(f_strlen("abc") == 3);
    assert(f_strlen("abcabc") == 6);
    assert(f_strlen("abcabcabc") == 9);
    assert(f_strlen("abcabcabcabc") == 12);
    printf("strlen tests passed successfully!\n");
    return (0);
}

int test_putchar(void) {
    f_putchar('t');
    f_putchar('e');
    f_putchar('s');
    f_putchar('t');
    f_putchar('\n');
    printf("putchar tests passed successfully!\n");
    return (0);
}

int test_putstr(char *s) {
    int bytes;
    bytes = f_putstr(s);
    assert(f_strlen(s) == bytes);
    printf("putstr tests passed successfully!\n");
    return (bytes);
}

int test_putendl(char *s) {
    int bytes;
    bytes = f_putendl(s);
    assert(f_strlen(s) + 1 == bytes);
    printf("putendl tests passed successfully!\n");
    return (bytes);
}

void test_strcat () {
    char s1[8] = {
        'a',
        'b',
        'c',
        '\0',
        '\0',
        '\0',
        '\0',
        '\0'
    };
    const char *s2;
    s2 = "123";
    assert(f_strcmp(f_strcat(s1, s2), "abc123") == 0);
    f_putstr("strcat tests past sucessfully\n");
}

void test_strcmp() {
    char    *s1;
    char    *s2;
    
    s1 = "abc";
    s2 = "123";
    assert(f_strcmp(s1, s1) == 0);
    assert(f_strcmp(s1, s2) == -1);
    f_putstr("strcmp tests past sucessfully\n");
}

//abc
//123
//ttt
void test_strncmp() {
    char    *s1;
    char    *s2;
    
    s1 = "abc";
    s2 = "123";
    assert(f_strncmp(s1, s1, 3) == 0);
    assert(f_strncmp(s1, s2, 3) > 0);
    f_putstr("strncmp tests past sucessfully\n");
}

void test_strcpy() {
    char     s1[5];
    char     *s2;

    s2 = "dcba";
    assert(f_strcmp(f_strcpy(s1, s2), s2) == 0);
    f_putstr("strcpy tests past sucessfully\n");
}

void test_strncpy() {
    char     s1[5];
    char     *s2;

    s2 = "dcba";
    assert(f_strcmp(f_strncpy(s1, s2, 4), s2) == 0);
    f_putstr("strcpy tests past sucessfully\n");
}

void test_strncat() {
    char    s1[5];
    char    *s2;

    s2 = "dcba";
    assert(f_strcmp(f_strncat(s1, s2, 4), s2) == 0);
    f_putstr("strncat tests past successfully");
}

void test_putnbr() {
    f_putnbr(0);
    f_putchar('\n');
    f_putnbr(1);
    f_putchar('\n');
    f_putnbr(10);
    f_putchar('\n');
    f_putnbr(11);
    f_putchar('\n');
    f_putnbr(111);
}

int test_gnl() {
    int     fd;
    size_t  bytes;
    char    *line;

    bytes = f_gnl(fd, &line);
    f_putstr(line);
    assert(f_strncmp("test0", line, bytes) == 0);
    return (bytes);
}

int main(void) {
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_strlen();
    test_putchar();
    test_putstr("test putstr");
    test_putendl("test putendl");
    test_dtoc();
    test_putnbr();
    test_iswhitespace();
    test_strcat();
    test_strcmp();
    test_strncmp();
    test_absval();
    test_strcpy();
    test_strncpy();
    test_strncat();
    test_strnstr();
    test_strsplit();
    test_gnl();
    return (0);
}