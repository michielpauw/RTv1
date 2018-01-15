SRC = ft_matrix_mult.c \
	  ft_get_zero_matrix.c \
	  ft_dot_product.c \
	  ft_v_add.c \
	  ft_v_scalar.c \
	  ft_m_add.c \
	  ft_m_scalar.c \
	  ft_transpose.c \
	  ft_v_to_row_m.c \
	  ft_m_to_v.c \
	  ft_get_id_matrix.c \
	  ft_set_det.c \
	  ft_lin_trans.c \
	  ft_v_subtract.c \
	  ft_get_unit.c \
	  ft_get_3d_rot.c \
	  ft_free_matrix.c \
	  ft_free_vector.c \
	  ft_get_v_size.c \
	  ft_make_unit.c \
	  ft_cross_product.c \
	  ft_rotate_v.c
OBJ = 	ft_matrix_mult.o \
		ft_get_zero_matrix.o \
	  	ft_dot_product.o \
	  	ft_v_add.o \
	  	ft_v_scalar.o \
	  	ft_m_add.o \
	  	ft_m_scalar.o \
	  	ft_transpose.o \
	  	ft_v_to_row_m.o \
	  	ft_m_to_v.o \
		ft_get_id_matrix.o \
		ft_set_det.o \
		ft_lin_trans.o \
	  	ft_v_subtract.o \
		ft_get_unit.o \
		ft_get_3d_rot.o \
	  	ft_free_matrix.o \
	  	ft_free_vector.o \
	  	ft_get_v_size.o \
	  	ft_make_unit.o \
		ft_cross_product.o \
		ft_rotate_v.o
NAME = libla.a
INCLUDES = -I. -I../libft
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	-@gcc -ggdb $(FLAGS) $(INCLUDES) -c $(SRC)
	-@ar rc $(NAME) $(OBJ) && ranlib $(NAME)
	-@echo "Libla ready"

clean:
	-@/bin/rm -f $(OBJ)

fclean: clean
	-@/bin/rm -f $(NAME)

re: fclean all
