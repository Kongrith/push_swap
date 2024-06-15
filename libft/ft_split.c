/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:44:45 by kkomasat          #+#    #+#             */
/*   Updated: 2024/06/15 14:40:36 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	ft_split
 *	string:		"Hello,World,Split,Me"
 *	delimeter:	','
 *	return:		["Hello", "World", "Split", "Me", NULL]
 */

#include "libft.h"

static size_t	count_char_section(char *ptr, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(ptr + i) != '\0')
	{
		if (*(ptr + i) != c)
		{
			while ((*(ptr + i) != c) && (*(ptr + i) != '\0'))
				++i;
			++count;
		}
		else
			++i;
	}
	return (count);
}

static char	*find_chr_or_delimiter(char *ptr, char c, int string_flag)
{
	size_t	i;

	i = 0;
	while (ptr[i] != '\0')
	{
		if (string_flag == 1)
		{
			if (ptr[i] != c)
				return (ptr + i);
		}
		else
		{
			if (ptr[i] == c)
				return (ptr + i);
		}
		++i;
	}
	return (0);
}

static char	*split_string(char *s, char c)
{
	char	*string;
	char	*ptr;
	size_t	len;

	ptr = s;
	len = 0;
	while ((ptr[len] != c) && (ptr[len] != '\0'))
		++len;
	string = malloc(sizeof(char) * (len + 1));
	if (!string)
	{
		free(string);
		return (NULL);
	}
	ft_strlcpy(string, s, len + 1);
	return (string);
}

static void	split_to_str_arr(char **string_array, char *ptr,
	char c, size_t num_split)
{
	size_t	i;

	i = 0;
	while (i < num_split)
	{
		if (ptr[0] == c)
			ptr = find_chr_or_delimiter(ptr, c, 1);
		string_array[i] = split_string(ptr, c);
		ptr = find_chr_or_delimiter(ptr, c, 0);
		++i;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**string_array;
	char	*ptr;
	size_t	num_split;

	if (!s || !*s)
	{
		string_array = malloc(sizeof(char *) * 1);
		if (!string_array)
			return (NULL);
		*string_array = (void *)0;
		return (string_array);
	}
	ptr = (char *)s;
	num_split = count_char_section(ptr, c);
	string_array = (char **)malloc(sizeof(char *) * (num_split + 1));
	if (!string_array)
	{
		free(string_array);
		return (NULL);
	}
	string_array[num_split] = NULL;
	split_to_str_arr(string_array, ptr, c, num_split);
	return (string_array);
}

// int main()
// {

// 	// char *s1 = "split  ||this|for|me|||||!|";
// 	// char **expected = (char *[6]){"split  ", "this", "for", "me", "!", NULL};

// 	char *s1 = "Hello,World,Split,Me";
// 	char **expected = (char *[5]){"Hello", "World", "Split", "Me", NULL};
// 	char delimiter = ',';
// 	char **pointer_arrays;
// 	printf("original: %s\n", s1);
// 	for (int i = 0; i < 5; i++)
// 		printf("[%d] %s\n", i, expected[i]);
// 	printf("\n");

// 	pointer_arrays = ft_split(s1, delimiter);
// 	for (int i = 0; i < 5; i++)
// 		printf("[%d] %s\n", i, pointer_arrays[i]);
// 	// printf("ft_split: %s\n", ft_split(s1, delimiter)[0]);
// }
