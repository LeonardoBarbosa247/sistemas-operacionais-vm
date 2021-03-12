# Makefile (Leonardo Barbosa, Diego Oliveira e Lucas H. Hassmann; March 10th, 2021)
# Sistemas Operacionais - PUCRS

EXEC = app
CFLAGS = -c -std=c++17

${EXEC}: main.o Aux.o Cpu.o Sistema.o Vm.o Word.o
	@g++ main.o Aux.o Cpu.o Sistema.o Vm.o Word.o -o ${EXEC}

main.o: main.cpp Sistema.o
	@g++ ${CFLAGS} main.cpp

Aux.o: Aux.hpp Aux.cpp Word.o
	@g++ ${CFLAGS} Aux.cpp

Cpu.o: Cpu.hpp Cpu.cpp Word.o
	@g++ ${CFLAGS} Cpu.cpp

Vm.o: Vm.hpp Vm.cpp Word.o Cpu.o
	@g++ ${CFLAGS} Vm.cpp

Word.o: Word.hpp Word.cpp
	@g++ ${CFLAGS} Word.cpp

Sistema.o: Sistema.hpp Sistema.cpp Vm.o Aux.o Word.o
	@g++ ${CFLAGS} Sistema.cpp

run:	${EXEC}
	@./${EXEC}

clean:
	@rm -f main.o Aux.o Cpu.o Sistema.o Vm.o Word.o 

cleanall: 
	@rm -f main.o Aux.o Cpu.o Sistema.o Vm.o Word.o ${EXEC}

All: ${EXEC}