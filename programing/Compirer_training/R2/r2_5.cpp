#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> int_vector;
typedef int_vector::iterator int_vector_iter;

int main(void)
{
  int_vector v(6);
  v.push_back(3);
  v.push_back(5);
  v.push_back(2);
  v.push_back(3);
  v.push_back(2);
  v.push_back(3);

  std::cout << ">";
  int i;
  std::cin >> i;

  // 繝ｪ繧ｹ繝井ｸｭ縺ｮ i 繧呈､懃ｴ｢
  int_vector_iter p = find(v.begin(), v.end(), i);
  if (p==v.end()) {
    // 隕九▽縺九ｉ縺ｪ縺��ｴ蜷�
    std::cout << "not found\n";
  }
  else {
    // 隕九▽縺九▲縺溷�ｴ蜷�
    std::cout << *p << " found\n";

    // 隕九▽縺九▲縺溘→縺薙ｍ縺ｮ逶ｴ蠕後°繧画峩縺ｫ讀懃ｴ｢繧堤ｶ咏ｶ�
    p = find(++p, v.end(), i);
    if (p==v.end()) {
       std::cout << "not found\n";
    }
    else {
      std::cout << *p << " found again\n";
    }
  }

  return 0;
}
