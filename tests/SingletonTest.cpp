/* 
 * File:   SingletonTest.cpp
 * Author: Marco Ambu
 */

#include "soil/Singleton.h"
#include <gtest/gtest.h>

using namespace soil;

class Dummy {};

class SingletonTestClass : public Singleton<SingletonTestClass>
{
public:
    int f() {return ++val;}

protected:
    SingletonTestClass()
        : val(0)
    {}

private:
    int val;
private:
    friend class Singleton<SingletonTestClass>;
};

TEST(SingletonTest, testUniqueness)
{
    Dummy& inst1 = Singleton<Dummy>::get();
    Dummy& inst2 = Singleton<Dummy>::get();
    ASSERT_EQ(&inst1, &inst2);
}

TEST(SingletonTest, testSingletonClass)
{
    SingletonTestClass& c = SingletonTestClass::get();
    ASSERT_EQ(1, c.f());
    ASSERT_EQ(2, SingletonTestClass::get().f());
    ASSERT_EQ(3, c.f());
}
