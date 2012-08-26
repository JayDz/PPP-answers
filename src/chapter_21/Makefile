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
exer3: 21-3.cpp $(headers)
	$(recipe)
exer4: 21-4.cpp $(headers)
	$(recipe)
exer5: 21-5.cpp $(headers)
	$(recipe)
exer6: 21-6.cpp $(headers)
	$(recipe)
exer7: 21-7.cpp $(headers)
	$(recipe)
exer8: 21-8.cpp $(headers)
	$(recipe)
exer9: 21-9.cpp $(headers)
	$(recipe)
exer10: 21-10.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
