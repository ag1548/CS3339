.PHONY: run compile clean

run:
	@${MAKE} --no-print-directory compile
	@time -p ./main
	@${MAKE} --no-print-directory clean

compile:
	@g++ -o main --save-temps main.cpp

clean:
	@-rm main main.ii main.o main.s

diff:
	diff main.s.fast main.s.slow
