#include<bits/stdc++.h>
#include<climits> 
using namespace std;

void swap(int *x,int *y);

class MinHeap
{
    int *harr;//pointer to store an array of heap element
    int  capacity;
    int heap_size;
public:
    MinHeap(int capacity);
    void MinHeapify(int ); //to heapify a subtree with a given index
    int parent(int i) {return (i-1)/2 ;} //return the parent of given key
    int left(int i) {return  (2*i+1);} //return the left child of given key
    int right(int i) {return (2*i+2);} //return the right child of given key
    int extractMin();
    void decreaseKey(int i, int new_val);
    // Returns the minimum key (key at root) from min heap
    int getMin() { return harr[0]; }
    // Deletes a key stored at index i
    void deleteKey(int i);
    // Inserts a new key 'k'
    void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
    heap_size=0;
    capacity=cap;
    harr= new int[cap];
}
void MinHeap::insertKey(int k)
{
    if(heap_size==capacity)
    {
        cout<<" Overflow : can't insert new key"<<endl;
    }
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;

    // Fix the min heap property is it is voiledted
    while(i>=0 && harr[parent(i)]>harr[i])
    {
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
}

void MinHeap::decreaseKey(int i,int new_val)
{
    harr[i]=new_val;
    while(i>=0 && harr[parent(i)]>harr[i])
    {
        swap(&harr[i],&harr[parent(i)]);
        i=parent(i);
    }
}

// Method to remove small element from heap
int MinHeap::extractMin()
{
    if(heap_size<=0)
    {
        return INT_MAX;
    }
    if(heap_size==1)
    {
        heap_size--;
        return harr[0];
    }
    //otherwise store the min value and remove it
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
  
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    //cout<<"Removing smallets from heap"<<endl;
    cout <<"Extracted Ele: "<<h.extractMin()<<endl;
    cout <<"Minimum Element in Heap: "<<h.getMin()<<endl;
    cout<<"Decresing key "<<endl;
    h.decreaseKey(2, 1);
    cout <<"Getting minimum element :"<<h.getMin()<<endl;
    return 0;
}