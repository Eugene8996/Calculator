SRC := main.c
SRC_OBJ := main.o
LIB_SRC := calculator.c
LIB_OBJ := calculator.o
LIB := calculator
EXEC := exec

L_FLAGS := -L. -l$(LIB) -Wl,-rpath,.

all: $(SRC_OBJ) $(LIB)
	gcc $(SRC_OBJ) $(L_FLAGS) -o $(EXEC)

$(SRC_OBJ): %.o : %.c
	gcc -c $< -o $@

$(LIB): $(LIB_OBJ)
	gcc -shared -o lib$@.so $(LIB_OBJ)
	
$(LIB_OBJ): %.o : %.c
	gcc -fPIC -c $< -o $@

clean:
	rm -f $(SRC_OBJ) $(LIB_OBJ) $(EXEC) lib$(LIB).so
