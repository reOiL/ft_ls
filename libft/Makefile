# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 17:05:02 by jwebber           #+#    #+#              #
#    Updated: 2019/12/12 17:58:18 by jwebber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c  \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strnstr.c \
	  ft_strcmp.c \
	  ft_strncmp.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_itoa.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_isspace.c \
	  ft_remove_sstr.c \
	  ft_wcount.c \
	  ft_strrev.c \
	  ft_range.c \
	  get_next_line.c \
	  ft_printf/colored.c \
	  ft_printf/ft_itoa_base.c \
	  ft_printf/ft_itoa_base_uns.c \
	  ft_printf/ft_printf.c \
	  ft_printf/get_format.c \
	  ft_printf/helper_numbers.c \
	  ft_printf/helper_numbers2.c \
	  ft_printf/print_addr_helper.c \
	  ft_printf/print_chars_helper.c \
	  ft_printf/print_float.c \
	  ft_printf/print_float2.c \
	  ft_printf/print_ints_helper.c \
	  ft_printf/print_percent_helper.c \
	  ft_printf/print_uns_helper.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

RM = /bin/rm -f

TEST_NAME = test.out

TEST_SRC = test.c

cc = gcc

.c.o:
	@$(cc) $(FLAGS) -c $< -o $@
	@printf "\e[32m😲 😲 😲  build success \e[36m$<\n"

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@printf "\e[36m 🏁  👍  👍  👍  $(NAME) 👍  👍  👍  🏁  !\n"

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@printf "\e[33mCleaned 😵 😵 😵 😵  !!!\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\e[31mFull cleaned 💀 💀 💀 💀  !!!\n"

re: fclean all
