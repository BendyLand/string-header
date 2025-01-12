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

string* str(const char* text) 
{
    string* result = (string*)malloc(sizeof(string));
    if (!result) {
        fprintf(stderr, "Unable to allocate memory for string struct.\n");
        exit(1);
    }
    size_t size = strlen(text);
    size_t capacity = size * 2;
    result->data = (char*)malloc(capacity+1);
    strncpy(result->data, text, capacity+1);
    if (!result->data) {
        fprintf(stderr, "Unable to copy text into string struct.\n");
        exit(1);
    }
    result->size = size;
    result->capacity = capacity;
    return result;
}

void str_free(string* str)
{
    if (str) {
        free(str->data);
        free(str);
    }
}

void str_append(string** str, const char* text) 
{
    size_t text_len = strlen(text);
    size_t data_len = (*str)->size;
    if (text_len + data_len < (*str)->capacity) {
        strncat((*str)->data, text, data_len);
        (*str)->size = text_len + data_len;
        (*str)->capacity = (text_len + data_len) * 2 ;
    }
    else {
        char* temp = realloc((*str)->data, text_len + data_len);
        if (!temp) {
            fprintf(stderr, "Reallocation failed for str_append.\n");
            exit(1);
        }
        strncat(temp, text, data_len + text_len);
        (*str)->size = text_len + data_len;
        (*str)->data = temp;
        (*str)->capacity = (text_len + data_len) * 2 ;
    }
}

