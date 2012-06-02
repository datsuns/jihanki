#include <gtest/gtest.h>
#include "Jihanki.cpp"

class JihankiTest : public ::testing::Test {
	public:
		virtual void SetUp() {
		}

		virtual void TearDown() {
		}
	protected:
		Jihanki jihanki;
};

TEST_F( JihankiTest, InsertRetrunCharge ){
  ASSERT_EQ(1, jihanki.insert(1));
  ASSERT_EQ(5, jihanki.insert(5));
  ASSERT_EQ(300, jihanki.insert(300));
  ASSERT_EQ(1001, jihanki.insert(1001));
}

TEST_F( JihankiTest, InsertMoney ){
  ASSERT_EQ(0, jihanki.insert(10));
  ASSERT_EQ(0, jihanki.insert(50));
  ASSERT_EQ(0, jihanki.insert(100));
  ASSERT_EQ(0, jihanki.insert(500));
  ASSERT_EQ(0, jihanki.insert(1000));
}

TEST_F( JihankiTest, MultiInsert ){
  ASSERT_EQ(0, jihanki.insert(10));
  ASSERT_EQ(0, jihanki.insert(10));
  ASSERT_EQ(0, jihanki.insert(10));
}

TEST_F( JihankiTest, GetTotalMoney ){
  ASSERT_EQ(0, jihanki.getTotalMoney());
}

