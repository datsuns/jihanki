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
    Jihanki() : totalMoney(0) {
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

    int getTotalMoney() {
      return totalMoney;
    }

    int payBack() {
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
      const static std::vector<int> list = {10, 50, 100, 500, 1000};
      if(std::find(list.begin(), list.end(), money) != list.end()) return true;
      return false;
    }
};

