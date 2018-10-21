#include <iostream>
inline int abs(int x)  {return 0<=x ? x : -x;}

class canvas {
  public:
    canvas(int sx, int sy);
    ~canvas();
    void clear();
    void set(int x, int y);
    void print(std::ostream &os);
  private:
    int size_x;
    int size_y;
    char **p;
    canvas(const canvas&);
    canvas& operator=(const canvas&);
};

std::ostream& operator<<(std::ostream& os, canvas& c) {c.print(os);}

//canvas::canvas(): size_x(0), size_y(0), p(0) {}

canvas::canvas(int sx, int sy): size_x(sx), size_y(sy) {
  p = new char*[size_x];
  for (int x=0; x<size_x; x++) p[x] = new char[size_y];
  this->clear();
}

canvas::~canvas() {
  for (int x=0; x<size_x; x++) delete [] p[x];
  delete [] p;
}

void canvas::clear() {
  for (int x=0; x<size_x; x++) {
    for (int y=0; y<size_y; y++) {
      p[x][y] = ' ';
    }
  }
}

void canvas::set(int x, int y) {
  if (0<=x && x<size_x && 0<=y && y<size_y) p[x][y] = 'X';
}

void canvas::print(std::ostream& os) {
  os << '+';
  for (int x=0; x<size_x; x++) {os << '-';}
  os << '+' << std::endl;
  for (int y=size_y-1; 0<=y; y--) {
    os << '|';
    for (int x=0; x<size_x; x++) {
      os << p[x][y];
    }
    os << '|' << std::endl;
  }
  os << '+';
  for (int x=0; x<size_x; x++) {os << '-';}
  os << '+' << std::endl;
}


class point {
  private:
    int px, py;
  public:
    point(int x, int y);
    ~point();
    void move(int ix, int iy);
    void draw(canvas &c);
};

point::point(int x, int y) : px(x), py(y) {}
point::~point() {}
void point::move(int ix, int iy) {px += ix; py += iy;}
void point::draw(canvas &c) {c.set(px,py);}

class rectangle {
  private:
    int px, py;
    int width, height;
  public:
    rectangle(int x, int y, int w, int h);
    ~rectangle();
    void move(int ix, int iy);
    void draw(canvas &c);
};

rectangle::rectangle(int x, int y, int w, int h) : px(x), py(y), width(w), height(h) {}
rectangle::~rectangle() {};
void rectangle::move(int ix, int iy) {px += ix; py += iy;}
void rectangle::draw(canvas &c) {
  for(int i=px; i<=px+width-1; i++) {
    for(int j=py; j<=py+height-1; j++) {c.set(i, j);}
  }
}



class diamond {
  private:
    int px, py;
    int radius;
  public:
    diamond(int x, int y, int r);
    ~diamond();
    void move(int ix, int iy);
    void draw(canvas &c);
};

diamond::diamond(int x, int y, int r) : px(x), py(y), radius(r) {}
diamond::~diamond() {}
void diamond::move(int ix, int iy) {px += ix; py += iy;}
void diamond::draw(canvas &c) {
  if (0<=radius) {
    for (int r=-radius; r<=radius; r++) {
      int h = radius - abs(r);
      for (int s=-h; s<=h; s++) {
        c.set(px+r,py+s);
      }
    }
  }
}


int main( void )
{

  point p1(0,0);
  point p2(17,9);
  point p3(19,2);
  rectangle r1(2,1,3,2);
  rectangle r2(7,7,6,2);
  diamond d1(2,7,2);
  diamond d2(15,3,4);

  canvas c(20,10);
  p1.draw(c);
  p2.draw(c);
  p3.draw(c);
  r1.draw(c);
  r2.draw(c);
  d1.draw(c);
  d2.draw(c);
  std::cout << c;

  p1.move(4,2);
  p2.move(4,2);
  p3.move(4,2);
  r1.move(4,2);
  r2.move(4,2);
  d1.move(4,2);
  d2.move(4,2);

  c.clear();
  p1.draw(c);
  p2.draw(c);
  p3.draw(c);
  r1.draw(c);
  r2.draw(c);
  d1.draw(c);
  d2.draw(c);
  std::cout << c;

  return 0;
}
