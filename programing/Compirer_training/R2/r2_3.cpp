#include <iostream>
#include <string>
#include <list>

// 蟄ｦ逕� 1 莠ｺ蛻��險倬鹸
class Record {
  public:
    int id;             // 蟄ｦ邀咲分蜿ｷ
    std::string name;   // 蜷榊燕
    int score;          // 轤ｹ謨ｰ
    Record() {}
    Record(int i, const std::string& nm, int s) {
      id = i;
      name = nm;
      score = s;
    }
};

std::ostream& operator<<(std::ostream& os, const Record& r)
{
  os << "[" << r.id << "] " << r.name << " : " << r.score;
  return os;
}

// 謌千ｸｾ邁ｿ (蜈ｨ蟄ｦ逕溘�險倬鹸)
class Seiseki {
  public:
    std::list<Record> data;
    void insert(int, const std::string&, int);
    void lookup(int) const;
    void erase_worst();
};

std::ostream& operator<<(std::ostream& os, const Seiseki& s)
{
  os << "*** 成績簿 ***\n";
  for (std::list<Record>::const_iterator p = s.data.begin();
    p != s.data.end(); p++) {
    os << *p << "\n";
  }
  return os;
}

void Seiseki::insert(int id, const std::string& nm, int s)
{
  // -----------------------------
  //    縺薙�驛ｨ蛻�ｒ螳梧�縺輔○繧�
  data.push_back(Record(id, nm, s));
  // -----------------------------
}

void Seiseki::lookup(int id) const
{
  // -----------------------------
  //    縺薙�驛ｨ蛻�ｒ螳梧�縺輔○繧�
  std::list<Record>::const_iterator p;
  for(p = data.begin(); p != data.end(); p++) {
    if(p->id==id) {
      std::cout << *p << std::endl;
      break;
    }
    else ;
  }
  if(p==data.end()) std::cout << "not found" << std::endl;
  else ;
  // -----------------------------
}

void Seiseki::erase_worst()
{
  // -----------------------------
  //    縺薙�驛ｨ蛻�ｒ螳梧�縺輔○繧�
  int buff = 100;

  std::list<Record>::const_iterator p, p_buffo;
  for(p = data.begin(); p != data.end(); p++) {
    if(p->score < buff) {
      buff = p->score;
      p_buffo = p;
    }
    else ;
  }
  data.erase(p_buffo);
  // -----------------------------
}

int main(void)
{
  Seiseki s;

  // 謌千ｸｾ縺ｮ逋ｻ骭ｲ
  s.insert(7001,"aaaa",89);
  s.insert(7123,"bbbb",70);
  s.insert(7013,"cccc",55);
  s.insert(7200,"dddd",99);
  s.insert(7087,"eeee",83);

  // 蜈ｨ蟄ｦ逕溘�謌千ｸｾ縺ｮ陦ｨ遉ｺ
  std::cout << s;

  // 蜈･蜉帙＠縺� id 縺ｮ險倬鹸縺ｮ陦ｨ遉ｺ (0 繧貞�蜉帙☆繧九∪縺ｧ郢ｰ繧願ｿ斐＠)
  int id;
  std::cout << "> ";
  std::cin >> id;
  while (id!=0) {
    s.lookup(id);
    std::cout << "> ";
    std::cin >> id;
  }

  // 轤ｹ謨ｰ縺梧怙繧よが縺�ｭｦ逕溘ｒ豸亥悉
  s.erase_worst();

  // 蜈ｨ蟄ｦ逕溘�謌千ｸｾ縺ｮ陦ｨ遉ｺ
  std::cout << s;

  return 0;
}
