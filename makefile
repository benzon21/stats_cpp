newfile: newfile.o
	g++ newfile.o -o newfile

newfile.o: newfile.cpp
	g++ -c newfile.cpp

clean:
	rm *.o newfile