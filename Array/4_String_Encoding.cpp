#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<endl;
        return;
    }
    
    if(str[0] == '0'){
        return;
    }

    string s1 = str.substr(0,1);
    string ros1 = str.substr(1);
    printEncoding(ros1,asf + (char)(stoi(s1) + 'a' - 1));

    if(str.length() >= 2){
        string s2 = str.substr(0,2);
        string ros2 = str.substr(2);
        if(stoi(s2) <= 26)
        printEncoding(ros2,asf + (char)(stoi(s2) + 'a' - 1));
    }

}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}