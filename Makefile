CLANG = clang -std=c11 -Wall -Wextra -Werror -Wpedantic
SF = src/*.c 
EFN = way_home

all: install

install:
	@${CLANG} -o ${EFN} ${SF}

uninstall: 
	@rm -rf ${EFN}

clean:


reinstall:
	@rm -rf ${EFN}
	@${CLANG} -o ${EFN} ${SF}

