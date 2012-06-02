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
exer1: 7-1.cpp $(headers)
	$(recipe)
exer2: 7-2.cpp $(headers)
	$(recipe)
exer3: 7-3.cpp $(headers)
	$(recipe)
exer4: 7-4.cpp $(headers)
	$(recipe)
exer5: 7-5.cpp $(headers)
	$(recipe)
exer6: 7-6.cpp $(headers)
	$(recipe)
exer7: 7-7.cpp $(headers)
	$(recipe)
exer9: 7-9.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
