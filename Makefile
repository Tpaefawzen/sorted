.PHONY: release debug clean

# SETTINGS
root = .
target = Sorted
objects = .
CXXFLAGS = -fno-for-scope -fno-rtti -DTARGET_IS_UNIX -traditional -traditional-cpp -O0
CXX = g++

src = EnglishNumbers.cpp GermanNumbers.cpp Sorted.cpp SortedSyntax.cpp SortedInterpreter.cpp OPP.cpp gtools.cpp
obj = $(src:.cpp=.o)

release: $(obj)
	mkdir -p release
	$(CXX) $(CXXFLAGS) -o release/$(target) $(obj)

debug: $(obj)
	mkdir -p debug
	$(CXX) $(CXXFLAGS) -g -o debug/$(target) $(obj)

clean:
	rm -f *.o
	rm -Rf release/ debug/
	rm -f *,opp examples/*.s,opp
