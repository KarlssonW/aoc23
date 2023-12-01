#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void process(FILE *file) {
    int sum = 0;

    char line[100];

    while(fgets(line, sizeof(line), file)) {
        int firstDigit = 0;
        int lastDigit = 0;

        char *p = line;
        while(*p) {
            if(isdigit(*p)) {
                if(firstDigit == 0) {
                    firstDigit = *p - '0';
                }
                lastDigit = *p - '0';
            }
            p++;
        }
        sum += (10 * firstDigit) + lastDigit;
    }

    printf("Sum: %d\n", sum);
}

int main(int argc, char *argv[]) {
    FILE *file = fopen("input.txt", "r");

    process(file);

    fclose(file);

    return 0;
}