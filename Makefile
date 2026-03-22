
SRC = src

SQLite: $(SRC)/main.cpp
	g++ -Wall -Wextra -o SQLite $(SRC)/main.cpp

clean:
	rm -f SQLite
