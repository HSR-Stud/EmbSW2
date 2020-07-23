#
# Makefile fuer CRC Programm
# File: makefile
# Reto Bonderer, 25.03.2019
#
CC = g++
LINK = g++
# '-pedantic' sorgt dafuer, dass g++ streng arbeitet
CFLAGS = -c -Wall -pedantic
LFLAGS = -pedantic -Wall
OBJS = Crc.o crcTest.o

crcTest: $(OBJS)
	$(LINK) $(LFLAGS) -o $(@) $(OBJS)

crcTest.o: crcTest.cpp Crc.h
	$(CC) $(CFLAGS) crcTest.cpp

Crc.o: Crc.cpp Crc.h
	$(CC) $(CFLAGS) Crc.cpp

clean:
	rm -f crcTest $(OBJS)
