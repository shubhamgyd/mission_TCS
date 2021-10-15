// Replace every element with  the least greater element 


#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

struct node* newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left =  temp->right = NULL;
    return temp;
}

void insert(struct node*& root, int data, struct node*& succ){
    if(root == NULL)
    {
        root = newNode(data);
        return;
    }
    
    if(root->data > data){
        succ = root;
        insert(root->left, data, succ);
    }
    
    else{
        insert(root->right, data, succ);
    }
}

void replace(int arr[], int N){
    //if(N < 2)
    //return;
    
    struct node *root = NULL;
    for(int i=N-1; i>=0; i--){
        struct node *succ = NULL;
        
        insert(root, arr[i], succ);
        if(succ){
            arr[i] = succ->data;
        }
        else{
            arr[i] = -1;
        }
    }
    
}

int main()
{
    int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 28, 80, 28 };
    int n = sizeof(arr)/ sizeof(arr[0]);
 
    replace(arr, n);
    //cout<<n;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}