
SRC = src

SQLite: $(SRC)/main.cpp
	g++ -std=c++20 -Wall -Wextra -o SQLite $(SRC)/main.cpp

clean:
	rm -f SQLite
