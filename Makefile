SRC := main.c
SRC_OBJ := main.o
LIB_SRC := calculator.c
LIB_OBJ := calculator.o
LIB := calculator
EXEC := exec

L_FLAGS := -L. -l$(LIB)

all: $(SRC_OBJ) $(LIB)
	gcc $(SRC_OBJ) $(L_FLAGS) -o $(EXEC)

$(SRC_OBJ): %.o : %.c
	gcc -c $< -o $@

$(LIB): $(LIB_OBJ)
#	ar rcs lib$@.a $(LIB_OBJ)
	gcc -shared -o lib$@.so $(LIB_OBJ)
	pwd
	export LD_LIBRARY_PATH=$PWD

$(LIB_OBJ): %.o : %.c
	gcc -fPIC -c $< -o $@

clean:
	rm -f $(SRC_OBJ) $(LIB_OBJ) lib$(LIB).a $(EXEC) lib$(LIB).so
