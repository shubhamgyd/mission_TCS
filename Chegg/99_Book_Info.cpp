#include<bits/stdc++.h>
using namespace std;

struct BookInfo
{
    string bookName;
    int id;
    int publishYear;
    double price;
    string autorName;
    BookInfo(string name,int num,int year,double priceOfBook,string aName)
    {
        bookName=name;
        id=num;
        publishYear=year;
        price=priceOfBook;
        autorName=aName;
    }
};


void viewRecord(map<int,vector<BookInfo>>&bookStore)
{
    for(auto it:bookStore)
    {
        cout<<it.first<<" ";
        auto ele=it.second;
        for(auto ele:it.second)
        {
            cout<<ele.bookName<<" "<<ele.price<<" "<<ele.publishYear<<endl;
        }
    }
}

void addRecord(map<int,vector<BookInfo>>&bookStore)
{
    string bookName;
    int id;
    int year;
    double price;
    cout<<"Enter Book Name: ";
    cin>>bookName;
    cout<<"Enter Book Id: ";
    cin>>id;
    cout<<"Enter Publish Year: ";
    cout<<year;
    cout<<"Enter Book Price: ";
    cin>>price;
    vector<BookInfo>info;
    info.push_back(BookInfo(bookName,id,year,price));
    bookStore[id]=info;
}

void searchAutor(map<int,vector<BookInfo>>&bookStore)
{
    string name=
}

int main()
{
    fstream file;
    string fileName="book_info.txt";
    file.open(fileName.c_str());
    string word;
    if(!file)
    {
        cerr<<"Error: File could not be opened!";
        exit(1);
    }
    int content=0;
    map<int,vector<BookInfo>>bookStore;
    int id=0;
    string bookName;
    int publishYear;
    double price=0;
    while(file >> word)
    {
        if(content==0)
        {
            bookName=word;
            content++;
        }
        else if(content==1)
        {
            id=stoi(word);
            content++;
        }
        else if(content==2)
        {
            publishYear=stoi(word);
            content++;
        }
        else if(content==3)
        {
            price=stod(word);
            content=0;
            vector<BookInfo>temp;
            temp.push_back(BookInfo(bookName,id,publishYear,price));
            bookStore[id]=temp;
        }
    }
    file.close();
    while(true)
    {
        cout<<"1. View Record"<<endl;
        cout<<"2. Add Record"<<endl;
        cout<<"3. Search Author"<<endl;
        cout<<"4. Modify Record"<<endl;
        cout<<"5. Delete Record"<<endl;
        int option;
        cin>>option;
        if(option==1)
        {
            viewRecord(bookStore);
        }
        else if(option==2)
        {
            addRecord(bookStore);
        }
        else if(option==3)
        {
            searchAutor(bookStore);
        }
    }
    ofstream outfile;
    outfile.open("book_info.txt");


}