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

exer2: 6-2.cpp $(headers)
	$(recipe)
exer3: 6-3.cpp $(headers)
	$(recipe)
exer4: 6-4.cpp $(headers)
	$(recipe)
exer6: 6-6.cpp $(headers)
	$(recipe)
exer8: 6-8.cpp $(headers)
	$(recipe)
exer9: 6-9.cpp $(headers)
	$(recipe)
exer10: 6-10.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
