all: copy

mkdir:
	if [ ! -d "../build/chapter4" ]; then mkdir ../build/chapter4; fi

copy: copy.c mkdir
	gcc -g copy.c -o ../build/chapter4/copy
clean:
	rm -rf ../build/chapter4/*
