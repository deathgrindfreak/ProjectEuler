// Project Euler Problem: 31
// Goal: Find the number of ways to make 2pounds
// Author: Cooper Bell

#include <iostream>
using namespace std;

int pound(int a, int b, int c, int d, int e, int g, int f)
{
  return a + 2*b + 5*c + 10*d + 20*e + 50*g + 100*f;
}

int main()
{
  int perms = 0;

  for(int a=0; a<=200; ++a){
    for(int b=0; b<=100; ++b){
      for(int c=0; c<=40; ++c){
	for(int d=0; d<=20; ++d){
	  for(int e=0; e<=10; ++e){
	    for (int g=0; g<=4; ++g){
	      for(int f=0; f<=2; ++f){
		if(pound(a,b,c,d,e,g,f) == 200){
		  perms += 1;
		}
	      }
	    }
	  }
	}
      }
    }
  }
  cout << perms + 1 << endl;   // Don't forget the 2 pounds!
}
