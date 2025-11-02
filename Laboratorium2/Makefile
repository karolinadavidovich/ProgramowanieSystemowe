target=hello
filename=hello.c
fileO=hello.o
outdir=build
dir=src
cc=gcc
cflags=-Wall -g

all: $(target)

$(target): $(outdir) $(fileO)
	$(cc) $(outdir)/$(fileO) -o $(outdir)/$(target)
	cp $(dir)/$(filename) $(outdir)/$(filename)

$(fileO): $(dir) $(outdir)
	$(cc) -c $(dir)/$(filename) -o $(outdir)/$(fileO)

clean:
	rm -rf $(outdir)

$(outdir):
	mkdir -p $(outdir)
