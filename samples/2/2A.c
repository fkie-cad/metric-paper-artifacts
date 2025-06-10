#include <stdbool.h>
int fun(unsigned char *input, int input_len, unsigned char *output, int output_len) {
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
        printf("X");
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

    return 0;
}
