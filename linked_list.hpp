/* 
Group Name: Jake K, Liya T, Keyu C, Daisy B
Class: CPSC223, Section 1
Date Submitted: September 8, 2024
Assignment: Managing and collecting tree shade data per block on the Logan neighborhood
Description: implementations for the search, delete, insert, and print, IsEmpty, PrintForward, PrintBackward functions
*/

#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct doubleNode
{
  doubleNode* prev;
  int street_id;
  int block_id;
  int treeNum;
  int NorthDistance;
  int SouthDistance;
  doubleNode* next;

  // Constructor for doubleNode
  doubleNode(int st, int blk, int tree, int north, int south)
  {
    street_id = st;
    block_id = blk;
    treeNum = tree;
    NorthDistance = north;
    SouthDistance = south;
    prev = nullptr;
    next = nullptr;
  }
};

class ListD
{
public:
  ListD();  // Constructor
  ~ListD();  // Destructor

  bool IsEmpty() const;

  void Insert(int street_id, int block_id, int treeNum, int NorthDistance, int SouthDistance);

  void Delete(int);

  doubleNode* Search(const int street_id, const int block_id) const;

  void Print(int street_id, int block_id) const;

  // The item value of each node, from head to tail, is displayed on the screen, excluding the dummy nodes. 
  void PrintForward();

  void PrintBackward();

private:
  doubleNode* FindPosition(int pos);  // Find the node at the given position

  int length;
  doubleNode* head;
  doubleNode* tail;
};

void readFile(const string& filename, ListD& list);
void menu();
void treeMap();
void treeAndDistance();

#endif
