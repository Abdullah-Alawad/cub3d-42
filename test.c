#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	total;
	char	*dest;

	i = 0;
	total = 0;
	if (!s1 || !set)
		return (NULL);
	total = strlen(s1);
	while (s1[i] && strchr(set, s1[i]))
	{
		i++;
	}
	while (total > i && strchr(set, s1[total - 1]))
	{
		total--;
	}
	dest = (char *)malloc((total - i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	memcpy(dest, s1 + i, total - i);
	dest[total - i] = '\0';
	return (dest);
}


static void 	is_beg_end_one(char *map)
{
    char *tmp;
    int len;

    tmp = ft_strtrim(map, " \n\t");
    len = strlen(tmp);
    if (tmp[0] != '1' || tmp[len - 1] != '1')
    {
        perror("unclosd map: beg_end");
        exit(1);
    }
    free(tmp);
}

int     main(void)
{
    char s[100] = "11110111 1110101 10111101000";
    is_beg_end_one(s);
    return (0);
}