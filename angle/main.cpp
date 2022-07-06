
#include <iostream>
#include "angle.h"

using namespace std;



int main()
{
   Angle a1(10.0);
   Angle a2(20.0);

   while (true)
   {
      // extraction
      cout << "<a1> ";
      cin >> a1;

      // increment postfix
      a2 = a1++;
      cout << "a2 = a1++;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // increment prefix
      a2 = ++a1;
      cout << "a2 = ++a1;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // compare
      cout << "a1 == a2 : " << (a1 == a2) << endl;
      cout << "a1 != a2 : " << (a1 != a2) << endl;

      // decrement prefix
      a2 = --a1;
      cout << "a2 = --a1;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // decrement postfix
      a2 = a1--;
      cout << "a2 = a1--;  "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      // compare
      cout << "a1 == a2 : " << (a1 == a2) << endl;
      cout << "a1 != a2 : " << (a1 != a2) << endl;

      // negative
      a2 = -a1;
      cout << "a2 = -a1: "
         << " a1:" << a1
         << " a2:" << a2 << endl;

      cout << endl;
   }

   return 0;
}