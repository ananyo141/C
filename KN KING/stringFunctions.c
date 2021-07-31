// This is a module mimic-ing the string library of C
#include <stdio.h>
#define MAXLEN 50

// function declarations
int readline(char *sentence, int arr_size); // reader
int mod_strlen (const char *str);  // strlen
int mod_strcmp(const char *str1, const char *str2); // strcmp
char *mod_strcpy (char *str1, const char *str2, int size); // strcpy
char *mod_strcat (char *str1, const char *str2); // strcat
void slicer (const char *str, char *returnStr, int start, int stop); // slicer   // stop is non-inclusive


// driver function
int main() {
    char message[MAXLEN];
    printf("Enter a string: ");
    readline(message, MAXLEN);
    int len = mod_strlen(message);
    printf("%d\n", len);
    puts(message);
    printf("%d\n", sizeof(message) - len);

    mod_strcat(message, "abcdeeeeee");
    puts(message);

    return 0;
}

// reads a line from stdin
int readline (char *sentence, int arr_size) {
    int ch, i = 0;

    // skip the leading spaces
    while ((ch = getchar()) == ' ' || ch == '\n');

    sentence[i++] = ch;         
    while ((ch = getchar()) != '\n')
        if (i < arr_size - 2)
            sentence[i++] = ch;
    sentence[i] = '\0';
    return i;
}

// string length
int mod_strlen (const char *str) {
    const char *start = str; 
    while (*str++);

    return str - start - 1;
}

// string copy
char *mod_strcpy (char *str1, const char *str2, int size) {
    int i = 0;
    char *start = str1;
    while (*str2)
        if (i++ < size - 2)
            *str1++ = *str2++;
    *str1 = '\0';
    return start;
}

// string concatenation
char *mod_strcat (char *str1, const char *str2, int size) {
    char *start = str1;

    while (*str1) str1++;   // find the last character of str1
    if ((str1 - start) >= size) return start;   // if no space left
    while ((str1 - start) < size - 1)
        *str1++ = *str2++;
    *str1 = '\0';       // so str1 is always null-terminated

    return start;
}

// string compare
int mod_strcmp(const char *str1, const char *str2) {
    while (*str1++ == *str2++)
        if (*str1 == 0)
            return 0;
    return *str1 - *str2;
}

// string slicer
void slicer (const char *str, char *returnStr, int start, int stop) {   // stop is non-inclusive
    while (start < stop) 
        *returnStr++ = str[start++];
    *returnStr = '\0';          // close it off with null-terminator
}