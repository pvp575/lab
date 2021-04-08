/*
5.Произвольная последовательность переменных типа char, int и long.
Перед каждой переменной размещается байт, определяющий ее тип (0-char, 1-int, 2-long).
Последовательность вводится в виде целых переменных типа long, которые затем
«укорачиваются» до минимальной размерности без потери значащих цифр.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    char c;
    char A[10];
    int B[10];
    long C[10];
    int type = 3, j = 0, k = 0, l = 0;
    for (int i = 0; i < 10; i++){
        scanf("%c", &c);
        if(c == '\n'){
            printf("END\n");
            return 0;
        }
        //printf("%c", c);

        if((i % 2) == 0){
            switch (c)
            {
            case '0':
                printf("char\n");
                type = 0;
                break;
            case '1':
                printf("int\n");
                type = 1;
                break;
            case '2':
                printf("long\n");
                type = 2;
                break;
            
            default:
                printf("\nОшибка!\n");
                type = 3;
                break;
            }
        }
        else{
            switch (type)
            {
            case 0:
                A[j] = c;
                printf("%c\n", A[j]);
                j++;
                break;
            case 1:
                B[k] = atoi(&c);
                printf("%d\n", B[k]);
                k++;
                break;
            case 2:
                C[l] = atoi(&c);
                printf("%ld\n", C[l]);
                l++;
                break;

            default:
                break;
            }
        }
    }

    return 0;
}
