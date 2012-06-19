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
exer1: 11-1.cpp $(headers)
	$(recipe)
exer2: 11-2.cpp $(headers)
	$(recipe)
exer3: 11-3.cpp $(headers)
	$(recipe)
exer4: 11-4.cpp $(headers)
	$(recipe)
exer5: 11-5.cpp $(headers)
	$(recipe)
exer6: 11-6.cpp $(headers)
	$(recipe)
exer7: 11-7.cpp $(headers)
	$(recipe)
exer8_part01: 11-8_part01.cpp $(headers)
	$(recipe)
exer8_part02: 11-8_part02.cpp $(headers)
	$(recipe)
exer9: 11-9.cpp $(headers)
	$(recipe)
exer10: 11-10.cpp $(headers)
	$(recipe)
exer11: 11-11.cpp $(headers)
	$(recipe)
exer12: 11-12.cpp $(headers)
	$(recipe)
exer13: 11-13.cpp $(headers)
	$(recipe)
exer14: 11-14.cpp $(headers)
	$(recipe)
exer15: 11-15.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
