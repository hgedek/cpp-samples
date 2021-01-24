#include <stdio.h>
#include <stdarg.h>

void print(const char* format, ...) {
    
    va_list args;

    va_start(args, format);

    while(*format != '\0') {

        if (*format == 'd'){
            int val = va_arg(args, int);
            printf("%d\n", val);
        } else if (*format == 'c') {
            char c = (char)va_arg(args, int);
            printf("%c\n", c);
        } else {
            double f = va_arg(args, double);
            printf("%f\n", f);
        }

        format++;
    }

    va_end(args);
}

int main() {
    print("dcff", 3, 'a', 1.2, 4.4);
}
