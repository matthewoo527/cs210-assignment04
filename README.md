# cs210-assignment04
## Code
Woo_Matthew_Assignment4_part1_main.cpp
```cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include "Matthew_NumberList.h"
using namespace std;

int main() {
   vector<double> numbersToInsert = {
      77.75, 15.25, -4.25, 63.5, 18.25, -3.5
   };

   NumberList list;
   cout << fixed << setprecision(2);

   // Test adding and printing
   cout << "ADDING ITEMS\n";
   for (double number : numbersToInsert) {
      cout << "List after appending " << number << ": ";
      list.Append(number);
      list.Print(cout, ", ", "", "\n");
   }

   // Test searching
   cout << "\nSEARCHING\n";
   cout << "Search for 63.50: "
        << (list.Search(63.50) ? "Found" : "Not found") << '\n';
   cout << "Search for 100.00: "
        << (list.Search(100.00) ? "Found" : "Not found") << '\n';

   // Test removing from the front, middle, end, and a missing value
   cout << "\nREMOVING ITEMS\n";
   vector<double> numbersToRemove = {
      77.75, 18.25, -3.5, 100.0
   };

   for (double toRemove : numbersToRemove) {
      cout << "Removing " << toRemove << ": ";

      if (list.Remove(toRemove)) {
         list.Print(cout, ", ", "", "\n");
      }
      else {
         cout << "value not found\n";
      }
   }
   cout << endl;
   cout << "Searching for 63.5: ";
   if (list.Search(63.5)) {
      cout << "Found" << endl;
   }
   else {
      cout << "Not found" << endl;
   }
   
   cout << "Searching for 100: ";
   if (list.Search(100)) {
      cout << "Found" << endl;
   }
   else {
      cout << "Not found" << endl;
   }

   return 0;
}
```

Matthew_NumberList.h

```cpp
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
```

NumberListNode.h

