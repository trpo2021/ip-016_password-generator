APP_NAME = generator
LIB_NAME = libgenerator
APP_TEST_NAME = password_generator_test

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -I thirdparty -MP -MMD
GDB = -g -O0

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_DIR)/$(APP_TEST_NAME)
CTEST_PATH = $(TP_DIR)/ctest.h

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)
APP_TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
APP_TEST_OBJECTS = $(APP_TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

.PHONY: all clean test

all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	g++ $(CFLAGS) $(GDB) $(CPPFLAGS) $^ -o $@ 

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	g++ -c $(CFLAGS) $(GDB) $(CPPFLAGS) $< -o $@

test: $(TEST_PATH)

$(OBJ_DIR)/$(TEST_DIR)/%.o: %.cpp
	g++ -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(TEST_PATH): $(APP_TEST_OBJECTS) $(LIB_PATH)
	g++ $(CFLAGS) $(CPPFLAGS) $^ -o $@ 

clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
