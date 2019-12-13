/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: prouvoet <prouvoet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 15:05:05 by prouvoet       #+#    #+#                */
/*   Updated: 2019/12/13 11:31:17 by prouvoet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*copy_buffer_to_str(char *buff, char *str, int lg)
{
	char	*tmp;
	int		strlg;

	tmp = NULL;
	if (*buff == '\n')
		buff++;
	if (str == NULL)
		tmp = ft_strsub(buff, 0, lg);
	else
	{
		strlg = ft_strlen(str);
		tmp = (char *)malloc((strlg + lg + 1) * sizeof(char));
		ft_bzero(tmp, strlg + lg + 1);
		ft_memcpy(tmp, str, strlg);
		free(str);
		ft_memcpy(&(tmp[strlg]), buff, lg);
	}
	return (tmp);
}

char	*check_write(char *buff, char *str, const int fd, int size)
{
	char	*tmp;

	tmp = ft_strchr(buff, '\n');
	if (tmp != NULL)
		return (copy_buffer_to_str(buff, str, (tmp - buff)));
	if (size != BUFFER_SIZE && size != 0)
		return (copy_buffer_to_str(buff, str, size));
	tmp = copy_buffer_to_str(buff, str, ft_strlen(buff));
	ft_bzero(buff, BUFFER_SIZE + 1);
	size = read(fd, buff, BUFFER_SIZE);
	if (*buff == '\n' || size == 0)
		return (tmp);
	return (check_write(buff, tmp, fd, size));
}

void	move_till_next_line(char *buff)
{
	char	*tmp;

	tmp = ft_strchr(buff, '\n');
	if (tmp != NULL)
		ft_memcpy(buff, &tmp[1], ft_strlen(tmp));
	else
		buff[0] = '\0';
}

int		get_next_line(int fd, char **line)
{
	static char		buff[1000][BUFFER_SIZE + 1];
	char			*str;
	int				size;

	size = 0;
	str = NULL;
	if (line == NULL)
		return (-1);
	*line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (*(buff[fd]) == '\0')
	{
		ft_bzero(buff[fd], BUFFER_SIZE + 1);
		size = read(fd, buff[fd], BUFFER_SIZE);
		if (size == 0)
			return (0);
		if (size < 0)
			return (-1);
	}
	*line = check_write(buff[fd], str, fd, size);
	move_till_next_line(buff[fd]);
	return (1);
}
