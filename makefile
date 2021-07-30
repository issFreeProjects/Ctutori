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
CFLAGS  = -I .
OCFLAGS = -I $(UDIR)


_OBJ    = ptrs.o pprint.o intLinkedList.o main.o
# create .o path: build/example.o
OBJ     = $(patsubst %,$(ODIR)/%,$(_OBJ))




# compiling .c files
$(ODIR)/%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

## just for utils/*.[ch] files
$(ODIR)/%.o: $(UDIR)/%.c $(UDIR)/%.h
	$(CC) $(OCFLAGS) -c $< -o $@


# compiling main.c and linking .o files to exec file
main: $(OBJ) main.c
	$(CC) $(CFLAGS) -c main.c -o $(ODIR)/main.o
	$(CC) -o $@ $(OBJ) $(CFLAGS)


# clean
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o