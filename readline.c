#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXHIST 256

struct history {
    char *line;
    int size;
};

static struct history _history[MAXHIST];
static int _historyn;

/* Gets a line of input from keyboard.
 */
int readline(char *s, int n)
{
    int c,i;
    
    for(i=0; i<n && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = 0;
    return i;
}
/* Add line of input to history.
 */
void add_history(char *s, int n)
{
    int i = _historyn;
    if(i >= 0 && i < MAXHIST) {
        _history[i].line = (char*)malloc(n+1);
        strncpy(_history[i].line, s, n);
        _history[i].line[n] = 0;
        _history[i].size = n;
        _historyn = ++i;
    }
}
/* Del line of input from history.
 */
void del_history()
{
    int i = _historyn;
    if(i >= 0 && i < MAXHIST) {
        free(_history[i].line);
        _history[i].size = -1;
        _historyn = --i;
    }
}
/* Get line from history and return it.
 */
char *get_history(int n)
{
    if(n < 0 || n > MAXHIST)
        return NULL;
    return _history[n].line;
}
