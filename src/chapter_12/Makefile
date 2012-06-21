vpath %.h ../../include

CC = g++
CPPFLAGS = -I ../../include -Wall -lfltk -lfltk_gl -lfltk_images 
#Stop warning for deprecated headers included by std_lib_facilities.h
IGNORE = -Wno-deprecated
headers = std_lib_facilities.h
recipe = $(CC) $(CPPFLAGS) $(IGNORE) $< -o $@

.PHONY: all
all: 
	@echo "USAGE <make exerX> where X is exercise number."
exer1: 12-1.cpp $(headers)
	$(recipe)
exer2: 12-2.cpp $(headers)
	$(recipe)
exer3: 12-3.cpp $(headers)
	$(recipe)
exer4: 12-4.cpp $(headers)
	$(recipe)
exer5: 12-5.cpp $(headers)
	$(recipe)
exer6: 12-6.cpp $(headers)
	$(recipe)
exer7: 12-7.cpp $(headers)
	$(recipe)
exer8: 12-8.cpp $(headers)
	$(recipe)
exer9: 12-9.cpp $(headers)
	$(recipe)
exer10: 12-10.cpp $(headers)
	$(recipe)
exer11: 12-11.cpp $(headers)
	$(recipe)
exer12: 12-12.cpp $(headers)
	$(recipe)
exer13: 12-13.cpp $(headers)
	$(recipe)
.PHONY: clean
clean:
	@rm -rf exer*
