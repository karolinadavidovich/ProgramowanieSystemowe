username=$(shell whoami)
timespan=$(shell date +%s)
filename=$(username)_$(timespan).txt
outdir="build"

all: data.txt $(outdir)
	cp data.txt $(outdir)/$(filename)

data.txt:
	echo "Hello, world!" > data.txt

clean:
	rm -rf $(outdir)
	rm data.txt

$(outdir):
	mkdir $(outdir)

