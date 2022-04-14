#include <gtest/gtest.h>
#include "t.hpp"

TEST(basicTest, addTest){

  t tes;

  EXPECT_FLOAT_EQ(3.0, tes.add(1.0, 2.0));


}
