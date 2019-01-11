//
// Created by echufy on 29.10.18.
//

#include "spl3.h"

t_zminna	*ft_lstnew(char *typ, char *nazva)
{
    t_zminna *res;

    if (!(res = (t_list*)malloc(sizeof(t_list))))
        return (NULL);
    if (typ == NULL)
        res->typ = NULL;
    else
    {
        if (!(res->typ = (char*)malloc(content_size)))
        {
            free(res);
            return (NULL);
        }
        res->content = ft_memcpy(res->content, content, content_size);
        res->content_size = content_size;
    }
    res->next = NULL;
    return (res);
}