#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long long recursive(int input);
unsigned long long iterative(int input);

int main(int argc, char *argv[]) {
    
    int input_num = atoi(argv[1]);


    FILE *file = fopen(argv[3], "r");
    int file_num;
    fscanf(file, "%d", &file_num);
    fclose(file);

    int input = input_num + file_num;


    unsigned long long result;
    if (strcmp(argv[2], "r") == 0) {
        result = recursive(input);
    } else {
        result = iterative(input);
    }

    
    printf("%llu\n", result);

    return 0;
}

unsigned long long recursive(int input) {
    if (input == 1) {
        return 0;
    }
    if (input == 2) {
        return 1;
    }
    return recursive(input - 1) + recursive(input - 2);
}

unsigned long long iterative(int input) {
    if (input == 1) {
        return 0;
    }
    if (input == 2) {
        return 1;
    }
    unsigned long long a = 0;
    unsigned long long b = 1;
    for (int i = 3; i <= input; i++) {
        unsigned long long temp = b;
        b = b + a;
        a = temp;
    }
    return b;
}
