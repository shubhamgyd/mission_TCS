#include<stdio.h>
#include<string.h>

int main()
{
    char arr[1000];
    gets(arr);
    // printf("%s\n", arr);
    int ans[256];
    for(int i=0;i<256;i++)
    {
        ans[i]=0;
    }
    int mx=0;
    char ch='~';
    // printf("%c\n",arr);
    for(int i=0;arr[i]!='\0';i++)
    {
        int num=arr[i];
        // if(arr[i]>='0' && arr[i]<='9')
        // {
        //     num=arr[i]
        // }
        // printf("%d\n",num);
        ans[num]++;
        if(ans[num]>mx)
        {
            mx=ans[num];
            // printf("%d\n",mx);
            ch=arr[i];
        }
        else if(ans[num]==mx)
        {
            if(ch>arr[i])
            {
                ch=arr[i];
            }
        }
    }
    printf("%c %d\n",ch,mx);
    return 0;
}

