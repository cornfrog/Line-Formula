all:
	@gcc mx.c -o mx
	@mv mx bin
	@echo MAKE Success: use \'make run\' to run

run:
	@./bin/mx 

clean:
	@rm bin/mx
	@echo MAKE CLEAN Success: use \'make\' to recompile
