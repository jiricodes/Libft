# Libft

Project given by Hive Helsinki.

>**Final Grade 100/100**
>
>**Bonus Grade  22/25**

Currently includes also files of get_next_line and ft_printf projects.

The goal of this project was to create our own library containing
useful functions which should be then reused through the first year of 42 curriculum.

Only allowed libc functions were `malloc(3)`, `free(3)` and `write(2)`

## Installation

Library creation

>`git clone https://github.com/forfungg/Libft.git; cd Libft; make`

## Notes
pf refactoring:
31.7.2021 - 2.25% of original speed

So it turns out that increasing implementation complexity helps a lot if not usign optimizations flags. However the story is different once we enable O2 or O3, which turns the tides and makes the complex code slower - guessing the complexity obfuscates the possible compiler optimizations.


# Structure
## libc
## noopt
These implementations are significantly faster compared to the naive implementations found it other folders (e.g. [`ft_memset`](src/libc/ft_memset.c) is 30x times slower than `ft_memset_noopt`). However these implementations are generally slower if compiled with optimization flags, since they obfuscate their functionality to the compiler more. (e.g `ft_memset_noopt` is 2x slower than `ft_memset` when compiled with `-O2`).