#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"

int getFileInputChoice();
void getInput(char* input);
void getFileInput(char* input);

using namespace std;

int main(){
  char inp[999];
  char* input = &inp[0];

  //First we get user input from console or file input
 switch (getFileInputChoice()){
  case 1:
    //Get console input
    getInput(input);
 case 2:
    //Get file input
    getFileInput(input);
  }
  //Then we need to parse out the input

  //While adding completed numbers into the tree

  //Ask if user wants to 

  //Add

  //Delete

  //Search

  //Print 

  //Quit


}

int getFileInputChoice(){
  int input = 0;
  while(input != 1 && input != 2){
    cout << "Please enter (1) for console input or (2) for file input." << endl;
    cin >> input;
    cin.clear();
    cin.ignore(999, '\n');
  }
  return input;
}


void getInput(char* input){
  do {
    cout << "Please enter ..." << endl;
    cin.getline(input, strlen(input));
    cin.clear();
    if(strcmp(input, "") != 0){
      break;
    }
  }while(strcmp(input, "") != 0);
}

void getFileInput(char* input){
  ifstream stream;
  while(!stream.good()){
    stream.open()
  }
}
