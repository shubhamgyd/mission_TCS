#include<stdio.h>
#include <string.h>


int search(const char statement[],const char word[])
{
    // length of searching word
    int len=strlen(word);
    // keep track on the first index where search word start
    int startInd=0;
    int i=0;
    int j=0;
    while(statement[i]!='\0')
    {
        // if the fist char of statement word and word matched
        // then start searching until both words have same match
        if(statement[i]==word[j])
        {
            startInd=i;

            // Keep searching until the both have same matched
            while( statement[i]==word[j] && statement[i]!='\0')
            {
                i++;
                j++;
            }

            // If we find the desired word in a statement
            if(j==len)
            {
                // Return the starting index of search word
                // from the statement
                return startInd;
            }
        }
        // if char is not matched then iterate
        // until to the next space
        else
        {
            // ignore the next word and start from another one
            while(statement[i]!=' ')
            {
                i++;
                // if statement ends then 
                // break 
                if(statement[i]=='\0')
                {
                    break;
                }
            }
        }
        // go to the next char
        i++;
        // reset the start index of searching word
        j=0;
        // reset the starting index of searching word
        startInd=0;
    }
    // return the ans
    // word is not found
    return -1;
}

void main()
{
    // Test 1:
    // Statement
    char statement[] = "It is a very long trip";
    // search word
    char word[] = "very";
    int ans=search(statement,word);
    printf("%d\n",ans);



    // Test 2:
    char statement2[] = "this grilled swordfish is marinated in lemon";
    // search word
    char word2[] = "sword";
    int ans2=search(statement2,word2);
    printf("%d\n",ans2);



    // Test 3:
    char statement3[] = "c plus plus is an easy programming language";
    // search word
    char word3[] = "process";
    int ans3=search(statement3,word3);
    printf("%d\n",ans3);

}