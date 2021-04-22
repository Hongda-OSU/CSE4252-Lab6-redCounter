#
# Hongda Lin: C++ Makefile
# Modify Date: 23/3/2021

all:  tags headers

#*********************************************************

clean: 
	rm -rf *.o

# Build executable #

redCounter2: redCounter2.o function.o
	g++ -g -o $@ $^

#*********************************************************

# building the zip file.

lab6.zip: makefile readme *.cpp *.h
	zip lab6.zip makefile readme *.cpp *.h
	rm –rf install
	# create the install folder
	mkdir install
	# unzip to the install folderunzip *.zip –d install
	unzip lab6.zip -d install
	# make ONLY the * target, not *.zip
	make –C install lab6

#*********************************************************

%.o: %.cpp
	g++ -g -c -o $@ $^

#*********************************************************
