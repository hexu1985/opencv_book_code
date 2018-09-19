RM = rm -f
CXX = g++
CXXFLAGS = -Wall -g $(shell pkg-config --cflags opencv)
INCLUDES =
LDFLAGS = $(shell pkg-config --libs opencv)
LDPATH =

SOURCES = $(shell ls *.cpp)
PROGS = $(SOURCES:%.cpp=%)

all: $(PROGS)
	@echo "PROGS = $(PROGS)" 

clean:
	$(RM) $(PROGS)
	$(RM) -r build

%: %.cpp
	$(CXX) -o $@ $(CXXFLAGS) $(INCLUDES) $^ $(LDFLAGS) $(LDPATH)
