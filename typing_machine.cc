// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  cursor = head = tail = new Node(0);
  return;
}

void TypingMachine::HomeKey() {
  cursor = head;
  return;
}

void TypingMachine::EndKey() {
  cursor = tail;
  return;
}

void TypingMachine::LeftKey() {
  if (cursor->GetPreviousNode() == nullptr) {
    return;
  }

  cursor = cursor->GetPreviousNode();
  return;
}

void TypingMachine::RightKey() {
  if (cursor->GetNextNode() == nullptr) {
    return;
  }

  cursor = cursor->GetNextNode();
  return;
}

bool TypingMachine::TypeKey(char key) {
  if (isValidkey(key) == false) {
    return false;
  }

  if (isFull()) {
    return false;
  }

  ++stringCount;
   
  cursor->InsertPreviousNode(key);
  bool isPreviousNodeHead = 
        (cursor->GetPreviousNode()->GetPreviousNode() == nullptr) ? true : false;
  if (isPreviousNodeHead) {
    head = cursor->GetPreviousNode();
  }
  return true;
}

bool TypingMachine::EraseKey() {
  if (cursor->GetPreviousNode() == nullptr) {
    return false;
  }

  --stringCount;

  cursor->ErasePreviousNode();
  if (cursor->GetPreviousNode() == nullptr) {
    head = cursor;
  }
  return true;
}

std::string TypingMachine::Print(char separator) {
  std::string TypingString;
  Node* current = head;

  const bool skipCursorPrint = (separator == 0) ? true : false;
  bool isCursorPrint { true };
  while (current) {
    isCursorPrint = (current == cursor && skipCursorPrint == false) ? true : false;
    if (isCursorPrint) {
      TypingString += separator;
    }

    if (current != tail)
    {
      TypingString += current->GetData();
    }

    current = current->GetNextNode();
  }  
  return TypingString;
}

bool TypingMachine::isFull() {
  return stringCount >= 100 ;
}

bool TypingMachine::isValidkey(char key) {
  return key >= 32 && key <= 126;
}


