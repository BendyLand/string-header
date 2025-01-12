#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string
{
    char* data;
    size_t size;
    size_t capacity;
} string;

void print_string_details(string* str);
string* str(const char* text);
void str_free(string* str);
void str_append(string** str, const char* text);
string* str_copy(string* s);
string* str_copy_from(string* s, size_t start);
string* str_copy_to(string* s, size_t end);
string* substr(string* s, size_t start, size_t end);
