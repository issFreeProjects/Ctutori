#####################################################
#				projects make file					#
#				24  -  07  -  2021					#
#	run ``` make ```  to make project 				#
#	and``` make clean ```` to remove object files	#
#####################################################

# flags and .o files definition
CC      = gcc
ODIR	= build
UDIR    = utils
LDIR	= lib
DSDIR   = ds
CFLAGS  = -I .
OCFLAGS = -I $(UDIR)


_OBJ    = ptrs.o pprint.o hash.o mmath.o sort.o intLinkedList.o binarySearchTree.o intStack.o main.o
_SOBJ	= libQrcodegen.so
# create .o path: build/example.o
OBJ     = $(patsubst %,$(ODIR)/%,$(_OBJ))
SOBJ	= $(patsubst %,$(ODIR)/%,$(_SOBJ))




# compiling .c files
## just for .c files (otherwise cannot compile main.c when main.o not exist)
$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
## just for .h files
$(ODIR)/%.o: %.h
	$(CC) $(CFLAGS) -c $< -o $@
## just for utils/*.[ch] files
$(ODIR)/%.o: $(UDIR)/%.c $(UDIR)/%.h
	$(CC) -I utils -c $< -o $@
## just for ds/*.[ch] files
$(ODIR)/%.o: $(DSDIR)/%.c $(DSDIR)/%.h
	$(CC) -I ds -c $< -o $@
## compiling libraries
$(ODIR)/%.so: $(LDIR)/%.c $(LDIR)/%.h
	$(CC) -I lib -fPIC -shared -lc $< -o $@


# ordinary make  -- static library --
# compiling main.c and linking .o files to exec file
main: $(OBJ) main.c
	$(CC) $(CFLAGS)  -c main.c -o $(ODIR)/main.o
	$(CC) $(OCFLAGS) -o $@ $(OBJ) $(SOBJ)


# alternative main  -- dynamic library --
# copy build/.so files in /usr/lib, or /usr/local/lib
# without that, binary wont work
# if you want use Env. variables (or dont want to use /lib), use this:
# 		export LD_LIBRARY_PATH="$(pwd)/build"
runtime_main: $(OBJ) main.c
	$(CC) $(CFLAGS)  -c main.c -o $(ODIR)/main.o
	$(CC) $(OCFLAGS) -o $@ $(OBJ) -L $(ODIR) -lQrcodegen


# clean
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(ODIR)/*.so