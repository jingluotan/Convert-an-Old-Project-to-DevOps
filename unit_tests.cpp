/* 
Group Name: Jake K, Liya T, Keyu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: September 8, 2024
Assignment: Managing and collecting tree shade data per block on the Logan neighborhood
Description: tests for the insert, delete, search and print functions
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#include "linked_list.cpp"

int main() 
{
  // Test case 1: Inserting a node in the list
  ListD* lst = new ListD;
  
  cout << "\nTest 1: Inserting nodes of tree data into an empty list" << endl;
  // Insert tree data with different properties
  lst->Insert(6, 4, 19, 327, 284);// street_id = 6, block_id = 4, treeNum = 19, NorthDistance = 327, SouthDistance = 284
  lst->Insert(2, 3, 11, 156, 206);
  lst->Insert(5, 8, 8, 122, 155); 

  cout << "Test Insert 3 nodes of tree data: " << endl;
  lst->PrintForward();  // Expected: Prints the 3 nodes with their properties
  cout << endl;

  //Insert another new node of tree data 
  cout << "\nTest Insert an additional node of tree data: ";
  cout << endl;
  lst->Insert(1, 5, 13, 199, 245);  // Insert another tree
  lst->PrintForward();  // Expected: 4 nodes now, with the last node showing street_id = 1, block_id = 5, etc.
  cout << endl;

  delete lst; // properly deallocate the memory to avoid memory leaks


  
  // Test case 2: Delete the propertie of a node
  ListD *lst2 = new ListD;
  
  cout << "\nTest 2: Deleting nodes of tree data from an empty list" << endl;
  
  lst2->Insert(6, 4, 19, 327, 284); // street_id = 6
  lst2->Insert(2, 3, 11, 156, 206); // street_id = 2
  lst2->Insert(5, 8, 8, 122, 155); // street_id = 5

  cout << "List before deleting: \n";
  lst2->PrintForward();
  cout << endl;

  // Attempt to delete by street_id
  cout << "Attempting to delete element with street_id = 3:\n";
  lst2->Delete(6);  // Deletes node with street_id = 6
  lst2->PrintForward();
  cout << endl;

  cout << "Attempting to delete element with street_id = 2:\n";
  lst2->Delete(2);  // Deletes node with street_id = 2
  lst2->PrintForward();
  cout << endl;

  cout << "Attempting to delete element with street_id = 5:\n";
  lst2->Delete(5);  // Deletes node with street_id = 5
  lst2->PrintForward();
  cout << endl;

  delete lst2;  // Clean up memory


  
  // Test 3: Search for a node
  ListD *lst3 = new ListD;
  cout << "\nTest 3: Searching for a node in a list in the Logan neighborhood" << endl;
  lst3->Insert(3, 5, 15, 295, 122); // street_id = 3, block_id = 5
  lst3->Insert(1, 5, 13, 199, 245); // street_id = 1, block_id = 5
  lst3->Insert(2, 7, 16, 322, 629); // street_id = 2, block_id = 7
  lst3->Insert(6, 6, 15, 322, 105); // street_id = 6, block_id = 6

  // Test case 1: Search for an existing node
  cout << "Test Search for street_id = 1, block_id = 5:\n";
  doubleNode* target = lst3->Search(1, 5);
  if (target != nullptr) {
      cout << "Node found! Street: " << target->street_id << ", Block: " << target->block_id 
           << ", Tree #: " << target->treeNum << ", North Distance: " << target->NorthDistance 
           << ", South Distance: " << target->SouthDistance << endl;
  } else {
      cout << "Node not found!" << endl;
  }
  cout << endl;

  // Test case 2: Search for a non-existing node
  cout << "Test Search for street_id = 5, block_id = 8 (should not be found):\n";
  target = lst3->Search(5, 8);
  if (target != nullptr) {
      cout << "Node found! Street: " << target->street_id << ", Block: " << target->block_id 
           << ", Tree #: " << target->treeNum << ", North Distance: " << target->NorthDistance 
           << ", South Distance: " << target->SouthDistance << endl;
  } else {
      cout << "Node not found!" << endl;
  }
  cout << endl;

  delete lst3; 


  
  // Test 4: Print the index of a list
  ListD *lst4 = new ListD;
  cout << "\nTest 4: Printing a list of tree data in the Logan neighborhood" << endl;
  lst4->Insert(2, 4, 24, 288, 302);
  
  // Print information of an existing node
  cout << "List before printing specific details from a node: \n";
  lst4->PrintForward();
  cout << endl;

  cout << "Test Print for street_id = 2, block_id = 4:\n";
  lst4->Print(2, 4);  // Expected: Prints the details for the node with street_id 2 and block_id 5
  cout << endl;

  // Test case 2: Print for a non-existing node
  cout << "Test Print for street_id = 6, block_id = 2 (should not be found):\n";
  lst4->Print(6, 2);  // Expected: "No trees found" message since this node does not exist
  cout << endl;

  delete lst4;
}