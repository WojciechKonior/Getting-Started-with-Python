#include <iostream>
#include <cstdint>

static int a = 10;
extern int b;
register int c = 10;

const int d = 20;
mutable int e = 30;
volatile int f = 10;

typedef long long int lli;

int main()
{
  char c = 'c';
  short s = 42;
  int i = 42;
  long l = 42L;
  long long ll = 42LL;
  unsigned int ui = 42U;
  unsigned long ul = 42UL;
  unsigned long long ull = 42ULL;

  int8_t a;
  uint8_t ua;

  int16_t b;
  uint16_t ub;

  int32_t c;
  uint32_t uc;

  int64_t c;
  uint64_t uc;
  
  intmax_t d;
  uintmax_t ud;

  float f = 10.0f;
  double fd = 140.2;
  long double ldf = 123.0;

  auto e = 10;

  int ia[5] {}; //0 0 0 0 0 
  
}
