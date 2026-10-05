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
