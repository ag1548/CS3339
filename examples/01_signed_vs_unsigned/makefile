.PHONY: run compile clean

run:
	@${MAKE} --no-print-directory compile
	@./main
	@${MAKE} --no-print-directory clean

compile:
	@g++ -o main --save-temps main.cpp

clean:
	@-rm main main.ii main.o
