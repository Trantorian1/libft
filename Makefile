# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:26:34 by emcnab            #+#    #+#              #
#    Updated: 2023/01/23 10:05:33 by emcnab           ###   ########.fr        #
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

export HEADER
export EXITS_ALREADY

# ==============================================================================
#                                 COMPILATION
# ==============================================================================

# header directory
HDIR = include/

# character functions
CHARDIR = char/
define CHARFILES
	ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_islower.c
	ft_isprint.c  ft_isspace.c  ft_isupper.c  ft_todigit.c  ft_tolower.c
	ft_toupper.c
endef

# integer functions
INTDIR = int/
define INTFILES
	ft_baselen.c  ft_intlen.c  ft_itoa.c  ft_longlen.c  ft_ltoa.c  ft_max.c
	ft_min.c  ft_sign.c  ft_ultoa_base.c
endef

# meth functions
MATHDIR = math/
define MATHFILES
	ft_abs.c  ft_abslong.c  ft_closest_power.c  ft_pow.c
endef

# string functions
STRINGDIR = str/
define STRINGFILES
	ft_atoi.c          ft_quickfind.c  ft_stralloc.c  ft_strcmp.c  ft_striteri.c
	ft_strlen.c   ft_strncmp.c  ft_strnsum.c  ft_strrev.c  ft_strtrim.c
	ft_lword_search.c  ft_split.c      ft_strchr.c    ft_strdup.c  ft_strjoin.c
	ft_strmapi.c  ft_strnstr.c  ft_strrchr.c  ft_strsum.c  ft_substr.c
endef

# io functions
IODIR = io/
define IOFILES
	ft_putchar_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c	ft_putstr_fd.c
endef

# memory functions
MEMDIR = mem/
define MEMFILES
	ft_bzero.c  ft_calloc.c  ft_freeset.c  ft_memchr.c  ft_memcmp.c  ft_memcpy.c
	ft_memmove.c  ft_memset.c  ft_memstr.c  ft_pack.c
endef

# ==============================================================================
#                                 DATA STRUCTURES
# ==============================================================================

# data structure directory
DSDIR = data_structures/

# linked list functions
LISTDIR = linklst/
define LISTFILES
	ft_lst_add_back.c  ft_lst_add_front.c  ft_lst_clear.c  ft_lst_delone.c
	ft_lst_iter.c  ft_lst_last.c  ft_lst_map.c  ft_lst_new.c  ft_lst_size.c
endef

# all .c files
define CFILES
	$(foreach file,$(CHARFILES)  ,src/$(CHARDIR)$(file)        )
	$(foreach file,$(INTFILES)   ,src/$(INTDIR)$(file)         )
	$(foreach file,$(MATHFILES)  ,src/$(MATHDIR)$(file)        )
	$(foreach file,$(STRINGFILES),src/$(STRINGDIR)$(file)      )
	$(foreach file,$(IOFILES)    ,src/$(IODIR)$(file)          )
	$(foreach file,$(MEMFILES)   ,src/$(MEMDIR)$(file)         )
	$(foreach file,$(LISTFILES)  ,src/$(DSDIR)$(LISTDIR)$(file))
	$(foreach file,$(CONVFILES)  ,src/$(DSDIR)$(CONVDIR)$(file))
	$(foreach file,$(LSTRFILES)  ,src/$(DSDIR)$(LSTRDIR)$(file))
endef

# parent directory for all object files
ODIR = build/objs/
# object files sub-directories
ODIRS = $(ODIR)				$(ODIR)$(CHARDIR)		$(ODIR)$(INTDIR) \
		$(ODIR)$(MATHDIR)	$(ODIR)$(STRINGDIR)		$(ODIR)$(IODIR)  \
		$(ODIR)$(MEMDIR)	$(ODIR)$(DSDIR)                          \
		$(ODIR)$(DSDIR)$(LISTDIR)			$(ODIR)$(DSDIR)$(CONVDIR)\
		$(ODIR)$(DSDIR)$(LSTRDIR)

# all .o files
OFILES  = $(patsubst src/%.c, $(ODIR)%.o, $(CFILES)) 

# C compiler
CC     = clang
CMODE  = debug
OPT    = -O0
CFLAGS = -Wall -Wextra -Werror $(OPT)

# compilation modes
# debug    : debug mode
# fsanitize: uses fsanitize option for compilation
# hard     : stricter compilation rules and error checking
ifneq ($(filter debug, $(CMODE)),)
	CFLAGS += -g
endif
ifneq ($(filter fsanitize, $(CMODE)),)
	CFLAGS += -fsanitize=address
endif
ifneq ($(filter hard, $(CMODE)),)
	CFLAGS += -Weverything
	# -Wno-cast-qual -Wno-missing-noreturn -Wno-disabled-macro-expansion
	# -Wno-reserved-id-macro
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

# for the binary to be build, all object files must have been compiled
$(BINARY): $(ODIRS) $(OFILES)
	@$(AR) $(AFLAGS) $@ $(OFILES)
	@echo "${LGREEN} ${WHITE}${BINARY} ${LGREEN}built successfully!${LGRAY}"

# creates all directories necessary to building
%/:
	@mkdir $@
	@echo "${LGREEN} created directory ${@}${LGRAY}"

# for any object to be compiled, the associated .c file must exist
$(ODIR)%.o:src/%.c
	@$(CC) $(CFLAGS) -c -o $@ $^ -I $(HDIR)
	@echo "${LGRAY}${@} ${GREEN}built successfully!${LGRAY}"

# removes all objects
clean:
	@rm -f $(OFILES)
	@echo "${RED} removed all object files${LGRAY}"

# removes all objects and the binary
fclean: clean
	@rm -f $(BINARY)
	@echo "${RED}|${LGRAY}"
	@echo "${LRED} removed ${WHITE}${BINARY}${LGRAY}"

# removes all objecst, the binary qnd rebuilds the binary
re: fclean all

# displays debug info
debug:
	@echo "${LBLUE} object files${LGRAY}"
	@echo $(OFILES)
	@echo "${LBLUE} source files${LGRAY}"
	@echo $(CFILES)

# avoids name collision with files
.PHONY: all display clean fclean re debug
