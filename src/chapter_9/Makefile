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

exer2: 9-2.cpp $(headers)
	$(recipe)
exer3: 9-3.cpp $(headers)
	$(recipe)
exer5: 9-5.cpp $(headers)
	$(recipe)
exer6: 9-6.cpp $(headers)
	$(recipe)
exer7: 9-7.cpp $(headers)
	$(recipe)
exer8: 9-8.cpp $(headers)
	$(recipe)
exer9: 9-9.cpp $(headers)
	$(recipe)
exer10: 9-10.cpp $(headers)
	$(recipe)
exer13: 9-13.cpp $(headers)
	$(recipe)
exer14: 9-14.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
