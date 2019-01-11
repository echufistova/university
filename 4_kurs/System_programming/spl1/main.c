#include <stdio.h>
//знайти ті слова, які у тексті з'являються найбільшу кількість раз
//обмеження на довжину слова - 30 літер
//слова перемежовуються проміжками, дужками, кодами операцій, символами, що природньо розділяють слова

//
#include "libft/libft.h"
#include "get_next_line.h"
#include "spl1.h"

char *if_opchar (char *str)
{
    if (str[0] == '\'')
        return (ft_strsub(str, 1, strlen(str) - 1));
    if (str[strlen(str) - 1] == '\'')
        return (ft_strsub(str, 0, strlen(str) - 1));
    return(str);
}

t_dictionary *add_word(t_dictionary *dict, char *split_str, int *i)
{
    int j;
    char *search_content;

    j = 0;

    if (split_str != NULL)
    {
        search_content = strdup(split_str);
        while (j < (*i))
        {
            if (strcmp(search_content, dict[j].content) == 0)
            {
                    dict[j].times++;
                    return (dict);
            }
            j++;
        }
        dict[*i].content = strdup(if_opchar(split_str));
        dict[*i].times = 1;
        (*i)++;
    }
    return (dict);
}

t_dictionary *sort_dict(t_dictionary *dict, int k)
{
    int i;
    int j;
    int l;
    char *str;

    i = 0;
    while (i < k)
    {
        j = 0;
        while (j < k)
        {
            if (dict[j].times > dict[j + 1].times)
            {
                l = dict[j].times;
                dict[j].times = dict[j + 1].times;
                dict[j + 1].times = l;

                str = strdup(dict[j].content);
                bzero(dict[j].content, strlen(dict[j].content));
                dict[j].content = strdup(dict[j + 1].content);
                bzero(dict[j + 1].content, strlen(dict[j + 1].content));
                dict[j + 1].content = strdup(str);
                bzero(str, strlen(str));
            }
            j++;
        }
        i++;
    }
    return (dict);
}

char *to_lower(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        i++;
    }
    return (str);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int fd;
    char *line;
    char *delim;
    char *split_str;
    t_dictionary *dict;
    FILE *result;

    i = 0;
    dict = (t_dictionary*)malloc(sizeof(t_dictionary) * 10000);
    delim =  "\"\\/1234567890!@#№$;%^:&?*()-=_+{}[]<>,. \n\t\v\r\f";
    fd = open("/home/echufy/CLionProjects/spl1/text", O_RDONLY);\
    while (get_next_line(fd, &line) > 0 )
    {
        line = strdup(to_lower(line));
        split_str = strtok(line, delim);
        while (split_str != NULL)
        {
            dict = add_word(dict, split_str, &i);
            split_str = strtok (NULL, delim);
        }
        bzero(line, strlen(line));
    }
    dict = sort_dict(dict, --i);
    j = i - ft_atoi(av[1]);
    result = fopen("/home/echufy/CLionProjects/spl1/result1.txt", "w");
    while (i > j)
    {
        fprintf(result, "%s - %d\n", dict[i].content, dict[i].times);
        i--;
    }
    return 0;
}