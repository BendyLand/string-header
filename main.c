#include "str_header.h"

int main(void)
{
    string* test = str("this is a test");
    print_string_details(test);

    str_append(&test, ". And some more text!");
    print_string_details(test);

    string* subtest = substr(test, 1, 7);
    print_string_details(subtest);

    str_free(subtest);
    print_string_details(subtest);
    print_string_details(test);

    return 0;
}
