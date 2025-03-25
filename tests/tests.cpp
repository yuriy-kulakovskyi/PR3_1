#include <gtest/gtest.h>
#define UNIT_TEST
#include "../Elem.h"

TEST(ElemTest, StructureCreation) {
  Elem* p = new Elem;
  p->info = 1;
  p->link2 = nullptr;

  p->link1 = new Elem;
  p->link1->info = 2;
  p->link1->link2 = new Elem;
  p->link1->link2->info = 3;
  p->link1->link2->link2 = nullptr;
  p->link1->link2->link1 = p->link1;

  p->link1->link1 = new Elem;
  p->link1->link1->info = 4;
  p->link1->link1->link1 = p;
  p->link1->link1->link2 = p->link1->link2;

  EXPECT_EQ(p->info, 1);
  EXPECT_EQ(p->link1->info, 2);
  EXPECT_EQ(p->link1->link2->info, 3);
  EXPECT_EQ(p->link1->link1->info, 4);

  // Перевірка зв'язків
  EXPECT_EQ(p->link1->link2->link1, p->link1);
  EXPECT_EQ(p->link1->link1->link1, p);
  EXPECT_EQ(p->link1->link1->link2, p->link1->link2);

  // Видалення
  delete p->link1->link1;
  delete p->link1->link2;
  delete p->link1;
  delete p;
}