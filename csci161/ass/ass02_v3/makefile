pex2: main.o ui.o order.o order_list.o food_menu.o record.o
	g++ main.o ui.o order.o order_list.o food_menu.o record.o -o Pex2
main.o: main.cc ui.h food_menu.h
	g++ -c main.cc
ui.o: ui.cc order_list.h food_menu.h
	g++ -c ui.cc
order_list.o: order_list.cc order.h
	g++ -c order_list.cc	
order.o: order.cc
	g++ -c order.cc
food_menu.o: food_menu.cc record.h
	g++ -c food_menu.cc
record.o: record.cc
	g++ -c record.cc
clean:
	rm *.o main
