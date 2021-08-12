CC= g++ -g -std=c++11 -Wall -Wextra -I. -o

main: proj4.x

proj4.x: proj4_driver.cpp bet.hpp bet.h
			$(CC) proj4.x proj4_driver.cpp

clean: 
		-rm *.o
		-rm *.h.gch
		-rm *.x