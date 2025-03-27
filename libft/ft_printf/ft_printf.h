/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:42:46 by nhendrik          #+#    #+#             */
/*   Updated: 2024/11/17 15:29:02 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>

int		ft_printptr(uintptr_t ptr);
int		ft_printchar(char c);
int		ft_printnbr(int n);
int		ft_printunbr(unsigned int n);
int		ft_printstr(const char *s);
int		ft_hexlen(unsigned int n);
int		ft_printhex(unsigned int n, char c);
int		ft_printf(const char *str, ...);

#endif