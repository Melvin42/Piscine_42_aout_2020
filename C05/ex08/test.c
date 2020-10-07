#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i] + 4);
        i++;
    }
}

int main(int ac, char **av)
{
    (void)ac;
    ft_putstr(av[1]);
    return 0;
}
