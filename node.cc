// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
  this->data = data;
}

char Node::GetData() {
  return data;
}

Node* Node::GetPreviousNode() {
  return previousNode;
}

Node* Node::GetNextNode() {
  return nextNode;
}

Node* Node::InsertPreviousNode(char data) {
  Node* newNode = nullptr;

  try {
    newNode = new Node(data);
  }
  catch (...)
  {
    return nullptr;
  }

  newNode->previousNode = previousNode;
  newNode->nextNode = this;

  if (previousNode)
    previousNode->nextNode = newNode;

  previousNode = newNode;
  return newNode;
}

Node* Node::InsertNextNode(char data) {
  Node* newNode = nullptr;
  
  try {
    newNode = new Node(data);
  }
  catch (...)
  {
    return nullptr;
  }

  newNode->nextNode = nextNode;
  newNode->previousNode = this;

  if (nextNode)
    nextNode->previousNode = newNode;

  nextNode = newNode;
  return newNode;
}

bool Node::ErasePreviousNode() {
  if (previousNode == nullptr)
    return false;
  
  Node* deleteNode = previousNode;
  previousNode = previousNode->previousNode;
  if (previousNode)
    previousNode->nextNode = this;

  delete deleteNode;
  
  return true;
}

bool Node::EraseNextNode() {
  if (nextNode == nullptr)
    return false;

  Node* deleteNode = nextNode;
  nextNode = nextNode->nextNode;
  if (nextNode)
    nextNode->previousNode = this;

  delete deleteNode;

  return true;
}
