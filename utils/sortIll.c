#include <sortIll.h>

void illBubbleSort(illNode* head)
{
    if(illLenght(head)>1)
        for(int p=illLenght(head); p>1; p--)
        {
            for(int i=0; i<p-1; i++)
                if( illData(head,i) < illData(head,i+1) )
                    illReplaceIndex(head,i,i+1);
        }
}