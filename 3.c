#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct reader {
    char name[15];
    int number;
    char book[15];
    int period;
};
typedef struct reader reader;

void newrec(reader *X){
    printf("Введите фамилию: ");
    scanf("%s", X->name);
    printf("Введите номер билета: ");
    scanf("%d", &X->number);
    printf("Введите название книги: ");
    scanf("%s", X->book);
    printf("Введите срок возврата: ");
    scanf("%d", &X->period);     
}
void fileout(reader *X, int i){
    FILE *file;
    file = fopen("struct.txt", "w");
    for (int j = 0; j <= i; j++){
        fprintf(file, "%s %d %s %d", X[j].name, X[j].number, X[j].book, X[j].period);
    }
    fclose(file);
}
int filein(reader *X){
    FILE *file;
    file = fopen("struct.txt", "r");
    int j = 0;
    while (fscanf(file, "%s%d%s%d", X[j].name, &X[j].number, X[j].book, &X[j].period) > 0){
        printf("%s\t%d\t%s\t%d\n", X[j].name, X[j].number, X[j].book, X[j].period);
        j++;
    }
    fclose(file);
    j--;
    return j;
}
void sort(reader *X, int i){
    int a;
    int A[10], B[10];
    printf("Сортировать по:\n1.сроку / 2.номеру билета\n");
    scanf("%d", &a);
    if (a == 1){
        for(int j = 0; j <= i; j++){
            A[j] = X[j].period;
            B[j] = X[j].number;
        }
    }
    else{
        for(int j = 0; j <= i; j++){
            A[j] = X[j].number;
            B[j] = X[j].period;
        }
    }
    for (int j = 0; j < i; j++){  	
        for (int k = i; k > j; k--) 
        {
            if (A[k - 1] > A[k]) 
            {
                int temp1 = A[k - 1]; 
                A[k - 1] = A[k];
                A[k] = temp1;
                int temp2 = B[k-1];
                B[k - 1] = B[k];
                B[k] = temp2;
                char temp3[15];
                strcpy(temp3, X[k - 1].name);
                strcpy(X[k - 1].name, X[k].name);
                strcpy(X[k].name, temp3);
                char temp4[15];
                strcpy(temp4, X[k - 1].book);
                strcpy(X[k - 1].book, X[k].book);
                strcpy(X[k].book, temp4);
            }
        }
    }
    if (a == 1){
        for(int j = 0; j <= i; j++){
            X[j].period = A[j];
            X[j].number = B[j];
        }
    }
    else{
        for(int j = 0; j <= i; j++){
            X[j].number = A[j];
            X[j].period = B[j];
        }
    }
}
void screen(reader *X, int i){
    printf("Name\tNumber\tBook\tPeriod\n");
    for (int j = 0; j <= i; j++){
        printf("%s\t%d\t%s\t%d\n", X[j].name, X[j].number, X[j].book, X[j].period);
    }
}
void red(reader *X){
    int x, y;
    printf("Строка:\n");
    scanf("%d", &y);
    printf("Столбец:\n");
    scanf("%d", &x);
    y--;
    char str[15];
    printf("Введите новое значение:\n");
    switch (x){
    case 1:
        scanf("%s", X[y].name);
        break;
    case 2:
        scanf("%d", &X[y].number);
        break;
    case 3:
        scanf("%s", X[y].book);
        break;
    case 4:
        scanf("%d", &X[y].period);
        break;
    default:
        break;
    }
}
int del(reader *X, int i){
    int y;
    printf("Какую строку удалить:\n");
    scanf("%d", &y);
    y--;
    for (int j = 0; j <= i; j++){
        if (j >= y){
            strcpy(X[j].name, X[j+1].name);
            X[j].number = X[j+1].number;
            strcpy(X[j].book, X[j+1].book);
            X[j].period = X[j+1].period;
        }
    }
    i--;
    return i;
}

int main(){
    reader X[10];
    int i = 0; //количество записей
    int menu;

    while(1){
    printf("1.Добавить запись\n2.Записать в файл\n3.Прочитать из файла\n4.Сортировка\n5.Вывести на экран\n6.Редактировать\n7.Удалить\n");
    scanf("%d", &menu);
    switch(menu){
        case 1:
            i++;
            newrec(&X[i]);
            break;
        case 2:
            fileout(X, i);
            break;
        case 3:
            i = filein(X);
            break;
        case 4:
            sort(X, i);
            break;
        case 5:
            screen(X, i);
            break;
        case 6:
            red(X);
            break;
        case 7:
            i = del(X, i);
            break;
        default:
            return 0;
    }
    }
    return 0;
}
