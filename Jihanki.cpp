#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Juice {
  std::string name;
  int price;
};

struct JuiceInfo {
  Juice juice;
  int stock;
};

class Jihanki {
  public:
    Jihanki( void ) : totalMoney(0) {
      Juice cola = {"cola", 120};
      JuiceInfo colaInfo = {cola, 5};
      JuiceList.push_back(colaInfo);
    }

    int insert(int money) {
      if(isExpected(money)){
        totalMoney += money;
        return 0;
      }
      return money;
    }

    int getTotalMoney(void) {
      return totalMoney;
    }

    int payBack(void) {
      int tmp = totalMoney;
      totalMoney = 0;
      return tmp;
    }

    std::vector<JuiceInfo> getJuiceList() {
      return JuiceList;
    }

  private:
    int totalMoney;
    std::vector<JuiceInfo> JuiceList;

    bool isExpected(int money) {
      std::vector<int> list /* = {10, 50, 100, 500, 1000}; */;
      list.push_back(10);
      list.push_back(50);
      list.push_back(100);
      list.push_back(500);
      list.push_back(1000);
      if(std::find(list.begin(), list.end(), money) != list.end()) return true;
      return false;
    }
};

