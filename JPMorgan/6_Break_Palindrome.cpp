#include<bits/stdc++.h>
using namespace std;


// public class SumOfDigits {
//    public static String breakPalindrome(String palindrome) {
//         if(palindrome.length() == 0 || palindrome.length() == 1){
//             return "";
//         }
//         char[] ch = palindrome.toCharArray();
//         for(int i = 0;i<ch.length/2;i++){
//             if(ch[i]-'a' != 0){
//                 ch[i] = 'a';
//                 return new String(ch);
//             }
            
//         }
//         ch[ch.length-1] = 'b';
//         return new String(ch);
//     }
//      public static void main(String args[])
//      {
//          String s="aaabbaaa";
//         System.out.print(breakPalindrome(s));
//      }
    
// }

string breakPalindrome(string s) {
      bool changed = false;
      if(s.size() == 1)return "";
      int i = 0, j = s.size() - 1;
      bool leftA = true;
      bool rightA= true;
      while(i < j){
         if(s[i] != 'a'){
            s[i] = 'a';
            return s;
         }
         i++;
         j--;
      }
      s[s.size() - 1] = 'b';
      return s;
   }