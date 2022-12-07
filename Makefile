# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 18:15:47 by jorsanch          #+#    #+#              #
#    Updated: 2022/12/07 00:45:22 by jorsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_putnbrbase.c \
	  ft_uitoa.c

PRINT_SRC = ft_magic.c ft_magic2.c ft_printf.c ft_printtools.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)


$(NAME): 
	gcc -c $(FLAGS) $(PRINT_SRC) ./libft/*.c
	ar -crs $(NAME) *.o


clean:
	@ rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

# Esta regla compila todos los archivos .c, incluido main.c, y ejecuta el programa creado
main:
	gcc  $(FLAGS) $(PRINT_SRC) main.c ./libft/*.c
	@echo - - - - - TEST PROGRAM: - - - - -
	@./a.out
	@make clean

# Esta regla hace stage, commit y push al directorio git de todos los archivos 
push:
	git add .
	git status
	git commit -m "Last Commit"
	git push

norm:
	norminette $(PRINT_SRC)
