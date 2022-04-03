#include <iostream>

int main() { 
 double x, y;
  std::cout << "Enter x and y: ";
 std::cin >> x >> y;
  double res=0.0,one=1.0;
 _asm { //возведение х в степень у
  finit
  fld y
  fld x
  fyl2x
  fld1
  fscale
  fst res
  }
  std::cout << res;
  //нахождение корней квадратного уравнения
 int two = 2;
 float a,b,c;
 std::cout << "Enter a,b,c: ";
 std::cin >> a >> b >> c;
 float x1, x2, discr;
 _asm {
fild a
fld b
fld c
fmul st, st(2) 
fild two
fmul st, st 
fmul st, st(1)
fld b
fmul st, st
fsub st, st(1)
fst discr
 }
 if (discr < 0) {
   std::cout << "No roots\n";
   return 1;
 }
 _asm {
fsqrt
fild a
fadd st, st(0) 
fld b
fchs
fadd st, st(2)
fdiv st, st(1)
fstp x1
fld st(3)
fchs
fsub st, st(2)
fdiv st, st(1)
fstp x2
 }
 std::cout << x1 << '\t' << x2 << std::endl;

 return 0;
}