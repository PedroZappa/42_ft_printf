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
    <a href="#usage">Usage</a> ~
    <a href="#implementation">Implementation</a> ~
    <a href="#license">License</a> ~
</p>
<div/>

___

<div align="left">

# About :pushpin:

</div>

<div align=center>

> Because `ft_putnbr()` and `ft_putstr()` aren't enough!

<div align="left">

This project is an exploration into how `printf()` works. The objective is to write a library that mimics the behaviour of `printf()`. A re-code challenge with the aiming of revealing how `variadic functions` work in C. This project is a exercise on how to build a well-planned, well-structured extensible code base.

</div>

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

To accomplish this, the implementation is limited to the use of [libft](https://github.com/PedroZappa/libft) and the following standard functions:

<div>
    <detail>
        <summary>malloc()</summary>
        <p>Allocated `size` bytes of memory and returns a pointer to the allocated memory. The memory is not initialized. </p>
    </detail>
    <detail>
        <summary>free()</summary>
        <p>Deallocates the memory previously allocated by `malloc()`.</p>
    </detail>
    <detail>
        <summary>write()</summary>
            ```c
                ssize_t write(int fd, const void *_buf_, size_t _nbyte_);
            ```
        <p>Writes `nbytes` from the buffer pointer to by `buff` associated with the open file descriptor.</p>
</div>

- va_start();
- va_arg();
- va_copy();
- va_end();

## Requirements :exclamation:

- Do NOT implement the buffer management of the original `printf()`;
- The function has to handle the following conversions (format specifiers):

    > `%c` → `character`;

    > `%s` → `char *` (String of Characters);

    > `%p` → `void *` (Pointer Address);
    
    > `%d` → `signed decimal integer`;
    
    > `%i` → `signed decimal integer`;
        
    > `%u` → `unsigned decimal int`;
    
    > `%x` → `unsigned hexadecimal int` (lowercase);
    
    > `%X` → `unsigned hexadecimal int` (uppercase);

    > `%%` → `% Character`;


</div>




___

### License

This work is published under the terms of <a href="https://github.com/PedroZappa/libft/blob/master/LICENSE">42 Unlicense</a>.

<p align="right">(<a href="#readme-top">get to top</a>)</p>
