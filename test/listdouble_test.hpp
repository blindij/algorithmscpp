
#ifndef ALGDAT_LISTDOUBLE_TEST_HPP
#define ALGDAT_LISTDOUBLE_TEST_HPP
#include "gmock/gmock.h"
#include "list.hpp"

using namespace testing;
using namespace std;

// The fixture for testing class ListTest
class ListDoubleTest: public testing::Test{
   // The class definition can be a an empty body. 
   // Functions/Methods can be removed
   protected:
      ListDoubleTest(){
         // Can contain set-up for each test
      }

      ~ListDoubleTest(){
         // Can do clean-up work that doesn't throw exceptions
      }

      void SetUp() override {
         // Code here will be called immediately after the 
         // constructor, right before each test.
         testList.Insert(0.75);
         testList.Insert(0.3E-6);
         testList.Insert(0.45);
         testList.Insert(0.314159E-19);
      }

      void TearDown() override {
         // Code here will be called immediately after each
         // test, right before the destructor.
      }

      // Objects declared here can be used by all tests in
      // the test case for Foo
      public:
      List<double> testList;

};

// Test List::Insert and List::Count
TEST_F(ListDoubleTest, DoInsertAndCount){
   EXPECT_EQ(testList.Count(),4);
}

// Test List::Get
TEST_F(ListDoubleTest, DoGet){
   EXPECT_EQ(testList.Get(1),0.3E-6);
}

// Test List::Remove
TEST_F(ListDoubleTest, DoRemove){
   EXPECT_TRUE(testList.Remove(0.314159E-19));
}

// Test List::Search
TEST_F(ListDoubleTest, DoSearch){
   EXPECT_EQ(testList.Search(0.45),2);
}
#endif //ALGDAT_LISTDOUBLE_TEST_HPP