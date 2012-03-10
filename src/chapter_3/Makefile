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

exer2: 3-2.cpp $(headers)
	$(recipe)
exer3: 3-3.cpp $(headers)
	$(recipe)
exer4: 3-4.cpp $(headers)
	$(recipe)
exer5: 3-5.cpp $(headers)
	$(recipe)
exer6: 3-6.cpp $(headers)
	$(recipe)
exer7: 3-7.cpp $(headers)
	$(recipe)

.PHONY: clean
clean:
	@rm -rf exer*
