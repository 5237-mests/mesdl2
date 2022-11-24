main: maze1.c
	gcc -I src/include -L src/lib -o main maze1.c -lmingw32 -lSDL2main -lSDL2  
