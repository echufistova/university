cmake_minimum_required(VERSION 3.12)
project(spl3 C)

set(CMAKE_C_STANDARD 99)

add_executable(spl3 main.c spl3.h get_next_line.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strsub.c libft/ft_strjoin.c
        libft/ft_bzero.c libft/ft_strcmp.c libft/ft_strlen.c
        libft/ft_strdup.c)