#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"

int getFileInputChoice(); //Gets an int that is used to decide between console and file input
void getInput(char* input); //Gets console input, stores into input
void getFileInput(char* input); //Gets file input, stores into input
int getActionChoice(char* input); //Gets an int that is used to decide between add, delete, search, print, or quit
void bubbleIn(Node* &bubby, int toAdd); //Inserts a number
void bubbleOut(Node* &bubby, int toDelete); //Deletes all numbers of a specified value 
void bubbleScry(Node* bubby, int toSearch); //Searches for if a number is in the tree
void bubblePop(); //Quits the program

using namespace std;

int main(){
  //Input variable
  char inp[999];
  char* input = &inp[0];

  //Root node of binary search tree
  Node* bubby = NULL;

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
        //Convert the string to in, and add the number to the binary search tree
        bubbleIn(bubby, atoi(buffer));
        //Then reset counter and buffer
        counter = 0;
        buffer = new char[5]();
      }
      buffer[counter++] = input[a];
    }

    //Then, ask if user wants to...
    bool moddingTree = true;
    while(moddingTree){
      switch(getActionChoice(input)){
        //Add
      case 1:

        break;
        //Delete
      case 2:
        break;
        //Search
      case 3:
        break;
        //Print 
      case 4:
        break;
      case 5:
        //Quit
        moddingTree = false;
        break;
      }
    }
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

int getActionChoice(char* input){
  int actionChoice = 0;
  //While input does not equal 1, 2, 3, 4, or 5
  while(true){
    cout << "Now, please enter \"add\" to add a number to the tree, \"delete\" to delete all instances of a number in the tree, \"search\" to check if a number is in the tree, \"print\" to print the tree, or \"quit\" to exit the program" << endl;
    getInput(input);
    int inputLen = strlen(input);
    for(int a = 0; a < inputLen; ++a){
      input[a] = toupper(input[a]);
    }
    if(strcmp(input, "ADD") == 0){
return 1;
    }else if(strcmp(input, "DELETE") == 0){
return 2;
    }else if(strcmp(input, "SEARCH") == 0){
return 3;
    }else if(strcmp(input, "PRINT") == 0){
return 4;
    }else if(strcmp(input, "QUIT") == 0){
return 5;
}
    cout << "Invalid Input." << endl;
  }
}

//Inserts a number
void bubbleIn(Node* &bubby, int toAdd){
  //First, we have to check the null case
  if(bubby == NULL){
    bubby = new Node(toAdd);
  }
  //Then, we'll just compare the num to the left and right child, and traverse down the tree until there is an open node
  

  return;
}

//Deletes all numbers of a specified value
void bubbleOut(Node* &bubby, int toDelete){
  
}

//Searches for if a number is in the tree
void bubbleScry(Node* bubby, int toSearch){
  
}
//Quits the program
void bubblePop(){
  
}
