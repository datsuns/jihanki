#include <iostream>
#include <vector>
#include <algorithm>

class Jihanki {
public:
  int insert(int money) {
    if(isExpected(money)) return 0;
    return money;
  }

  int getTotalMoney(void) {
  }

private:
  bool isExpected(int money) {
    const static std::vector<int> list = {10, 50, 100, 500, 1000};
    if(std::find(list.begin(), list.end(), money) != list.end()) return true;
    return false;
  }
};

