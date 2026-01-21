void fun(const unsigned char* input, int input_len, unsigned char* output) {
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
    foo(var_5);
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
    return;
}
