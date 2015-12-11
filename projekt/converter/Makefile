all: converter sizer
converter: converter.cpp
	g++ -Wall -g -o converter converter.cpp
sizer: sizer.cpp
	g++ -Wall -g -o sizer sizer.cpp
test: converter sizer
	./converter full test.full $$(cat test.full | wc -l) 2
	./converter half test.half $$(./sizer test.half) 2
clean:
	rm -f converter sizer
