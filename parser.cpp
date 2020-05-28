#include <stdio.h>
#include <iostream>
#include <cstring>
#include <malloc.h> 

void TrimRight( char *s )
{
 
    
    if (!*s) return; // нет строки (нулевой указатель)
    char* frs = s; // указатель на начало последней (самой правой) группы пробелов
    while (*s){
        if (*s != ' ')
            frs = s + 1; s++;}
    *frs = '\0';      // задаем новый конец строки
}

char *get_string( int *len ) 
{
    int size = 1000;
    *len = 0; // изначально строка пуста
    int capacity = 1; // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    char *s = (char*) malloc(size * sizeof(char)); // динамическая пустая строка

    char c = getchar(); // символ для чтения данных

    // читаем символы, пока не получим символ переноса строки (\n)
    while (c != '\n') {
        s[(*len)++] = c; // заносим в строку новый символ

        // если реальный размер больше размера контейнера, то увеличим его размер
        if (*len >= size) {
            capacity *= 2; // увеличиваем ёмкость строки в два раза
            s = (char*) realloc(s, capacity * sizeof(char)); // создаём новую строку с увеличенной ёмкостью  
        }
        c = getchar(); // считываем следующий символ          
    }
    s[*len] = '\0'; // завершаем строку символом конца строки
    return s; // возвращаем указатель на считанную строку
}

int main( void )
{
   int len;
   char *s = get_string(&len);
   TrimRight(s);
   return 1;
}
