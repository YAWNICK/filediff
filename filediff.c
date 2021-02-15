#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Wrong input\nInput format: filediff file1 file2\n");
        exit(EXIT_FAILURE);
    }
    char *filename1 = argv[1];
    char *filename2 = argv[2];
    FILE *fp1, *fp2;
    fp1 = fopen(filename1, "r");
    if (fp1 == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename1);
        exit(EXIT_FAILURE);
    }
    fp2 = fopen(filename2, "r");
    if (fp2 == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename2);
        exit(EXIT_FAILURE);
    }
    
    char f1char, f2char;
    int line = 1;
    while ((f1char = fgetc(fp1)) == (f2char = fgetc(fp2))) {
        if (f1char == '\n') line++;
        if (f1char == EOF) {
            printf("No differences found.\n");
            fclose(fp1);
            fclose(fp2);
            exit(EXIT_SUCCESS);
        }
    }
    printf("Found difference in line %i.\n", line);
    fclose(fp1);
    fclose(fp2);
    return 0;
}
