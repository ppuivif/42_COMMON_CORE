#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int i;
	char *str;

	i = 0;
	if (!s)
		return (NULL);//return(0) because char * is expected. If int was expected 0 would be a value and no an ASCII value
	if (start > (unsigned int)ft_strlen(s))
		len = 0;	
	else if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (i < (unsigned int)len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = 0;
		return(str);
	}
	return (NULL);
}
