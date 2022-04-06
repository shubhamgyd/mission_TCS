#include <bits/stdc++.h>
#define ll long long

using namespace std;
int inf = 1e9 + 7, MOD = 1e9 + 7;

int w = 1;

void Disp(int num)
{
    if(num==1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}
struct Tree
{
public:
    bool isLocked;
    bool isLockable;
    int id;
    int ma;
    Tree *p;
    vector<Tree *> c;
    Tree()
    {
        isLocked = false;
        isLockable = true;
        id = -1;
        ma = w++;
        p = NULL;
    }
    Tree(Tree *parent)
    {
        isLocked = false;
        isLockable = true;
        id = -1;
        ma = w++;
        p = parent;
    }
};

bool locking(Tree *n, int uID)
{
    if (n->isLockable == false || (n->isLocked)) return false;
    Tree *T = n;
    queue<Tree *> q;
    q.push(T);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        for (auto x : temp->c)
        {
            if (x->isLocked)
                return false;
            q.push(x);
        }
    }
    n->id = uID;
    n->isLocked = true;
    q.push(T);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        for (auto x : temp->c)
        {
            x->isLockable = false;
            q.push(x);
        }
    }
    return true;
}

bool unlocking(Tree *n, int uID)
{
    if (n->isLockable == false || n->isLocked == false || (n->isLocked && uID != n->id))
        return false;
    Tree *T = n;
    n->isLocked = false;
    n->id = -1;
    queue<Tree *> q;q.push(T);
    while (!q.empty())
    {   Tree *temp = q.front();q.pop();
        for (auto x : temp->c){x->isLockable = true;q.push(x);}
    }
    return true;
}

bool updateID(Tree *n, int uID)
{
    if (n->isLockable == false || n->isLocked == true)
        return false;
    Tree *T = n;
    queue<Tree *> q;
    q.push(T);
    bool f = false;
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        for (auto x : temp->c)
        {
            if (x->isLocked == true && x->id != uID)
            {
                return false;
            }
            if (x->isLocked)
                f = true;
            q.push(x);
        }
    }
    if (!f)
        return false;
    q.push(T);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        for (auto x : temp->c)
        {
            if (x->isLocked)
            {
                if (!unlocking(x, uID))
                    return false;
            }
            q.push(x);
        }
    }
    return locking(n, uID);
}

void Print(Tree *n)
{
    queue<Tree *> q;
    q.push(n);
    while (!q.empty())
    {
        Tree *temp = q.front();
        q.pop();
        for (auto x : temp->c)
        {
            cout << temp->ma << " -> " << x->ma << " ";
        }
    }
}

unordered_map<string, Tree *> sT;

int main()
{
    int n, m, quer; cin >> n >> m >> quer;
    Tree *t = new Tree();
    string d;
    cin >> d;
    sT[d] = t;
    queue<Tree *> q;
    q.push(t);
    int k = 1;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        while (k < n && (int)temp->c.size() < m)
        {
            string str; cin >> str;
            Tree *u = new Tree(temp);
            sT[str] = u; temp->c.push_back(u);
            q.push(u);
            k++;
        }
    }
    for (int i = 0; i < quer; i++)
    {
        int query, uID; string name; bool ok;
        cin >> query >> name >> uID;
        if (query == 1)  ok = locking(sT[name], uID);
        else if (query == 2) ok = unlocking(sT[name], uID);
        else  ok = updateID(sT[name], uID);
        if (ok)  Disp(1);
        else  Disp(0);
    }
    return 0;
}