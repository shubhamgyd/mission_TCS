#include <bits/stdc++.h>
using namespace std;

string ss(string s)
{
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++)
  {
    if ((s[i] == 'G') || (s[i] == 'C'))
    {
      if (s[i] == 'G')
        s[i] = 'C';
      else
        s[i] = 'G';
    }
    else if ((s[i] == 'A') || (s[i] == 'T'))
    {
      if (s[i] == 'A')
        s[i] = 'T';
      else
        s[i] = 'A';
    }
  }
  return s;
}