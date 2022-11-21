/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gromero- <gromero-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:59:42 by gromero-          #+#    #+#             */
/*   Updated: 2022/11/07 16:48:47 by gromero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100

size_t			ft_strlen(char *str);

char			*ft_strchr(char *s, int c);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

char			*ft_get_line(char *save);

char			*ft_save(char *save);

char			*ft_read_and_save(int fd, char *save);

#endif
