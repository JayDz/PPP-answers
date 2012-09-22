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
exer3: 25-3.cpp $(headers)
	$(recipe)
exer5: 25-5.cpp $(headers)
	$(recipe)
exer6: 25-6.cpp $(headers)
	$(recipe)
exer7: 25-7.cpp $(headers)
	$(recipe)
exer8: 25-8.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
