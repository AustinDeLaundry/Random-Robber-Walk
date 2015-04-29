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
void ListVertices(WalkGraph* walkGraph);

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
  printf(" c - list the connected component of a specific vertex\n");
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
      case('c'): case('q'):
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

bool LoadFile(WalkGraph* graph, string* fileName)
{
  //If error in loading file
  if(!graph -> LoadFromFile(*fileName))
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

void ListVertices(WalkGraph* graph)
{
  printf("\nVertices:\n"); //Note: we're printing out vertices

  //Print out each vertex ID in the graph
  for(int i = 0; i < graph -> GetVertices().size(); i++)
  {
    cout << graph -> GetVertices().at(i) -> ToString() << endl;
  }
}

