/* 
Group Name: Jake K, Liya T, Keyu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: September 8, 2024
Assignment: Managing and collecting tree shade data per block on the Logan neighborhood
Description: user interface with our tree list data
*/

#include "linked_list.hpp"

int main()
{   
  ListD treeList; // craete a ListD object

  readFile("Data.txt", treeList);  // Read data from the file and insert into the list

  bool reLoad = true;
  while(reLoad)
{
    menu();
    int user_choose;
    cin >> user_choose;
    if(user_choose == 1)
    {
      treeMap();
      char answer;
      bool correct = true;
      do
      {
        cout << "Do you want to quit (Q/q) or check the menu (C/c)" << endl;
        cin >> answer;
            
        if(answer == 'Q' || answer == 'q')
        {
          reLoad = false;
          correct = true;
          break;
        }
        else if(answer == 'C' || answer == 'c')
        {
          reLoad = true;
          correct = true;
          break;
        }
        else
        {
          cout << "Please enter a valid letter (Q/q or C/c)." << endl;
          correct = false;
        }
      }
      while(!correct);  
    }



    else if(user_choose == 2)
    {
      treeAndDistance();
      int street_id;
      int block_id;
      char choice, reload, dir;

      do
      {
        cout << "Enter the street ID to search: ";
        cin >> street_id;

        cout << "Enter block ID to search: ";
        cin >> block_id;

        treeList.Print(street_id, block_id);  // Print the details of the node

        cout << "Do you want to check another block or street? (b/s): ";    
        cin >> reload;
      }
      while (reload == 'S' || reload == 's');

      doubleNode* cur = treeList.Search(street_id, block_id);

      do
      {
        cout << "Do you want to go forward or go backward (F/B)? or Q to quit: ";
        cin >> dir;

        switch (dir)
        {
          case 'F': 
          case 'f':
          if (cur->next != nullptr && cur->next->street_id == street_id)
          {
            cur = cur->next;  
            cout << "Tree Amount: " << cur->treeNum << ", North distance of the block between the first tree and last tree: " << cur->NorthDistance << " ft, South distance of the block between the first tree and last tree: " << cur->SouthDistance << " ft\n";
          }
          else {
            cout << "\nYou have reached the end of the street\n" << endl;
            cout << "Current tree Amount: " << cur->treeNum << ", North distance of the block between the first tree and last tree: " << cur->NorthDistance << " ft, South distance of the block between the first tree and last tree: " << cur->SouthDistance << " ft\n";
          }
          break;

          case 'B': 
          case 'b':
          if (cur->prev != nullptr && cur->prev->street_id == street_id)
          {
            cur = cur->prev;  
            cout << "Tree Amount: " << cur->treeNum << ", North distance of the block between the first tree and last tree: " << cur->NorthDistance << " ft, South distance of the block between the first tree and last tree: " << cur->SouthDistance << " ft\n";
          }
          else 
          {
            cout << "\nYou have reached the start of the street\n" << endl;
            cout << "Current tree Amount: " << cur->treeNum << ", North distance of the block between the first tree and last tree: " << cur->NorthDistance << " ft, South distance of the block between the first tree and last tree: " << cur->SouthDistance << " ft\n";
          }
          break;

          case 'Q': 
          case 'q':
          // Exit the loop
          break;

          default:
          // Handle invalid input
          cout << "Invalid choice, please try again." << endl;
          break;
        }
      }
      while (dir != 'Q' && dir != 'q');

      treeList.Delete(street_id);  // Delete the node
      return 0;
      reLoad = false;
    }
  }
}