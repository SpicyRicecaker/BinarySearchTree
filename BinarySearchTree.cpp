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
int bubbleScry(Node* bubby, int toSearch, int boba); //Searches for if a number is in the tree
void airBubble(Node* bubby, int depth); //Prints all numbers in the tree!
void bubblePop(); //Quits the program
void bubbleHelp(); //Prints out help

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
      cout << "Please enter your input then." << endl;
      getInput(input);
      break;
    case 2:
      //Get file input
      getFileInput(input);
      break;
    }
    //Then we need to parse out the input
    char* buffer = new char[4]();
    int counter = 0;
    int inputLength = strlen(input);
    for(int a = 0; a <= inputLength; ++a){
      if(input[a] == ' ' || a == inputLength){
        //Convert the string to in, and add the number to the binary search tree
        bubbleIn(bubby, atoi(buffer));
        //Then reset counter and buffer
        counter = 0;
        buffer = new char[4]();
        continue;
      }
      buffer[counter++] = input[a];
    }

    //Then, ask if user wants to...
    bool moddingTree = true;
    cout << "Numbers inserted. Now moving to tree modding phase. Type \"help\" for help!" << endl;
    while(moddingTree){
      switch(getActionChoice(input)){
      case 1:
        //Add
        cout << "Please enter the number to add" << endl;
        getInput(input);
        bubbleIn(bubby, atoi(input));
        break;
      case 2:
        //Delete
        //We need to remove all instances of a number, and alert the user how many instances were removed.
        cout << "Please enter the number to delete" << endl;
        getInput(input);
        for(int a = 0; a < bubbleScry(bubby, atoi(input), 0); ++a){
          bubbleOut(bubby, atoi(input));
        }
        break;
      case 3:
        //Search
        //Scans for all instances of a number in the tree
        cout << "Please enter the number to search for" << endl;
        getInput(input);
        bubbleScry(bubby, atoi(input), 0);
        break;
      case 4:
        //Print 
        airBubble(bubby, atoi(input));
        break;
      case 5:
        //Quit
        moddingTree = false;
        break;
      case 6:
        //Help
        bubbleHelp();
        break;
      }
    }
  }
}

//This function makes the user decide on console input or file input
int getFileInputChoice(){
  char input[4];
  //While input does not equal 1 or 2
  cout << "Please enter (1) for console input or (2) for file input." << endl;
  while(true){
    //Get input
    cin.getline(input, 999);
    cin.clear();
    if(strcmp(input, "1") == 0){
      return 1;
    }else if(strcmp(input, "2") == 0){
      return 2;
    }
    cout << "Please enter a valid number." << endl;
  }
}


//This function takes in user input and sets the input variable equal to it
void getInput(char* input){
  while(true){
    cin.getline(input, 999);
    cin.clear();
    if(strcmp(input, "") != 0){
      break;
    }
    cout << "No input detected" << endl;
  }
}

//This function reads in file input as a line and sets the input variable equal to it
void getFileInput(char* input){
  ifstream stream;
  while(true){
    cout << "Please enter the name of your file..." << endl;
    getInput(input);
    stream.open(input);
    if(stream.good()){
      break;
    }
    cout << "That file does not exist..." << endl;
  }
  stream.getline(input, 999);
}

int getActionChoice(char* input){
  int actionChoice = 0;
  //While input does not equal 1, 2, 3, 4, 5, or 6
  while(true){
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
    }else if(strcmp(input, "HELP") == 0){
      return 6;
    }
    cout << "Invalid Input." << endl;
  }
}

//Inserts a number
void bubbleIn(Node* &bubby, int toAdd){
  //First, we have to check the null case
  if(bubby == NULL){
    bubby = new Node(toAdd);
    return;
  }
  //If the current number is greater than the current node
  if(toAdd > bubby->getValue()){
    Node* right = bubby->getRight();
    //If there is a left subtree
    if(right != NULL){
      //Recurse
      bubbleIn(right, toAdd);
    }else{
      //Otherwise just add the right node
      bubby->setRight(new Node(toAdd));
    }
  }else{ //If the current number is less than or equal to the current node
    Node* left = bubby->getLeft();
    //If there is a right subtree
    if(left != NULL){
      //Recurse
      bubbleIn(left, toAdd);
    }else{
      //Otherwise just add the left node
      bubby->setLeft(new Node(toAdd));
    }
  }
}

//Deletes all numbers of a specified value
void bubbleOut(Node* &bubby, int toDelete){
  
}

//Searches for if a number is in the tree
int bubbleScry(Node* bubby, int toSearch, int boba){
  int inQuestion = bubby->getValue();
  //If node is less than search number
  if(toSearch < inQuestion){

  }

  //If node is equal to search number
  if(toSearch == inQuestion){
    
  }

  //If node is greater than search number
  if(toSearch > inQuestion){
    
  }
}

//Prints out the entire tree using inorder traversal from the right node to the left node
void airBubble(Node* bubby, int depth){
  //If null
  if(bubby == NULL){
    //We out!
    return;
  }
  //Recurse to the right, incrementing the depth counter
  airBubble(bubby->getRight(), depth+1);
  //Print out root
  for(int a = 0; a < depth; ++a){
    cout << "    ";
  }
  cout << bubby->getValue() << "\n" << endl;
  //Recurse to the left, incrementing the depth counter
  airBubble(bubby->getLeft(), depth+1);
}

//Quits the program
void bubblePop(){
  
}

void bubbleHelp(){
  cout << "\n----------\nEnter \"add\" to add a number to the tree,\n\"delete\" to delete all instances of a number in the tree,\n\"search\" to check if a number is in the tree,\n\"print\" to print the tree,\nor \"quit\" to exit the program.\nType \"help\" again to reprint this list.\n----------\n" << endl;
}

