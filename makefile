main:main.o folder.o OutputFile.o
	g++ -std=c++11 -o main main.o folder.o OutputFile.o

main.o:main.cpp
	g++ -std=c++11 -c -o main.o main.cpp
folder.o:folder.cpp
	g++ -std=c++11 -c -o folder.o folder.cpp
OutputFile.o:OutputFile.cpp
	g++ -std=c++11 -c -o OutputFile.o OutputFile.cpp

.PHONY:clean
clean:
	-rm *.o main
