/*
 * pprintformat.c
 *
 *  Created on: 2019年9月6日
 *      Author: wangshupeng
 */

#include"types/stdarg.h"
#include"common/macro.h"
#include"types/stdint.h"
#include "platform/macuart.h"
#define kernel_putchar uart_send

static unsigned long udivide(unsigned long N,unsigned long  D){
	unsigned long x,y;
	unsigned long ret=0;
	while(N>=D){
	        x=D;
	        y=1;
	        while(N>=(x<<1)){
	            x<<=1;
	            y<<=1;
	        }
	        N-=x;
	        ret+=y;
	    }
	    return ret;
}

void
putchar(char c)
{
	uart_send(c);
    if (c == '\n') {
    	uart_send('\r');
    }
}

static unsigned int
print_spaces(int n)
{
    for (int i = 0; i < n; i++) {
        kernel_putchar(' ');
    }

    return n;
}

static unsigned int
print_string(const char *s)
{
    unsigned int n;

    for (n = 0; *s; s++, n++) {
        kernel_putchar(*s);
    }

    return n;
}

static unsigned long
xdiv(unsigned long x, unsigned int denom)
{
    switch (denom) {
    case 16:
        return x >> 4; //x右移4位相当于x/16
    case 10:
        return udivide(x,10);
    default:
        return 0;
    }
}

static unsigned long
xmod(unsigned long x, unsigned int denom)
{
    switch (denom) {
    case 16:
        return x & 15;
    case 10:
        return x-udivide(x,10)*10; //只是一个简单的取余运算，
    default:
        return 0;
    }
}


//x = 1,ui_abse = 10;
static unsigned long
print_unsigned_long(unsigned long x, unsigned long ui_base)
{
    char out[sizeof(unsigned long) * 2 + 3]; //11
    unsigned long i, j;
    unsigned int d;

    /*
     * Only base 10 and 16 supported for now. We want to avoid invoking the
     * compiler's support libraries through doing arbitrary divisions.
     */
    if (ui_base != 10 && ui_base != 16) {
        return 0;
    }

    if (x == 0) {
        kernel_putchar('0'); //如果x = 0,直接输出0
        return 1;
    }

    for (i = 0; x; x = xdiv(x, ui_base), i++) {
        d = xmod(x, ui_base);

        if (d >= 10) {
            out[i] = 'a' + d - 10;
        } else {
            out[i] = '0' + d; //将要输出的语句保存在out中
        }
    }

    for (j = i; j > 0; j--) {
        kernel_putchar(out[j - 1]);
    }

    return i;
}

/* The print_unsigned_long_long function assumes that an unsinged int
   is half the size of an unsigned long long */

static unsigned int
print_unsigned_long_long(unsigned long long x, unsigned int ui_base)
{
    unsigned int upper, lower;
    unsigned int n = 0;
    unsigned int mask = 0xF0000000u;
    unsigned int shifts = 0;

    /* only implemented for hex, decimal is harder without 64 bit division */
    if (ui_base != 16) {
        return 0;
    }

    /* we can't do 64 bit division so break it up into two hex numbers */
    upper = (unsigned int) (x >> 32llu);
    lower = (unsigned int) x & 0xffffffff;

    /* print first 32 bits if they exist */
    if (upper > 0) {
        n += print_unsigned_long(upper, ui_base);
        /* print leading 0s */
        while (!(mask & lower)) {
            kernel_putchar('0');
            n++;
            mask = mask >> 4;
            shifts++;
            if (shifts == 8) {
                break;
            }
        }
    }
    /* print last 32 bits */
    n += print_unsigned_long(lower, ui_base);

    return n;
}

static inline bool
isdigit(char c) //判断字符是否是数字
{
    return c >= '0' &&
           c <= '9';
}

static inline int
atoi(char c) //将字符转换成实际的数字
{
    return c - '0';
}



static int
vprintf(const char *format, va_list ap)
{
    unsigned int n;
    unsigned int formatting; //flag标识
    int nspaces = 0;

    if (!format) { //如果要输出的字符串为空
        return 0; //直接返回
    }

    n = 0;
    formatting = 0;
    while (*format) {
        if (formatting) {
            while (isdigit(*format)) { //如果当前字符是数字的话，
                nspaces = nspaces * 10 + atoi(*format); //nspaces保存的是转换后的数字
                format++;
                if (format == NULL) {
                    break;
                }
            }
            //如果不是数字的话，条件分支判断
            switch (*format) {
            case '%':  //如果是字符%的话，直接将字符输出
                kernel_putchar('%');
                n++;
                format++;
                break;

            case 'd': {
                int x = va_arg(ap, int);  //使用va_start获取可变参数列表的第一个参数，使用va_arg依次获取可变参数列表的后面的参数

                if (x < 0) {
                    kernel_putchar('-');
                    n++;
                    x = -x;
                }

                n  = n +print_unsigned_long(x, 10);
                format++;
                break;
            }

            case 'u':
                n += print_unsigned_long(va_arg(ap, unsigned int), 10);
                format++;
                break;

            case 'x':
                n += print_unsigned_long(va_arg(ap, unsigned int), 16);
                format++;
                break;

            case 'p': {
                unsigned long p = va_arg(ap, unsigned long);
                if (p == 0) {
                    n += print_string("(nil)");
                } else {
                    n += print_string("0x");
                    n += print_unsigned_long(p, 16);
                }
                format++;
                break;
            }

            case 's':
                n += print_string(va_arg(ap, char *));
                format++;
                break;

            case 'l':
                format++;
                switch (*format) {
                case 'd': {
                    long x = va_arg(ap, long);

                    if (x < 0) {
                        kernel_putchar('-');
                        n++;
                        x = -x;
                    }

                    n += print_unsigned_long((unsigned long)x, 10);
                    format++;
                }
                break;
                case 'l':
                    if (*(format + 1) == 'x') {
                        n += print_unsigned_long_long(va_arg(ap, unsigned long long), 16);
                    }
                    format += 2;
                    break;
                case 'u':
                    n += print_unsigned_long(va_arg(ap, unsigned long), 10);
                    format++;
                    break;
                case 'x':
                    n += print_unsigned_long(va_arg(ap, unsigned long), 16);
                    format++;
                    break;

                default:
                    /* format not supported */
                    return -1;
                }
                break;
            default:
                /* format not supported */
                return -1;
            }

            n += print_spaces(nspaces - n);
            nspaces = 0;
            formatting = 0;
        } else {
            switch (*format) {
            case '%':
                formatting = 1; //遇到%,formatting = 1;
                format++;
                break;
            default:
                kernel_putchar(*format);  //串口输出字符，回车表示一段输出的结束，换行将输出打到下一个行
                n++; //每输出一次，将n加加
                format++; //将format指向字符串的下一个字符
                break;
            }
        }
    }
    return n;
}

int kprintf(const char *format, ...)
{
    va_list args; //在函数里定义一个va_list型的变量，这个变量是指向参数的指针
    unsigned long i;
    va_start(args, format); //va_start：用va_start宏初始化刚定义的va_list变量,让它指向可变参数表里面的第一个参数,
    i = vprintf(format, args);
    va_end(args);  //获取所有的参数之后，将这个指针关掉，以免发生危险，将指针置为 NULL
    return i;
}
