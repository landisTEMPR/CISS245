// File : mystring.cpp
// Author : Brysen Landis

#include "mystring.h"

int str_len(char x[])
{
    int len = 0;
    while (x[len] != '\0')
    {
        ++len;
    }

    return len;
}


void str_cat(char x[], char y[])
{
    int xlen = str_len(x);
    int ylen = str_len(y);

    for (int i = 0; i <= ylen; ++i)
    {
        x[xlen + i] = y[i];
    }

    return;
}

int str_cmp(char x[], char y[])
{
    for (int i = 0;; ++i)
    {
        if(x[i] != y[i])
        {
            return 1;
        }
        if(x[i] == '\0')
        {
            return 0;
        }
    }
}



