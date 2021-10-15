// #include <bits/stdc++.h>
// using namespace std;
// #define maxN (long long)1000000000000


// vector<int> prime;

// void sieve(long long n)
// {

// 	bool check[1000007] = { 0 };
// 	long long i, j;

// 	check[0] = 1, check[1] = 1,
// 	check[2] = 0;
// 	for (i = 4; i <= n; i += 2)
// 		check[i] = true;

// 	for (i = 3; i * i <= n; i += 2)
// 		if (!check[i]) {
// 			for (j = i * i; j <= n; j += 2 * i)
// 				check[j] = true;
// 		}

// 	prime.push_back(2);

// 	for (int i = 3; i <= n; i += 2)
// 		if (!check[i])
// 			prime.push_back(i);

// 	return;
// }

// long long count(long long a[],
// 				int n, long long m)
// {
// 	long long parity[3] = { 0 };
// 	for (int i = 1; i < (1 << n); i++) {
// 		long long mult = 1;
// 		for (int j = 0; j < n; j++)
// 			if (i & (1 << j))
// 				mult *= a[j];
// 		parity[__builtin_popcount(i) & 1]
// 			+= (m / mult);
// 	}

// 	return parity[1] - parity[0];
// }

// long long countRelPrime(
// 	long long n,
// 	long long m)
// {

// 	long long a[20];
// 	int i = 0, j = 0;
// 	long long pz = prime.size();
// 	while (n != 1 && i < pz) {
// 		if ((long long)prime[i]
// 				* (long long)prime[i]
// 			> n)
// 			break;
// 		if (n % prime[i] == 0)
// 			a[j] = (long long)prime[i], j++;

// 		while (n % prime[i] == 0)
// 			n /= prime[i];
// 		i++;
// 	}

// 	if (n != 1)
// 		a[j] = n, j++;
// 	return m - count(a, j, m);
// }

// void countRelPrimeInRange(
// 	long long n, long long l,
// 	long long r)
// {
// 	sieve(sqrt(maxN));
// 	long long result
// 		= countRelPrime(n, r)
// 		- countRelPrime(n, l - 1);
// 	cout << result << "\n";
// }

// int main()
// {
//     long long N;
//     cin>>N;
//     long long L = 1, R = N;
// 	countRelPrimeInRange(N, L, R);

// 	return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// int precedence(char op){
// 	if(op == '+'||op == '-')
// 	return 1;
// 	if(op == '*'||op == '/')
// 	return 2;
// 	return 0;
// }
// int applyOp(int a, int b, char op){
// 	switch(op){
// 		case '+': return a + b;
// 		case '-': return a - b;
// 		case '*': return a * b;
// 		case '/': return a / b;
// 	}
// }

// int evaluate(string tokens){
// 	int i;
	
// 	stack <int> values;
// 	stack <char> ops;
	
// 	for(i = 0; i < tokens.length(); i++){
// 		if(tokens[i] == ' ')
// 			continue;
// 		else if(tokens[i] == '('){
// 			ops.push(tokens[i]);
// 		}
// 		else if(isdigit(tokens[i])){
// 			int val = 0;
			
// 			while(i < tokens.length() &&
// 						isdigit(tokens[i]))
// 			{
// 				val = (val*10) + (tokens[i]-'0');
// 				i++;
// 			}
			
// 			values.push(val);
// 			i--;
// 		}
// 		else if(tokens[i] == ')')
// 		{
// 			while(!ops.empty() && ops.top() != '(')
// 			{
// 				int val2 = values.top();
// 				values.pop();
				
// 				int val1 = values.top();
// 				values.pop();
				
// 				char op = ops.top();
// 				ops.pop();
				
// 				values.push(applyOp(val1, val2, op));
// 			}
// 			if(!ops.empty())
// 			ops.pop();
// 		}

// 		else
// 		{
// 			while(!ops.empty() && precedence(ops.top())
// 								>= precedence(tokens[i])){
// 				int val2 = values.top();
// 				values.pop();
				
// 				int val1 = values.top();
// 				values.pop();
				
// 				char op = ops.top();
// 				ops.pop();
				
// 				values.push(applyOp(val1, val2, op));
// 			}
// 			ops.push(tokens[i]);
// 		}
// 	}
	

// 	while(!ops.empty()){
// 		int val2 = values.top();
// 		values.pop();
				
// 		int val1 = values.top();
// 		values.pop();
				
// 		char op = ops.top();
// 		ops.pop();
				
// 		values.push(applyOp(val1, val2, op));
// 	}
	
// 	return values.top();
// }

// int main() {
// 	string str;
//     cin>>str;
//     cout<<evaluate(str);
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;


int main()
{
	int l=11;
    int r=100;
    int val=0;
    for(int i=l;i<=r;i++)
    {
        val^=i;
    }
    cout<<val<<endl;
    return 0;
}