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

exer1: 8-1.cpp $(headers)
	$(recipe)
exer2: 8-2.cpp $(headers)
	$(recipe)
exer3: 8-3.cpp $(headers)
	$(recipe)
exer4: 8-4.cpp $(headers)
	$(recipe)
exer5: 8-5.cpp $(headers)
	$(recipe)
exer6: 8-6.cpp $(headers)
	$(recipe)
exer7: 8-7.cpp $(headers)
	$(recipe)
exer8: 8-8.cpp $(headers)
	$(recipe)
exer9: 8-9.cpp $(headers)
	$(recipe)
exer10: 8-10.cpp $(headers)
	$(recipe)
exer11: 8-11.cpp $(headers)
	$(recipe)
exer12: 8-12.cpp $(headers)
	$(recipe)
exer13: 8-13.cpp $(headers)
	$(recipe)
exer14: 8-14.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
