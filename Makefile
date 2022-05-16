all:
	g++ -m32 -o MD5 source/md5.cpp source/printHelp.cpp source/main.cpp

clean:
	rm MD5
	rm test.md5

demo:
	md5sum test.pdf > test.md5