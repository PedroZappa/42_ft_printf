<a name="readme-top"></a>
<div align="center">

# ft_printf

( a [42 School](https://github.com/42School) Project )

<p>
    <img src="https://img.shields.io/badge/score-...%20%2F%20100-success?style=for-the-badge" />
    <img src="https://img.shields.io/github/repo-size/PedroZappa/ft_printf?style=for-the-badge&logo=github">
    <img src="https://img.shields.io/github/languages/count/PedroZappa/ft_printf?style=for-the-badge&logo=" />
    <img src="https://img.shields.io/github/languages/top/PedroZappa/ft_printf?style=for-the-badge" />
    <img src="https://img.shields.io/github/last-commit/PedroZappa/ft_printf?style=for-the-badge" />
</p>

___

<h3>Table o'Contents</h3>
<p>
    ~
    <a href="#about-pushpin">About</a> ~
    <a href="#usage-scroll">Usage</a> ~
    <a href="#implementation-exclamation">Implementation</a> ~
    <a href="#structure-bar_chart">Structure</a> ~
    <a href="#license">License</a> ~
</p>
<div/>

___

<div align="left">

# About :pushpin:

</div>

<div align=center>

> Because `ft_putnbr()` and `ft_putstr()` aren't enough!

This project is an exploration into how `printf()` works. The objective is to write a library that mimics the behaviour of `printf()`. A re-code challenge with the aiming of revealing how `variadic functions` work in C. This project is a exercise on how to build a well-planned, well-structured extensible code base.

[ft_printf (Subject English)](/libft.en.subject.pdf)

___

<div align="left">

# Usage :checkered_flag:

</div>

____

<div align="left">

# Implementation :scroll:

In this project `printf()` is implemented with the following prototype:

```c
void	ft_printf(const char *format, ...);
```

## Constrains 

- To accomplish this, the implementation is limited to the use of [libft](https://github.com/PedroZappa/libft) (which makes it's performance slower than the standard `printf()`) and a restricted set of standard functions.

    > For **memory allocation** and **deallocation**: `malloc()` and `free()`; 
    >
    > To **write** into the allocated memory: `write()`;
    >
    > To support **variadic functionality**: `va_start()`, `va_arg()`, `va_copy()`, `va_end()`;

- `ft_printf()` doesn't handle overflows and unexpected inputs the same way the real `printf()` would.

## Mandatory Requirements:exclamation:

- Do NOT implement the buffer management of the original `printf()`;
- The function has to handle the following conversions (format specifiers):

    | Format | Meaning |
    |--------|---------|
    | `%c` | Prints a single `char`;
    | `%s` | Prints a string of characters (`char *`);
    | `%p` | Prints a Pointer Address in hexadecimal (`void *`);
    | `%d` | Prints a decimal (base 10) number;
    | `%i` | Prints an integer in base 10;
    | `%u` | Prints an unsigned decimal (base 10) number;
    | `%x` | Prints a number in hexadecimal (base 16) lowercase format;
    | `%X` | Prints a number in hexadecimal (base 16) uppercase format;
    | `%%` | Prints a `%` character;

- Format specifiers obey the following prototype:

    ```c
    %[flags][width][.precision]specifier
    ```

- The function must behave like `printf()`;

- The library has to be built using the command `ar`;

## Bonus Requirements:poop:

- Handle any combination of the following **flags** and **minimum field width** under all conversions;

    |    Flag   | Description |
    |-----------|---------|
    |      `-`  | Left justify within given **field width** |
    |      `0`  | Left-pads the number with zeroes (0) where padding is specified |
    | `.`       | Precison |

    | .precision | Description |
    |-----------|---------|
    | `.number` | For integer specifiers (`%d`, `%i`, `%u`, `%x`, `%X`) - specifies the minimum number of digits to be written. If the value to be written is shorter than this number the result is padded with leading zeroes. The value is not truncated even if the result is longer. A precision of 0 mean that no value is written for the value '0'; For `s`, this is the maximum numbers of characters to be printed. By default all characters are printed until the null terminator is found; |
    | `.*` | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted;

    |   Width    | Description |
    |------------|---------|
    | `(number)` | Minimum number of characters to be printed. If the value to be printed is shorter than this value, it is padded with blanks. The value is not truncated even if the result is larger |

- Plus the following flags (yes,one of them is a blank):

    | Flag | Description |
    |------|---------|
    | `#` | When used with `o`, `x` or `X` specifiers the value is prefixed with `0`, `0x` or `0X` respectively for values different than zero |
    | ` ` | If no sign is going to be written, print a space before the value |
    | `+` | Forces a plus or minus sign before printing the result |

## 

### Files & Folders

`ft_printf()`s library code base is split into the following file structure:

```mermaid
---
title ft_printf Structure
---
classDiagram
    class Makefile
    Makefile <-- File0
    class File0["ft_printf.h"]
    class libft["libft.h"]
    File0 <-- File1
    File0 <-- File2
    File0 <-- File3
    File0 <-- File4
    File0 <-- File5
    libft --> File0
    class File1["ft_printf.c"]
    File1 : ft_printf()
    File1 : ft_newformat()
    File1 : ft_print_specifier()
    class File2["ft_parse.c"]
    File2 : ft_parse()
    File2 : ft_parse_width()
    File2 : ft_parse_prec()
    File2 : ft_parse_bonus()
    class File3["ft_print_chars.c"]
    File3 : ft_print_char()
    File3 : ft_print_str()
    class File4["ft_print_nbrs.c"]
    File4 : ft_print_diu()
    File4 : ft_print_nbr()
    File4 : ft_plus()
    class File5["ft_print_hex.c"]
    File5 : ft_print_hex()
    File5 : ft_recur_hex()
    File5 : ft_print_ptr()
    File5 : ft_sharp()
```

___

### Processing Flow

The subprocesses of `ft_printf` are called in the following order:

```mermaid
---
title ft_printf Processing Flow
---
graph LR;
    ft_printf-->ft_parse;
    ft_parse-->ft_newformat;
    ft_parse-->ft_parse_width;
    ft_parse-->ft_parse_prec;
    ft_parse-->ft_parse_bonus;
    ft_parse-->ft_print_specifier;
    ft_print_specifier-->ft_print_char;
    ft_print_specifier-->ft_print_str;
    ft_print_specifier-->ft_print_diu;
    ft_print_specifier-->ft_print_hex;
    ft_print_specifier-->ft_print_ptr;
    ft_print_diu-->ft_print_nbr;
    ft_print_nbr-->ft_plus;
    ft_print_hex-->ft_print_recur_hex;
    ft_print_hex-->ft_print_sharp;
```

</div>

___

### License

This work is published under the terms of <a href="https://github.com/PedroZappa/ft_printf/blob/master/LICENSE">42 Unlicense</a>.

<p align="right">(<a href="#readme-top">get to top</a>)</p>
