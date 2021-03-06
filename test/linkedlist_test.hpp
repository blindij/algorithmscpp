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
         testList.Insert(20);
         testList.Insert(21);
         testList.Insert(47);
         testList.Insert(87);
         testList.Insert(35);
         testList.Insert(92);
      }

      void TearDown() override {
         // Code here will be called immediately after each
         // test, right before the destructor.
      }

      // Objects declared here can be used by all tests in
      // the test case for Foo
      public:
      List<int> testList;
};

// Test that List::Count()
TEST_F(ListTest, DoCount){
   EXPECT_EQ(testList.Count(),6);
}

// Test that List::Get()
TEST_F(ListTest, DoGet){
   EXPECT_EQ(testList.Get(0), 20);
   EXPECT_EQ(testList.Get(3), 87);
   EXPECT_EQ(testList.Get(2), 47);
   EXPECT_EQ(testList.Get(4), 35);
}

// Test List::Remove()
TEST_F(ListTest, DoRemove){
   EXPECT_EQ(testList.Get(3),87);
   EXPECT_TRUE(testList.Remove(87));
   EXPECT_EQ(testList.Get(3),35);
}

// Test List::Search
TEST_F(ListTest, DoSearch){
   EXPECT_EQ(testList.Search(97),-1);   // Not found
   EXPECT_EQ(testList.Search(87),3);    // An item that must be found
}
 
 // Test List::Sort
 TEST_F(ListTest,DoSort){
    testList.Sort();
    EXPECT_EQ(testList.Get(0),20);
    EXPECT_EQ(testList.Get(1),21);
    EXPECT_EQ(testList.Get(2),35);
    EXPECT_EQ(testList.Get(3),47);
    EXPECT_EQ(testList.Get(4),87);
    EXPECT_EQ(testList.Get(5),92);
 }
#endif //ALGDAT_LIST
