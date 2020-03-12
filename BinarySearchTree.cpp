#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"

int getFileInputChoice(); //Gets an int that is used to decide between console and file input
void getInput(char* input); //Gets console input, stores into input
void getFileInput(char* input); //Gets file input, stores into input
void bubbleIn(); //Inserts a Node 
void bubbleOut(); //Deletes a Node 
void bubbleScry(); //Searches for a Node
void bubblePop(); //Quits the program

using namespace std;

int main(){
  char inp[999];
  char* input = &inp[0];

  bool running = true;

  while(running){
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
    char* buffer = new char[5]();
    int counter = 0;
    int inputLength = strlen(input);
    for(int a = 0; a < inputLength; ++a){
      if(strcmp(input, " ") == 0 || a == inputLength - 1){
        //Add the number to the binary search tree
        bubbleIn();
        //Then reset counter and buffer
        counter = 0;
        buffer = new char[5]();
      }
      buffer[counter++] = input[a];
    }

    //While adding completed numbers into the tree

    //Ask if user wants to 

    //Add

    //Delete

    //Search

    //Print 

    //Quit

  }
}

//This function makes the user decide on console input or file input
int getFileInputChoice(){
  int input = 0;
  //While input does not equal 1 or 2
  while(input != 1 && input != 2){
    cout << "Please enter (1) for console input or (2) for file input." << endl;
    //Get input
    cin >> input;
    cin.clear();
    cin.ignore(999, '\n');
  }
  return input;
}


//This function takes in user input and sets the input variable equal to it
void getInput(char* input){
  do {
    cout << "Please enter something" << endl;
    cin.getline(input, 999);
    cin.clear();
    if(strcmp(input, "") != 0){
      break;
    }
  }while(strcmp(input, "") != 0);
}

//This function reads in file input as a line and sets the input variable equal to it
void getFileInput(char* input){
  ifstream stream;
  while(!stream.good()){
    cout << "Please enter the name of your file..." << endl;
    getInput(input);
    stream.open(input);
  }
  stream.getline(input, 999);
}
