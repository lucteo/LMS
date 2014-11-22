
DEBUG_FLAGS=
OPT_LEVEL=-O2
INCLUDES=-I/usr/local/include
LIBS=-L/usr/local/lib -lczmq -lzmq
GCC=clang
RUN_ARGS=50000

OPTS=-O2

all: server.out client.out find.out dealer.out

%.out: %.o
	$(GCC) -o $@ $< $(LIBS) $(OPT_LEVEL) $(DEBUG_FLAGS)

%.o: %.c
	$(GCC) -o $@ $< -c $(OPT_LEVEL) $(CPP_FLAGS) $(INCLUDES)

run: server.out
	./server.out $(RUN_ARGS)

clean:
	rm -f *~
	rm -f *.ll
	rm -f *.bc
	rm -f *.o
	rm -f *.out
