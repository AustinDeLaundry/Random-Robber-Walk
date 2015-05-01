#include <iostream>
#include <vector>
#include "WalkGraph.h"
#include "WalkEdge.h"
#include "WalkVertex.h"
#include "Intersection.h"
#include "SafeHouse.h"
#include "PoliceStation.h"
#include "/afs/umbc.edu/users/c/m/cmarron/pub/gtest-1.7.0/include/gtest/gtest.h"
//#include "../gtest-1.7.0/include/gtest/gtest.h"

using namespace std;

TEST(Project4_STUDENT, WalkGraph_Walk) {
  const unsigned int max_steps = 20;
  unsigned int seed = 1234;

  WalkGraph G;
  G.LoadFromFile("data/campus_v5.dat");

  vector<WalkVertex*> walkOne;
  vector<WalkVertex*> walkTwo;

  walkOne = G.Walk(vertices[0], max_steps, seed);
  walkTwo = G.Walk(vertices[0], max_steps, seed);

  bool areEqual = true;

  if(walkOne.size() != walkTwo.size())
  {
  	int counter = 0;
  	while(areEqual && counter < walkOne.size())
  	{
  	  if(walkOne.at(i) -> GetID() != walkTwo.at(i) -> GetID())
  	  {
  	  	areEqual = false;
  	  }

  	  counter++;
  	}
  }

  EXPECT_EQ(true, areEqual);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
