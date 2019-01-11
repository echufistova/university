cmake_minimum_required(VERSION 3.12)
project(spl1 C)

set(CMAKE_C_STANDARD 99)

add_executable(spl1 main.c get_next_line.c libft/ft_strsub.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_swap.c
        libft/ft_tolower.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_memalloc.c libft/ft_strcpy.c libft/ft_bzero.c
        libft/ft_atoi.c spl1.h)