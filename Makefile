CXX = g++

gc:	gc.o
	$(CXX) gc.cpp -o gc.o
	
clean:	
	rm -f *.o 
