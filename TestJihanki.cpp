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
    Juice cola = { "cola", 120 };
};

TEST_F( JihankiTest, InsertRetrunCharge ){
  ASSERT_EQ(1, jihanki.insert(1).first);
  ASSERT_EQ(5, jihanki.insert(5).first);
  ASSERT_EQ(300, jihanki.insert(300).first);
  ASSERT_EQ(1001, jihanki.insert(1001).first);
}

TEST_F( JihankiTest, InsertMoney ){
  ASSERT_EQ(0, jihanki.insert(10).first);
  ASSERT_EQ(0, jihanki.insert(50).first);
  ASSERT_EQ(0, jihanki.insert(100).first);
  ASSERT_EQ(0, jihanki.insert(500).first);
  ASSERT_EQ(0, jihanki.insert(1000).first);
}

TEST_F( JihankiTest, MultiInsert ){
  ASSERT_EQ(0, jihanki.insert(10).first);
  ASSERT_EQ(0, jihanki.insert(10).first);
  ASSERT_EQ(0, jihanki.insert(10).first);
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

TEST_F( JihankiTest, GetJuiceStockInfo ){
  std::vector<JuiceStockInfo> list = jihanki.getJuiceStockInfoList();
  ASSERT_GE(list.size(), 1);
  ASSERT_EQ("cola", list[0].juice.name);
  ASSERT_EQ(120,    list[0].juice.price);
  ASSERT_EQ(5,      list[0].num);
}

TEST_F( JihankiTest, GetJuiceList ) {
  auto list = jihanki.insert(1000).second;
  ASSERT_GE(list.size(), 1);

  Juice tmp = list[0];
  ASSERT_EQ("cola", tmp.name);
  ASSERT_EQ(120,    tmp.price);
}

TEST_F( JihankiTest, GetJuiceEmptyList ) {
  auto list = jihanki.insert(100).second;
  ASSERT_EQ(list.size(), 0);
}

TEST_F( JihankiTest, CheckCharge ) {
  jihanki.insert(1000);
  ASSERT_EQ(jihanki.buy("cola").first, 880 );
  ASSERT_EQ(jihanki.getTotalMoney(), 0 );
}

TEST_F( JihankiTest, CheckCharge2 ) {
  jihanki.insert(500);
  ASSERT_EQ(jihanki.buy("cola").first, 380 );
  ASSERT_EQ(jihanki.getTotalMoney(), 0 );
}

TEST_F( JihankiTest, BuyCola) {
  jihanki.insert(500);
  auto cola = jihanki.buy("cola").second;
  ASSERT_TRUE(cola);
  ASSERT_EQ(cola->name, "cola" );
}

TEST_F( JihankiTest, CantBuyCola) {
  auto cola = jihanki.buy("cola").second;
  ASSERT_FALSE(cola);
}
