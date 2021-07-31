// Print the command line input in reverse
#include <stdio.h>

int main(int argc, char **argv) {
    for (int i = argc - 1; i > 0; i--) 
        printf("%s ", argv[i]);
    return 0;
}