CXXFLAGS += -std=c++11
GTKFLAGS = `pkg-config gtkmm-3.0 --cflags --libs`

ex: main.o MurderMystery.o
	$(CXX) $(CXXFLAGS) -o murder main.o MurderMystery.o $(GTKFLAGS)
	
main.o: main.cpp MurderMystery.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS)
	
MurderMystery.o: MurderMystery.h MurderMystery.cpp
	$(CXX) $(CXXFLAGS) -c MurderMystery.cpp $(GTKFLAGS)
	
clean:
	echo "Cleaning up object files and executable!"
	rm *.o
	rm murder