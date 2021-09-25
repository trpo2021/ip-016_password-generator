CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -Werror
CPPFLAGS = -MMD -I src -I test
TEST_PATH = /test

APPLICATION_NAME = generator
APPLICATION_LIB = libgenerator

SRC = src
BIN = bin
OBJ = obj

APPLICATION_PATH = $(BIN)/$(APPLICATION_NAME)/$(APPLICATION_NAME)
LIBRARY_PATH = $(OBJ)/$(SRC)/$(APPLICATION_LIB)/$(APPLICATION_LIB).a

APPLICATION_SRC = $(shell find $(SRC)/$(APPLICATION_NAME) -name '*.cpp')
APPLICATION_OBJ = $(APPLICATION_SRC:$(SRC)/%.cpp=$(OBJ)/$(SRC)/%.o)

LIBRARY_SRC = $(shell find $(SRC)/$(APPLIACATION_LIB) -name '*.cpp')
LIBRARY_OBJ = $(LIBRARY_SRC:$(SRC)/%.cpp=$(OBJ)/$(SRC)/%.o)

TEST_SOURCES = $(wildcard test/*.cpp)
TEST_OBJECTS = $(TEST_SOURCES:test/%.cpp=$(OBJ)/test/%.o)

TEST_APP_SOURCES = $(shell find $(SRC)/$(APPLICATION_NAME) -name '*.cpp') $(shell find $(SRC)/$(APPLIACATION_LIB) -name '*.cpp')
TEST_APP_OBJECTS = $(TEST_APP_SOURCES:$(SRC)/%.cpp=$(OBJ)/test/$(SRC)/%.o)

DEPENDENCIES = $(APPLICATION_OBJ:.o=.d)

.PHONY: all
all: $(APPLICATION_PATH)
-include $(DEPENDENCIES)


$(APPLICATION_PATH): $(APPLICATION_OBJ) $(LIBRARY_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $^
	
$(OBJ)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
	
$(LIBRARY_PATH): $(LIBRARY_OBJ)
	ar rcs $@ $^

$(OBJ)/test/%.o: %.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -DTEST -c $< -o $@

$(TEST_PATH): $(TEST_APP_OBJECTS) $(TEST_OBJECTS)
	$(CC) $^ -o $@ $(CPPFLAGS) $(CFLAGS)


.PHONY: test
test: $(TEST_PATH)


.PHONY: clean
clean:
	$(RM) $(APPLICATION_PATH)
	find $(OBJ) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ) -name '*.d' -exec $(RM) '{}' \;
	find $(OBJ) -name '*.a' -exec $(RM) '{}' \;