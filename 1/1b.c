#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// checks if the input string is a valid written digit from 1-9
int checkWrittenDigits(char *p) {
    if(strncmp(p, "one", 3) == 0) {
        return 1;
    } else if(strncmp(p, "two", 3) == 0) {
        return 2;
    } else if(strncmp(p, "three", 5) == 0) {
        return 3;
    } else if(strncmp(p, "four", 4) == 0) {
        return 4;
    } else if(strncmp(p, "five", 4) == 0) {
        return 5;
    } else if(strncmp(p, "six", 3) == 0) {
        return 6;
    } else if(strncmp(p, "seven", 5) == 0) {
        return 7;
    } else if(strncmp(p, "eight", 5) == 0) {
        return 8;
    } else if(strncmp(p, "nine", 4) == 0) {
        return 9;
    } else {
        return 0;
    }
}

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
            } else {
                int d = checkWrittenDigits(p);
                if(d != 0) {
                    if(firstDigit == 0) {
                        firstDigit = d;
                    }
                    lastDigit = d;
                }
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