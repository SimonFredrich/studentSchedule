.PHONY: all

all:
	gcc -o ./out/main -g ./src/*.*

run:
	./out/main

br: all run

desktop:
	gcc -o /home/simplex/Desktop/studentSchedule -g ./src/*.*
