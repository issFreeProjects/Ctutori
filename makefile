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
DSDIR   = ds
CFLAGS  = -I .
OCFLAGS = -I $(UDIR)


_OBJ    = ptrs.o pprint.o hash.o mmath.o sort.o intLinkedList.o binarySearchTree.o main.o
# create .o path: build/example.o
OBJ     = $(patsubst %,$(ODIR)/%,$(_OBJ))




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

# compiling main.c and linking .o files to exec file
main: $(OBJ) main.c
	$(CC) $(CFLAGS)  -c main.c -o $(ODIR)/main.o
	$(CC) $(OCFLAGS) -o $@ $(OBJ)


# clean
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o