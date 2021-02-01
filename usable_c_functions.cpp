#define __STDC_WANT_LIB_EXT1__ 1
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// in c++ using T arr[] is not a good thing but 
// const char* or const T arr[] => static data block and constant so safe
void test_memset() {

    char text[] = "sample text";
    puts(text);
    memset(text, '!', 4);
    puts(text);
}

/*
void test_memset_s() {
    char text[] = "sample text";
    puts(text);

    memset_s(text, sizeof(text), '!', 4);
    puts(text);
}
*/

void test_memcmp() {
    const char* str1 = "sample";
    const char* str2 = "text";

    auto result = memcmp(str1, str2, std::min(strlen(str1), strlen(str2)));

    result == 0 ? puts("same") : result > 0 ? puts("high") : puts("low");
}

int main() {
    test_memset();
   // test_memset_s();
    test_memcmp();
}
