// See if the file can be opened

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *file_name;
    FILE *fp;
    if (argc < 2) {
        printf("Usage: canopen <filenames>\n");
        exit(EXIT_FAILURE);
    }
    // iterate over the filenames supplied on the command line
    for (int i = 1; i < argc; i++) {
        file_name = argv[i];
        
        if ((fp = fopen(file_name, "rb")) == NULL) {
            printf("%s can't be opened for reading\n", file_name);
            continue;
        }

        printf("%s can be opened\n", file_name);
        fclose(fp);
    }

    return 0;
}
