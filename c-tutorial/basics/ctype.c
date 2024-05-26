#include <stdio.h>
#include <ctype.h>

void what_char(char var){
    printf("'%c' is", var);    
    if(isalnum(var)){    
        printf(" alpha-numeric character");
        if(isalpha(var))
            printf(" and it is %s letter.\n", isupper(var) ? "capital" : "small");
        else if(isdigit)
            printf(" and it is digit.\n");
        else
            printf("\n");
    }
    else if(iscntrl(var)){
        printf(" control character");
        if(isprint(var))
            printf(" and it is printable.\n");
        else
            printf(" and it is unprintable\n");
    }
    else if(ispunct(var))
        printf(" punctuation character.\n");
    else
        printf(" special character.\n");
}

int main(int argc, char*argv[])
{
    what_char(toupper('a'));
    what_char(tolower('A'));
    what_char('1');
    what_char('$');
    what_char('\n');
    what_char('\t');
    what_char('.');

    printf("\nDone.\n");
    return 0;
}