#include "str.h"

void print_string_details(string* str)
{
    if (!str) {
        fprintf(stderr, "String is NULL.\n\n");
        return;
    }
    printf("    Data: %s\n", str->data);
    printf("    Size: %zu\n", str->size);
    printf("Capacity: %zu\n", str->capacity);
    puts("");
}

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
        str->data = NULL;
        free(str);
    }
}

void str_append(string** str, const char* text) 
{
    size_t text_len = strlen(text);
    size_t data_len = (*str)->size;
    if (text_len + data_len + 1 > (*str)->capacity) {
        size_t new_capacity = (text_len + data_len) * 2;
        char* temp = realloc((*str)->data, new_capacity);
        if (!temp) {
            fprintf(stderr, "Reallocation failed for str_append.\n");
            exit(1);
        }
        (*str)->data = temp;
        (*str)->capacity = new_capacity;
    }
    strncat((*str)->data, text, text_len);
    (*str)->size = data_len + text_len;
}

string* str_copy(string* s)
{
    return str(s->data);
}

string* str_copy_from(string* s, size_t start)
{
    if (!s || start >= s->size) {
        fprintf(stderr, "Invalid start index for string copy.\n");
        exit(1);
    }
    return str(s->data + start);
}

string* str_copy_to(string* s, size_t end)
{
    if (!s || end >= s->size) {
        fprintf(stderr, "Invalid end index for string copy.\n");
        exit(1);
    }
    string* result = str(s->data);
    result->data[end] = '\0';
    result->size = end - 1;
    result->capacity = (end - 1) * 2;
    return result;
}

string* substr(string* s, size_t start, size_t end)
{
    if (start >= end || end >= s->size) {
        fprintf(stderr, "Invalid substring range.\n");
        exit(1);
    }
    string* result = str_copy_from(s, start);
    str_free(s);
    result->data[end-start-1] = '\0';
    size_t new_size = end - start - 1;
    result->size = new_size;
    result->capacity = new_size * 2;
    return result;
}
