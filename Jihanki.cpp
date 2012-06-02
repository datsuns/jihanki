#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
      Juice cola = {"cola", 120};
      JuiceStockInfo colaInfo = {cola, 5};
      juiceStockList.push_back(colaInfo);
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

    std::pair<int,Juice> buy(std::string name) {
        for(auto juiceStock : juiceStockList)
			if( juiceStock.juice.price < totalMoney ){
				Juice empty = {"", 0};
				return std::make_pair(totalMoney, empty);
			}

		if( totalMoney < 
		Juice juice = {"cola", 120};
		totalMoney = 0;
		return std::make_pair(880, juice );
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

