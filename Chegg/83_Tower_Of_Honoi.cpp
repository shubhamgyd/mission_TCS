#include<iostream>
using namespace std;
// Utility Function which move disks from one tower to another tower optimizely
void movingDisk(int n,char from,char to,char helper)
{
    // If only one disk is remaining
    if(n==1)
    {
        // Then transfer it directily from source to destination
        cout<<"Moving Disk "<<n<<" from tower "<<from<<" to tower "<<to<<endl;
        return;
    }
    // Move Disk from A to to with the help of helper
    movingDisk(n-1,from,helper,to);
    // Print the moved disk
    cout<<"Moving Disk "<<n<<" from tower "<<from<<" to tower "<<to<<endl;
    movingDisk(n-1,helper,to,from);
    return;
}
int main()
{
    int n;
    cin>>n;
    movingDisk(n,'A','B','C');
    return 0;
}