#include "header.h"
#include <gtest/gtest.h>
#include <memory>

TEST (AddFunction, add)
{
	ASSERT_EQ (add (2, 3), 5);
}

TEST (TestClass, getA)
{
	auto TestObject = std::make_shared<TestClass> ();
	ASSERT_EQ (TestObject->getA (), 1);
}

TEST (TestClass, getB)
{
	auto TestObject = std::make_shared<TestClass> ();
	ASSERT_EQ (TestObject->getB (), 2);
}

TEST (TestClass, setA)
{
	auto TestObject = std::make_shared<TestClass> ();
	TestObject->setA (42);
	ASSERT_EQ (TestObject->getA (), 42);
}

TEST (TestClass, setB)
{
	auto TestObject = std::make_shared<TestClass> ();
	TestObject->setB (43);
	ASSERT_EQ (TestObject->getB (), 43);
}
