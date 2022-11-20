# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:26:34 by emcnab            #+#    #+#              #
#    Updated: 2022/11/20 16:19:31 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==============================================================================
# 										DISPLAY
# ==============================================================================

# colors
BLACK   = \033[0;30m
GRAY    = \033[1;30m
RED     = \033[0;31m
LRED    = \033[1;31m
GREEN   = \033[0;32m
LGREEN  = \033[1;32m
ORANGE  = \033[0;33m
YELLOW  = \033[1;33m
BLUE    = \033[0;34m
LBLUE   = \033[1;34m
PURPLE  = \033[0;35m
LPURPLE = \033[1;35m
CYAN    = \033[0;36m
LCYAN   = \033[1;36m
LGRAY   = \033[0;37m
WHITE   = \033[1;37m

# header
define HEADER
$(LBLUE) _    _     _____  $(LGRAY)   $(CYAN) _____     _____  ______   ________  _________  
$(LBLUE)| |  | |   / ___ `.$(LGRAY)   $(CYAN)|_   _|   |_   _||_   _ \ |_   __  ||  _   _  | 
$(LBLUE)| |__| |_ |_/___) |$(LGRAY)   $(CYAN)  | |       | |    | |_) |  | |_ \_||_/ | | \_| 
$(LBLUE)|____   _| .'____.'$(LGRAY)   $(CYAN)  | |   _   | |    |  __'.  |  _|       | |     
$(LBLUE)    _| |_ / /_____ $(LGRAY) _ $(CYAN) _| |__/ | _| |_  _| |__) |_| |_       _| |_    
$(LBLUE)   |_____||_______|$(LGRAY)(_)$(CYAN)|________||_____||_______/|_____|     |_____|   

$(LGRAY) - version by Eliot McNab
endef
define SEPERATOR
$(WHITE).....................................................................
endef

export HEADER
export SEPERATOR
export EXITS_ALREADY

# ==============================================================================
# 									COMPILATION
# ==============================================================================

# paths to .c and .o files
define CFILES
	ft_memcmp.c 		ft_min.c 			ft_max.c		ft_isspace.c
	ft_memcpy.c			ft_calloc.c 		ft_putendl_fd.c ft_strnstr.c
	ft_isalpha.c		ft_strtrim.c		ft_freeset.c	ft_memmove.c
	ft_isalnum.c		ft_isdigit.c		ft_tochar.c		ft_tostr.c
	ft_pow.c			ft_abs.c			ft_isprint.c	ft_tolower.c
	ft_toupper.c		ft_strncmp.c		ft_todigit.c	ft_strlen.c
	ft_putstr_fd.c		ft_bzero.c			ft_memset.c		ft_substr.c
	ft_strmapi.c		ft_strchr.c			ft_atoi.c		ft_isascii.c
	ft_putchar_fd.c		ft_itoa.c			ft_strjoin.c	ft_split.c
	ft_strlcat.c		ft_pack.c			ft_islower.c	ft_isupper.c
	ft_putnbr_fd.c		ft_memchr.c			ft_strrchr.c	ft_striteri.c
	ft_strdup.c			ft_stralloc.c		ft_strlcpy.c	ft_strrev.c
	ft_strnsum.c		ft_strsum.c			ft_strcmp.c		ft_strnjoin.c
	ft_convcmp.c		ft_converter.c		ft_convtoint.c	ft_convtostr.c
	ft_convtochar.c		ft_convtolong.c		ft_sign.c		ft_memstr.c	
endef

define BONUS
	ft_lstadd_front.c	ft_lstiter.c		ft_lstmap.c		ft_lstsize.c
	ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c
	ft_lstnew.c
endef

ODIR   = objs/
OFILES = $(patsubst %.c, $(ODIR)%.o, $(CFILES)) 
BOFILES = $(patsubst %.c, $(ODIR)%.o, $(BONUS))

# C compiler
CC     = clang
CMODE  = hard
OPT    = -O0
CFLAGS = -Wall -Wextra -Werror $(OPT)
ifeq ($(CMODE), debug)
	CFLAGS += -g
else ifeq ($(CMODE), fsanitize)
	CFLAGS += -fsanitize=address
else ifeq ($(CMODE), hard)
	CFLAGS += -Weverything -fsanitize=address,undefined #-Wno-cast-qual -Wno-missing-noreturn -Wno-disabled-macro-expansion -Wno-reserved-id-macro
endif

# archive compiler
AR     = ar
AFLAGS = -cqs

# archive name
BINARY = libft.a

# by default, builds the binary
all: display $(BINARY)

# displays the header
display:
	@echo "$$HEADER"
	@echo "$$SEPERATOR"

# for the binary to be build, all object files must have been compiled
$(BINARY): $(ODIR) $(OFILES)
	@$(AR) $(AFLAGS) $@ $(OFILES)
	@echo "$$SEPERATOR"
	@echo "${LGREEN} ${WHITE}${BINARY} ${LGREEN}built successfully!${LGRAY}"

# compiles bonus files into archive
bonus: display $(ODIR) $(OFILES) $(BOFILES)
	@$(AR) $(AFLAGS) $(BINARY) $(OFILES) $(BOFILES)
	@echo "$$SEPERATOR"  
	@echo "${LGREEN} ${WHITE}${BINARY} ${LGREEN}built successfully!${LGRAY}"  
	@echo "${LRED}(bonus)${LGRAY}"

# compiles dynamic library for libft unit tester
so: display $(ODIR) $(OFILES) $(BOFILES)
	gcc -shared -o libft.so $(OFILES) $(BOFILES)

$(ODIR):
	@mkdir $(ODIR)
	@echo "${LGREEN} created directory ${ODIR}${LGRAY}"
	@echo "$$SEPERATOR"

# for any object to be compiled, the associated .c file must exist
$(ODIR)%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo "${LGRAY}${@} ${GREEN}built successfully!${LGRAY}"

# removes all objects
clean:
	rm -f $(OFILES)

# removes all objects and the binary
fclean: clean
	rm -f $(BINARY)

# removes all objecst, the binary qnd rebuilds the binary
re: fclean all

# displays debug info
debug:
	@echo $(OFILES)
	@echo $(subst ./objs/,,$(OFILES))

# avoids name collision with files
.PHONY: all bonus so clean fclean re debug
