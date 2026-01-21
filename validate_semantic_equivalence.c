#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_STRING_LENGTH 30


int fun_1_A(const unsigned char* input, int input_len, unsigned char* output) {
    int count_foo = 0;
    int var_2 = input_len/2;
    for(int var_1 = 0; var_1 < input_len; var_1++,var_2 += 1){
        int var_3 = input[var_2 % input_len];
        int var_4 = 0;
        int var_5 = var_3 / 3;
        while (var_5 <= 150){
            if (var_5 < 60){
                for (int var_6 = 0; var_6 < 3; var_6++){
                    var_3 += input[(var_1 + var_6) % input_len];
                }
                var_5 = var_3 / 3;
                continue;
            }
            if (var_4 > 2) {
                break;
            }
            // foo(var_5);
            count_foo += 1;
            var_4++;
            var_3 -= input[var_1];
            var_5 = var_3 / 2;
        }
        var_3 = var_3 % 43 + 80;
        if(var_1 % 2 == 0){
            output[var_1] = var_3 % 39 + 62;
        }else{
            output[var_1] = var_3;
        }
    }
    return count_foo;
}

int fun_1_B(const unsigned char* input, int input_len, unsigned char* output) {
    int count_foo = 0;
    int var_1 = 0;
    int var_2 = input_len / 2;
LABEL_1:
    if (var_1 >= input_len){
        goto LABEL_8;
    }
    int var_3 = input[var_2 % input_len];
    int var_4 = 0;
LABEL_2:
    int var_5 = var_3 / 3;
LABEL_3:
    if (var_5 > 150){
        goto LABEL_7;
    }
    if (var_5 < 60){
        goto LABEL_4;
    }
    goto LABEL_6;
LABEL_4:
    int var_6 = 0;
LABEL_5:
    if (var_6 >= 3){
        goto LABEL_2;
    }
    var_3 += input[(var_1 + var_6) % input_len];
    var_6++;
    goto LABEL_5;
LABEL_6:
    if (var_4 > 2){
        goto LABEL_7;
    }
    // foo(var_5);
    count_foo += 1;
    var_4++;
    var_3 -= input[var_1];
    var_5 = var_3 / 2;
    goto LABEL_3;
LABEL_7:
    var_3 = var_3 % 43 + 80;
    if (var_1 % 2 == 0) {
        output[var_1] = var_3 % 39 + 62;
    }else{
        output[var_1] = var_3;
    }
    var_2++;
    var_1++;
    goto LABEL_1;
LABEL_8:
    return count_foo;
}

int fun_2_A(unsigned char *input, int input_len, unsigned char *output, int output_len) {
    int count_print_X = 0;
    if(input_len < 1){
        return -1;
    }
    int var_7, var_1 = 0;
    unsigned int var_2 = 0;
    unsigned char var_3 = 0;
    unsigned char var_5;
LABEL_1:
    int var_6 = var_1;
    if(var_6 >= input_len){
        // printf("X");
        count_print_X += 1;
        var_3 = var_6 % (2 * input_len);
        if( var_3 < input_len){
            var_6 = var_3;
        }else{
            var_6 = var_3 - input_len;
        }
    }
    var_5 = input[var_6];
    if (var_5 % 2 == 1){
        goto LABEL_4;
    }
LABEL_2:
    var_5 /= 2;
    do {
        if(var_6 >= input_len){
            output[var_1] = var_5 % 256;
            if(output[var_1] <= 100){
LABEL_3:
                output[var_1] = ( output[var_1] + var_5 ) % 74 + 48;
            }else {
                output[var_1] /= 2;
                if (output[var_1] <= 30){
                    goto LABEL_3;
                }
                output[var_1] -= 15;
                if (output[var_1] != 40){
                    goto LABEL_3;
                }
                output[var_1] -= 5;
            }
            var_1++;
            if(var_1 < 8){
                goto LABEL_1;
            }
            var_7 = 0;
            break;
        }
        var_5 += input[var_6];
        var_6 += output_len;
        if(var_5 > 256){
            goto LABEL_2;
        }
LABEL_4:
        var_5 += 1;
    } while(true);

    return count_print_X;
}

