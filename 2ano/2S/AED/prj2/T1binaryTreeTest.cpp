#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <queue>
#include <random>
#include <algorithm>
#include <set>
#include "sampleGenerator.hpp"

using namespace std;

class Node
{
  public:
    int value;
    Node* left;
    Node* right;
    Node(int x)
    {
      value = x;
      left = right = nullptr;
    }
};

// Function to insert new value in BT using BFS (Breadth First) to find the first available place
// This will create a Complete Binary Tree
Node* InsertNode(Node* root, int value)
{
  // if root is null, assign value
  if (root == nullptr)
  {
    return new Node(value);
  }

  // Otherwise, do breadth first (BFS) to insert new leaf
  queue<Node*> q; // queue that stores POINTERS to Node
  q.push(root);

  // at each iteration update queue values to find correct node
  while (!q.empty())
  {
    Node* cur = q.front();
    q.pop();

    // first check if left node is null
    if (cur->left == nullptr)
    {
      cur->left = new Node(value);
      return root;
    }
    else
    {
      q.push(cur->left);
    }

    // if left node exists, check right node
    if (cur->right == nullptr)
    {
      cur->right = new Node(value);
      return root;
    }
    else
    {
      q.push(cur->right);
    }
  }

  return root; // This line should not be reached with a correct BFS implementation
}

// Do Inorder traversal of the tree
void inorder(Node* cur)
{
  if(cur == nullptr) return;
  inorder(cur->left);
  // cout << cur->value << ' ';
  inorder(cur->right);
}

// Free memory allocated for the tree (important to avoid memory leaks)
void freeTree(Node* root)
{
  if (root == nullptr) return;
  freeTree(root->left);
  freeTree(root->right);
  delete root;
}

void menu()
{
  cout << "\n----------------------------------------\n";
  cout << "               MENU OPTIONS             \n";
  cout << "----------------------------------------\n";
  cout << "1. Generate random sample few repeated values\n";
  cout << "2. Generate sample with few repeated values in ascending order\n";
  cout << "3. Generate sample with few repeated values in descending order\n";
  cout << "4. Generate random sample with 90% repeated values\n";
  cout << "5. Exit\n";
  cout << "----------------------------------------\n";
}

// Main function, now calls user input and then calls functions
int main()
{
  vector<int> amount;
  int value;
  Node* root = nullptr;
  int choice;
  
  vector<double> sample_durations(5, 0.0);

  cout << "----------------------------------------\n            SET SAMPLE SIZES            \n----------------------------------------\n";
  for (int i = 0; i < 5; i++)
  {
    value = (i+1)*1000;   // Example sample sizes for test purposes
    amount.push_back(value);
    cout << "Sample " << i << ": " << value << "\n";
  }

  menu();
  cout << "Enter choice: ";
  cin >> choice;

  // Generate random samples based on user choice
  for(int i = 0; i < 5; i++)
  {
    cout << "\nGenerated sample " << amount[i] << "\n";
    root = nullptr; // Reset root for each iteration

    auto start = chrono::high_resolution_clock::now();
    
    // Lambda function to insert nodes using InsertNode
    // insert_func(5) will insert 5 in the tree 
    auto insert_func = [&root](int val) { 
      root = InsertNode(root, val); 
    };

    switch(choice)
    {
      case 1:
        generate_sample_with_repetition(1, 100000, amount[i], insert_func, true, true);
        break;
      case 2:
        ascending_sample_repetition(1, 100000, amount[i], insert_func);
        break;
      case 3:
        descending_sample_repetition(1, 100000, amount[i], insert_func);
        break;
      case 4:
        random_sample_90percent(1, 100000, amount[i], insert_func);
        break;
      case 5:
        cout << "Exiting program\n";
        return 0;
      default:
        cout << "Invalid choice\n";
        return 1;
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    sample_durations[i] = duration.count();
    
    cout << "Time (ms): " << duration.count() << "\n";
    freeTree(root);     // Free the tree memory
  }

  cout << "----------------------------------------\n             END OF PROGRAM             \n----------------------------------------\n";

  // Output results in CSV format for graphing
  cout << "\n----------------------------------------\n";
  cout << "           DATA FOR GRAPHING            \n";
  cout << "----------------------------------------\n";
  cout << "SampleSize,TimeInMs\n";
  for (int i = 0; i < 5; i++) {
    cout << amount[i] << "," << sample_durations[i] << "\n";
  }

  return 0;
}
