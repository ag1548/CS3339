.PHONY: run compile clean

run:
	@${MAKE} --no-print-directory compile
	@./main
	@${MAKE} --no-print-directory clean

compile:
	g++ -o main main.cpp -g -O0 --save-temps
	objdump -D main > main_dump

clean:
	rm main

clean_all:
	@-rm main main_dump main.ii main.o main.s
