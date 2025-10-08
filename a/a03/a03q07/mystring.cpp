// File : mystring.cpp
// Author : Brysen Landis

#include <iostream>
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
        if(x[i] != y[i]) { return 1; }
        if(x[i] == '\0') { return 0; }
    }
}


void str_cpy(char x[], char y[])
{
    int i = 0;
    while (true)
    {
        x[i] = y[i];
        if (y[i] == '\0') { break; }
        ++i;
    }
}


int str_chr(char x[], char c)
{
    int i = 0;
    
    while (x[i] != '\0')
    {
        if(x[i] == c) { return i; }
        else { ++i; }
    }
    
    return -1;
}


int str_str(char x[], char y[])
{
    if (y[0] == '\0') { return 0; }
    for (int i = 0; x [i] != '\0'; ++i)
    {
        int j = 0;
        while (x[i + j] == y[j] && y[j] != '\0')
        {
            ++j;
        }
            
        if (y[j] == '\0') { return i; }
    }
    return -1;
}


void str_lower(char x[], char y[])
{
    int i = 0;
    while (y[i] != '\0')
    {
        x[i] = y[i]; 
        if ('A' <= x[i] && x[i] <= 'Z')
        {
            x[i] = x[i] - 'A' + 'a';
        }
        ++i;
    }
    x[i] = '\0';
    
    return;
}


bool str_tok(char x[], char y[], char delimiters[])
{
    if (y[0] == '\0')
    {
        x[0] = '\0';
        return false;
    }
    
    int min_index = -1;
    
    for (int i = 0; i < str_len(delimiters); ++i)
    {
        int index = str_chr(y, delimiters[i]);
        if (index != -1)
        {
            if (min_index == -1 || index < min_index)
            {
                min_index = index;
            }
        }
    }
    
    if (min_index == -1)
    {
        str_cpy(x, y);
        y[0] = '\0';
        return true;
    }
    
    int i;
    for (i = 0; i < min_index; ++i)
    {
        x[i] = y[i];
    }
    x[i] = '\0';
    
    int j = 0;
    for (i = min_index + 1; i <= str_len(y); ++i)
    {
        y[j] = y[i];
        ++j;
    }
    
    return true;
}


void str_cap(char x[])
{
    if (x[0] != '\0' && 'a' <= x[0] && x[0] <= 'z')
    {
        x[0] = x[0] - 'a' + 'A';
    }
}



void chat_bot(char input[], char name[], char done[])
{
    if (y[0] == '\0')
    {
        x[0] = '\0';
        return;
    }

    int min_index = -1;
    
    for (int i = 0; i < str_len(delimiters); ++i)
    {
        int index = str_chr(y, delimiters[i]);
        if (index != -1)
        {
            if (min_index == -1 || index < min_index)
            {
                min_index = index;
            }
        }
    }

    if (min_index == -1)
    {
        str_cpy(x, y);
        y[0] = '\0';
        return;
    }
    
    int i;
    for (i = 0; i < min_index; ++i)
    {
        x[i] = y[i];
    }
    x[i] = '\0';
    
    int j = 0;
    for (i = min_index + 1; i <= str_len(y); ++i)
    {
        y[j] = y[i];
        ++j;
    }
    
    return;
    
}

