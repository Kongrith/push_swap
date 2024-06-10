/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomasat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:45:50 by kkomasat          #+#    #+#             */
/*   Updated: 2024/06/06 22:39:34 by khkomasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// functions from ctype.h
int ft_isalpha(int c);
int ft_isspace(int ch);

// functions from string.h
size_t ft_strlen(const char *s);
void *ft_memmove(void *dst, const void *src, size_t len);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_strchr(const char *s, int c);
bool ft_atoi(const char *str, long *num);

// custom functions from 42bangkok
char **ft_split(char const *s, char c);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif
