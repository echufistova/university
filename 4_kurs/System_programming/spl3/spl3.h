//
// Created by echufy on 26.10.18.
//

#ifndef SPL3_SPL3_H
#define SPL3_SPL3_H

#include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct  s_zminna
{
    char            *typ;
    char            *nazva;
    struct s_zminna *next;
}               t_zminna;

#endif //SPL3_SPL3_H
