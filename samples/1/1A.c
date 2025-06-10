void fun(const unsigned char* input, int input_len, unsigned char* output) {
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
            foo(var_5);
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
}
