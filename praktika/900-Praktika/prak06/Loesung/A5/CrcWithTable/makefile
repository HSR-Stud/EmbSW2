#
# Makefile to profile the CRC program with valgrind
# File: makefile
# Gian Danuser, 06.04.2016
#
CC = g++
LINK = g++
# '-g3' to include debugging information
CFLAGS = -c -Wall -pedantic -g3
LFLAGS = -pedantic -Wall
OBJS = Crc.o crcTest.o
EXEC = crcTest

$(EXEC): $(OBJS)
	$(LINK) $(LFLAGS) -o $(@) $(OBJS)

crcTest.o: crcTest.cpp Crc.h
	$(CC) $(CFLAGS) crcTest.cpp

Crc.o: Crc.cpp Crc.h
	$(CC) $(CFLAGS) Crc.cpp

clean:
	rm -f $(EXEC) $(OBJS) callgrind.out.*

callgrind: $(EXEC)
	valgrind --tool=callgrind ./$(EXEC) datafile.txt && kcachegrind
