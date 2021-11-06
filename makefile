#######################################################################################
#   this is the main project make file                                                #
#   created at: 24-07-2021                                                            #
#                                                                                     #
#   run ``` make ```               to make the project --static  libraries--          #
#   run ``` make runtime_main ```  to make the project --dynamic libraries--          #
#   	you will need to copy build/*.so files in /usr/lib, or /usr/local/lib         #
#   	or use environment variables: ``` export LD_LIBRARY_PATH="$(pwd)/build" ```   #
#                                                                                     #
#   and ``` make clean ```` to remove object files                                    #
#######################################################################################

CC      = gcc
CP		= cp
RM		= rm -f
ODIR	= build
UDIR    = utils
LDIR	= lib
DSDIR   = ds
# set CFLAGS = -g -I for debugging and set CLAGS = -I for normal make
CFLAGS  = -I

## edit this part when you need to compile new file - add [filename].o to _OBJ
#  if you need to compile library:
#		add lib[lib name].so   to  _SOBJ and,   -- static  library --
#		-l[lib name]           to  LFLAGS.      -- dynamic library --
_OBJ    = ptrs.o pprint.o hash.o mmath.o 2dAlgebra.o intLinkedList.o binarySearchTree.o intStack.o scanner.o main.o
_SOBJ	= libQrcodegen.so libBarcode128GS1.so libattopng.so libupng.so
LFLAGS  = -lQrcodegen -lBarcode128GS1 -lattopng -lupng



# create .o path: build/example.o
OBJ     = $(patsubst %,$(ODIR)/%,$(_OBJ))
SOBJ	= $(patsubst %,$(ODIR)/%,$(_SOBJ))

## just for ./*.c files (otherwise cannot compile main.c when main.o does not exist)
$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) . -c $< -o $@
## just for ./*.h files
$(ODIR)/%.o: %.h
	$(CC) $(CFLAGS) . -c $< -o $@
## just for utils/*.[ch] files
$(ODIR)/%.o: $(UDIR)/%.c $(UDIR)/%.h
	$(CC) $(CFLAGS) utils -c $< -o $@
## just for ds/*.[ch] files
$(ODIR)/%.o: $(DSDIR)/%.c $(DSDIR)/%.h
	$(CC) $(CFLAGS) ds -c $< -o $@
## compiling libraries
$(ODIR)/%.so: $(LDIR)/%.c $(LDIR)/%.h
	$(CC) $(CFLAGS) lib -fPIC -shared -lc $< -o $@


# ordinary make  -- static library --
# compiling main.c and linking .o files to exec file
main: $(OBJ) $(SOBJ) main.c
	$(CC) $(CFLAGS) . -c main.c -o $(ODIR)/main.o
	$(CC) $(CFLAGS) build/ -o cTutori $(OBJ) $(SOBJ)


# alternative main  -- dynamic library --
# copy build/*.so files in /usr/lib, or /usr/local/lib
# without that, binary won't work
# if you want to use environment variables (or dont want to use /lib),
# set LD_LIBRARY_PATH:	``` export LD_LIBRARY_PATH="$(pwd)/build" ```
runtime_main: $(OBJ) $(SOBJ) main.c
	$(CC) $(CFLAGS) . -c main.c -o $(ODIR)/main.o
	$(CC) $(CFLAGS) build/ -o runtime_cTutori $(OBJ) -L $(ODIR) $(LFLAGS)


# copy build/*.so files to /usr/lib => dynamic library binary, will work
installLib: $(SOBJ)
	$(CP) $(SOBJ) /usr/lib
# remove compiled build/*.so files from /usr/lib/
uninstallLib:
	$(RM) /usr/lib/$(_SOBJ)


# clean
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(ODIR)/*.so
