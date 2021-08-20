/***************************************************************************************************
*                         //  Do math on integers in a text file  //                               *                                  
*  i) Each line on file can contain any number of integers (including none) separated by one       *          
*     or more spaces.                                                                              *                 
* ii) Display the largest, smallest and median of the numbers in the file.                         *                  
****************************************************************************************************/
  
#include <stdio.h>
#include <stdlib.h>

// the comparison function for 'stdlib' qsort
int compare(const void *p, const void *q);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: fileStatistics <filename>\n");
        exit(EXIT_FAILURE);
    }

    FILE *readfile;
    if ((readfile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Unable to open file %s\n.", argv[1]);
        exit(EXIT_FAILURE);
    }
    // read the integers in the buffer  
    int ch, buffer[BUFSIZ], totalInt = 0;
    while (fscanf(readfile, "%d", &ch) == 1) 
            buffer[totalInt++] = ch;
    fclose(readfile);

    // sort the buffer
    qsort(buffer, totalInt, sizeof(int), compare);

    int midVal = totalInt / 2;
    double median;
    // find the median
    if ((totalInt % 2) == 1)    // if total number is odd
        median = buffer[midVal];
    else                        // if total number is even
        median = (buffer[midVal - 1] + buffer[midVal]) / 2.0f;

    puts("Results:");
    printf("Largest: %d\nSmallest: %d\nMedian: %.2lf\n", buffer[totalInt - 1], buffer[0], median);

    return 0;
}

int compare(const void *p, const void *q) {
    const int *p1 = p;
    const int *q1 = q;

    if (*p1 < *q1)  return -1;
    else if (*p1 == *q1)    return 0;
    else    return 1;
}
