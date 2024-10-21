#include "familytree.h"
FamilyTree::FamilyTree(string filename)
{
  ifstream in(filename.c_str());
  if (in.fail() || in.eof()) {
    root = 0;
    in.close();
    return;
  }
  string line;
  getline(in, line);
  if (line == "<" || line == ">") {
    in.close();
    throw string("invalid file format");
  }
  root = new Node;
  root->name = line;
  root->num_children = 0;
  root->parent = 0;

  Node *ptr = 0;
  while (!in.eof()) {
    getline(in, line);
    //cout << "Here -> " << line << endl; //debug
    if (line == ">") {
      ptr = ptr->parent;
    } else if (line == "<") {
      if (ptr == 0)
	ptr = root;
      else
	ptr = ptr->children[ptr->num_children -1];
    } else if (line != "") {
      if (ptr->num_children == MaxChildren) {
	in.close();
	throw string("invalid file format");
      }
      ptr->children[ptr->num_children] = new Node;
      ptr->children[ptr->num_children]->num_children = 0;
      ptr->children[ptr->num_children]->name = line;
      ptr->children[ptr->num_children]->parent = ptr;
      ptr->num_children++;
    }
  }
  if (ptr != 0) {
    in.close();
    throw string("invalid file format");
  }
  in.close();
}
FamilyTree::~FamilyTree()
{
  DestroyAll(root);
}
void FamilyTree::DestroyAll(FamilyTree::Node *ptr)
{
  if (ptr == 0)
    return;
  for(int i = 0; i < ptr->num_children; i++)
    DestroyAll(ptr->children[i]);
  delete ptr;
}
void FamilyTree::PreOrder()
{
  PreOrder(root);
}
void FamilyTree::Visit(FamilyTree::Node *ptr)
{
  cout << ptr->name << endl;
}
void FamilyTree::PreOrder(FamilyTree::Node *ptr)
{
  if (ptr == 0)
    return;
  Visit(ptr);
  for(int i=0;i<ptr->num_children;i++)
    PreOrder(ptr->children[i]);
}
void FamilyTree::PostOrder()
{
  PostOrder(root);
}
void FamilyTree::PostOrder(FamilyTree::Node *ptr)
{
  if (ptr == 0)
    return;
  for(int i=0;i<ptr->num_children;i++)
    PostOrder(ptr->children[i]);
  Visit(ptr);
}
