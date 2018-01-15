# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpauw <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/06 17:41:17 by mpauw             #+#    #+#              #
#    Updated: 2018/01/15 16:10:24 by mpauw            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
FLAGS = -Wall -Wextra -Werror 
INCLUDES = rtv1.h
SRCS = 	rtv1.c\
		set_scene.c\
		set_object.c\
		tools.c\
		s_cylinder_function.c\
		raytracer.c\
		window_init.c\
		key_control.c\
		rotate_object.c
OBJ = $(SRCS:%.c=%.o)
LFTDIR = libft/
LLADIR = libla/
LMLXDIR = minilibx_macos/
LIBFT = libft.a
LIBLA = libla.a
LIBMLX = libmlx.a
FT = ft
LA = la
MLX = mlx
MAKE = make
FRAMEWORK = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT) $(LMLXDIR)$(LIBMLX) $(LLADIR)$(LIBLA)
	-@gcc $(FLAGS) -o $(NAME) -ggdb $(OBJ) -I$(LFTDIR) -L$(LFTDIR) -l$(FT) \
	 -I$(LMLXDIR) -L$(LMLXDIR) -l$(MLX) -I$(LLADIR) -L$(LLADIR) -l$(LA) \
	 $(FRAMEWORK)
	-@echo "RTv1 Ready"

%.o: %.c $(INCLUDES)
	-@gcc $(FLAGS) -I$(LFTDIR) -I$(LMLXDIR) -I$(LLADIR) -c $(SRCS)

$(LFTDIR)$(LIBFT):
	$(MAKE) -C $(LFTDIR) $(LIBFT)

$(LLADIR)$(LIBLA):
	$(MAKE) -C $(LLADIR) $(LIBLA)

$(LMLXDIR)$(LIBMLX):
	$(MAKE) -C $(LMLXDIR) $(LIBMLX)

clean:
	-@/bin/rm -f $(OBJ)
#	-@$(MAKE) -C $(LFTDIR) clean
#	-@$(MAKE) -C $(LMLXDIR) clean
#	-@$(MAKE) -C $(LLADIR) clean

fclean: clean
	-@/bin/rm -f $(NAME)
#	-@$(MAKE) -C $(LFTDIR) fclean
#	-@$(MAKE) -C $(LLADIR) fclean

re: fclean all
