#
# Makefile fuer Effizienzbetrachtungen
# File: makefile
# Reto Bonderer, 28.04.2011
#
UNIT = main
CC = g++
LINK = g++
# '-pedantic' sorgt dafuer, dass g++ streng nach dem C++-Standard arbeitet
CFLAGS = -c -pedantic -Winline -O1
LFLAGS = -pedantic 
#OBJS = $(UNIT).o rectangle.o
OBJS = $(UNIT).o

$(UNIT): $(OBJS) $(UNIT).s makefile
	$(LINK) $(LFLAGS) -o $(UNIT) $(OBJS)

$(UNIT).o: $(UNIT).cpp rectangle.h makefile
	$(CC) $(CFLAGS) $(UNIT).cpp

$(UNIT).s: $(UNIT).cpp rectangle.h makefile
	$(CC) $(CFLAGS) -S $(UNIT).cpp


clean:
	rm -f $(UNIT) $(OBJS) *.s
