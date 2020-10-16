
GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)
GCOV = -ftest-coverage -fprofile-arcs
VALGRIND = -g

G++_FLAGS = -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

ODIR=obj
LDIR =../lib

_DEPS = pilha.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = pilha.o testa_pilha.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

testa_pilha: $(OBJ)
	$(CC) $(VALGRIND) -o $@ $^ $(LD_FLAGS) $(CFLAGS) $(GCOV)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(VALGRIND) -c -o $@ $(G++_FLAGS) $< $(CFLAGS) $(GCOV) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o  $(ODIR)/*.gcno $(ODIR)/*.gcov $(ODIR)/*.h.gcov $(ODIR)/*.c.gcov *~ core $(INCDIR)/*~
