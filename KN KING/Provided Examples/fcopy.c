// Copy a file //
#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[]) {
    FILE *source_fp, *dest_fp;
    BYTE *buffer;

    if (argc != 3) {
        fprintf(stderr, "Usage: fcopy source dest\n");
        exit(EXIT_FAILURE); 
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    if ((buffer = malloc(sizeof(BYTE) * BLOCK_SIZE)) == NULL) {
        fprintf(stderr, "Couldn't allocate memory to buffer");
        exit(EXIT_FAILURE);
    }

    int block_read;
    while (block_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, source_fp)) 
        fwrite(buffer, sizeof(BYTE), block_read, dest_fp);

    fclose(source_fp);
    fclose(dest_fp);
    free(buffer); 
    printf("File copied at %s\n", argv[2]);   

    return 0;
}
