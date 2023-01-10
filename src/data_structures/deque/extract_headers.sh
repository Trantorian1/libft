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
			i=$(i+1)	# moves on to the next argument
			;;
		--verbose|-v)	# activates verbose output
			map_opts["verbose"]=1
			;;
		--help|-h)		# displays help
			map_opts["help"]=1
			;;
	esac
done

# matches function prototypes in a file
regex_prototype='[a-zA-Z0-9_ ]+	+\**[a-z][a-z0-9_]+\(([a-zA-Z0-9_*]* [a-zA-Z0-9_,*]*)*\)$'

# looks for c files in the source directory
for file in $(find map_opts["dir"] -name "*.c"); do
	# uses '\n' as field seperator so our greps 
	# are not seperated at each \t and ' '
	IFS=$'\n'

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
		if [[ ! -v map_include["size_t"] && $function == *"size_t"* ]]; then
			map_include["size_t"]=1
			import_extra=1
			echo "# include <stddef.h>" >> $name_file
		fi
		if [[ ! -v map_include["bool"] && $function == *"bool"* ]]; then
			map_include["bool"]=1
			import_extra=1
			echo "# include <stdbool.h>" >> $name_file
		fi
		if [[ ! -v map_include["va_list"] && $function == *"va_list"* ]]; then
			map_include["va_list"]=1
			import_extra=1
			echo "# include <stdarg.h>" >> $name_file
		fi
		struct=$(echo $function | grep -oE 't_s_[a-zA-Z0-1_]*' | sed -s 's/t_//')
		if [[ $struct && ! -v map_struct[$file:$struct] ]]; then
			map_struct["$file:$struct"]=1
			echo "# include \"$struct.h\"" >> $name_file
		fi
	done

	if [[ $import_extra == 1 ]]; then
		echo "" >> $name_file
	fi

	for function in ${prototype[@]}; do
		if [[ -v map_opts["verbose"] ]]; then
			name_fun=$(echo $function | grep -oE '[a-zA-Z0-9_]*\(' | sed -s 's/(//') 
			echo "Addding $name_fun to $name_file"
		fi
		echo "$function;" >> $name_file
	done

	echo "" >> $name_file
	echo "#endif" >> $name_file
done
