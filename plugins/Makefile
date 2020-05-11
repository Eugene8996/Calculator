LIB_ADD := add
LIB_MUL := mul
LIB_SUB := sub
LIB_DIV := div

lib: $(LIB_ADD) $(LIB_DIV) $(LIB_SUB) $(LIB_MUL)
	echo bla

$(LIB_ADD):
	gcc -fPIC -c $(LIB_ADD).c -o $(LIB_ADD).o
	gcc -shared $(LIB_ADD).o -o lib$(LIB_ADD).so

$(LIB_SUB): 
	gcc -fPIC -c $(LIB_SUB).c -o $(LIB_SUB).o
	gcc -shared $(LIB_SUB).o -o lib$(LIB_SUB).so

$(LIB_DIV): 
	gcc -fPIC -c $(LIB_DIV).c -o $(LIB_DIV).o
	gcc -shared $(LIB_DIV).o -o lib$(LIB_DIV).so

$(LIB_MUL): 
	gcc -fPIC -c $(LIB_MUL).c -o $(LIB_MUL).o
	gcc -shared $(LIB_MUL).o -o lib$(LIB_MUL).so

clean:
	rm -f *.o *.so