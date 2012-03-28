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

exer2: 5-2.cpp $(headers)
	$(recipe)
exer3: 5-3.cpp $(headers)
	$(recipe)
exer4: 5-4.cpp $(headers)
	$(recipe)
exer5: 5-5.cpp $(headers)
	$(recipe)
exer6: 5-6.cpp $(headers)
	$(recipe)
exer7: 5-7.cpp $(headers)
	$(recipe)
exer8: 5-8.cpp $(headers)
	$(recipe)
exer9: 5-9.cpp $(headers)
	$(recipe)
exer10: 5-10.cpp $(headers)
	$(recipe)
exer11: 5-11.cpp $(headers)
	$(recipe)
exer12: 5-12.cpp $(headers)
	$(recipe)
exer13: 5-13.cpp $(headers)
	$(recipe)
exer14: 5-14.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
