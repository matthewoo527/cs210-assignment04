#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>
#include <string>
#include "NumberListNode.h"

// Base class for a double-linked list of NumerListNodes
class NumberList {

public:
NumberListNode* head;
NumberListNode* tail;
   NumberList() {
      head = nullptr;
      tail = nullptr;
   }
   
   virtual ~NumberList() {
   }
   
   NumberListNode* GetHead() const {
      return head;
   }
   
   // Prints this list's contents in order from head to tail
   void Print(std::ostream& output = std::cout, std::string separator = ", ",
      std::string prefix = "", std::string suffix = "") const {

      // Print prefix first
      output << prefix;
      
      // Start at the list's head
      NumberListNode* node = head;
      
      // First node's data is printed without accompanying separator
      if (node) {
         output << node->GetData();
         node = node->GetNext();
      }
      else {
         // Special case for empty list
         output << "(empty)";
      }
      
      // Remaining nodes are printed with separator before
      while (node) {
         output << separator << node->GetData();
         node = node->GetNext();
      }
      
      // Suffix is printed last
      output << suffix;
   }

   void Append(double number) {
      NumberListNode* newNode = new NumberListNode(number, nullptr, nullptr);
      
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->SetNext(newNode);
            tail = newNode;
        }
   }

    void Prepend(double number){
        NumberListNode* newNode = new NumberListNode(number, nullptr, nullptr);
      
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->SetNext(head);
            head = newNode;
        }
    }
   
   bool Search(double number) {
   NumberListNode* current = head;

   while (current != nullptr) {
      if (current->GetData() == number) {
         return true;
      }

      current = current->GetNext();
   }
      return false;
   }
   
   bool Remove(double number) {
   NumberListNode* current = head;
   NumberListNode* previous = nullptr;

   while (current != nullptr && current->GetData() != number) {
      previous = current;
      current = current->GetNext();
   }

   // Number was not found
   if (current == nullptr) {
      return false;
   }

   // Removing the head
   if (current == head) {
      head = head->GetNext();
      // If only one node, then point tail
      if (head == nullptr) {
         tail = nullptr;
      }
   }

   // Removing somewhere after the head
   else {
      previous->SetNext(current->GetNext());

      if (current == tail) {
         tail = previous;
      }
   }

   delete current;
   return true;
   }
};

#endif