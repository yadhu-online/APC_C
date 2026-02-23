#include"head.h"

int compare(Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2)
{
    Dlist *t1=*head1,*t2=*head2;
    int c1=0,c2=0;
    while(t1!=NULL)
    {
        t1=t1->next;
        c1++;
    }
    while(t2!=NULL)
    {
        t2=t2->next;
        c2++;
    }
    if(c1>c2) return 1;
    else if(c2>c1) return 0;
    else 
    {
        t1=*head1;t2=*head2;
        while(t1 && t2)
        {
            if (t1->data > t2->data) return 1;
            if (t1->data < t2->data) return 0;
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    return 1;
}


void division(Dlist **head1, Dlist **tail1,
              Dlist **head2, Dlist **tail2,
              Dlist **res_head, Dlist **res_tail)
{
    if (*head1 == NULL)
    {
        insert_first(res_head, res_tail, 0);
        return;
    }

    Dlist *curr_head = NULL;
    Dlist *curr_tail = NULL;

    Dlist *t = *head1;
    while (t)
    {
        insert_last(&curr_head, &curr_tail, t->data);
        delprecedingzero(&curr_head, &curr_tail);

        int qdigit = 0;

        while (compare(&curr_head, head2, &curr_tail, tail2))
        {
            Dlist *temphead = NULL;
            Dlist *temptail = NULL;

            sub(&curr_head, &curr_tail,
                head2, tail2,
                &temphead, &temptail);

            delprecedingzero(&temphead, &temptail);

            freelist(curr_head);
            curr_head = temphead;
            curr_tail = temptail;

            qdigit++;
        }

        insert_last(res_head, res_tail, qdigit);
        t = t->next;
    }
    delprecedingzero(res_head, res_tail);
}
