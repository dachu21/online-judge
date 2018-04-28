// pl.spoj.com: dachu21

#include <iostream>

using namespace std;

void balance(const int a, const int b, const int d) {
  long long a_ = a, b_ = b;
  long long p = 1, q = 0, pp = 0, qq = 1, pp_, qq_;
  long long quotient, remainder;

  do {
    quotient = a_ / b_;
    remainder = a_ % b_;
    a_ = b_;
    b_ = remainder;
    pp_ = pp;
    qq_ = qq;
    pp = p - quotient * pp;
    qq = q - quotient * qq;
    p = pp_;
    q = qq_;
  } while (remainder > 0);
  long long gcd = a_;

  if (d % gcd != 0) {
    cout << "BRAK\n";
  } else {

    quotient = d / gcd;
    p = p * quotient;
    q = q * quotient;

    long long quotient1 = (abs(p) * gcd / b);
    long long quotient2 = (abs(q) * gcd / a);

    long long p1 = p - quotient1 * b / gcd;
    long long p2 = p + quotient1 * b / gcd;
    long long p3 = p - quotient2 * b / gcd;
    long long p4 = p + quotient2 * b / gcd;

    long long q1 = q + quotient1 * a / gcd;
    long long q2 = q - quotient1 * a / gcd;
    long long q3 = q + quotient2 * a / gcd;
    long long q4 = q - quotient2 * a / gcd;

    long long m = abs(p) * a + abs(q) * b;
    long long m1 = abs(p1) * a + abs(q1) * b;
    long long m2 = abs(p2) * a + abs(q2) * b;
    long long m3 = abs(p3) * a + abs(q3) * b;
    long long m4 = abs(p4) * a + abs(q4) * b;

    long long s = abs(p) + abs(q);
    long long s1 = abs(p1) + abs(q1);
    long long s2 = abs(p2) + abs(q2);
    long long s3 = abs(p3) + abs(q3);
    long long s4 = abs(p4) + abs(q4);

    if (s1 >= s2 && (s1 != s2 || m1 >= m2)) {
      p1 = p2;
      q1 = q2;
      m1 = m2;
      s1 = s2;
    }
    if (s3 >= s4 && (s3 != s4 || m3 >= m4)) {
      p3 = p4;
      q3 = q4;
      m3 = m4;
      s3 = s4;
    }
    if (s1 >= s3 && (s1 != s3 || m1 >= m3)) {
      p1 = p3;
      q1 = q3;
      m1 = m3;
      s1 = s3;
    }
    if (s >= s1 && (s != s1 || m >= m1)) {
      p = p1;
      q = q1;
      m = m1;
      s = s1;
    }

    p1 = p - b / gcd;
    p2 = p + b / gcd;

    q1 = q + a / gcd;
    q2 = q - a / gcd;

    m1 = abs(p1) * a + abs(q1) * b;
    m2 = abs(p2) * a + abs(q2) * b;

    s1 = abs(p1) + abs(q1);
    s2 = abs(p2) + abs(q2);

    if (s1 >= s2 && (s1 != s2 || m1 >= m2)) {
      p1 = p2;
      q1 = q2;
      s1 = s2;
      m1 = m2;
    }
    if (s >= s1 && (s != s1 || m >= m1)) {
      p = p1;
      q = q1;
    }

    long long x = abs(p);
    long long y = abs(q);

    cout << x << " " << y << "\n";
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, d;

  while (cin >> a >> b >> d && !(a == 0 && b == 0 && d == 0)) {
    balance(a, b, d);
  }

  return 0;
}