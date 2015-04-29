EXE = proj4
OBJS = proj4.o Intersection.o SafeHouse.o PoliceStation.o WalkEdge.o WalkGraph.o WalkVertex.o
CPPFLAGS = -ansi -Wall

# The variable CXX is the default C++ compiler, in this case it's g++
$(EXE): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(EXE)

.PHONY : clean
clean:
	-rm -f $(OBJS) $(EXE)