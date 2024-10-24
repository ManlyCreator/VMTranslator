# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rami/CProjects/VMTranslator/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rami/CProjects/VMTranslator/build

# Include any dependencies generated for this target.
include Parser/CMakeFiles/Parser.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Parser/CMakeFiles/Parser.dir/compiler_depend.make

# Include the progress variables for this target.
include Parser/CMakeFiles/Parser.dir/progress.make

# Include the compile flags for this target's objects.
include Parser/CMakeFiles/Parser.dir/flags.make

Parser/CMakeFiles/Parser.dir/src/parser.c.o: Parser/CMakeFiles/Parser.dir/flags.make
Parser/CMakeFiles/Parser.dir/src/parser.c.o: /home/rami/CProjects/VMTranslator/src/Parser/src/parser.c
Parser/CMakeFiles/Parser.dir/src/parser.c.o: Parser/CMakeFiles/Parser.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/rami/CProjects/VMTranslator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Parser/CMakeFiles/Parser.dir/src/parser.c.o"
	cd /home/rami/CProjects/VMTranslator/build/Parser && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Parser/CMakeFiles/Parser.dir/src/parser.c.o -MF CMakeFiles/Parser.dir/src/parser.c.o.d -o CMakeFiles/Parser.dir/src/parser.c.o -c /home/rami/CProjects/VMTranslator/src/Parser/src/parser.c

Parser/CMakeFiles/Parser.dir/src/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Parser.dir/src/parser.c.i"
	cd /home/rami/CProjects/VMTranslator/build/Parser && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rami/CProjects/VMTranslator/src/Parser/src/parser.c > CMakeFiles/Parser.dir/src/parser.c.i

Parser/CMakeFiles/Parser.dir/src/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Parser.dir/src/parser.c.s"
	cd /home/rami/CProjects/VMTranslator/build/Parser && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rami/CProjects/VMTranslator/src/Parser/src/parser.c -o CMakeFiles/Parser.dir/src/parser.c.s

# Object files for target Parser
Parser_OBJECTS = \
"CMakeFiles/Parser.dir/src/parser.c.o"

# External object files for target Parser
Parser_EXTERNAL_OBJECTS =

Parser/libParser.a: Parser/CMakeFiles/Parser.dir/src/parser.c.o
Parser/libParser.a: Parser/CMakeFiles/Parser.dir/build.make
Parser/libParser.a: Parser/CMakeFiles/Parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/rami/CProjects/VMTranslator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libParser.a"
	cd /home/rami/CProjects/VMTranslator/build/Parser && $(CMAKE_COMMAND) -P CMakeFiles/Parser.dir/cmake_clean_target.cmake
	cd /home/rami/CProjects/VMTranslator/build/Parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Parser/CMakeFiles/Parser.dir/build: Parser/libParser.a
.PHONY : Parser/CMakeFiles/Parser.dir/build

Parser/CMakeFiles/Parser.dir/clean:
	cd /home/rami/CProjects/VMTranslator/build/Parser && $(CMAKE_COMMAND) -P CMakeFiles/Parser.dir/cmake_clean.cmake
.PHONY : Parser/CMakeFiles/Parser.dir/clean

Parser/CMakeFiles/Parser.dir/depend:
	cd /home/rami/CProjects/VMTranslator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rami/CProjects/VMTranslator/src /home/rami/CProjects/VMTranslator/src/Parser /home/rami/CProjects/VMTranslator/build /home/rami/CProjects/VMTranslator/build/Parser /home/rami/CProjects/VMTranslator/build/Parser/CMakeFiles/Parser.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Parser/CMakeFiles/Parser.dir/depend

