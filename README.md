# FT_PRINTF

A custom implementation of printf in C, supporting the most common format specifiers.


## About

In C, there is no built-in way to print different types with a single function call - 
you would need a separate function for each type. ft_printf solves this by parsing a 
format string and dispatching each conversion specifier to a dedicated handler function.

It uses custom utility functions instead of the standard C library.


## Functions
### Internal functions
| Function | Description |
|----------|-------------|
| `ft_putchar` | Writes a single character to stdout |
| `ft_putstr` | Writes a string to stdout |
| `ft_putpointer` | Writes a pointer address in hexadecimal format with `0x` prefix |
| `ft_putnbr` | Writes a signed integer |
| `ft_putfloat` | Writes a floating point number |
| `ft_putunbr` | Writes an unsigned integer |
| `ft_putnbr_hmin` | Writes an unsigned integer in lowercase hexadecimal |
| `ft_putnbr_hmax` | Writes an unsigned integer in uppercase hexadecimal |
| `ft_conversions` | Matches the format specifier and calls the corresponding handler |

### Main function
| `ft_printf` | Parses the format string and returns the total number of characters written |


## Usage

```bash
git clone https://github.com/sarabezz/ft_printf.git
cd get_next_line
```

Include the header in your file:

```c
#include "ft_printf.h"
```

Compile it with your project:

```bash
gcc -Wall -Wextra -Werror ft_printf.c __my_srcs/*.c your_file.c -o your_program
```


## Key concepts

- `va_list` and variadic functions — ft_printf accepts any number of arguments using `...`
- Format string parsing — iterates character by character, detecting `%` to identify conversions
- Conversion dispatching — each specifier (`%s`, `%d`, `%x`...) maps to a dedicated handler
- Custom output functions — all writing is done without the standard C library


## Project info 

| | |
|---|---|
| Language | C |
| School | 42 Madrid |
| Status | ✅ Completed |
