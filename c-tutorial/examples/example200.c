// Count the occurrences of a character in a string using recursion
#include <stdio.h>

int count_occurrences(char *string, char c)
{
    if(*string == '\0') 
        return 0;
    else{
        int counter = count_occurrences(string+1, c);
        if(*string == c)
            return counter + 1;
        else
            return counter;
    }
}

int main(void)
{
    char test[] = "Some characters in the string.";
    char c = 'r';
    printf(
        "Number of '%c' occurences in: \"%s\" is %d\n",
        c, test, count_occurrences(test, c)
    );
    return 0;
}