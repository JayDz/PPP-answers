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
exer1: 18-1.cpp $(headers)
	$(recipe)
exer2: 18-2.cpp $(headers)
	$(recipe)
exer3: 18-3.cpp $(headers)
	$(recipe)
exer4: 18-4.cpp $(headers)
	$(recipe)
exer5: 18-5.cpp $(headers)
	$(recipe)
exer6: 18-6.cpp $(headers)
	$(recipe)
exer7: 18-7.cpp $(headers)
	$(recipe)
exer8: 18-8.cpp $(headers)
	$(recipe)
exer9: 18-9.cpp $(headers)
	$(recipe)
exer10: 18-10.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
