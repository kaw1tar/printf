#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if usigned value
 *
 * @plus_flag: on if plus flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @with: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modofier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign          : 1;

	unsigned int plus_flag       : 1;
	unsigned int space_flage     : 1;
	unsigned int hashtag_flag    : 1;
	unsigned int zero_flag       : 1;
	unsigned int minus_flag      : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier      : 1;
	unsigned int l_modifier      : 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list op, params_t *params);
int print_int(va_list op, params_t *params);
int print_string(va_list op, params_t *params);
int print_percent(va_list op, params_t *params);
int print_S(va_list op, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list op, params_t *params);
int print_address(va_list op, params_t *params);

int (*get_specifier(char *s))(va_list op, params_t *params);
int get_print_func(char *s, va_list op, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list op);

int print_hex(va_list op, params_t *params);
int print_HEX(va_list op, params_t *params);
int print_binary(va_list op, params_t *params);
int print_octal(va_list op, params_t *params);

int print_from_to(char *start, char *stop, char *expect);
int print_rev(va_list op, params_t *params);
int print_rot13(va_list op, params_t *params);

int isdigit(int d);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

void init_params(params_t, *params, va_list op);

char *get_precision(char *p, params_t *params, va_list op);

int _printf(const char *format, .)


int _printf(const char *format, ...);


#endif
