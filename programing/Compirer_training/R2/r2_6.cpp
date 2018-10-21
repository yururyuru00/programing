#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Entry {
  public:
    std::string name;
    std::string phone;
    Entry(const std::string& nm="", const std::string& ph="") {
      name = nm;
      phone = ph;
    }
  };

  class by_name { // 名前の比較関数オブジェクト
  public:
    bool operator()(const Entry& e1, const Entry& e2) const {
      return e1.name < e2.name;
    }
  };

  class by_phone { // 番号の比較関数オブジェクト
  public:
    bool operator()(const Entry& e1, const Entry& e2) const {
      return e1.phone < e2.phone;
    }
  };

  typedef std::vector<Entry> vec_Entry;
  typedef vec_Entry::iterator vec_Entry_ite;
  typedef std::vector<std::string> vec_str;
  typedef std::vector<std::string>::iterator vec_str_ite;

  std::ostream& operator<<(std::ostream& os, const Entry& e) {
    os << e.name << ": " << e.phone;
    return os;
  };

int main(void)
{
  std::vector<Entry> e;

  e.push_back(Entry("Kwansei Gakuin University (PR)", "0798-54-6017"));
  e.push_back(Entry("Kwansei Gakuin University (KSC)", "079-565-7600"));
  e.push_back(Entry("Kobe University", "078-881-1212"));
  e.push_back(Entry("Sanda Woodytown SATY", "079-564-8800"));
  e.push_back(Entry("Sanda Hotel", "079-564-1101"));


  for (int i=0; i<5; i++) {
    // ------------------------------------------------
    // 電話番号 "079-xxx-xxxx" を "xxx-xxxx" にせよ
    if(e[i].phone.find("079-")!=e[i].phone.npos)
      e[i].phone.replace(0, 4, "");
    else ;
    // ------------------------------------------------
  };



  vec_Entry_ite p;

  std::cout << "ソート前" << std::endl;
  for(p=e.begin(); p!=e.end(); p++) {
    std::cout << *p << std::endl;
  }

  std::cout << std::endl << "ソート後" << std::endl;

  sort(e.begin(), e.end(), by_name());
  for(p=e.begin(); p!=e.end(); p++) {
    std::cout << p->name << std::endl;
  }
  std::cout << std::endl;
  sort(e.begin(), e.end(), by_phone());
  for(p=e.begin(); p!=e.end(); p++) {
    std::cout << p->phone << std::endl;
  }

  return 0;
}
