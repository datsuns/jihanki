#include <gtest/gtest.h>
#include "Jihanki.cpp"

TEST(TestJihanki, InsertRetrunCharge) {
  Jihanki jihanki;
  ASSERT_EQ(1, jihanki.insert(1));
  ASSERT_EQ(5, jihanki.insert(5));
  ASSERT_EQ(300, jihanki.insert(300));
  ASSERT_EQ(1001, jihanki.insert(1001));
}

TEST(TestJihanki, InsertMoney) {
  Jihanki jihanki;
  ASSERT_EQ(0, jihanki.insert(10));
  ASSERT_EQ(0, jihanki.insert(50));
  ASSERT_EQ(0, jihanki.insert(100));
  ASSERT_EQ(0, jihanki.insert(500));
  ASSERT_EQ(0, jihanki.insert(1000));
}

TEST(TestJihanki, MultiInsert) {
  Jihanki jihanki;
  ASSERT_EQ(0, jihanki.insert(10));
  ASSERT_EQ(0, jihanki.insert(10));
  ASSERT_EQ(0, jihanki.insert(10));
}

TEST(TestJihanki, GetTotalMoney) {
  Jihanki jihanki;

  ASSERT_EQ(0, jihanki.getTotalMoney());
}

