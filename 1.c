#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void input(char *s){
    FILE *file;
    file = fopen("si.txt", "r");

    int i = 0;

    while ((s[i] = fgetc(file)) != EOF) {
        i++;
    }
    s[i] = '\0';
    printf("INPUT (C/C++):\n%s\n",s);
    fclose(file);
}
void output(char *res){
    FILE *file;
    printf("OUTPUT (Pascal):\n%s\n", res);
    int i=0;
    file = fopen("pascal.txt", "w");
    fprintf(file, "%s\n", res); 
    fclose(file);
}
void change(char *s, char *res){
    int j = 0;
    char k;
    int i = 0;
    
    while (s[i] != '\0')
    {
        if (s[i] == '='
         && s[i+1] == '=')
        {
            res[j++] = '=';
            i += 2;
        }
        else if (s[i] == '!'
              && s[i+1] == '=')
        {
            res[j++]='#';
            i += 2;
        }
        else if (s[i] == '+'
              && s[i+1] == '=')
        {
            k = s[i-1];
            res[j++] = '=' ;
            res[j++] = k   ;
            res[j++] = '+' ;
            i += 2;
        }
        else if (s[i] == '-'
              && s[i+1] == '=')
        {
            k = s[i-1];
            res[j++] = '=' ;
            res[j++] = k   ;
            res[j++] = '-' ;
            i += 2;
        }
        else if (s[i] == '='
              && s[i-1] != '-'
              && s[i-1] != '+'
              && s[i-1] != '!'
              && s[i-1] != '=')
        {
            res[j++] = ':';
            res[j++] = '=';
            i++;
        }
        else
            res[j++] = s[i++];
    }
}
void ascii_sort(char *s){
    int A[128];
    int i = 0;
    while (s[i] != '\0'){
        A[i] = (int)s[i];
        //printf("%d\n", A[i]);
        i++;
    }
    int size = i;
    i = 0;
    for (i = 0; i < size - 1; i++){
        for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
        {
            if (A[j - 1] > A[j]) // если текущий элемент меньше предыдущего
            {
                int temp = A[j - 1]; // меняем их местами
                A[j - 1] = A[j];
                A[j] = temp;
            }
        }
    }
    for (i = 0; i < size - 1; i++){
        printf("%d\n", A[i]);
    }
}

int main()
{
    
    char s[128];
    char res[128] = ""; 

    input(s);
    change(s, res);
    
    output(res);
    ascii_sort(s);
    return 0;
}