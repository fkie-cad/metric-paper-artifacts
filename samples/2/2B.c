#include <stdbool.h>
int fun(unsigned char *input, int input_len, unsigned char *output, int output_len) {
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
            printf("X");
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

    return 0;
}
