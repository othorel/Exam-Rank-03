/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:06:22 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/30 16:06:25 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (ft_putstr("(null)"));
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_putnbr(long nb)
{
    int i;

    i = 0;
    if (nb < 0)
    {
        i = i + ft_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        i = i + ft_putnbr(nb / 10);
    i = i + ft_putchar(nb % 10 + 48);
    return (i);
}

int ft_puthexa(unsigned int nb)
{
    int i;
    char *hexa = "0123456789abcdef";

    i = 0;
    if (nb > 15)
        i = i + ft_puthexa(nb / 16);
    i = i + ft_putchar(hexa[nb % 16]);
    return (i);
}

int	ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    int     len;

    i = 0;
    len = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            if (format[i] == 's')
                len = len + ft_putstr(va_arg(args, char *));
            else if (format[i] == 'd')
                len = len + ft_putnbr(va_arg(args, int));
            else if (format[i] == 'x')
                len = len + ft_puthexa(va_arg(args, unsigned int));
            else if (format[i] == '%')
                len = len + ft_putchar('%');
            else
                len = len + ft_putchar(format[i]);
        }
        else
            len = len + ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (len);
}

// #include <stdio.h>

// int	main(void)
// {
//     int count1, count2;

//     // Test 1 : Affichage d'une chaîne simple
//     count1 = ft_printf("Test 1: %s\n", "Hello, world!");
//     count2 = printf("Test 1: %s\n", "Hello, world!");
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     // Test 2 : Affichage d'un nombre entier
//     count1 = ft_printf("Test 2: %d\n", 42);
//     count2 = printf("Test 2: %d\n", 42);
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     // Test 3 : Affichage d'un nombre négatif
//     count1 = ft_printf("Test 3: %d\n", -1234);
//     count2 = printf("Test 3: %d\n", -1234);
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     // Test 4 : Affichage en hexadécimal
//     count1 = ft_printf("Test 4: %x\n", 255);
//     count2 = printf("Test 4: %x\n", 255);
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     // Test 5 : Affichage d'un mix (string, int, hex)
//     count1 = ft_printf("Test 5: Magic %s is %d and hex is %x\n", "number", 42, 42);
//     count2 = printf("Test 5: Magic %s is %d and hex is %x\n", "number", 42, 42);
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     // Test 6 : NULL string
//     count1 = ft_printf("Test 6: %s\n", (char *)NULL);
//     count2 = printf("Test 6: %s\n", (char *)NULL);
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     // Test 7 : Affichage du caractère '%'
//     count1 = ft_printf("Test 7: 100%% done!\n");
//     count2 = printf("Test 7: 100%% done!\n");
//     printf("ft_printf => %d chars | printf => %d chars\n\n", count1, count2);

//     return (0);
// }