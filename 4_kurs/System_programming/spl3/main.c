
#include "spl3.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int rozdilovi_znaky(char c)
{
    if (c == 44 || c == 46 || c == 58 || c == 59)
        return (1);
    return (0);
}

int symvolni_constanty(char c)
{
    if ((c >= 39 && c <= 43) || (c >= 60 && c <= 62) || c == 91 || c == 93 || c == 123 || c == 125)
        return (1);
    return (0);
}

int ce_nazva(unsigned int *i, char *line, t_zminna *zminni, int j)
{
    int k;
    unsigned int p;
    char *slovo;

    k = 0;
    p = *i;
    while (k < j)
    {
        if (line[*i] == zminni[k].nazva[0])
        {
            slovo = ft_strsub(line, *i, ft_strlen(zminni[k].nazva));
            if (ft_strcmp(slovo, zminni[k].nazva) == 0)
            {
                *i += ft_strlen(zminni[k].nazva);
                return (1);
            }
        }
        k++;
    }
    *i = p;
    return (0);
}

char *nazva_zminnoi(unsigned int i, char *line)
{
    unsigned int k;

    while (line[i + 1] == 32)
        (i)++;
    k = ++(i);
    if ((line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122)
           || line[i] == '$' || line[i] == '_')
    {
        while (line[i] != '\0' && ((line[i] >= 65 && line[i] <= 90)
    || (line[i] >= 97 && line[i] <= 122) || line[i] == '$' || line[i] == '_') && line[i] != ' ')
             (i)++;
        return (ft_strsub(line, k , i - k));
    }
    return (NULL);
}

int constanta(unsigned int *i, char *line, t_zminna **zminni, int j)
{
    char *subline;

    if (line[*i] == 'c')
    {
        subline = ft_strsub(line, *i, 5);
        if (ft_strcmp(subline, "const") == 0)
        {
            zminni[j]->typ = strdup(subline);
            (*i) += 5;
            zminni[j]->nazva = strdup(nazva_zminnoi(*i, line));
            ft_strdel(&subline);
            return (1);
        }
        ft_strdel(&subline);
    }
    else if (line[*i] == 'l')
    {
        subline = ft_strsub(line, *i, 3);
        if (ft_strcmp(subline, "let") == 0)
        {
            zminni[j]->typ = strdup(subline);
            (*i) += 3;
            zminni[j]->nazva = strdup(nazva_zminnoi(*i, line));
            ft_strdel(&subline);
            return (1);
        }
        ft_strdel(&subline);
    }
    else if (line[*i] == 'v')
    {
        subline = ft_strsub(line, *i, 3);
        if (ft_strcmp(subline, "var") == 0)
        {
            zminni[j]->typ = strdup(subline);
            (*i) += 3;
            zminni[j]->nazva = strdup(nazva_zminnoi(*i, line));
            ft_strdel(&subline);
            return (1);
        }
        ft_strdel(&subline);
    }
    else if (line[*i] == 'f')
    {
        subline = ft_strsub(line, *i, 8);
        if (ft_strcmp(subline, "function") == 0)
        {
            zminni[j]->typ = strdup(subline);
            (*i) += 8;
            zminni[j]->nazva = strdup(nazva_zminnoi(*i, line));
            ft_strdel(&subline);
            return (1);
        }
        ft_strdel(&subline);
    }
    return (0);
}

void what_word(char *line, t_zminna **zminni, int *j)
{
    unsigned int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (rozdilovi_znaky(line[i]))
            printf("%s%c%s", KCYN, line[i], RESET);
        else if (constanta(&i, line, zminni, *j))
        {
            i--;
            printf("%s%s%s", KMAG, (*zminni)->typ, RESET);
            (*j)++;
        }
        else if (ce_nazva(&i, line, *zminni, *j))
        {
            i--;
            printf("%s%s%s", KRED, (*zminni)->nazva, RESET);

        }
        else if (line[i] >= 48 && line[i] <= 57)
            printf("%s%c%s", KGRN, line[i], RESET);
        else if (symvolni_constanty(line[i]))
            printf("%s%c%s", KYEL, line[i], RESET);
        else
            putchar(line[i]);
        i++;
    }
}

int main()
{
    int fd;
    int j;
    int k;
    char *line;
    t_zminna *zminni;

    j = 0;
    k = 30;
    zminni = (t_zminna*)malloc(sizeof(t_zminna) * k);
    while (j < k)
    {
        zminni[j].typ = (char*)malloc(sizeof(char) * 100);
        zminni[j].nazva = (char*)malloc(sizeof(char) * 100);
        j++;
    }
    j = 0;
    fd = open("/home/echufy/CLionProjects/spl3/poopsLab2", O_RDONLY);
    line = ft_strnew(0);
    while (get_next_line(fd, &line) > 0)
    {
        what_word(line, &zminni, &j);
        printf("%c", '\n');
        ft_strdel(&line);
    }
    return 0;
}