```cpp
#ifndef NUMBERLISTNODE_H
#define NUMBERLISTNODE_H

class NumberListNode {
protected:
   double data;
   NumberListNode* next;
   NumberListNode* previous;

public:
   // Constructs this node with the specified numerical data value. The next
   // and previous pointers are each assigned nullptr.
   NumberListNode(double initialData) {
      data = initialData;
      next = nullptr;
      previous = nullptr;
   }

   // Constructs this node with the specified numerical data value, next
   // pointer, and previous pointer.
   NumberListNode(double initialData, NumberListNode* nextNode,
      NumberListNode* previousNode) {
      data = initialData;
      next = nextNode;
      previous = previousNode;
   }

   virtual ~NumberListNode() {
   }

   // Returns this node's data.
   virtual double GetData() {
      return data;
   }

   // Sets this node's data.
   virtual void SetData(double newData) {
      data = newData;
   }

   // Gets this node's next pointer.
   virtual NumberListNode* GetNext() {
      return next;
   }

   // Sets this node's next pointer.
   virtual void SetNext(NumberListNode* newNext) {
      next = newNext;
   }

   // Gets this node's previous pointer.
   virtual NumberListNode* GetPrevious() {
      return previous;
   }

   // Sets this node's previous pointer.
   virtual void SetPrevious(NumberListNode* newPrevious) {
      previous = newPrevious;
   }
};

#endif
```
## Output
Part 1:
<img width="505" height="288" alt="Screenshot 2026-10-04 at 23 20 49" src="https://github.com/user-attachments/assets/b1e6764e-4e60-4b4f-aaca-a54fefd88f03" />
Part 2 Monopoly:
Initial Game GUI:
<img width="1132" height="860" alt="Screenshot 2026-10-04 at 23 22 19" src="https://github.com/user-attachments/assets/6eea58dc-fcda-4ed9-9b48-2e62463a6abe" />
Turn 11 GUI:
<img width="1132" height="860" alt="Screenshot 2026-10-04 at 23 23 03" src="https://github.com/user-attachments/assets/aafe22c2-533e-411e-96f0-3301e1d45187" />
CLI output:
```
Turn 1
P1 rolled 4
Landed on Connecticut Avenue
Cost: $120
Owner: Unowned
P1 bought Connecticut Avenue for $120
Money left: $880

Turn 2
P2 rolled 5
Landed on St Charles Place
Cost: $140
Owner: Unowned
P2 bought St Charles Place for $140
Money left: $860

Turn 3
P1 rolled 1
Landed on St Charles Place
Cost: $140
Owner: P2
St Charles Place is already owned by P2. Cannot buy this property.

Turn 4
P2 rolled 1
Landed on States Avenue
Cost: $140
Owner: Unowned
P2 bought States Avenue for $140
Money left: $720

Turn 5
P1 rolled 2
Landed on Virginia Avenue
Cost: $160
Owner: Unowned
P1 bought Virginia Avenue for $160
Money left: $720

Turn 6
P2 rolled 6
Landed on Indiana Avenue
Cost: $220
Owner: Unowned
P2 bought Indiana Avenue for $220
Money left: $500

Turn 7
P1 rolled 6
Landed on Illinois Avenue
Cost: $240
Owner: Unowned
P1 bought Illinois Avenue for $240
Money left: $480

Turn 8
P2 rolled 5
Landed on Pacific Avenue
Cost: $300
Owner: Unowned
P2 bought Pacific Avenue for $300
Money left: $200

Turn 9
P1 rolled 5
Landed on North Carolina Avenue
Cost: $300
Owner: Unowned
P1 bought North Carolina Avenue for $300
Money left: $180

Turn 10
P2 rolled 5
Landed on Reading Railroad
Cost: $200
Owner: Unowned
P2 bought Reading Railroad for $200
Money left: $0

===== RESULTS AFTER 10 TURNS =====
P1 Money: $180
P2 Money: $0

Property Results:
Mediterranean Avenue | Cost: $60 | Owner: Unowned
Baltic Avenue | Cost: $60 | Owner: Unowned
Oriental Avenue | Cost: $100 | Owner: Unowned
Vermont Avenue | Cost: $100 | Owner: Unowned
Connecticut Avenue | Cost: $120 | Owner: P1
St Charles Place | Cost: $140 | Owner: P2
States Avenue | Cost: $140 | Owner: P2
Virginia Avenue | Cost: $160 | Owner: P1
St James Place | Cost: $180 | Owner: Unowned
Tennessee Avenue | Cost: $180 | Owner: Unowned
New York Avenue | Cost: $200 | Owner: Unowned
Kentucky Avenue | Cost: $220 | Owner: Unowned
Indiana Avenue | Cost: $220 | Owner: P2
Illinois Avenue | Cost: $240 | Owner: P1
Atlantic Avenue | Cost: $260 | Owner: Unowned
Ventnor Avenue | Cost: $260 | Owner: Unowned
Marvin Gardens | Cost: $280 | Owner: Unowned
Pacific Avenue | Cost: $300 | Owner: P2
North Carolina Avenue | Cost: $300 | Owner: P1
Pennsylvania Avenue | Cost: $320 | Owner: Unowned
Park Place | Cost: $350 | Owner: Unowned
Boardwalk | Cost: $400 | Owner: Unowned
Reading Railroad | Cost: $200 | Owner: P2
Pennsylvania Railroad | Cost: $200 | Owner: Unowned
B and O Railroad | Cost: $200 | Owner: Unowned
Short Line | Cost: $200 | Owner: Unowned
Electric Company | Cost: $150 | Owner: Unowned
Water Works | Cost: $150 | Owner: Unowned
Harbor Avenue | Cost: $180 | Owner: Unowned
Sunset Avenue | Cost: $240 | Owner: Unowned
==================================
Turn 11
P1 rolled 4
Landed on Reading Railroad
Cost: $200
Owner: P2
Reading Railroad is already owned by P2. Cannot buy this property.

2026-10-04 23:23:06.524 Woo_Matthew_Assignment4_monopoly[63433:2936971] TSM AdjustCapsLockLEDForKeyTransitionHandling - _ISSetPhysicalKeyboardCapsLockLED Inhibit
Turn 12
P2 rolled 2
Landed on B and O Railroad
Cost: $200
Owner: Unowned
P2 does not have enough money.

Turn 13
P1 rolled 6
Landed on Harbor Avenue
Cost: $180
Owner: Unowned
P1 bought Harbor Avenue for $180
Money left: $0
```

It will print the results after turn 10, but will not end.

## Explanation
