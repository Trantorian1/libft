# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:26:34 by emcnab            #+#    #+#              #
#    Updated: 2022/11/20 18:26:00 by emcnab           ###   ########.fr        #
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

# character functions
CHARDIR = character/
define CHARFILES
	ft_isalnum.c		ft_isalpha.c		ft_isascii.c	ft_isdigit.c
	ft_islower.c		ft_isprint.c		ft_isspace.c	ft_isupper.c
	ft_tochar.c			ft_todigit.c		ft_tolower.c	ft_tostr.c
	ft_toupper.c
endef

# integer functions
INTDIR = integer/
define INTFILES
	ft_itoa.c			ft_max.c			ft_min.c		ft_sign.c
endef

# meth functions
MATHDIR = math/
define MATHFILES
	ft_abs.c			ft_pow.c
endef

# string functions
STRINGDIR = string/
define STRINGFILES
	ft_atoi.c			ft_split.c			ft_stralloc.c	ft_strchr.c
	ft_strchr.c			ft_strcmp.c			ft_strdup.c		ft_striteri.c
	ft_strjoin.c		ft_strlcat.c		ft_strlcpy.c	ft_strlen.c
	ft_strmapi.c		ft_strnjoin.c		ft_strnjoin.c	ft_strnsum.c
	ft_strrchr.c		ft_strrev.c			ft_strsum.c		ft_strtrim.c
	ft_substr.c
endef

# io functions
IODIR = system_io/
define IOFILES
	ft_putchar_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c	ft_putstr_fd.c
endef

# linked list functions
LISTDIR = linked_lists/
define LISTFILES
	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c	ft_lstdelone.c
	ft_lstiter.c		ft_lstlast.c		ft_lstmap.c		ft_lstnew.c
	ft_lstsize.c
endef

# type conversion functions
CONVDIR = converter/
define CONVFILES
	ft_convcmp.c		ft_converter.c		ft_convtochar.c	ft_convtolong.c
	ft_convtostr.c
endef

# all .c files
define CFILES
	$(foreach file, $(CHARFILES)  , $(CHARDIR)$(file)  )
	$(foreach file, $(INTFILES)   , $(INTDIR)$(file)   )
	$(foreach file, $(MATHFILES)  , $(MATHDIR)$(file)  )
	$(foreach file, $(STRINGFILES), $(STRINGDIR)$(file))
	$(foreach file, $(IOFILES)    , $(IODIR)$(file)    )
	$(foreach file, $(LISTFILES)  , $(LISTDIR)$(file)  )
	$(foreach file, $(CONVFILES)  , $(CONVDIR)$(file)  )
endef

# parent directory for all object files
ODIR = objs/
# object files sub-directories
ODIRS = $(ODIR)				$(ODIR)$(CHARDIR)		$(ODIR)$(INTDIR)\
		$(ODIR)$(MATHDIR)	$(ODIR)$(STRINGDIR)		$(ODIR)$(IODIR)\
		$(ODIR)$(LISTDIR)	$(ODIR)$(CONVDIR)

# all .o files
OFILES  = $(patsubst %.c, $(ODIR)%.o, $(CFILES)) 

# C compiler
CC     = clang
CMODE  = debug
OPT    = -O0
CFLAGS = -Wall -Wextra -Werror $(OPT)

# compilation modes
# debug    : debug mode
# fsanitize: uses fsanitize option for compilation
# hard     : stricter compilation rules and error checking
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
$(BINARY): $(ODIRS) $(OFILES)
	@$(AR) $(AFLAGS) $@ $(OFILES)
	@echo "$$SEPERATOR"
	@echo "${LGREEN} ${WHITE}${BINARY} ${LGREEN}built successfully!${LGRAY}"

# creates all directories necessary to building
%/:
	@mkdir $@
	@echo "${LGREEN} created directory ${@}${LGRAY}"

# for any object to be compiled, the associated .c file must exist
$(ODIR)%.o:%.c
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo "${LGRAY}${@} ${GREEN}built successfully!${LGRAY}"

# removes all objects
clean:
	@rm -f $(OFILES)
	@echo "$$SEPERATOR"
	@echo "${RED} removed all object files${LGRAY}"

# removes all objects and the binary
fclean: clean
	@rm -f $(BINARY)
	@echo "${RED}|${LGRAY}"
	@echo "${LRED} removed ${WHITE}${BINARY}${LGRAY}"
	@echo "$$SEPERATOR"

# removes all objecst, the binary qnd rebuilds the binary
re: fclean all

# displays debug info
debug:
	@echo $(OFILES)
	@echo $(subst ./objs/,,$(OFILES))

# avoids name collision with files
.PHONY: all display clean fclean re debug
