#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

int Randoms(int lower, int upper, int count)
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % 
           (upper - lower + 1)) + lower; 
        return(num);
    }
    return (0);
} 

int     main(int argc, char **argv)
{
    char **ops;
    char *str;

    ops = malloc(sizeof(char*) * 17);
    int i = 0;
    int nblines = atoi(argv[1]);

    ops[0] = strdup("add	r6,r6,r6\n");
    ops[1] = strdup("ld	%0,r10\n");
    ops[2] = strdup("zjmp %-360\n");
    ops[3] = strdup("live %633\n");
    ops[4] = strdup("sub r2,r4,r2\n");
    ops[5] = strdup("zjmp %0\n");
    ops[6] = strdup("sti r1,%264,%1\n");
    ops[7] = strdup("or r2,r2,r2\n");
    ops[8] = strdup("xor r10,r10,r10\n");
    ops[9] = strdup("fork %32\n");
    ops[10] =  strdup("ldi %326,%3,r2\n");
    ops[11] =  strdup("and	r6,%2147483648,r8\n");
    ops[12] =  strdup("st	r5,r2\n");
    ops[13] =  strdup("lldi    %42, %42, r16\n");
    ops[14] =  strdup("lfork		%2048\n");
    ops[15] =  strdup("#aff		r13\n");
    ops[16] =  strdup("zjmp %253\n");

    int fd = open("randomchamp.s", O_CREAT | O_TRUNC | O_RDWR , S_IWUSR | S_IRUSR);
    
    ft_putstr_fd(".name	\"Leeloo\" \n", fd);
    ft_putstr_fd(".comment \"Multipass\" \n", fd);

    i = 0;
    srand(time(0));
    ft_putstr_fd("\n", fd);
    while (i < nblines)
    {
        str = strdup(ops[Randoms(0,16, 1)]);
        ft_putstr_fd(str, fd);
        i++;
    }
}
