// // C++ program to find the missing number
// // in the equation a + b = c
// #include <bits/stdc++.h>
// using namespace std;


// int findMissing(string str)
// {

// 	stringstream ss(str);
//     string word;
//     string pre,mid,fin;
//     int i=0;
//     while(ss>>word)
//     {
//         if(i==0 && word=="X")
//         {
//             pre=word;
//             i++;
//         }
//         if(i==1 && word=="X")
//         {
//             mid=word;
//             i++;
//         }
//         if(i==2 && word=="X")
//         {
//             fin=word;
//             i++;
//         }
        

//     }
// }

// // Driver code
// int main()
// {
// 	string str = "2+15=X";
// 	cout<<findMissing(str);
// 	return 0;
// }




// C++ program to find the missing number
// in the equation a + b = c
#include <bits/stdc++.h>
using namespace std;

// Function to find the missing number
// in the equation a + b = c
int ReplaceX(string str)
{
    string s="";
    for(int i=0;str[i]!='\0';i++)
    {
        s+=str[i];
    }
	string arrStr[5];
	stringstream ss(str);
	
	int i = 0;
	
	while (ss.good() && i < 5) {
		ss >> arrStr[i];
		++i;
	}
	
	int pos = -1;
	if(arrStr[0] == "X")
		pos = 0;
	else if(arrStr[2] == "X")
		pos = 2;
	else
		pos = 4;
	
	if(pos == 0)
	{
		string b,c;
		b = arrStr[2];
		c = arrStr[4];

		int a = stoi(c) - stoi(b);
		
		return a;
	}
	else if(pos==2)
	{
		string a,c;
		a = arrStr[0];
		c = arrStr[4];
		int b = stoi(c) - stoi(a);
		
		return b;
	}
	else if(pos == 4)
	{
		string b,a;
		a = arrStr[0];
		b = arrStr[2];
		
		// Using stoi() to convert strings to int
		int c = stoi(a) + stoi(b);
		
		return c;
	}
    return -1;
}

// Driver code
int main()
{
	// Equation with missing value
	string str = "2 + 15 = X";
	
	cout<<ReplaceX(str);

	return 0;
}
