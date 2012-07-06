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
exer2: 17-2.cpp $(headers)
	$(recipe)
exer3: 17-3.cpp $(headers)
	$(recipe)
exer4: 17-4.cpp $(headers)
	$(recipe)
exer5: 17-5.cpp $(headers)
	$(recipe)
exer6: 17-6.cpp $(headers)
	$(recipe)
exer7: 17-7.cpp $(headers)
	$(recipe)
exer8: 17-8.cpp $(headers)
	$(recipe)
exer9: 17-9.cpp $(headers)
	$(recipe)
exer10: 17-10.cpp $(headers)
	$(recipe)
exer13: 17-13.cpp $(headers)
	$(recipe)
exer14: 17-14.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
