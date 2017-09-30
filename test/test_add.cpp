#include <gtest/gtest.h>
#include "header.h"

TEST(AddTest, add)
{
  ASSERT_EQ(add(2,3),5);
  ASSERT_EQ(add(3,3),6);
  ASSERT_EQ(add(2,5),7);
}

