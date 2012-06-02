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

TEST_F( JihankiTest, GetInitialMoney ){
	ASSERT_EQ(0, jihanki.getTotalMoney());
}

TEST_F( JihankiTest, GetTotalMoney ){
	jihanki.insert(1);
	ASSERT_EQ(0, jihanki.getTotalMoney());
}

TEST_F( JihankiTest, GetTotalMoney2 ){
	jihanki.insert(10);
	ASSERT_EQ(10, jihanki.getTotalMoney());
}

TEST_F( JihankiTest, GetTotalMoney3 ){
	jihanki.insert(10);
	jihanki.insert(100);
	ASSERT_EQ(110, jihanki.getTotalMoney());
}

TEST_F( JihankiTest, GetTotalMoney4 ){
	jihanki.insert(10);
	jihanki.insert(100000);
	jihanki.insert(100);
	ASSERT_EQ(110, jihanki.getTotalMoney());
}

TEST_F( JihankiTest, InitialPayBack ){
	ASSERT_EQ(0, jihanki.payBack());
}

TEST_F( JihankiTest, PayBack ){
	jihanki.insert(100);
	ASSERT_EQ(100, jihanki.payBack());
	ASSERT_EQ(0, jihanki.getTotalMoney());
}

TEST_F( JihankiTest, GetJuiceInfo ){
  std::vector<JuiceInfo> list = jihanki.getJuiceList();
	ASSERT_GE(1,      list.size());
	ASSERT_EQ("cola", list[0].juice.name);
	ASSERT_EQ(120,    list[0].juice.price);
	ASSERT_EQ(5,      list[0].stock);
}

