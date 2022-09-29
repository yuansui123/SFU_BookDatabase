test: main.o Book.o Database.o Menu.o
	g++ -o test main.o Book.o Database.o Menu.o

main: main.cpp
	g++ -c main.cpp

Book: Book.h Book.cpp ansi_codes.h
	g++ -c Book.cpp

Database: Database.h Database.cpp
	g++ -c Database.cpp

Menu: Menu.h Menu.cpp ansi_codes.h
	g++ -c Menu.cpp

clean:
	rm -f test main.o Book.o Database.o Menu.o

CPPFLAGS = -std=c++14 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g