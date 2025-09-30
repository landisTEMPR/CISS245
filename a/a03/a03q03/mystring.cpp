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


void str_cpy(char x[], char y[])
{
    int i = 0;
    while (true)
    {
        x[i] = y[i];
        if (y[i] == '\0')
        {
            break;
        }
        ++i;
    }
}


int str_chr(char x[], char c)
{
    int i = 0;
    
    while (x[i] != '\0')
    {
        if(x[i] == c)
        {
            return i;
        }
        else
        {
        ++i;
        }
    }
    
    return -1;
}






