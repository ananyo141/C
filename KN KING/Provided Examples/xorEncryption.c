// Use XOR Encryption to encode a message
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: xorEncryption <inputfile> <outputfile>\n");
        exit(EXIT_FAILURE);
    }

    int orig_char, key;
    printf("Enter the key: ");
    scanf("%c", &key);

    FILE *readfile, *writefile;
    if ((readfile = fopen(argv[1], "rb")) == NULL) {
        printf("File %s couldn't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((writefile = fopen(argv[2], "wb")) == NULL) {
        printf("File %s couldn't be opened\n", argv[2]);
        fclose(readfile);
        exit(EXIT_FAILURE);
    }

    while ((orig_char = getc(readfile)) != EOF) {
        putc(orig_char ^ key, writefile);
    }
    fclose(readfile);
    fclose(writefile);
    printf("File successfully encrypted/decrypted\n");
    
    return 0;
}
