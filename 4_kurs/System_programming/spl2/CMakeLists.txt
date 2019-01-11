cmake_minimum_required(VERSION 3.12)
project(spl2 C)

set(CMAKE_C_STANDARD 99)

add_executable(spl2 main.c get_next_line.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_atoi.c
        libft/ft_strsplit.c libft/ft_cw.c libft/ft_cl.c libft/ft_strlen.c libft/ft_strdel.c
        libft/ft_strnew.c libft/ft_bzero.c libft/ft_strcmp.c libft/ft_strsub.c spl2.h)