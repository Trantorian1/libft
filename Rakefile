require 'rake/clean'
require 'rake/loaders/makefile'

# the name of the binary to create
BINARY = 'libft.a'.freeze

# compilation side-effect files to remove
CLEAN.include('build/objs/**/*.o', 'build/deps/**/*.mf')
# compiled binary to remove
CLOBBER.include(BINARY)

# recursively finds all project c files, keeping only those added to git
SOURCE_FILES = Rake::FileList.new('src/**/*.c') do |file|
  file.exclude { |f| 'git ls-files #{f}'.empty? }
end
# object files and dependency files
OBJECT_FILES = SOURCE_FILES.pathmap("%{^src/,build/objs/}X.o")
DEPEND_FILES = SOURCE_FILES.pathmap("%{^src/,build/deps/}X.mf")

# build and header directory
BUILD_DIR = "build/".freeze
H_DIR     = "include/".freeze

# variables related to object compilation
CC        = "clang".freeze
C_FLAGS   = "-Wall -Wextra -Werror -I #{H_DIR}".freeze
C_DIR     = "src/".freeze
O_DIR     = "#{BUILD_DIR}objs/".freeze

# variables related to archive compilation
AR        = "ar".freeze
A_FLAGS   = "-cqs".freeze
A_DIR     = "./".freeze

# variables related to dependency generation
D_FLAGS   = "-I #{H_DIR} -M -MP -MM".freeze
D_DIR     = "#{BUILD_DIR}deps/".freeze

# creates all required directories
directory BUILD_DIR
directory O_DIR
directory D_DIR
directory A_DIR

# by default, builds binary
task :default => :binary

# for binary to be built, object files must have been compiled
file :binary => OBJECT_FILES do
  sh "#{AR} #{A_FLAGS} #{BINARY} #{OBJECT_FILES} -lm"
end

# for object files to be compilated, the corresponding c file must exist
rule '.o' => [->(f){source_for_object(f)}, O_DIR] do |task|
  dir = task.name.pathmap("%d")
  sh "mkdir -p #{dir}" unless Dir.exist? dir
  sh "#{CC} #{C_FLAGS} -c #{task.source} -o #{task.name}"
end

# for dependency files to be compilated, the corresponding c file must exist
rule '.mf' => [->(f){source_for_deps(f)}, D_DIR] do |task|
  dir = task.name.pathmap("%d")
  sh "mkdir -p #{dir}" unless Dir.exist? dir
  cmd = "#{CC} #{D_FLAGS} #{task.source} -MT #{task.source.ext('.o')}"
  make_target = `#{cmd}`
  open("#{task.name}", 'w') do |file|
      file.puts "#{make_target}"
      file.puts "#{make_target.sub(".o:", ".mf:")}"
  end
end

# Determines the location of c files from object paths
def source_for_object(o_file)
  SOURCE_FILES.detect do |file|
    file.ext == o_file.ext.pathmap("%{^build/objs/,src/}X")
  end
end

# Determines the location of c files from dependency paths
def source_for_deps(d_file)
  SOURCE_FILES.detect do |file|
    file.ext == d_file.ext.pathmap("%{^build/deps/,src/}X")
  end
end

# Explictly import each dependency file. If the file doesn't exist, the file
# task to create it is invoked. (rule '.mf')
DEPEND_FILES.each do |dep|
  puts "importing #{dep}"
  import dep
end

# Declare an explict file task for each dependency file. This will use the rule
# defined to create .mf files defined earlier. This is necessary because it
# assures that the .mf file exists before importing.
DEPEND_FILES.each do |dep|
  file dep
end
