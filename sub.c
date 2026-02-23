#include "head.h"

void subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail,int n1,int n2,int len1,int len2)
{
        if(len1>len2){
            sub(head1,tail1,head2,tail2,res_head,res_tail);
            delprecedingzero(res_head,res_tail);
            return;
        }
        else if(len2>len1){
            sub(head2,tail2,head1,tail1,res_head,res_tail);
            delprecedingzero(res_head,res_tail);
            (*res_head)->data=((*res_head)->data)*-1;
            return;
        }
        else{
            Dlist *temp1=*head1,*temp2=*head2;
            while(temp1!=NULL)
            {
                if(temp1->data>temp2->data){
                    sub(head1,tail1,head2,tail2,res_head,res_tail);
                    delprecedingzero(res_head,res_tail);
                    return;
                    break;}
                else if(temp1->data<temp2->data){
                    sub(head2,tail2,head1,tail1,res_head,res_tail);
                    delprecedingzero(res_head,res_tail);
                    (*res_head)->data=((*res_head)->data)*-1;                 
                    return;
                    break;}
                else if(temp1->data==temp2->data){
                    temp1=temp1->next; temp2=temp2->next;
                }
            }
            if(temp1==NULL){
            insert_first(res_head,res_tail,0);}
        }
}

void sub(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail)
{
    Dlist *t1=*tail1,*t2=*tail2;
    int sub;
    while(t1!=NULL && t2!=NULL)
    {
        sub=0;
        if(t1->data<t2->data){
         t1->data=t1->data+10;
        if(t1->prev!=NULL && t1->prev->data!=0)
         t1->prev->data=t1->prev->data-1;

         else if(t1->prev->data==0){
         Dlist *dup=t1;
         dup=dup->prev;
         while(dup->data==0 && dup->prev!=NULL)
         {
            dup->data=9;
            dup=dup->prev;
         }
         dup->data=dup->data-1;
        }
        }
        sub= (t1->data) - (t2->data);
        t1=t1->prev;
        t2=t2->prev;
        insert_first(res_head,res_tail,sub);
    }
    while(t1!=NULL){    
        insert_first(res_head,res_tail,t1->data);
        t1=t1->prev;
    } 
}