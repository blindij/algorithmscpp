#ifndef ALGDAT_LISTSTRING_TEST_HPP
#define ALGDAT_LISTSTRING_TEST_HPP
#include "gmock/gmock.h"
#include "list.hpp"

using namespace testing;
using namespace std;

// The fixture for testing class ListTest
class ListStringTest: public testing::Test{
   // The class definition can be a an empty body. 
   // Functions/Methods can be removed
   protected:
      ListStringTest(){
         // Can contain set-up for each test
      }

      ~ListStringTest(){
         // Can do clean-up work that doesn't throw exceptions
      }

      void SetUp() override {
         // Code here will be called immediately after the 
         // constructor, right before each test.
         testList.Insert("x");
         testList.Insert("a");
         testList.Insert("f");
         testList.Insert("c");
         testList.Insert("k");
      }

      void TearDown() override {
         // Code here will be called immediately after each
         // test, right before the destructor.
      }

      // Objects declared here can be used by all tests in
      // the test case for Foo
      public:
      List<std::string> testList;
};

// Test List::Insert and List::Count
TEST_F(ListStringTest, DoStringInsertAndCount){
   EXPECT_EQ(testList.Count(),5);
}

// Test List::Get
TEST_F(ListStringTest, DoGet){
        EXPECT_EQ(testList.Get(3),"c");
}
// TODO: Add a test that checks for a thrown exception: When Get()
//       paramater is negative or larger than array size

// Test List::Remove
TEST_F(ListStringTest, DoStringRemove){
   testList.Remove("c");
   EXPECT_EQ(testList.Get(3),"k");
}

// Test List::Search()
TEST_F(ListStringTest, DoStringSearch){
   EXPECT_EQ(testList.Search("f"),2);
}
#endif //ALGDAT_LISTDOUBLE_TEST_HPP