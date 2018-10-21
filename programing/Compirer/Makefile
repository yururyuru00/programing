CC = gcc
CFLAGS = -g

ALL = \
  vsm \
  mcc \
  testlex \


all: $(ALL)

vsm: vsm.o code.o
	$(CC) $(CFLAGS) vsm.o code.o -o vsm
mcc: mcc.o lex.o tab.o code.o
	$(CC) $(CFLAGS) mcc.o lex.o tab.o code.o -o mcc
testlex: testlex.o lex.o
	$(CC) $(CFLAGS) testlex.o lex.o -o testlex

.c.o:
	$(CC) $(CFLAGS) -c $<

lex.o: lex.c lex.h
tab.o: tab.c tab.h
code.o: code.c code.h
vsm.o: vsm.c code.h
mcc.o: mcc.c lex.h tab.h code.h
testlex.o: testlex.c lex.h

clean: 
	rm -f $(ALL) *.o
