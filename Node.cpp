//Cpp file for Node
#include <iostream>
#include "Node.h"

Node::Node(int newValue){
  value = new int(newValue);

  left = NULL;
  right = NULL;
}

Node::~Node(){
  delete value;
  value = NULL;

  //Might not need this I'm not sure
  left = NULL;
  right = NULL;
}

