vpath %.h ../../include

CC = g++
CPPFLAGS = -I ../../include -Wall
#Stop warning for deprecated headers included by std_lib_facilities.h
IGNORE = -Wno-deprecated
headers = std_lib_facilities.h
recipe = $(CC) $(CPPFLAGS) $(IGNORE) $< -o $@

.PHONY: all
all: 
	@echo "USAGE <make exerX> where X is exercise number."

exer1: 10-1.cpp $(headers)
	$(recipe)
exer2: 10-2.cpp $(headers)
	$(recipe)
exer3: 10-3.cpp $(headers)
	$(recipe)
exer4_part01: 10-4-part01.cpp $(headers)
	$(recipe)
exer4_part02: 10-4-part02.cpp $(headers)
	$(recipe)
exer4:
	@echo "Run: make exer4_part01 and make exer4_part02."
exer5: 10-5.cpp $(headers)
	$(recipe)
exer8: 10-8.cpp $(headers)
	$(recipe)
exer9: 10-9.cpp $(headers)
	$(recipe)
exer11: 10-11.cpp $(headers)
	$(recipe)
exer12: 10-12.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
