# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 14:08:48 by emcnab            #+#    #+#              #
#    Updated: 2023/04/25 09:38:43 by emcnab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                UNIX COLOR CODES                              #
# **************************************************************************** #

RESET = \033[0m
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m
BLINK = \033[5m
REVERSE = \033[7m
HIDDEN = \033[8m

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m

BLACK_BG = \033[40m
RED_BG = \033[41m
GREEN_BG = \033[42m
YELLOW_BG = \033[43m
BLUE_BG = \033[44m
MAGENTA_BG = \033[45m
CYAN_BG = \033[46m
WHITE_BG = \033[47m

# **************************************************************************** #
#                               COMPILATIONS VARS                              #
# **************************************************************************** #

DIR_BUILD = ./build
DIR_OBJS = $(DIR_BUILD)/objs
DIR_DEPS = $(DIR_BUILD)/deps
DIR_SRCS = ./src
DIR_INCL = ./include ./vendor/libft

# FILES_SRCS = $(shell find . -wholename "$(DIR_SRCS)/*.c")
FILES_SRCS = ./src/mem/ft_memcmp.c                                  \
             ./src/mem/ft_memcpy.c                                  \
             ./src/mem/ft_calloc.c                                  \
             ./src/mem/ft_freeset.c                                 \
             ./src/mem/ft_memmove.c                                 \
             ./src/mem/ft_bzero.c                                   \
             ./src/mem/ft_memset.c                                  \
             ./src/mem/ft_m_any.c                                   \
             ./src/mem/ft_pack.c                                    \
             ./src/mem/ft_malloc.c                                  \
             ./src/mem/ft_memchr.c                                  \
             ./src/mem/ft_memstr.c                                  \
             ./src/char/ft_isalpha.c                                \
             ./src/char/ft_isalnum.c                                \
             ./src/char/ft_isdigit.c                                \
             ./src/char/ft_isprint.c                                \
             ./src/char/ft_tolower.c                                \
             ./src/char/ft_toupper.c                                \
             ./src/char/ft_todigit.c                                \
             ./src/char/ft_isascii.c                                \
             ./src/char/ft_isspace.c                                \
             ./src/char/ft_islower.c                                \
             ./src/char/ft_isupper.c                                \
             ./src/str/ft_lword_search.c                            \
             ./src/str/ft_str_to_d.c                                \
             ./src/str/str_get_sign.c                               \
             ./src/str/ft_strrev.c                                  \
             ./src/str/ft_strnstr.c                                 \
             ./src/str/ft_strtrim.c                                 \
             ./src/str/ft_strcmp.c                                  \
             ./src/str/ft_str_to_i.c                                \
             ./src/str/skip_space.c                                 \
             ./src/str/ft_strncmp.c                                 \
             ./src/str/ft_strlen.c                                  \
             ./src/str/ft_atol.c                                    \
             ./src/str/ft_substr.c                                  \
             ./src/str/ft_strmapi.c                                 \
             ./src/str/ft_strchr.c                                  \
             ./src/str/ft_strnsum.c                                 \
             ./src/str/ft_atoi.c                                    \
             ./src/str/ft_atoui.c                                   \
             ./src/str/ft_strjoin.c                                 \
             ./src/str/ft_split.c                                   \
             ./src/str/ft_quickfind.c                               \
             ./src/str/ft_strrchr.c                                 \
             ./src/str/ft_striteri.c                                \
             ./src/str/ft_strdup.c                                  \
             ./src/str/ft_stralloc.c                                \
             ./src/str/ft_strsum.c                                  \
             ./src/math/ft_abslong.c                                \
             ./src/math/max_d.c                                     \
             ./src/math/ft_pow.c                                    \
             ./src/math/ft_abs.c                                    \
             ./src/math/lerp.c                                      \
             ./src/math/max.c                                       \
             ./src/math/abs.c                                       \
             ./src/math/ft_closest_power_ul.c                       \
             ./src/math/ft_closest_power.c                          \
             ./src/int/ft_ltoa.c                                    \
             ./src/int/ft_ultoa_base.c                              \
             ./src/int/ft_min.c                                     \
             ./src/int/ft_max.c                                     \
             ./src/int/ft_longlen.c                                 \
             ./src/int/ft_baselen.c                                 \
             ./src/int/ft_itoa.c                                    \
             ./src/int/ft_sign.c                                    \
             ./src/int/ft_m_data.c                                  \
             ./src/int/ft_intlen.c                                  \
             ./src/data_structures/vec2D/vec2D_scale.c              \
             ./src/data_structures/vec2D/vec2D_sub.c                \
             ./src/data_structures/vec2D/vec2D_add.c                \
             ./src/data_structures/vec2D/vec2D_new.c                \
             ./src/data_structures/array_int/ft_array_create.c      \
             ./src/data_structures/array_int/ft_array_insert.c      \
             ./src/data_structures/array_int/ft_array_add.c         \
             ./src/data_structures/array_int/ft_array_get.c         \
             ./src/data_structures/array_int/ft_array_size.c        \
             ./src/data_structures/array_int/ft_array_destroy.c     \
             ./src/data_structures/array_int/ft_m_array.c           \
             ./src/data_structures/deque/ft_deque_pop_front_bulk.c  \
             ./src/data_structures/deque/ft_deque_to_array.c        \
             ./src/data_structures/deque/ft_deque_reverse_rotate.c  \
             ./src/data_structures/deque/ft_deque_push_back.c       \
             ./src/data_structures/deque/ft_deque_poll_front.c      \
             ./src/data_structures/deque/ft_deque_poll_back_bulk.c  \
             ./src/data_structures/deque/ft_deque_pop_front.c       \
             ./src/data_structures/deque/ft_deque.c                 \
             ./src/data_structures/deque/ft_m_deque.c               \
             ./src/data_structures/deque/ft_deque_swap.c            \
             ./src/data_structures/deque/ft_deque_push_back_bulk.c  \
             ./src/data_structures/deque/ft_deque_push_front.c      \
             ./src/data_structures/deque/ft_deque_poll_front_bulk.c \
             ./src/data_structures/deque/ft_deque_poll_back.c       \
             ./src/data_structures/deque/ft_deque_rotate.c          \
             ./src/data_structures/deque/ft_deque_size.c            \
             ./src/data_structures/deque/ft_deque_push_front_bulk.c \
             ./src/data_structures/deque/ft_deque_is_empty.c        \
             ./src/data_structures/deque/ft_deque_pop_back.c        \
             ./src/data_structures/deque/ft_deque_pop_back_bulk.c   \
             ./src/data_structures/linklst/ft_lst_map.c             \
             ./src/data_structures/linklst/ft_lst_iter.c            \
             ./src/data_structures/linklst/ft_lst_size.c            \
             ./src/data_structures/linklst/ft_lst_add_front.c       \
             ./src/data_structures/linklst/ft_lst_last.c            \
             ./src/data_structures/linklst/ft_lst_clear.c           \
             ./src/data_structures/linklst/ft_lst_new.c             \
             ./src/data_structures/linklst/ft_lst_delone.c          \
             ./src/data_structures/linklst/ft_lst_add_back.c        \
             ./src/data_structures/array_any/ft_array_any_create.c  \
             ./src/data_structures/array_any/ft_array_any_destroy.c \
             ./src/data_structures/array_any/ft_m_array_any.c       \
             ./src/data_structures/array_any/ft_array_any_add.c     \
             ./src/data_structures/array_any/ft_array_any_get.c     \
             ./src/data_structures/array_any/ft_array_any_insert.c  \
             ./src/data_structures/array_any/ft_array_any_size.c    \
             ./src/data_structures/vec2d_d/vec2d_sub_d.c            \
             ./src/data_structures/vec2d_d/vec2d_scale_d.c          \
             ./src/data_structures/vec2d_d/vec2d_copy_d.c           \
             ./src/data_structures/vec2d_d/vec2d_new_d.c            \
             ./src/data_structures/vec2d_d/vec2d_norm_d.c           \
             ./src/data_structures/vec2d_d/vec2d_angle_d.c          \
             ./src/data_structures/vec2d_d/vec2d_add_d.c            \
             ./src/io/ft_putendl_fd.c                               \
             ./src/io/ft_putstr_fd.c                                \
             ./src/io/ft_putchar_fd.c                               \
             ./src/io/ft_putlong_fd.c                               \
             ./src/io/ft_putnbr_fd.c
FILES_OBJS = $(patsubst $(DIR_SRCS)/%.c,$(DIR_OBJS)/%.o,$(FILES_SRCS))
FILES_DEPS = $(patsubst $(DIR_SRCS)/%.c,$(DIR_DEPS)/%.d,$(FILES_SRCS))

OPT = -O3

C_COMPILER = clang
I_FLAGS = $(foreach dir,$(DIR_INCL),-I$(dir) )
C_FLAGS = -Wall -Wextra -Werror $(I_FLAGS)
C_DEPS = -MM -MP $(I_FLAGS)

A_COMPILER = ar
A_FLAGS = -cqs

BIN = libft.a

PROG = 0
TARGET = 1

# **************************************************************************** #
#                               COMPILATIONS TASKS                             #
# **************************************************************************** #

# @brief Default rule, calls dry run and compiles binary
all: dry_run $(BIN)



# @brief Builds main project binary.
#
# Builds project binary and displays compilation progress (100%). Will create
# binary directory if not already present. This rule will only be executed once
# the libf has been compiled, and all object and dependency files have been
# generated.
$(BIN): $(FILES_OBJS) $(FILES_DEPS)
# 	displays build status
	@echo "$(BOLD)$(BLUE)building $(WHITE)$(BIN)$(RESET)"
	@printf "$(BOLD)$(WHITE)[100.00%%]$(RESET)"
# 	displays build command
	@printf " $(GREEN)$(A_COMPILER) $(A_FLAGS) $(BIN) $(FILES_OBJS) -lm$(RESET)\n"
# 	builds binary
	@mkdir -p $(@D)
	@$(A_COMPILER) $(A_FLAGS) $(BIN) $(FILES_OBJS) -lm



# @brief Builds object files.
#
# Builds object files, copying the structure of the src/ folder. Any missing
# directories will be created. 
# Also displays the current progress in the compilation. Progress is calculated
# based on the number of commands executed by Make, so this should be accurate
# even with Make dependency tracking.
#
# @warning Has not been tested in a multithread environment yet.
$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
# 	increments the number of files compiled
	@$(eval PROG=$(shell echo $$(($(PROG)+1))))
# 	displays build status. We have to do a bit of voodo shit by redirecting any
# 	error from bc since this seems to cause errors when running make -n in the
# 	dry_run task
	@printf "$(BOLD)$(WHITE)[%6.2f%%]$(RESET)" $(shell echo "scale=2;$(PROG)/($(TARGET)) * 100" | bc 2>/dev/null)
# 	displays build command
	@printf " $(GREEN)$(C_COMPILER) $(C_FLAGS) -c $< -o $@\n$(RESET)"
# 	builds object file
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) -c $< -o $@



# @brief Builds dependency files.
#
# Builds dependency files, copying the structure of the src/ folder. Any missing
# directories will be created.
#
# @warning Has not been tested in a multithread environment yet.
$(DIR_DEPS)/%.d: $(DIR_SRCS)/%.c
	@mkdir -p $(@D)
	@$(C_COMPILER) $(C_FLAGS) $(C_DEPS) -MT $(DIR_OBJS)/$*.o -MF $@ $<



# @brief Builds the libft
#
# This will only execute once the libft gitmodule has been initialised.
$(LIB_FT): $(LIB_GIT)
	@echo "$(BOLD)$(BLUE)building $(WHITE)$(LIB_FT)$(RESET)"
	@rake -s -C $(@D)



# @brief Initialises git submodules
$(LIB_GIT):
	@echo "initialising git submodules..."
	@git submodule init && git submodule update



# @brief Calculates the number of rules to be executed.
#
# This is used to accuratly determine the number of object files to be generated
# in order to calculate compilation status. Object file compilation is detected
# by grepping their progress.
dry_run:
# 	rules to be executed are stored in a file to be read. For some reason,
# 	running this directly as a shell command causes an infinite recursion...
	@make -n > $(DIR_BUILD)/dry_run.txt
#	greps the numbre of objec files to be generated
	@$(eval TARGET=$(shell cat $(DIR_BUILD)/dry_run.txt | grep %6.2f%% | wc -l))
#	counts the final binary as part of the compilation
	@$(eval TARGET=$(shell echo $$(($(TARGET)+1))))



# @brief Removes any object or dependency file that was generated
clean:
	@echo "$(RED)removing $(WHITE)*.o$(RESET)"
	@rm $(FILES_OBJS)
	@echo "$(RED)removing $(WHITE)*.d$(RESET)"
	@rm $(FILES_DEPS)



# @brief Removes any object or dependency file that was generated as well as the
# project binary
fclean: clean
	@echo "$(BOLD)$(RED)removing $(WHITE)$(BIN)$(RESET)"
	@rm $(BIN)



# @brief Removes any build artifacts and recompiles the project.
re: fclean
	@make -s all



# @brief displays debug info
debug:
	@echo $(FILES_SRCS)
	@echo $(FILES_OBJS)
	@echo $(FILES_DEPS)
	@echo $(C_FLAGS)
	echo $(TARGET)



# dependency inclusion
-include $(FILES_DEPS)



# all cannot be executed in parallel since we always need to generate dry_run
# before executing $(BIN)
.NOTPARALLEL: all
.PHONY: all submodules clean fclean re debug
