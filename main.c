#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <stdio.h>

// int		main(void)
// {
// 	char	*buf;
// 	int		fd;

// 	fd = open("test", O_RDONLY);
// 	printf("%d\n", get_next_line(42, &buf));
// 	get
// 	return 0;
// }

//

int		main(int argc, char **argv)
{
	int		counter;
	int		choice;
	int		fd;
	int		i;
	int		ret;
	int		bs;
	int		des[1024];
	int		desi;
	char	*line = NULL;

	i = 1;
	counter = 1;
	bs = BUFFER_SIZE;
	printf("\nTesting with buffsize: %d\nChoose test:\n1 - Read files\n2 - Standard output\n3 - Wrong file descriptor\n4 - Multiple file descriptors\n", bs);
	scanf("%d", &choice);
	if (choice != 4)
	{
		if (argc < 2)
		{
			i = 0;
			if (choice == 1)
			{
				printf("No files to read from\n");
				return (0);
			}
		}
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (choice == 2)
				fd = 0;
			if (choice == 3)
				fd = 12000;
			printf("\nFile %d:\n", i);
			ret = 1;
			int tes = 26;
			while (ret > 0)// && tes > 0)
			{
				ret = get_next_line((const int)fd, &line);
				printf("%d\treturn: %d\t |%s\n", counter, ret, line);
				free(line);
				line = NULL;					
				counter++;
				tes--;
			}
			close(fd);
			i++;
			counter = 1;
		}
	}
	else
	{
		if (argc >= 3)
		{
			while (1)
			{
				while (i < argc)
				{
					des[i] = open(argv[i], O_RDONLY);
					i++;
				}
				printf("Enter file number\n");
				scanf("%d", &desi);
				if (desi >= argc || desi < 1)
					printf("Wrong file number %d\n", desi);
				else
				{
					printf("\nFile %d:\n", desi);
					ret = 1;
					if (des[desi] != 0)
					{
						ret = get_next_line((const int)des[desi], &line);
						printf("return: %d\t %s\n", ret, line);
						if (ret == 0)
						{
							des[desi] = 0;
							printf("End of file\n");
						}
						else
							free(line);
						line = NULL;
						counter++;
					}
					else
					{
						printf("End of file\n");
					}
					i++;
					counter = 1;/* code */
				}

			}
		}
		else
		{
			printf("Not enough files to read from\n");
			return (0);
		}
	}
	return (0);
}
