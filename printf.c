#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * format_checker - custom printf function
 * @c: format string
 * @ap: list
 * Return: number of characters printed
 */
void format_checker(char c, va_list ap)
{
    if (c == 'c')
    {
        char ch = va_arg(ap, int);
        write(1, &ch, 1);
    }
    else if (c == 's')
    {
        char *str = va_arg(ap, char*);
        str_print(str);
    }
    else if (c == '%')
    {
        write(1, "%", 1);
    }
    else if (c == 'd' || c == 'i')
    {
        int num = va_arg(ap, int);
        d_i(num);
    }
    else if (c == 'b')
    {
        int num = va_arg(ap, int);
        b_print(num);
    }
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, format);
    if (!format[i])
        return (-1);

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            write(1, format + i, 1);
            i++;
        }
        else
        {
            i++;
            format_checker(format[i], ap);
            i++;
        }
    }

    va_end(ap);
    return (i);
}
