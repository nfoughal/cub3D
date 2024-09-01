/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:04:40 by nfoughal          #+#    #+#             */
/*   Updated: 2023/01/31 17:59:50 by nfoughal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define BUFFER_SIZE 5

# include<unistd.h>
# include<stdlib.h>

char	*ftt_strjoin(char *s1, char *s2);
size_t	ftt_strlen(char *s);
int		ftt_strchr(char *s, int c);
char	*ftt_strdup(char *s1);
char	*get_next_line(int fd);
char	*read_record(int fd, char *record);
char	*get_line(char *record);
char	*new_record(char *record);
#endif