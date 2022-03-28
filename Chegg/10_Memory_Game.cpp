#include<bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

int main()
{
    cout<<"--------------------------------------------"<<endl;
    cout<<"  Hello, welcome to my adaptive game"<<endl;

    cout<<"\n  You will be represent with a few words."<<endl;
    cout<<"  You have a second to memorize those."<<endl;
    cout<<"  Then you will be promted to enter the words..."<<endl;

    cout<<"\n  For every word you enter correctly, you'll get 1 point."<<endl;
    cout<<"  Otherwise, you will be deducted 1 point."<<endl;
    cout<<"  If the number of words you enter doesn't match "<<endl;
    cout<<"  the number of challenged words, you will be deducted 1 point."<<endl;
    cout<<"--------------------------------------------"<<endl;
    char ch;
    cout<<"\n  Ready to begin (Y/N): ";
    cin>>ch;
    if(ch=='Y')
    {
        const string twoWordList[30]={"bad bad","easy easy","lol lol","Hurt Hurt","good good","code code","hate hate","kill kill","ice ice","fire fire","icecream icecream","hangman hangman","destroy destroy","computer computer","book book","dictionary words","technology machines","power power","thunder storm","controller controller","dexterity dexterity","keyboard keyboard","thunderous storm","blizzard blizzard","hazardous dust","algorithm code","destruction destiny","operation operation","assignment assignments","despicable despicable"};
        const string threeWordList[30]={"bad boy bad","easy task done","lol lol lol","Hurt Hurt break","good boy good","code snippet code","hate hate hate","kill kill kill","ice cream ice","fire fire fire","icecream cold cold","hangman hangman hangman","destroy destroy destruction","computer game game","book book book","dictionary words words","technology machines computers","power power brain","thunder storm thunder","controller back back","dexterity dexterity dexterity","keyboard keyboard keyboard","thunderous storm storm","blizzard blizzard blizzard","hazardous dust dust","algorithm code code","destruction destiny destiny","operation operation destiny","assignment assignments assignments","despicable despicable despicable"};
        const string fourWordList[10]={"bad boy bad bad","easy task done done","lol lol lol lol","Hurt Hurt break Hurt","good boy good good","code snippet code code","hate hate hate hate","kill kill kill kill","ice cream ice cream","fire fire fire fire"};
        int level=1;
        int score=0;
        int i=0;
        while(score<=10)
        {
                cout<<"*************************************************"<<endl;
                cout<<"               Memorize the following            "<<endl;
                cout<<"*************************************************"<<endl;
                string word="";
                if(level<=4)
                {
                    word=twoWordList[rand() % 30];
                }
                else if(level>4 && level<=8)
                {
                    word=threeWordList[rand() % 30];
                }
                else if(level>8)
                {
                    word=fourWordList[rand() % 10];
                }
                cout<<"               "<<word<<"                        "<<endl;
                cout<<"*************************************************"<<endl;
            //    sleep_for(10ns);
                cout<<"Please input words ( type q to exit): ";
                string input;
                getline(cin,input);
                cout<<word.length()<<" "<<input.length()<<endl;
                cout<<word<<endl;
                cout<<input<<endl;
                if(input=="q")
                {
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<"\n Thanks for playing....."<<endl;
                    cout<<"Your final score is: "<<score<<endl;
                    cout<<"Bye...."<<endl;
                    exit(0);
                }
                if(word!=input || word.length()!=input.length())
                {
                    --score;
                    cout<<"You have entered wrong word....."<<endl;
                    cout<<"Your current score is: "<<score<<endl;
                    cout<<"Here come to the next....."<<endl;
                    cout<<"Ready...."<<endl;
                    
                }
                else
                {
                    ++score;
                    cout<<"Checking your input......"<<endl;
                    cout<<"Your current score is: "<<score<<endl;
                    cout<<"Here come to the next"<<endl;
                    cout<<"Ready...."<<endl;
                }
                if(score>=4 && score<8)
                {
                    if(score==4)
                    {
                        level++;
                    }
                }
                if(score>=10)
                {
                    cout<<"-----------------------------------------------"<<endl;
                    cout<<"\n Excellent: YOU WIN"<<endl;
                    cout<<"\n Thanks for playing...."<<endl;
                    cout<<"Your final score is........"<<score<<endl;
                    cout<<"Bye...."<<endl;
                    exit(0);
                }   
        }
    }
    else
    {

    }
}