int fun_2_B(unsigned char *input, int input_len, unsigned char *output, int output_len) {
    int count_print_X = 0;
    if(input_len < 1){
        return -1;
    }
    int var_1 = 0;
    unsigned int var_2 = 0;
    unsigned char var_3 = 0;
    unsigned char var_5;
    do {
        int var_6 = var_1;
        if(var_6 >= input_len){
            // printf("X");
            count_print_X += 1;
            var_3 = var_6 % (2 * input_len);
            if(var_3 < input_len){
                var_6 = var_3;
            }else{
                var_6 = var_3 - input_len;
            }
        }
        var_5 = input[var_6];
        if (var_5 % 2 == 0) {
            var_5 /= 2;
        } else {
            var_5 += 1;
        }
        while (var_6 < input_len) {
            var_5 += input[var_6];
            var_6 += output_len;
            if (var_5 > 256) {
                var_5 /= 2;
            } else {
                var_5 += 1;
            }
        }
        output[var_1] = var_5 % 256;
        int var_8 = false;
        if (output[var_1] > 100) {
            output[var_1] /= 2;
            if (output[var_1] > 30) {
                output[var_1] -= 15;
                if (output[var_1] == 40) {
                    output[var_1] -= 5;
                }else{
                    var_8 = true;
                }
            }else{
                var_8 = true;
            }
        }else{
            var_8 = true;
        }
        if (var_8) {
            output[var_1] = ( output[var_1] + var_5 ) % 74 + 48;
        }
        var_1++;
    } while (var_1 < 8);

    return count_print_X;
}

// Generate a random printable ASCII string (ASCII 32 to 126)
void generate_random_string(char* str, int length) {
    for (int i = 0; i < length; ++i) {
        str[i] = (char)((rand() % (126 - 32 + 1)) + 32);
    }
    str[length] = '\0';
}

int main() {
    printf("How many runs to check for semantic equivalence to you want to do?");
    unsigned long long run_checks;
    if (scanf("%llu", &run_checks) != 1) {
        printf("Error while reading Input!");
        return 1;
    }

    srand((unsigned int)time(NULL));

    for (long long count = 0; count < run_checks; count++) {
        int len = (rand() % MAX_STRING_LENGTH) + 1;

        unsigned char* input_string = (unsigned char*)malloc((len + 1) * sizeof(unsigned char));
        if (input_string == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            return 1;
        }

        generate_random_string(input_string, len);

        unsigned char output1_A[len+1];
        unsigned char output1_B[len+1];
        unsigned char output2_A[8+1];
        unsigned char output2_B[8+1];

        // Zero out output buffers before each function call
        memset(output1_A, 0, len + 1);
        memset(output1_B, 0, len + 1);
        memset(output2_A, 0, 8 + 1);
        memset(output2_B, 0, 8 + 1);

        int result1_A = fun_1_A(input_string, len, output1_A);
        int result1_B = fun_1_B(input_string, len, output1_B);
        int result2_A = fun_2_A(input_string, len, output2_A, 8);
        int result2_B = fun_2_B(input_string, len, output2_B, 8);

        if (memcmp(output1_A, output1_B, len) != 0 || result1_A != result1_B || memcmp(output2_A, output2_B, 8) != 0 || result2_A != result2_B) {
            printf("Mismatch found after %lld successful tests!\n", count);
            printf("Input (%d chars): \"%s\"\n", len, input_string);
            printf("fun1_A (%d): \"%s\"\n", result1_A, output1_A);
            printf("fun1_B (%d): \"%s\"\n", result1_B, output1_B);
            printf("fun2_A (%d): \"%s\"\n", result2_A, output2_A);
            printf("fun2_B (%d): \"%s\"\n", result2_B, output2_B);
            free(input_string);
            return 1;
        }

        if (count > 0 && count % (run_checks/10) == 0) {
            printf("%lld strings tested successfully...\n", count);
        }

        free(input_string);
    }
    printf("Successfully tested all %lld strings", run_checks);
}