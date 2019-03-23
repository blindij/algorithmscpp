#ifndef ALGDAT_LIST_TEST_HPP
#define ALGDAT_LIST_TEST_HPP
#include "gmock/gmock.h"
#include "list.hpp"

using namespace testing;
using namespace std;

// The fixture for testing class ListTest
class ListTest: public testing::Test{
   // The class definition can be a an empty body. 
   // Functions/Methods can be removed
   protected:
      ListTest(){
         // Can contain set-up for each test
      }

      ~ListTest(){
         // Can do clean-up work that doesn't throw exceptions
      }

      void SetUp() override {
         // Code here will be called immediately after the 
         // constructor, right before each test.
         testList.Insert(0,21);
         testList.Insert(1,47);
         testList.Insert(2,87);
         testList.Insert(3,35);
         testList.Insert(4,92);
      }

      void TearDown() override {
         // Code here will be called immediately after each
         // test, right before the destructor.
      }

      // Objects declared here can be used by all tests in
      // the test case for Foo
      public:
      List testList;
      // List testList2;

};

// Test that List::Count()
TEST_F(ListTest, DoCount){
   EXPECT_EQ(testList.Count(),5);
}

// Test that List::Get()
TEST_F(ListTest, DoGet){
   EXPECT_EQ(testList.Get(0), 21);
   EXPECT_EQ(testList.Get(3), 35);
   EXPECT_EQ(testList.Get(2), 87);
   EXPECT_EQ(testList.Get(4), 92);
}

// Test List::Remove()
TEST_F(ListTest, DoRemove){
   EXPECT_EQ(testList.Get(3),35);
   testList.Remove(3);
   EXPECT_EQ(testList.Get(3),92);
}

// Test List::Search
#endif //ALGDAT_LIST
