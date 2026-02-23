#include "head.h"

void multiply(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail)
{
    Dlist *t1=*tail1,*t2=*tail2;

    Dlist *newhead=NULL,*newtail=NULL;

    *res_head=NULL; *res_tail=NULL;

    int i,prod=0,carry=0,zero_count=0;
    while(t2!=NULL)
    {
        newhead=NULL;  newtail=NULL;
        carry=0;
        t1=*tail1;
        while(t1!=NULL)
        {
            prod=(t1->data*t2->data)+carry;
            t1=t1->prev;
            if(prod>9)
            {
                carry=prod/10;
            }
            else carry=0;
            insert_first(&newhead,&newtail,prod%10);
        }
        if(carry) insert_first(&newhead,&newtail,carry);
        i=0;
        while(i<zero_count)
        {
            insert_last(&newhead,&newtail,0);
            i++;
        }
        zero_count++;

        if(*res_head==NULL)
        {
            *res_head=newhead;
            *res_tail=newtail;
        }
        else{

            Dlist *tmp_head = NULL, *tmp_tail = NULL;
            addition(&newhead,&newtail,res_head,res_tail,&tmp_head,&tmp_tail,1,1);

            freelist(newhead);
            freelist(*res_head);

            *res_head=tmp_head;
            *res_tail=tmp_tail;
        }  
        t2=t2->prev;
    }
}