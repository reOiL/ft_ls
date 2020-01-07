# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwebber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/14 11:06:36 by jwebber           #+#    #+#              #
#    Updated: 2019/12/14 11:21:13 by jwebber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = acrights_helper.c \
        arg_parser.c \
        comparators.c \
        comparators_2.c \
        del_from_lists.c \
        errors.c \
        get_fileinfo_1.c \
        get_fileinfo_2.c \
        l_flag_helper1.c \
        ls_with_l.c \
        ls_without_l.c \
        main.c \
        rec_flag_helper.c \
        t_file_helper.c \
        utils.c \
        utils2.c

HEADER = args.h \
            ft_ls.h

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIBFT_PATH = libft/
LIBFT = libft.a

.c.o:
	@gcc $(FLAGS) -c $< -o $@
	@printf "\e[32m😲 😲 😲  build success \e[36m$<\n"

$(NAME): $(OBJ) $(HEADER) $(LIBFT_PATH)$(LIBFT)
	@gcc $(FLAGS) $(OBJ) $(LIBFT_PATH)$(LIBFT) -o $(NAME)
	@printf "\e[36m 🏁  👍  👍  👍  $(NAME) 👍  👍  👍  🏁  !\n"

$(LIBFT_PATH)$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)

all: $(NAME) $(HEADER)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(RM) $(OBJ)
	@printf "\e[33mCleaned 😵 😵 😵 😵  !!!\n"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(RM) $(NAME)
	@printf "\e[31mFull cleaned 💀 💀 💀 💀  !!!\n"

re: fclean all
