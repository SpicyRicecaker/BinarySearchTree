//Header file for Node
#ifndef NODE_H
#define NODE_H

#include <iostream>

//A node includes a left node, a right node, and a value
class Node{
public:
  Node(int newValue);
  ~Node();

  //Getters and Setters for Left Node
  Node* getLeft();
  void setLeft(Node* newLeft);

  //Getters and Setters for Right Node
  Node* getRight();
  void setRight(Node* newRight);

  //Getters and Setters for Value
  int getValue();
  void setValue(int newInt);

private:
  Node* left;
  Node* right;
  int value;
};

#endif

