EXEC := exec
SRC := main.c
SRC_OBJ := main.o
LIB_ADD := add
LIB_ADD_SO := libadd.so
LIB_SRC_ADD := add.c
LIB_OBJ_ADD := add.o
LIB_MUL := mul
LIB_MUL_SO := libmul.so
LIB_SRC_MUL := mul.c
LIB_OBJ_MUL := mul.o
LIB_SUB := sub
LIB_SUB_SO := libsub.so
LIB_SRC_SUB := sub.c
LIB_OBJ_SUB := sub.o
LIB_DIV := div
LIB_DIV_SO := libdiv.so
LIB_SRC_DIV := div.c
LIB_OBJ_DIV := div.o

LIB_PATH := plugins/

L_FLAGS := -ldl

#all: $(SRC_OBJ) $(LIB)
#	gcc $(SRC_OBJ) $(L_FLAGS) -o $(EXEC)
#
#$(SRC_OBJ): %.o : %.c
#	gcc -c $< -o $@
#
#$(LIB): $(LIB_OBJ)
#	gcc -shared -o lib$@.so $(LIB_OBJ)
#	
#$(LIB_OBJ): %.o : %.c
#	gcc -fPIC -c $< -o $@
#
#clean:
#	rm -f $(SRC_OBJ) $(LIB_OBJ) $(EXEC) lib$(LIB).so

all: $(LIB_PATH)$(LIB_ADD) $(LIB_PATH)$(LIB_SUB) $(LIB_PATH)$(LIB_MUL) $(LIB_PATH)$(LIB_DIV)
	gcc main.c -o $(EXEC) $(L_FLAGS)

$(LIB_PATH)$(LIB_ADD): 
	gcc -fPIC -c $(LIB_PATH)$(LIB_SRC_ADD) -o $(LIB_PATH)$(LIB_OBJ_ADD)
	gcc -shared $(LIB_PATH)$(LIB_OBJ_ADD) -o $(LIB_PATH)$(LIB_ADD_SO)

$(LIB_PATH)$(LIB_SUB): 
	gcc -fPIC -c $(LIB_PATH)$(LIB_SRC_SUB) -o $(LIB_PATH)$(LIB_OBJ_SUB)
	gcc -shared $(LIB_PATH)$(LIB_OBJ_SUB) -o $(LIB_PATH)$(LIB_SUB_SO)

$(LIB_PATH)$(LIB_DIV): 
	gcc -fPIC -c $(LIB_PATH)$(LIB_SRC_DIV) -o $(LIB_PATH)$(LIB_OBJ_DIV)
	gcc -shared $(LIB_PATH)$(LIB_OBJ_DIV) -o $(LIB_PATH)$(LIB_DIV_SO)

$(LIB_PATH)$(LIB_MUL): 
	gcc -fPIC -c $(LIB_PATH)$(LIB_SRC_MUL) -o $(LIB_PATH)$(LIB_OBJ_MUL)
	gcc -shared $(LIB_PATH)$(LIB_OBJ_MUL) -o $(LIB_PATH)$(LIB_MUL_SO)