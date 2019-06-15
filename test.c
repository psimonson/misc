#include <stdio.h>
#include <string.h>

extern int readline(char*, int);
extern void add_history(char*, int);
extern void del_history();
extern char *get_history(int);

int main()
{
    char buf[100];
    
    (void)readline(buf, sizeof(buf));
    add_history(buf, strlen(buf));
    printf("History: %s\n", get_history(0));
    del_history();
    return 0;
}