#include "head.h"
#include <string.h>
#include <ctype.h>

status validate(int argc,char *argv[])
{
    if(argc!=4){
     printf(RED"CLA syntax Error: <filename> <1st operand> <operator> <2nd operand>\n"RESET);
     printf(RED"Addition \t->  +\nSubtraction \t->  -\nMultiplication  -> '*'\nDivision \t->  /\n"RESET);

     return FAILURE;
    }
    else
    {
       int i=0,dot_count=0;
       if(argv[1][0]=='+' || argv[1][0]=='-') i++;
       while(argv[1][i])
       {
            if(isdigit(argv[1][i]) || argv[1][i]=='.')
            {
                if(argv[1][i]=='.')
                {
                    printf(RED"Error! cannot compute floating number\n"RESET);
                    return FAILURE;
                    if(dot_count>0) return FAILURE;
                    dot_count++;
                }
                i++;
                continue;
            }
            else{
                return FAILURE;
            }
       }
       dot_count=0,i=0;
       if(argv[3][0]=='+' || argv[3][0]=='-') i++;
       while(argv[3][i])
       {
            if(isdigit(argv[3][i]) || argv[3][i]=='.')
            {
                if(argv[3][i]=='.')
                {
                    printf(RED"Error! cannot compute floating number\n"RESET);
                    return FAILURE;
                    if(dot_count>0) return FAILURE;
                    dot_count++;
                }
                i++;
                continue;
            }
            else{
                return FAILURE;
            }
       }
       char *opr="+-*/";
       if(argv[2][1]=='\0' && strchr(opr,argv[2][0])) return SUCCESS;
       else return FAILURE;
    }
}

status convert_str_to_list(char argv[],Dlist **head,Dlist **tail)
{
    int i=0,j=0;
    if(argv[i]=='+' || argv[i]=='-') i++;
    while(argv[i]=='0'){ 
        j=i;
        while(argv[j]){
        argv[j]=argv[j+1];j++;}
    }
    while(argv[i])
    {
       if(insert_last(head,tail,argv[i]-'0')==FAILURE)
        return FAILURE;
       i++;
    }
    return SUCCESS;
}

status insert_last(Dlist **head,Dlist **tail,int ndata)
{
     Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL) return FAILURE;
        new->data=ndata;
        new->prev=NULL; 
        new->next=NULL;
        if(*head==NULL)
        {
            *head=*tail=new;
            return SUCCESS;
        }
        else{
             new->prev = *tail;
             (*tail)->next = new;
             *tail = new;
            return SUCCESS;
        }
}

void print_list(Dlist *head)
{
	if (head == NULL)
	{
        printf("0\n");
	}
	else
	{
	    while (head)		
	    {
		    printf("%d", head -> data);
		    head = head -> next;
	    }
        printf(" \n");
    }
}

status insert_first(Dlist **head,Dlist **tail,int data)
{
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL) return FAILURE;
    new->data=data;
    new->next=NULL;
    new->prev=NULL;

    if(*head==NULL)
    {
        *head=*tail=new;
        return SUCCESS;
    }
    else{
        (*head)->prev = new;
        new->next=*head;
        *head=new;
        return SUCCESS;
    }
}

int stringsize(char argv[])
{
    if(argv[0]=='+' || argv[0]=='-')
     return strlen(argv)-1;
    return strlen(argv);
}

void delprecedingzero(Dlist **res_head,Dlist **res_tail)
{
    while((*res_head)!=NULL && (*res_head)->data==0){
     delete_first(res_head,res_tail);
    }
}

status delete_first(Dlist **res_head,Dlist **res_tail)
{
    if(*res_head==NULL)
     return FAILURE;

    if((*res_head)->next==NULL)
    {
        free(*res_head);
        *res_head=*res_tail=NULL;
        return SUCCESS;
    }
    Dlist *temp=*res_head;
    *res_head=(*res_head)->next;
    free(temp);
    (*res_head)->prev=NULL;
    return SUCCESS;
}

void freelist(Dlist *head)
{
    while(head)
    {
        Dlist *temp=head;
        head=head->next;
        free(temp);
    }
}