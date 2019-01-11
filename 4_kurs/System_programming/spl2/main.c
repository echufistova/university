
#include "spl2.h"

int is_alphabet(char c, int kvo_bukv)
{
    int i;
    char *alphabet;

    i = 0;
    alphabet = "abcdefABCDEF";
    while (alphabet[i] != '\0' && i < kvo_bukv)
    {
        if (c == alphabet[i])
            return (1);
        i++;
    }
    return (0);
}

int is_konec(char **konec, int c)
{
    int i;

    i = 0;
    while (konec[i] != '\0')
    {
        if (konec[i][0] == c + 48)
            return (1);
        i++;
    }
    return (0);
}

t_link *edge_poch(t_link *links, int poch, int kolvo)
{
    int i;
    int j;
    t_link *ret;

    i = 0;
    j = 0;
    ret = (t_link*)malloc(sizeof(t_link) * 30);
    while (j < kolvo)
    {
        if (poch == links[j].poch)
        {
            ret[i].poch = links[j].poch;
            ret[i].stan = links[j].stan;
            ret[i].kinc = links[j].kinc;
            i++;
        }
        j++;
    }
    return (ret);
}

int count_edge(t_link *links, int poch, int kolvo)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (j < kolvo)
    {
        if (poch == links[j].poch)
            i++;
        j++;
    }
    return (i);
}

int checkword(char *wordToFind, int poch, int kstlinks, t_link *links, int kvo_bukv, char **konec, int counter, char *currentWord, int findLetter)
{
    char c;
    int j = 0;
    int l = 0;
    int k = 0;
    int counter2;
    int findLetter2;
    t_link *currentStateTops = edge_poch(links, poch, kstlinks);

    if (counter == strlen(wordToFind) && is_konec(konec, poch) && strlen(currentWord) > strlen(wordToFind) + 1)
        return (1);
    if (counter < strlen(wordToFind) && !is_alphabet(wordToFind[counter], kvo_bukv))
        return (0);
    while (currentWord[j] != '\0')
    {
        l = j;
        c = wordToFind[j];
        while (currentWord[l + 1] == c && k < 25)
        {
            l++;
            k++;
        }
        if (k >= 25)
            return (0);
        j++;
    }
    for (int i = 0; i < count_edge(links, poch, kstlinks); i++)
    {
        counter2 = counter;
        findLetter2 = findLetter;
        if (strlen(currentWord) > 1 && counter < strlen(wordToFind) && wordToFind[counter] == currentWord[strlen(currentWord) - 1])
        {
            counter2++;
            findLetter2 = 1;
        }
        else
            findLetter2 = 0;
        if (!findLetter2 && counter < strlen(wordToFind))
            counter2 = 0;
        if (checkword(wordToFind, currentStateTops[i].kinc, kstlinks, links, kvo_bukv, konec, counter2, ft_strjoin(currentWord, &currentStateTops[i].stan), findLetter2))
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int i = 0;
    int fd = open("/home/echufy/CLionProjects/spl2/input2", O_RDONLY);;
    int kvo_bukv = 0;
    int findLetter = 0;
    int poch = 0;
    int counter2 = 0;
    int k = 0;
    char *w0 =  av[1];
    char **konec;
    char **str_split;
    char *line;
    char *currentWord = "";
    t_link *link;


    printf("У слові w = w1w0w2 шукаємо w0. Введіть будь ласка w0 : %s \n", av[1]);

    link = (t_link*)malloc(sizeof(t_link) * 100);
    while (i < 4 && get_next_line(fd, &line) > 0)
    {
        if (i == 0)
            kvo_bukv = ft_atoi(line);
        else if (i == 2)
            poch = ft_atoi(line);
        else if (i == 3)
            konec = ft_strsplit(line, ' ');
        i++;
        free(line);
    }
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        str_split = ft_strsplit(line, ' ');
        link[i].poch = ft_atoi(str_split[0]);
        link[i].stan = str_split[1][0];
        link[i].kinc = ft_atoi(str_split[2]);
        ft_strdel(str_split);
        ft_strdel(&line);
        i++;
    }
    if (checkword(w0, poch, i, link, kvo_bukv, konec, counter2, currentWord, findLetter))
        printf("Таке слово знайдено :)");
    else
        printf("Таке слово не вдалося знайти :(");
    return 0;
}