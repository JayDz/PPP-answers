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
exer1: 19-1.cpp $(headers)
	$(recipe)
exer2: 19-2.cpp $(headers)
	$(recipe)
exer3: 19-3.cpp $(headers)
	$(recipe)
exer4: 19-4.cpp $(headers)
	$(recipe)
exer5: 19-5.cpp $(headers)
	$(recipe)
exer6: 19-6.cpp $(headers)
	$(recipe)
exer7: 19-7.cpp $(headers)
	$(recipe)
exer8: 19-8.cpp $(headers)
	$(recipe)
exer9: 19-9.cpp $(headers)
	$(recipe)
exer10: 19-10.cpp $(headers)
	$(recipe)
exer11: 19-11.cpp $(headers)
	$(recipe)
exer12: 19-12.cpp $(headers)
	$(recipe)
exer13: 19-13.cpp $(headers)
	$(recipe)
exer14: 19-14.cpp $(headers)
	$(recipe)
exer15: 19-15.cpp $(headers)
	$(recipe)
exer16: 19-16.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
