
SRC = src

SQLite: $(SRC)/main.cpp $(SRC)/commands.cpp $(SRC)/IO.cpp
	g++ -std=c++20 -Wall -Wextra -o SQLite $(SRC)/main.cpp $(SRC)/commands.cpp $(SRC)/IO.cpp

clean:
	rm -f SQLite
