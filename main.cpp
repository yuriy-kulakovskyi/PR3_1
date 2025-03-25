#include <iostream>

struct Elem {
  Elem* link1,
      * link2;
  int info;
};


int main() {
  Elem* p;

  p = new Elem; // 1

  p->info = 1; // 2
  p->link2 = NULL; // 3

  p->link1 = new Elem; // 4
  p->link1->info = 2; // 5
  p->link1->link2 = new Elem; // 6
  p->link1->link2->info = 3; // 7
  p->link1->link2->link2 = NULL; // 8
  p->link1->link2->link1 = p->link1; // 9

  p->link1->link1 = new Elem; // 10
  p->link1->link1->link1 = p; // 11
  p->link1->link1->info = 4; // 12
  p->link1->link1->link2 = p->link1->link2; // 13

  delete p->link1->link1;
  delete p->link1->link2;
  delete p->link1;
  delete p;
  return 0;
}