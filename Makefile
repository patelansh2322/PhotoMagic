CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework
INCLUDEDIR = -I/opt/homebrew/Cellar/boost/1.87.0/include/ -I/opt/homebrew/Cellar/sfml@2/2.6.2/include/
LIBDIR = -L/opt/homebrew/Cellar/boost/1.87.0/lib/ -L/opt/homebrew/Cellar/sfml@2/2.6.2/lib/
DEPS = FibLFSR.hpp PhotoMagic.hpp
OBJECTS = FibLFSR.o PhotoMagic.o
PROGRAM = PhotoMagic
TEST_EXEC = test
STATIC_LIB = PhotoMagic.a

.PHONY: all run_test clean lint

# Default build target: build program, tests, and static library
all: $(PROGRAM) $(TEST_EXEC) $(STATIC_LIB)

# Compile FibLFSR.o only once
FibLFSR.o: FibLFSR.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(INCLUDEDIR)

PhotoMagic.o: PhotoMagic.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(INCLUDEDIR)

# Compile the main program
main.o: main.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(INCLUDEDIR) -o $@

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIB)

# Build and compile tests (with TEST macro defined)
test.o: test.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< $(INCLUDEDIR) -DTEST

$(TEST_EXEC): test.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBDIR) $(LIB)

# Create static library PhotoMagic.a
$(STATIC_LIB): $(OBJECTS)
	ar rcs $@ $^

# Run the tests
run_test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Clean compiled files and the static library
clean:
	rm -f *.o $(PROGRAM) $(TEST_EXEC) $(STATIC_LIB)

# Lint check
lint:
	cpplint *.cpp *.hpp
