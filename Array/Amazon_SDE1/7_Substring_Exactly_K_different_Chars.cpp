# include <string>
# include <iostream>
# include <unordered_map>
using namespace std;

int most_k_chars(string &s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, int> table;
    int num = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {
        table[s[i]]++;
        while (table.size() > k) {
            table[s[left]]--;
            if (table[s[left]] == 0) {
                table.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;
    }
    return num;
}

int exact_k_chars(string &s, int k) {
    return most_k_chars(s, k) - most_k_chars(s, k - 1);
}

int main() {
    string str;
    cin>>str;
    int num;
    cin>>num;
    cout<<exact_k_chars(str,num)<<endl;
    return 0;
}