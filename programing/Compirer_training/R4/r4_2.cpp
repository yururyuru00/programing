#include <iostream>

      class car {
      protected:
        std::string m_model; // 名前
        std::string m_maker; // メーカー
        int m_displacement; // 排気量
        int m_ps; // 最高出力
        int m_weight; // 車重
      public:
        car() {}

        car(const std::string& md, const std::string& mk, int dp, int p, int w):
        m_model(md), m_maker(mk), m_displacement(dp), m_ps(p), m_weight(w) {}

        ~car() {}

        std::string model() const {return m_model;}    // 蜷榊燕繧定ｿ斐☆

        int no() const {   // 3繝翫Φ繝舌�縺�5繝翫Φ繝舌�縺�
          if (m_displacement<2000) return 5;
          else                     return 3;
        }

        double pwratio() const { // 繝代Ρ繝ｼ繝ｻ繧ｦ繧ｧ繧､繝医�繝ｬ繧ｷ繧ｪ
          return (double) m_weight/(double) m_ps;
        }

        int tax() const {  // 閾ｪ蜍戊ｻ顔ｨ�
          if      (m_displacement<=1000) return  29500;
          else if (m_displacement<=1500) return  34500;
          else if (m_displacement<=2000) return  39500;
          else if (m_displacement<=2500) return  45000;
          else if (m_displacement<=3000) return  51000;
          else if (m_displacement<=3500) return  58000;
          else if (m_displacement<=4000) return  66500;
          else if (m_displacement<=4500) return  76500;
          else if (m_displacement<=6000) return  88000;
        else                         return 110000;
      }
  };

  class hybrid_car : public car { // public の意味は下記参照
    private:
      int m_motor_ps;
    public:
      hybrid_car() {}

        hybrid_car(const std::string& md, const std::string& mk,
          int dp, int p, int w, int mps):
          car(md,mk,dp,p,w), m_motor_ps(mps) {}

          ~hybrid_car() {}

          double pwratio() const { // 最高出力にモーターの馬力を加算
            return (double) m_weight/(double)(m_ps+m_motor_ps);
          }

          int tax() const {return car::tax()/2;} // 「税金がタダ」 (後で書き換える)
    };

  int main(void) {

  car a = car("Skyline", "Nissan", 3498, 272, 1500);
  car b = car("Civic", "Honda", 1998, 215, 1190);
   hybrid_car h = hybrid_car("Prius", "Toyota", 1496, 77, 1290, 68);

  std::cout << a.model() << "  "
       << a.no() << "  "
       << a.pwratio() << "  "
       << a.tax() << std::endl;

  std::cout << b.model() << "  "
       << b.no() << "  "
       << b.pwratio() << "  "
       << b.tax() << std::endl;

  std::cout << h.model() << " "
       << h.no() << " "
       << h.pwratio() << " "
       << h.tax() << std::endl;

  return 0;
}
