#include<bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
#define YES cout<<"YES"<<'\n'
#define NO cout<<"NO"<<'\n'
#define yes cout<<"yes"<<'\n'
#define no cout<<"no"<<'\n'
#define int  long long 
using namespace std;
#define endl '\n'
const int mod=1e9+7;
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back


void Disp(int n)
{
    if(n==1){cout<<"YES";}
    else{cout<<"NO";}
}


void Solution(){
   char ticTacToe[3][3];int xCount=0,yCount=0,totalCount=0;
   for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
            cin>>ticTacToe[i][j];
            if(ticTacToe[i][j]=='X'){xCount++;}
            if(ticTacToe[i][j]=='O'){yCount++;}
            if(ticTacToe[i][j]=='_'){totalCount++;}
       }
   }

    bool victory_xPlayer=false,victory_oPlayer=false;int countxPlayer=0,countyPlayer=0;
    if(ticTacToe[0][0]==ticTacToe[0][1]&&ticTacToe[0][1]==ticTacToe[0][2]&&ticTacToe[0][1]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[1][0]==ticTacToe[1][1]&&ticTacToe[1][1]==ticTacToe[1][2]&&ticTacToe[1][1]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[2][0]==ticTacToe[2][1]&&ticTacToe[2][1]==ticTacToe[2][2]&&ticTacToe[2][1]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[1][0]==ticTacToe[0][0]&&ticTacToe[0][0]==ticTacToe[2][0]&&ticTacToe[0][0]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[1][1]==ticTacToe[0][1]&&ticTacToe[0][1]==ticTacToe[2][1]&&ticTacToe[0][1]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[1][2]==ticTacToe[0][2]&&ticTacToe[0][2]==ticTacToe[2][2]&&ticTacToe[0][2]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[1][1]==ticTacToe[0][0]&&ticTacToe[1][1]==ticTacToe[2][2]&&ticTacToe[0][0]=='X'){victory_xPlayer=true;countxPlayer++;
    }
    if(ticTacToe[0][2]==ticTacToe[1][1]&&ticTacToe[1][1]==ticTacToe[2][0]&&ticTacToe[1][1]=='X'){victory_xPlayer=true;countxPlayer++;
    }
     if(ticTacToe[0][0]==ticTacToe[0][1]&&ticTacToe[0][1]==ticTacToe[0][2]&&ticTacToe[0][1]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[1][0]==ticTacToe[1][1]&&ticTacToe[1][1]==ticTacToe[1][2]&&ticTacToe[1][1]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[2][0]==ticTacToe[2][1]&&ticTacToe[2][1]==ticTacToe[2][2]&&ticTacToe[2][1]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[1][0]==ticTacToe[0][0]&&ticTacToe[0][0]==ticTacToe[2][0]&&ticTacToe[0][0]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[1][1]==ticTacToe[0][1]&&ticTacToe[0][1]==ticTacToe[2][1]&&ticTacToe[0][1]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[1][2]==ticTacToe[0][2]&&ticTacToe[0][2]==ticTacToe[2][2]&&ticTacToe[0][2]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[1][1]==ticTacToe[0][0]&&ticTacToe[1][1]==ticTacToe[2][2]&&ticTacToe[0][0]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if(ticTacToe[0][2]==ticTacToe[1][1]&&ticTacToe[1][1]==ticTacToe[2][0]&&ticTacToe[1][1]=='O'){victory_oPlayer=true;countyPlayer++;
    }
    if((victory_xPlayer==true&&victory_oPlayer==true)||xCount-yCount<0||xCount-yCount>1){Disp(0);
    }
    else if(xCount==0&&yCount==0&&totalCount==9){Disp(1);
    }
    else if(victory_xPlayer==true&&xCount>yCount){Disp(1);
    }
    else if(victory_oPlayer==true&&xCount==yCount){Disp(1);
    }
    else if(victory_xPlayer==false&&victory_oPlayer==false&&totalCount==0){Disp(1);
    }
    else if(victory_xPlayer==false&&victory_oPlayer==false&&totalCount>0){Disp(1);
    }
    else{Disp(0);
    }
}


signed main(){
    fast();
    Solution();
    return 0;
}