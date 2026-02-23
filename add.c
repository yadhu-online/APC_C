#include "head.h"

void addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail,int n1,int n2)
{
    Dlist *t1=*tail1,*t2=*tail2;
    int sum=0,carry=0;
    while(t1!=NULL && t2!=NULL)
    {
        sum=0;
        sum= t1->data + t2->data + carry;

        t1=t1->prev;
        t2=t2->prev;
        if(sum>9) {
            sum-=10;
            carry=1;
        }
        else carry=0;
        insert_first(res_head,res_tail,sum);
    }
    while(t1!=NULL){
        sum=t1->data+carry;
        carry=sum/10;
        insert_first(res_head,res_tail,sum%10);
        t1=t1->prev;}
    while(t2!=NULL){
        sum=t2->data+carry;
        carry=sum/10;
        insert_first(res_head,res_tail,sum%10);
        t2=t2->prev;
    }
    if(carry)
    {
       insert_first(res_head,res_tail,1); 
    }

    if(n1==-1 && n2==-1)
    {
        (*res_head)->data=((*res_head)->data)*-1;
    }
}