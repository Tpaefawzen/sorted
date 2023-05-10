.POSIX:

# SETTINGS
root = .
target = Sorted
objects = .
CXXFLAGS = -fno-for-scope -fno-rtti -DTARGET_IS_UNIX -traditional -traditional-cpp -O0
CXX = g++

src = EnglishNumbers.cpp GermanNumbers.cpp Sorted.cpp SortedSyntax.cpp OPP.cpp gtools.cpp

all: $(target)

$(target): $(src)
	$(CXX) $(CXXFLAGS) -o $< $@

debug: # HELP HOW?
	mkdir -p debug
	$(CXX) $(CXXFLAGS) -g -o debug/$(target) $(src)
