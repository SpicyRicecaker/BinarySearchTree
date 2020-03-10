//Cpp file for Node
#include <iostream>
#include "Node.h"

//Node Constructor
Node::Node(int newValue){
  value = newValue;

  left = NULL;
  right = NULL;
}

//Node Destructor
Node::~Node(){
  //Might not need this I'm not sure
  //Remove left and right pointers
  left = NULL;
  right = NULL;
}

//Getters and setters for left node
Node* Node::getLeft(){
  return left;
}

void Node::setLeft(Node* newLeft){
  left = newLeft;
}

//Getters and setters for right node
Node* Node::getRight(){
  return right;
}

void Node::setRight(Node* newRight){
  right = newRight;
}

//Getters and setters for value
//NEED TO TEST IF PASSING BY VALUE WORKS
int Node::getValue(){
  return value;
}

void Node::setValue(int newValue){
  value = newValue;
}


