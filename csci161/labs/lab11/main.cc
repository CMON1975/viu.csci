#include "familytree.h"

int main(int argc, char *argv[])
{
  string filename;
  if (argc != 2) {
    filename = "MyFamily.txt";
  } else {
    filename = argv[1];
  }
  try {
    FamilyTree my_family(filename);
    cout << "\npre order traverse:\n";
    my_family.PreOrder();
    cout << "\npost order traverse:\n";
    my_family.PostOrder();
  } catch (string e) {
    cout << e << endl;
  }
  return 0;
}
