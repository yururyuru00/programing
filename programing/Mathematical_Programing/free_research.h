#define BUS_MAX_SIZE 100
#define RIDE 1
#define ADD 2
#define TRACE 3
#define NORIDE 0
#define STOP -1

#define NOTTERM 0
#define TERM 1

typedef struct {
  char which_bus[5]; //そのバスがAかBか
  int pass_time; //7時から何分過ぎたか
  int capasity; //収容人数
  int profits; //利益
  int cost; //費用(~万円)
  int riding_time; //客を乗せるのにかかる時間
  float occupancy; //乗車率(割合)
} bus_detail_t;

typedef struct {
  int bus_size; //出したバスの合計数
  bus_detail_t bus[BUS_MAX_SIZE];
} bus_t;

bus_t* bus_new();
