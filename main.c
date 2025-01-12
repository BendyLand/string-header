#include "str_header.h"

void print_string_details(string* str);

int main(void)
{
    string* test = str("this is a test");
    print_string_details(test);

    str_append(&test, ". And this is some more text!");
    print_string_details(test);

    str_free(test);
    print_string_details(test);

    return 0;
}

void print_string_details(string* str)
{
    printf("%s\n", str->data); 
    printf("%zu\n", str->size); 
    printf("%zu\n", str->capacity);
}
