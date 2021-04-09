/*
5.Произвольная последовательность переменных типа char, int и long.
Перед каждой переменной размещается байт, определяющий ее тип (0-char, 1-int, 2-long).
Последовательность вводится в виде целых переменных типа long, которые затем
«укорачиваются» до минимальной размерности без потери значащих цифр.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(){

    char c;
    char *A;
    A = malloc(sizeof(char)*10);
    int *B;
    B = malloc(sizeof(int)*10);
    long *C;
    C = malloc(sizeof(long)*10);
    int type = 3, j = 0, k = 0, l = 0;
    int i = 0;
    while (1){
        scanf("%c", &c);
        if(c == '\n'){
            printf("END\nВсего получено %d переменных\nchar: %d\nint: %d\nlong: %d\n", (j+k+l), j, k, l);
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
                if (j > 9){
                    A = realloc(A, sizeof(char)*j);
                }
                break;
            case 1:
                B[k] = atoi(&c);
                printf("%d\n", B[k]);
                k++;
                if (k > 9){
                    B = realloc(B, sizeof(int)*k);
                }
                break;
            case 2:
                C[l] = atoi(&c);
                printf("%ld\n", C[l]);
                l++;
                if (l > 9){
                    C = realloc(C, sizeof(long)*l);
                }
                break;

            default:
                break;
            }
        }
        i++;
    }

    return 0;
}
