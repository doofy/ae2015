all: converter sizer
converter: converter.cpp
	g++ -Wall -g -o converter converter.cpp
sizer: sizer.cpp
	g++ -Wall -g -o sizer sizer.cpp
test: converter sizer
	./converter full test.full $$(cat test.full | wc -l)
	./converter half test.half $$(./sizer test.half)
clean:
	rm -f converter sizer
