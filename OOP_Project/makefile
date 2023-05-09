output: main.o Customer.o Restaurants.o Offers.o Bill.o
	g++ main.o Customer.o Restaurants.o Offers.o Bill.o -o output

main.o: main.cpp
	g++ -c main.cpp

Customer.o: Customer.cpp Customer.h
	g++ -c Customer.cpp

Restaurants.o: Restaurants.cpp Restaurants.h
	g++ -c Restaurants.cpp

Offers.o: Offers.cpp Offers.h
	g++ -c Offers.cpp

Bill.o: Bill.cpp Bill.h
	g++ -c Bill.cpp

clean:
	rm *.o output