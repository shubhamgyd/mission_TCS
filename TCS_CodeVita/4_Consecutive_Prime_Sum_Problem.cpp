/*
 Some prime numbers can be expressed as a sum of other consecutive prime numbers.

For example
5 = 2 + 3,
17 = 2 + 3 + 5 + 7,
41 = 2 + 3 + 5 + 7 + 11 + 13.
Your task is to find out how many prime numbers which satisfy this property are 
present in the range 3 to N subject to a constraint that summation should always 
start with number 2.
Write code to find out the number of prime numbers that satisfy the above-mentioned 
property in a given range.

Input Format: First line contains a number N

Output Format: Print the total number of all such prime numbers which are less than 
or equal to N.

Constraints: 2<N<=12,000,000,000
*/

#include<bits/stdc++.h>
using namespace std;


// function check whether a number
// is prime or not
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}

void Nums(int n)
{
    vector<int>res;
    for(int i=2;i<=n;i++)
    {
        if(isPrime(i))
        {
            res.push_back(i);
        }
    }
    int ct=0;
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(int i=1;i<res.size();i++)
    {
        res[i]=res[i-1]+res[i];
        if(res[i]>n)
        {
            break;
        }
        if(isPrime(res[i]))
        {
            cout<<"prime Sum: "<<res[i]<<endl;
            ct++;
        }
    }
    cout<<"Number is prime sum less than equal to n are: "<<ct<<endl;
}
// Time Complexity:O(n^3/2+ O(n))
// Space Complexity:O(n)

int main()
{
    int n;
    cin>>n;
    Nums(n);
    return 0;

}







/*

 int main(){
int N;
cin>>N; bool primeArray[N] = {0};
for(int i=2;i<N;i++){
if(primeArray[i]==0){
for(int j=i*i;j<N;j+=i){
primeArray[j] = 1;
}
}
}
primeArray[0] = 1;
primeArray[1] = 1;
int sum = 0;
vector vi;
/*for(int i=2;i<N;i++){
if(primeArray[i]==0 && sum<=N){
sum += i;
if(primeArray[sum]==0 && sum <= N){
vi.push_back(sum);
}
}
} // same loop using while loop
int i=2;
while(i<N){
if(primeArray[i]==0){
sum += i;
if(primeArray[sum]==0 && sum<=N && sum!=2){
vi.push_back(sum);
}
}
i++;
}
cout<<"Size is : ";
cout<<vi.size()<<"\n"; // this is the answer
for(int j=0;j<vi.size();j++){ // this will print all that number
cout<<vi[j]<<" ";
}
return 0;
} Time Complexity = O(N Log N)
Space Complexity = O(N)
*/












// Another approach

// Program for prime numbers till n

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<char> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int>vc;
    int ct=0;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            vc.push_back(i);
        }
    }
    int sum=2;
    for(int i=1;i<vc.size();i++)
    {
        sum+=vc[i];
        if(sum<=n)
        {
            if(is_prime[sum])
            {
                ct++;
            }
        }
        else
        {
            break;
        }
    }
    cout<<ct<<endl;

    return 0;
}