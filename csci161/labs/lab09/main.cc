#include "person.h"
#include "student.h"
#include "queue.h"
using namespace std;
int main()
{
  cout << "Main executed." << endl;
  //init Person queue
  Queue<Person> people(2);

  Person p1 = Person("Joe");
  Student p2 = Student("Jill");

  try {
    people.Dequeue();
  } catch (EmptyQueue & e) {
    cout << e.what() << endl;
  } catch (QueueException & e) {
  } catch (...) {
  }

  people.Enqueue(p2);
  people.Enqueue(p1);
  
  try {
    people.Enqueue(p1);
  } catch (FullQueue & e) {
    cout << e.what() << endl;
  } catch (QueueException & e) {
  } catch (...) {
  }
  
  return 0;
}
