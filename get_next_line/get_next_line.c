/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  hyunjang < hyunjang@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:14:49 by  hyunjang         #+#    #+#             */
/*   Updated: 2022/07/18 14:14:49 by  hyunjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*readline(char **stat_str, int fd);
static void	*notnullfree(char **c);

char	*get_next_line(int fd)
{
	static char	*stat_str;
	char		*nlcursor;
	char		*line;
	char		*t_str;

	if (!stat_str)
		stat_str = "";
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	nlcursor = readline(&stat_str, fd);
	if (!nlcursor && stat_str[0])
	{
		line = ft_substr(stat_str, 0, ft_strlen(stat_str));
		notnullfree(&stat_str);
		return (line);
	}
	else if (!nlcursor)
		return (notnullfree(&stat_str));
	t_str = stat_str;
	line = ft_substr(t_str, 0, nlcursor - t_str + 1);
	stat_str = ft_strjoin(nlcursor + 1, "");
	notnullfree(&t_str);
	return (line);
}

static char	*readline(char **stat_str, int fd)
{
	char	*temp;
	int		r_bytes;
	char	*t_str;

	while (!ft_strchr(*stat_str, '\n'))
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (0);
		r_bytes = read(fd, temp, BUFFER_SIZE);
		if (r_bytes <= 0)
		{
			free(temp);
			return (0);
		}
		temp[r_bytes] = '\0';
		t_str = *stat_str;
		*stat_str = ft_strjoin(t_str, temp);
		notnullfree(&t_str);
		free(temp);
	}
	return (ft_strchr(*stat_str, '\n'));
}

static void	*notnullfree(char **c)
{
	if ((*c) == 0)
		return (0);
	if ((*c)[0] != '\0')
		free(*c);
	*c = 0;
	return (0);
}
