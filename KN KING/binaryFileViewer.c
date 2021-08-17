// Display the contents of a file as bytes and characters.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// A custom type that signifies a byte
typedef unsigned char BYTE;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: binaryFileViewer <filename>\n");
        exit(EXIT_FAILURE);
    }
    FILE *file;
    if ((file = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch, byte_read, offset = 0;
    BYTE buffer[10];    // Read and store bytes in a buffer of 10 bytes
    printf("%7s  %15s  %25s\n", "Offset", "Bytes", "Characters");
    printf("-------  ------------------------------  ----------\n");
    while ((byte_read = fread(buffer, sizeof(BYTE), 10, file)) != 0) {
        // Print offset
        printf("%7d  ", offset);
        // Print the bytes
        int i;
        for (i = 0; i < byte_read && i < 10; i++) 
            printf("%2.2X ", buffer[i]);
        for (; i < 10; i++) 
            printf("   ");
        printf("  ");
        // Print characters
        for (int j = 0; j < byte_read; j++) {
            if (isprint(buffer[j]))
                printf("%c", buffer[j]);
            else 
                printf(".");
        }
        
        offset += 10;
        printf("\n");
    }
    printf("\n");
    fclose(file);

    return 0;
}
