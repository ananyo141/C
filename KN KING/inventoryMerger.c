// This program merges the binary files generated by the Parts Database program and creates a 
// merged binary containing the sorted inventory.
#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 25

// parts structure
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

int main(int argc, char *argv[]) {
    FILE *bin1, *bin2, *binOut;
    struct part buffer[BUFSIZ];

    if (argc != 4) {
        fprintf(stderr, "Usage: inventoryMerger <bin1> <bin2> <binOut>\n");
        exit(EXIT_FAILURE);
    }
    if ((bin1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "File %s couldn't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((bin2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "File %s couldn't be opened\n", argv[2]);
        fclose(bin1);
        exit(EXIT_FAILURE);
    }
    if ((binOut = fopen(argv[3], "wb")) == NULL) {
        fprintf(stderr, "File %s couldn't be opened\n", argv[3]);
        fclose(bin1);
        fclose(bin2);
        exit(EXIT_FAILURE);
    }

    int totalPart;
    // read the data of first binary to buffer
    for (totalPart = 0; fread(&buffer[totalPart], sizeof(struct part), 1, bin1); totalPart++) ;
    totalPart--;    // discard the failed read
    fclose(bin1);

    // read and sort the second binary to buffer
    struct part temp;
    while (fread(&temp, sizeof(struct part), 1, bin2)) {
        // discard the failed read (trailing pseudo-part with 0 part number)
        if (temp.number == 0)
            continue;
        int index;
        // find the place according to part number
        for (index = 0; index < totalPart; index++)
            if (buffer[index].number > temp.number)
                break;
        // make place to insert part
        for (int k = totalPart - 1; k >= index; k--)
            buffer[k + 1] = buffer[k];
        // insert part
        buffer[index] = temp;

        totalPart++;    // update total part count
    }
    fclose(bin2);

    // write contents of buffer into save binary
    fwrite(buffer, sizeof(struct part), totalPart, binOut);
    fclose(binOut);
    printf("Binaries merged and saved as %s\n", argv[3]);

    return 0;
}
