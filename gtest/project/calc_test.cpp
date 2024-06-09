// calc_test.cpp
#include <gtest/gtest.h>
#include "calc.h"
#include <iostream>
using namespace std;

class QueueTest : public testing::Test {
 protected:
  QueueTest() {
     // q0_ remains empty
     q1_.Enqueue(1);
     q2_.Enqueue(2);
     q2_.Enqueue(3);
  }

  // ~QueueTest() override = default;
   void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
     cout<<"SetUp"<<endl;
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
     cout<<"TearDown"<<endl;
  }

  Queue<int> q0_;
  Queue<int> q1_;
  Queue<int> q2_;
};

TEST_F(QueueTest, IsEmptyInitially) {
  EXPECT_EQ(q0_.size(), 0);
}

TEST_F(QueueTest, DequeueWorks) {

  int n = q1_.Dequeue();
  EXPECT_EQ(n, 1);
  EXPECT_EQ(q1_.size(), 0);

  n = q2_.Dequeue();
  EXPECT_EQ(n, 2);
  EXPECT_EQ(q2_.size(), 1);
}

TEST(CalcTest, Add) {
    EXPECT_EQ(2, add(1, 1));
    EXPECT_EQ(5, add(3, 2));
    EXPECT_EQ(10, add(7, 3));
    cout<<"--here"<<endl;
}

TEST(CalcTest, Sub) {
    ASSERT_EQ(3, sub(5, 2));
    ASSERT_EQ(-10, sub(5, 15));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}