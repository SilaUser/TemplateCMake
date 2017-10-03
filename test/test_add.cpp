#include "header.h"
#include "testmath.h"
#include <gtest/gtest.h>
#include <memory>

TEST(AddFunction, add)
{
    ASSERT_EQ(add(2, 3), 5);
}

TEST(TestClass, getA)
{
    auto TestObject = std::make_shared<TestClass>();
    ASSERT_EQ(TestObject->getA(), 1);
}

TEST(TestClass, getB)
{
    auto TestObject = std::make_shared<TestClass>();
    ASSERT_EQ(TestObject->getB(), 2);
}

TEST(TestClass, setA)
{
    auto TestObject = std::make_shared<TestClass>();
    TestObject->setA(42);
    ASSERT_EQ(TestObject->getA(), 42);
}

TEST(TestClass, setB)
{
    auto TestObject = std::make_shared<TestClass>();
    TestObject->setB(43);
    ASSERT_EQ(TestObject->getB(), 43);
}

TEST(MathLib, Add)
{
    ASSERT_EQ(Add(1, 1), 2);
}
TEST(MathLib, Sub)
{
    ASSERT_EQ(Sub(1, 1), 0);
}
TEST(MathLib, Mul)
{
    ASSERT_EQ(Mul(1, 1), 1);
}
TEST(MathLib, Div)
{
    ASSERT_EQ(Div(4, 2), 2);
}
TEST(MathLib, Or)
{
    ASSERT_EQ(Or(1, 1), 1);
}
TEST(MathLib, And)
{
    ASSERT_EQ(And(1, 1), 1);
}
