#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "WalkGraph.h"
#include "PoliceStation.h"
#include "SafeHouse.h"

using namespace std;

void PrintFileStatus(string fileName);
void PrintOptions();
char TakeSelection();
bool LoadFile(WalkGraph* walkGraph, string* fileName);

/*
 * ValidVertex(Graph*, int)
 * Checks if the vertex ID givenis valid for the loaded file
 * Pre:  Graph is a valid graph object, and vertexID is an integer within the range of int
 * Post: Returns wether the vertex is able to be accessed by the graph
 */
bool ValidVertex(WalkGraph* walkGraph, int vertexID);

void ListVertices(WalkGraph* walkGraph);
void ListEdges(WalkGraph* walkGraph);
void GraphWalk(WalkGraph* walkGraph);

int main()
{
	string fileName = "";
	char selection = '\0';
	WalkGraph walkGraph;

	while(selection != 'q')
	{
		PrintFileStatus(fileName);
		PrintOptions();

		selection = TakeSelection();

		switch(selection)
		{
			case('l'):
			{
				printf("Enter the file name: ");
				string oldFileName = fileName;
				cin >> fileName;

				if(!LoadFile(&walkGraph, &fileName))
				{
					fileName = oldFileName;
				}
				break;
			}

			case('v'):
			{
				ListVertices(&walkGraph);
				break;
			}

      case('e'):
      {
        ListEdges(&walkGraph);
        break;
      }

      case('w'):
      {
        GraphWalk(&walkGraph);
        break;
      }

			case('q'):
			{
				printf("\nGoodbye!\n");
				break;
			}
		}
	}

	return 0;
}

void PrintFileStatus(string fileName)
{
  printf("\n"); //Add a new line to make it pretty

  if(fileName == "") //There is no file loaded
    printf("There is no data file loaded");

  else //There is a file loaded
    printf("The data file %s is loaded\n", fileName.c_str());

  printf("\n"); //Add a new line to make it pretty
}

void PrintOptions()
{
  //Print all options possible
  printf("Choose an action from the following menu: \n\n");
  printf(" l - load a data file\n");
  printf(" v - list the vertices of the loaded graph\n");
  printf(" e - list the edges of the loaded graph \n");
  printf(" w - simulate a random walk from a given vertex\n");
  printf(" q - quit\n");
}

char TakeSelection()
{
  char selection = '\0';        //Selection
  bool properSelection = false;    //Current selection is '\0', so not valid

  //While we don't have a proper selection
  while(!properSelection)
  {
    //Get selection
    printf("Selection: ");
    cin >> selection;

    switch(selection)
    {
      //If proper selection set properSelection true to break loop
      case('l'): case('v'): case('e'):
      case('w'): case('q'):
        properSelection = true;
        break;

      //Not a proper selection, keep it false and print error
      default: 
        printf("ERROR! Please select again!\n");
        break;
    }
  }

  return selection;
}

bool LoadFile(WalkGraph* walkGraph, string* fileName)
{
  //If error in loading file
  if(!walkGraph -> LoadFromFile(*fileName))
  {
    //Print error
    printf("Error loading the data file (%s)\n", fileName -> c_str());
    return false;
  }

  else
  {
    return true;
  }
}

bool ValidVertex(WalkGraph* walkGraph, int vertexID)
{
  //Vertex offset (Used so all valid vertices will be in range from 0 to GetNumVertices - 1)
  int vertexOffset = walkGraph -> GetVertices()[walkGraph -> GetVertices().size() - 1] -> GetID() + 1 - walkGraph -> GetNumVertices();

  //If the vertexID is from 0 to GetNumVertices - 1
  //AKA A valid vertex
  if(0 <= vertexID - vertexOffset && vertexID - vertexOffset < walkGraph -> GetNumVertices())
    return true;

  else
    return false;
}

void ListVertices(WalkGraph* walkGraph)
{
  printf("\nVertices:\n"); //Note: we're printing out vertices

  //Print out each vertex ID in the graph
  for(int i = 0; i < walkGraph -> GetVertices().size(); i++)
  {
    cout << walkGraph -> GetVertices().at(i) -> ToString() << endl;
  }
}

void ListEdges(WalkGraph* walkGraph)
{
  printf("\nEdges:\n");

  for(int e = 0; e < walkGraph -> GetEdges().size(); e++)
  {
    cout << "  " << *walkGraph -> GetEdges().at(e) << endl;
  }
}

void GraphWalk(WalkGraph* walkGraph)
{
  int vertexID = -1;
  int steps = -1;
  int seed = 0;
  printf("\nSimulate a random walk from a given vertex.\n");
  while(!ValidVertex(walkGraph, vertexID))
  {
    printf("Enter vertex ID: ");
    cin >> vertexID;
  }

  while(steps <= 0)
  {
    printf("Enter the maximum number of steps in the simulation: ");
    cin >> steps;
  }

  printf("Enter an integer seed for the random number generator: ");
  cin >> seed;

  //Get the vertex list
  vector<WalkVertex *> vertices = walkGraph -> GetVertices();

  //Pointer to the vertex to test
  WalkVertex* toTest = NULL;

  //Get the vertex
  for(int i = 0; i < vertices.size(); i++)
  {
    if(vertices.at(i) -> GetID() == vertexID)
      toTest = vertices.at(i);
  }

  vector<WalkVertex*> path = walkGraph -> Walk(toTest, steps, seed);

  for(int vertex = 0; vertex < path.size(); vertex++)
  {
    cout << "  " << path.at(vertex) -> ToString() << endl;
  }

  if(path.at(path.size()-1) -> Status() == FAILURE)
    printf("You were caught!\n");
  else
    printf("You made it to safety!  But crime doesn't pay...\n");

}