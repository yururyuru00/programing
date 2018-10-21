#include <iostream>
#include <string>
#include <map>

int main(void)
{
  std::map<std::string, std::string> e;

  e["Kwansei Gakuin University (PR)"] = "0798-54-6017";
  e["Kwansei Gakuin University (KSC)"] = "079-565-7600";
  e["Kobe University"] = "078-881-1212";
  e["Sanda Woodytown SATY"] = "079-564-8800";
  e["Sanda Hotel"] = "079-564-1101";


  std::map<std::string, std::string>::iterator p;
  for (p=e.begin(); p!=e.end(); p++) {
    // ------------------------------------------------
    // 電話番号 "079-xxx-xxxx" を "xxx-xxxx" にせよ
    if(p->second.find("079-")==0)
      p->second.replace(0, 4, "");
    else ;
    //std::cout << p->second << std::endl;
    // ------------------------------------------------
  };
  std::cout << std::endl;
  std::cout << "検索用文字列を入力して下さい: ";
  std::string s;
  std::cin >> s;
  // ------------------------------------------------
  // name に s を含むデータを全て表示せよ
  /*if((p=e.find(s))==e.end()) std::cout << "not found";
  else {
    std::cout << p->first
  }*/
  for (p=e.begin(); p!=e.end(); p++) {
    if(p->first.find(s)!=p->second.npos)
      std::cout << p->first << p->second << std::endl;
    else ;
    // ------------------------------------------------
  }
  return 0;
}
