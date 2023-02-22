#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void usage(){
    printf("usage: sort [-r] num1 num2 ...\n");
    printf("-r: reverse sort\n");
}
void swap(double *x, double *y){
    double temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void sort(double *a, int length){
    int i = 1; 
    int j;
    while (i<length){
        j = i;
        while (j>0 && a[j-1]>a[j]){
            swap(&a[j], &a[j-1]);
            j = j-1;
        }
        i = i+1;
    }
}

int is_valid_num(char *word){
    int found_dot = 0;
    int i;
    for (i=0; i<strlen(word); ++i){
        if (word[i] == '-'){
            if (i != 0){
                return 0;
            }
            continue;
        }
        if (word[i] == '.'){
            if (found_dot == 1){
                return 0;
            }
            found_dot = 1;
            continue;
        }

        if (!isdigit(word[i])){
            return 0;
        }
    }
    return 1;
}
int main(int argc, char *argv[])
{
    if(argc<=2){
        usage();
        return 0;
    }
    int rev = 0;
    int i; 
    if(argv[1][0] == '-' && argv[1][1] == 'r'){
        rev = 1;
    } 
    for(i=0; i<argc-1-rev; ++i){
        if(!is_valid_num(argv[i+1+rev])){
            printf("%s is not a valid number. \n", argv[i+1+rev]);
            usage();
            return 0;
        }           
    }
    double arr[argc-1-rev]; 
    for(i=0; i<argc-1-rev; i++){
        arr[i] = atof(argv[i+rev+1]);
    }
    sort(arr, argc-1-rev); 
    if(rev){
        for(i=argc-3; i>=0; --i){
            printf("%g\n", arr[i]);
        }
    }
    else{
        for(i=0; i<argc-1; ++i){
            printf("%g\n", arr[i]);
        }
    }
    return 0;
}
