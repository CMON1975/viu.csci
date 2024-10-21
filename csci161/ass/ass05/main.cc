#include <iostream>
#include "dictionary.h"
using namespace std;
struct Homework {
  string course_name;
  string assign_name;
  string homework_name;
  string submit_deadline;
  string teacher_info;
  string description;
};
int main()
{
  Dictionary<int, Homework> homeworks
    = Dictionary<int, Homework>(100);

  Homework hw1 = Homework();
  hw1.course_name = "c name";
  hw1.assign_name = "a name";
  hw1.homework_name = hw1.course_name + hw1.assign_name;
  hw1.submit_deadline = "sub dead";
  hw1.teacher_info = "teach info";
  hw1.description = "description";

  homeworks.Insert(000, hw1);

  homeworks.Lookup(001);
  return 0;
}
