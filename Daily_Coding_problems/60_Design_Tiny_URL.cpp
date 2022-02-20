/*
This problem was asked by Microsoft.

Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. 
If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?
*/

#include<bits/stdc++.h>
using namespace std;

map<string,string>URLS;
static const char alphanum[] ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string createShortURL()
{
    string shortURL="";
    while(shortURL=="")
    {
        while(shortURL.length()<6)
        {
            shortURL+=alphanum[rand()%(sizeof(alphanum)-1)];
        }
        if(URLS.find(shortURL)!=URLS.end())
        {
            shortURL="";
        }
    }
    return shortURL;
}


string shortenNonRedundant(string newLongUrl)
{
    for(auto it:URLS)
    {
        if(it.second==newLongUrl)
        {
            return it.first;
        }
    }
    string newShortUrl=createShortURL();
    URLS[newShortUrl]=newLongUrl;
    return newShortUrl;
}


string shortenReduntant(string newLongUrl)
{
    string newshortUrl=createShortURL();
    URLS[newshortUrl]=newLongUrl;
    return newshortUrl;
}


string restore(string shortUrl)
{
    if(URLS.find(shortUrl)!=URLS.end())
    {
        return URLS[shortUrl];
    }
    return "None";
}

int main()
{
    vector<string> URLs = {"www.facebook.com", "www.google.com", "www.facebook.com","www.google.com"};
    cout<<"Non-reduntant shortening..!!!"<<endl;
    for(auto it:URLs)
    {
        string shortUrl=shortenNonRedundant(it);
        cout<<shortUrl<<"-->"<<restore(shortUrl)<<endl;
    }

    cout<<"\n Redundant Shortening...!!!"<<endl;
    for(auto it:URLs)
    {
        string shortUrl=shortenReduntant(it);
        cout<<shortUrl<<"-->"<<restore(shortUrl)<<endl;
    }
}