#include <stdio.h>
#include <string.h>

#define ENCSTR "!n3f8FJ#8f:;!"
#define ENCLEN (int)(sizeof(ENCSTR)-1)

char *encrypt_string(char *s, int len)
{
    char *p;
    int i;
    for(p=s,i=ENCLEN; (p-s) < len; p++) {
        if(i > 0)
            i--;
        else
            i=ENCLEN;
        *p = ((*p ^ ENCSTR[i]) + 32 / 2) % 255;
    }
    return s;
}

char *decrypt_string(char *s, int len)
{
    char *p;
    int i;
    for(p=s,i=ENCLEN; (p-s) < len; p++) {
        if(i > 0)
            i--;
        else
            i=ENCLEN;
        *p = ((*p - 32 / 2) ^ ENCSTR[i]) % 255;
    }
    return s;
}

#define MAXTOKENS 50

int split_string(char *s, char ***d)
{
    static char *t[MAXTOKENS];
    char *p;
    int i;
    
    i = 0;
    p = strtok(s, " \r\n");
    for(; i<MAXTOKENS && p; i++) {
        t[i] = p;
        p = strtok(NULL, " \r\n");
    }
    t[i] = p;
    *d = t;
    return i;
}

#define MAXTOKENS 50

int main()
{
    char msg[] = "Hello world!";
    char **tmp;
    
    printf("Encrypted: %s\n", encrypt_string(msg, sizeof(msg)));
    printf("Decrypted: %s\n", decrypt_string(msg, sizeof(msg)));
    printf("Tokenized: %d\n", split_string(msg, &tmp));
    while(*tmp) {
        printf("Token: %s\n", *tmp);
        tmp++;
    }
    return 0;
}