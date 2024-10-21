#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include <iostream>
#include <fstream>
using namespace std;

class FamilyTree {
 public:
  FamilyTree(string filename);
  ~FamilyTree();
  void PreOrder();
  void PostOrder();
 private:
  static const int MaxChildren = 5;
  struct Node {
    string name;
    int num_children;
    Node *children[MaxChildren];
    Node *parent;
  };
  Node *root;
  void Visit(Node *);
  void PreOrder(Node *);
  void PostOrder(Node *);
  void DestroyAll(Node *);
};
#endif
