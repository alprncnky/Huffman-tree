hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Bitsetler.o -c ./src/Bitsetler.cpp
	g++ -I ./include/ -o ./lib/Huffman.o -c ./src/Huffman.cpp
	g++ -I ./include/ -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Islem.o ./lib/Huffman.o ./lib/Bitsetler.o ./lib/Dugum.o ./src/test.cpp
	
calistir:	
	./bin/test