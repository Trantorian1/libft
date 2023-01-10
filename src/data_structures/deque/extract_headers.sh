#!/bin/bash

# processes the options passed to the script
options=$(getopt -o d:v,h -l dir:,verbose,help -- "$@")

# checks for errors when processing options
if [[ $? != 0 ]]; then
	echo "Error: failed to parse parameters"
	exit 1
fi

# sets positional argumenst to the values parsed by getopt
eval set -- $options

# retrieves arguments
args=("$@")

# map responsible for storing optional argument value
declare -A map_opts

# sets default values for options
map_opts["dir"]="."

# iterates over each argument to retrieve its value
for ((i=0; i < ${#args[@]}; i++)); do
	case "${args[$i]}" in
		--dir|-d)		# specifies source directory
			map_opts["dir"]=${args[$((i+1))]}
			i++	# moves on to the next argument
			;;
		--verbose|-v)	# activates verbose output
			map_opts["verbose"]=1
			;;
		--help|-h)		# displays help
			# help must be the only option if used
			if [[ ${#map_opts[@]} -gt 1 ]]; then
				echo "Error: --help cannot be used with any other parameter"
			fi
			map_opts["help"]=1
			;;
	esac
done

IFS=$'\n'

# uses '\n' as field seperator so our greps 
# are not seperated at each \t and ' '
help="\
Extract_headers is a program designed to facilitate header file generation         \n\
for 42 school projects.                                                            \n\
                                                                                   \n\
It detects c files at the specified path and extracts all function prototypes      \n\
into a new header file, automatically imporing the necessary stdlib and            \n\
structure headers. Please note that generated header files will be overwritten     \n\
each time extract_headers is called.                                               \n\
                                                                                   \n\
Structures can only be detected if they follow the naming convention \"t_s_name\". \n\
These will be automatically included in the header \"s_name.h\". So for example    \n\
if your function prototypes use \"t_s_deque\" then \"s_deque.h\" will automatically\n\
be imported. Please note that you still have to create this file, this is only     \n\
done so as to simplify structure inclusion, not automate it.                       \n\
                                                                                   \n\
  Usage:                                                                           \n\
    extract_headers -h/--help     displays help info for extract_headers           \n\
    extract_headers -d/--dir      specifies where to look for c files              \n\
    extract_headers -v/--verbose  toggles extra output                             \n\
                                                                                   \n\
  Supported headers:                                                               \n\
    <stddef.h>                    size_t                                           \n\
    <stdbool.h>                   bool                                             \n\
    <stdarg.h>                    va_list                                          \n\
                                                                                   \n\
  Author: Eliot McNab, based on the code of JB Caron                               \n"

# displays help info
if [[ -v map_opts["help"] ]]; then
	echo -e $help
	exit 0
fi

# matches function prototypes in a file
regex_prototype='[a-zA-Z0-9_ ]+	+\**[a-z][a-z0-9_]+\(([a-zA-Z0-9_*]* [a-zA-Z0-9_,*]*)*\)$'
# matches function names in a prototype
regex_function='[a-zA-Z0-9_]*\('

# looks for c files in the source directory
for file in $(find ${map_opts["dir"]} -name "*.c"); do
	# displays file name if in verbose mode
	if [[ -v map_opts["verbose"] ]]; then
		echo "[ $file ]"
	fi

	# keeps only the file base (without the extension)
	name_base=$(basename $file .c)
	# the name of the header file
	name_file="$name_base.h"
	# the define name used to protect from double inclusions
	name_prot=$(echo $name_file | tr '[:lower:]' '[:upper:]' | tr '.' '_')
	# retrieves all functon prototypes in the file
	prototype=($(grep -v 'static' $file | grep -oE $regex_prototype))

	# adds header protection
	echo "#ifndef $name_prot" > $name_file
	echo "# define $name_prot" >> $name_file
	echo "" >> $name_file

	# stores necessary includes
	import_extra=0
	declare -A map_include
	declare -A map_struct

	# for every function prototype in the current file...
	for function in ${prototype[@]}; do
		# ...if "size_t" is found...
		if [[ ! -v map_include["size_t"] && $function == *"size_t"* ]]; then
			# includes stddef.h
			map_include["size_t"]=1
			import_extra=1
			echo "# include <stddef.h>" >> $name_file
			# logs info message if in verbose mode
			if [[ -v map_opts["verbose"] ]]; then
				echo " Including stddef.h"
			fi
		fi
		# ...if "bool" is found...
		if [[ ! -v map_include["bool"] && $function == *"bool"* ]]; then
			# includes stdbool.h
			map_include["bool"]=1
			import_extra=1
			echo "# include <stdbool.h>" >> $name_file
			# logs info message if in verbose mode
			if [[ -v map_opts["verbose"] ]]; then
				echo " Including stdbool.h"
			fi
		fi
		# ...if "va_list" is found...
		if [[ ! -v map_include["va_list"] && $function == *"va_list"* ]]; then
			# includes stdarg.h
			map_include["va_list"]=1
			import_extra=1
			echo "# include <stdarg.h>" >> $name_file
			# logs info message if in verbose mode
			if [[ -v map_opts["verbose"] ]]; then
				echo " Including stdarg.h"
			fi
		fi
		# ...if a struct is found...
		struct=$(echo $function | grep -oE 't_s_[a-zA-Z0-1_]*' | sed -s 's/t_//')
		if [[ $struct && ! -v map_struct[$file:$struct] ]]; then
			# includes the header associated to that struct
			map_struct["$file:$struct"]=1
			echo "# include \"$struct.h\"" >> $name_file
			# logs info message if in verbose mode
			if [[ -v map_opts["verbose"] ]]; then
				echo " Including $struct.h"
			fi
		fi
	done

	# if extra headers were imported...
	if [[ $import_extra == 1 ]]; then
		# ...adds a newline
		echo "" >> $name_file
	fi

	# for every prototype in the current file...
	for function in ${prototype[@]}; do
		# adds prototype to the header
		echo "$function;" >> $name_file
		# logs info message if in verbose mode
		if [[ -v map_opts["verbose"] ]]; then
			name_fun=$(echo $function | grep -oE $regex_function | sed -s 's/(//') 
			echo " Addding $name_fun to $name_file"
		fi
	done

	# closes start ifndef
	echo "" >> $name_file
	echo "#endif" >> $name_file
done
