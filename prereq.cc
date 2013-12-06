/* File prereq.cc
   C++ source files normally have extension cc or cpp
*/
// Above is an example of a standard C multi-line comment
// Alternatively, in C++, you can use single-line comments such as these

#include <iostream>         // Use for C++ instead of C's stdio.h
                            // Contains definitions of cout and cerr

using namespace std;        // Do not worry about this line (yet)

void a_function(int n);     // Forward declaration (function prototype)

int main()
{ int an_integer;                   // 2 or 4 bytes in PCs, use up to 32K
  long a_large_int;                 // 4 bytes in PCs, use up to 10^9.
  long long a_very_large_int;       // 8 bytes in RedHat6, use up to 10^18
  char a_character = 'z';           // 1 or 2 bytes.  
  float a_floating_point_number;    // Approx. 10^-38 to 10^38 in PCs
  double a_double_precision_float;  // Approx. 10^-317 to 10^308 in PCs
  long double a_very_precise_float; // Approx. 10^-4945 to 10^4932 in PCs
  /*
     doubles have a greater precision (more sig. fig.s) than floats
     and long doubles are even more precise
  */

  int a_2D_array_of_ints[9][9];

  int i = 3;
  double d1,d2,d3;
  d1 = (double) i;                  // Convert between data types.  
  if (d1 == 3.0) d1 = 4.0;          // Notice ==
  d2 = 5.7; d3 = 11.13;
  d3 = d1 + d2 * d3;
  cout << "d3 is " << d3 << endl;   // Use C++'s cout to display d3

  int my_array[10];                 // Set up an array of 10 ints
  int n,m;
  for (n=0;n<10;n++)                // n=0; while (n<10) {... ;n++}
  { my_array[n] = 7;
    for (m=n;m;m=m/2)               // m=n; while (m) {... ;m=m/2}
      my_array[n] += m;
  }
  long long product = 1;
  for (n=0;n<10;n++)
    product *= my_array[n];
  cout << "product is " << product
       << endl;

  int a,b,c;
  a=5; b=a-2; c=b*7;
  if ((3==b) && !(c!=21))
    cout << "Hello World" << endl;
  else
    cerr << "Error: This should not" // cerr outputs to stderr not stdout
         << " happen" << endl;

  int s=41%6;                       // s=41 mod 6 (remainder from 41 / 6)
  switch (s)
  { case 3:
      cout << "s is three" << endl;
      break;
    case 9:
      cout << "s is nine" << endl;
      break;
    default: 
      cout << "s is not three"
           << " or nine" << endl;
      break;
  }

  char mystring[11] = "0123456789"; // Remember strings are null terminated
  int index; char *p;
  for (index=0,p=mystring+9;
       p>=mystring+5;
       p--,index++)
    *p=mystring[index];
  cout << mystring << endl;

  int z = 55 | ((1<<4) + (128>>1));
  a_function(z);
  return 0;
}

void a_function(int n)
{ cout << "The square of " << n << " is " << (n*n) << endl;
}
