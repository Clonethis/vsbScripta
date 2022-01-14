# hello:
# 	echo "hello world"
# blah: blah.o
# 	cc blah.o -o blah # Runs third

# blah.o: blah.c
# 	cc -c blah.c -o blah.o # Runs second

# blah.c:
# 	echo "int main() { return 0; }" > blah.c # Runs first
# some_file: other_file
# 	echo "This will run second, because it depends on other_file"
# 	touch some_file

# other_file:
# 	echo "This will run first"
# 	touch other_file

# files := file1 file2
# some_file: $(files)
# 	echo "Look at that var " $(files)
# 	touch some_file
CC = gcc # Flag for implicit rules
# flag for compiler..m
CFLAGS = -Wall# Flag for implicit rules. Turn on debug info
ASAN_FLAGS = -fsanitize=address -fno-omit-frame-pointer -Wno-format-security

file1: $
	touch fileNumero1
file2:
	touch fileNumero2
clean:
	rm -f fileNumero1 fileNumero2 some_file
createM:
	gcc main.c -o michal
borek:
	echo " nn borka nemuzes udelat, protoze nejsi teplej"
file:
	gcc fileopener.c -o nice
run:
	nice f1.txt game.txt
nice2:
	gcc fileopener.c -o nice $(ASAN_FLAGS)
	nice users.txt matchData.txt 
svg:
	gcc ./svgC/svg.c -o nice $(ASAN_FLAGS)
	nice
trial:
	gcc trial.c -o nice
	nice users.txt matchData.txt 
overkill:
	gcc -g trial.c -o nice
	lldb nice users.txt matchData.txt 
	run -flag1 -flag2
