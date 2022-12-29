// Copyright (c) by respective owners including Yahoo!, Microsoft, and
// individual contributors. All rights reserved. Released under a BSD (revised)
// license as described in the file LICENSE.

#include "vw/core/example.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(example_test, example_move_ctor_moves_pred)
{
  VW::example ex;
  ex.pred.scalars.push_back(8);
  EXPECT_EQ(ex.pred.scalars.size(), 1);

  VW::example ex2(std::move(ex));

  EXPECT_EQ(ex.pred.scalars.size(), 0);
  EXPECT_EQ(ex2.pred.scalars.size(), 1);
}

TEST(example_test, example_move_assign_op_moves_pred)
{
  VW::example ex;
  ex.pred.a_s.push_back({0, 0});
  EXPECT_EQ(ex.pred.a_s.size(), 1);

  VW::example ex2;
  EXPECT_EQ(ex2.pred.a_s.size(), 0);
  ex2 = std::move(ex);

  EXPECT_EQ(ex.pred.a_s.size(), 0);
  EXPECT_EQ(ex2.pred.a_s.size(), 1);
}