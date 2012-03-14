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

exer2: 4-2.cpp $(headers)
	$(recipe)
exer3: 4-3.cpp $(headers)
	$(recipe)
exer4: 4-4.cpp $(headers)
	$(recipe)
exer5: 4-5.cpp $(headers)
	$(recipe)
exer6: 4-6.cpp $(headers)
	$(recipe)
exer7: 4-7.cpp $(headers)
	$(recipe)
exer8: 4-8.cpp $(headers)
	$(recipe)
exer9: 4-9.cpp $(headers)
	$(recipe)
exer10: 4-10.cpp $(headers)
	$(recipe)
exer11: 4-11.cpp $(headers)
	$(recipe)

.PHONY: clean
clean:
	@rm -rf exer*
