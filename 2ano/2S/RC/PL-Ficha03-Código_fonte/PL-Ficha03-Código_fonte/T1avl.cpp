#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <queue>
#include <random>
#include <algorithm>
#include <set>

template <typename T>
class AVLNode 
{
  public:
    T key;
    AVLNode* left;    // left son
    AVLNode* right;   // right son
    int height;       // to measure FE (balance factor)
}
