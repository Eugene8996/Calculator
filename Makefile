EXEC := exec
SRC := main.c
SRC_OBJ := main.o

LIB_PATH := plugins

L_FLAGS := -ldl


all: $(LIB_PATH)
	gcc main.c -o $(EXEC) $(L_FLAGS)

.PHONY: $(LIB_PATH)
$(LIB_PATH):
	$(MAKE) -C $(LIB_PATH) lib

clean:
	rm -f $(EXEC)
	$(MAKE) -C $(LIB_PATH) clean