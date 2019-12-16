// Exercise on page 73
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

double atof(char s[]);

int main(){
    char s[] = "10.52e-1";
    printf("original: %s\n", s);
    printf("double:   %lf\n", atof(s));

    return 0;
}

double atof(char s[]){
    double val, power, result;
    int i, j, sign, exp_sign, exp;


    for(i=0; isspace(s[i]); i++){       // ommit white spaces
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;      // determine sign
    if(s[i]=='+' || s[i]=='-'){
        i++;
    }
    for(val=0.0; isdigit(s[i]); i++){   // convert integers
        val = val * 10.0 + (s[i] - '0');
    }
    if(s[i] == '.'){
        i++;
    }
    for(power=1.0; isdigit(s[i]); i++){ // convert decimals
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }


    if(tolower(s[i]) != 'e'){           // no scientific notation
        result = sign * val / power;

    }else{                              // scientific notation
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;      // determine sign of exponent
        if(s[i]=='+' || s[i]=='-'){
            i++;
        }
        
        for(exp=0.0; isdigit(s[i]); i++){       // convert exponent to integers
            exp = exp * 10 + (s[i] - '0');
        }
        
        if(exp_sign < 0){                       // modify power according to sign and value
            for(j=0; j<exp; j++){
                power *= 10.0;
            }
        }else{
            for(j=0; j<exp; j++){
                power /= 10.0;
            }
        }
        result = sign * val / power;            // calculate resulting double
    }

    
    return result;
}

