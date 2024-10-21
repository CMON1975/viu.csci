#include "my_class.h" //adds header to program

struct Node {
  MyClass* data; //data record (int process_id and string data)
  Node* next; //next node
  Node* prev; //previous node
};

class LinkedList {
  public:
    LinkedList(); //constructor
    ~LinkedList(); //destructor
    bool Insert(MyClass &); //insert fuction
    void DisplayAll(); //display all function
    int GetListSize(); //list length function
    MyClass & Search(int process_id) throw (std::string);
  private:
    Node* list_head; //list pointer
    int list_size; //list size
};
