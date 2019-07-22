#ifndef JS_PARSER_H
# define JS_PARSER_H

# include "rt.h"
# include <stdio.h>

char			*js_parser(int fd);
int		    	init_parser(t_rt *rt, char *file);

#endif
