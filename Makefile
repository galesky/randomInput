
txt: 
	./randomInput.out $$size 0

dat: 
	./randomInput.out $$size 1

all: randomInput
	g++ -o randomInput.out randomInput.cpp
	
run: 
	./randomInput.out $$args
