#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/optional.hpp>

struct Juice {
  std::string name;
  int price;
};

struct JuiceStockInfo {
  Juice juice;
  int num;
};

class Jihanki {
  public:
    Jihanki() : totalMoney(0) {
      juiceStockList.push_back({{"cola", 120}, 5});
    }

    std::pair<int,std::vector<Juice>> insert(int money) {
      std::vector<Juice> list;

      if(isExpected(money)){
        totalMoney += money;
        for(auto juiceStock : juiceStockList)
          if(totalMoney >= juiceStock.juice.price) list.push_back(juiceStock.juice);

        return std::make_pair(0, list);
      }
      return std::make_pair(money, list);
    }

    int getTotalMoney() {
      return totalMoney;
    }

    int payBack() {
      int tmp = totalMoney;
      totalMoney = 0;
      return tmp;
    }

    std::vector<JuiceStockInfo> getJuiceStockInfoList() {
      return juiceStockList;
    }

    std::pair<int, boost::optional<Juice>> buy(const std::string &name) {
      int tmp = totalMoney;
      totalMoney = 0;

      const Juice &cola = juiceStockList[0].juice;
      if( tmp < cola.price ){
        return std::make_pair(tmp, boost::none);
      }

      return std::make_pair(tmp-cola.price, cola);
    }

  private:
    int totalMoney;
    std::vector<JuiceStockInfo> juiceStockList;

    bool isExpected(int money) {
      const static std::vector<int> list = {10, 50, 100, 500, 1000};
      if(std::find(list.begin(), list.end(), money) != list.end()) return true;
      return false;
    }
};

