# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:06:25 by jwebber           #+#    #+#              #
#    Updated: 2019/11/14 10:39:23 by jwebber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_itoa_base.c \
        ft_itoa_base_uns.c \
        ft_printf.c \
        get_format.c \
        helper_numbers.c \
        print_addr_helper.c \
        print_chars_helper.c \
        print_ints_helper.c \
        print_uns_helper.c \
        print_percent_helper.c \
        print_float.c \
        print_float2.c \
        helper_numbers2.c \
        colored.c \
        libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c \
        libft/ft_isspace.c libft/ft_itoa.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c \
        libft/ft_lstnew.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c \
        libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c \
        libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_range.c libft/ft_remove_sstr.c libft/ft_strcat.c libft/ft_strchr.c \
        libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c \
        libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c \
        libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strrev.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c \
        libft/ft_strtrim.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_wcount.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIBFT_PATH = libft/

LIBFT = libft.a

.c.o:
	@gcc $(FLAGS) -c $< -o $@
	@printf "\e[32m😲 😲 😲  build success \e[36m$<\n"

$(NAME): $(OBJ) $(LIBFT_PATH)$(LIBFT)
	@ar rc $(NAME) $(OBJ) $(LIBFT_PATH)$(LIBFT)
	@printf "\e[36m 🏁  👍  👍  👍  $(NAME) 👍  👍  👍  🏁  !\n"

$(LIBFT_PATH)$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
	@printf "\e[33mCleaned 😵 😵 😵 😵  !!!\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
	@printf "\e[31mFull cleaned 💀 💀 💀 💀  !!!\n"

re: fclean all
