N=100

all: funnelsort blatt02.pdf
blatt02.pdf: blatt02.tex
	latexmk -pdf -bibtex blatt02.tex
funnelsort: funnelsort.cpp
	g++ -g -Wall -o funnelsort funnelsort.cpp
clean:
	latexmk -C
	rm -f funnelsort
	rm -f testdataset testdataset.sorted testdataset.check
test: funnelsort
	shuf -i 1-100 -n $N > testdataset
	cat testdataset | ./funnelsort $N > testdataset.sorted
	cat testdataset | sort -n > testdataset.check
	diff -q testdataset.sorted testdataset.check
