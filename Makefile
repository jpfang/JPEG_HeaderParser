include config.mk

#GNU makefile .c .cpp .o is default in implicit
#we can clean 
.SUFFIXS:

#then add .c file to implicit
.SUFFIXS:.c

#find all .c file in current dir.
SOURCES := $(wildcard $(PROJECTDIR)/src/*.c)
SOURCES += $(wildcard $(PROJECTDIR)/app/myjpeg/src/*.c)

#Using .o instead .c for variable objects
OBJECTS= $(SOURCES:.c=.o)

#Set Target
EXEBINARY=myjpeg.out
STRIPEXEBINARY=myjpeg

#Set Install Dir
INSTALLDIR=./bin

#target ... :dependencies ...
#	Command line1	#each Cmmand line is "Independent"!
#	Command line2 \ #if you want Command line 2, 3 to combine, plz using "\" to connect next command line
#	Command line3
#       .
#       .
#		.

all:$(EXEBINARY) install

#$@ is target
$(EXEBINARY):$(OBJECTS)
	$(CROSSCOMPILE)$(CC) $(FALGS) $(OBJECTS) -o $@ $(LIBRARYDIR) $(LIBRARYS)

#$< is first dependency
#$^ is all dependency
#$% is target menber e.g. foo.a(bar.o)
#$? is all dependencies that are newer than target
#$+ is like ‘$^’, but dependencies listed more than once are duplicated in the order they were listed in the makefile.
#$* The stem with which an implicit rule matches.
%.o:%.c
	$(CROSSCOMPILE)$(CC) -c $(FALGS) $< $(INCLUDEDIR) -o $@

install:
	if [ ! -d $(INSTALLDIR) ]; then \
		mkdir $(INSTALLDIR); \
	fi

	@#to get small size for exebinary
	@#remove debug message in exebinary
	$(CROSSCOMPILE)$(STRIP) $(EXEBINARY) -o $(STRIPEXEBINARY)
	mv $(STRIPEXEBINARY) $(INSTALLDIR)

ifeq ($(CROSSCOMPILE)$(CC),gcc)
	@echo "$(STRIPEXEBINARY) is for x86/x64 platform"
else
    @echo "$(STRIPEXEBINARY) is for ARM platform"
endif

clean:
	@#- ignore errors in commandline
	clear
	-rm -f $(EXEBINARY) $(OBJECTS)
	-rm -rf $(INSTALLDIR)
