/*
Name: Yadhu krishnan
Project: Arbitrary-Precision calculator
Date: 30/01/26
Desciption: Performs addition, subtraction, multiplication, and division on arbitrarily large integers using doubly linked lists.
*/

#include "head.h"
int main(int argc,char *argv[])
{
   if(validate(argc,argv)==SUCCESS){  //validate argument passed are valid
    Dlist *head1=NULL,*tail1=NULL;
    Dlist *head2=NULL,*tail2=NULL;

    Dlist *res_head=NULL,*res_tail=NULL;

    int n1=1,n2=1;

    if(convert_str_to_list(argv[1],&head1,&tail1)==SUCCESS)  //function to convert string to linked list
    {
        if(argv[1][0]=='-') n1=-1; 
        print_list(head1);
    }
    else{
        return FAILURE;
    }
    if(convert_str_to_list(argv[3],&head2,&tail2)==SUCCESS)  ////function to convert string to linked list
    {
        if(argv[3][0]=='-') n2=-1;
        print_list(head2);
    }
    else{
        return FAILURE;
    }
    int len1=stringsize(argv[1]);
    int len2=stringsize(argv[3]);


    switch(*argv[2])  //switch case for choosing operation t perfom
    {
        case '+':  //case for Addition
        {
            if(n1==1 && n2==-1)
            {
                subtraction(&head1,&tail1,&head2,&tail2,&res_head,&res_tail,n1,n2,len1,len2);
                break;
            }
            if(n1==-1 && n2==1)
            {
                subtraction(&head1,&tail1,&head2,&tail2,&res_head,&res_tail,n1,n2,len1,len2);
                (res_head)->data=((res_head)->data)*-1;
                break;
            } 
            addition(&head1,&tail1,&head2,&tail2,&res_head,&res_tail,n1,n2);
            break;
        }
  
        case '-':  //case for Subtraction
        {
            if(n1==1 && n2==-1)
            {
                addition(&head1,&tail1,&head2,&tail2,&res_head,&res_tail,n1,n2);
                break;
            }
            if(n1==-1 && n2==1)
            {
                addition(&head1,&tail1,&head2,&tail2,&res_head,&res_tail,n1,n2);
                (res_head)->data=((res_head)->data)*-1;
                break;
            } 
            subtraction(&head1,&tail1,&head2,&tail2,&res_head,&res_tail,n1,n2,len1,len2); 
            break;
        }

        case '*':  //case for Multiplication
        {
            multiply(&head1,&tail1,&head2,&tail2,&res_head,&res_tail);
            delprecedingzero(&res_head,&res_tail);
            if((n1==-1 && n2==1) || (n1==1 && n2==-1)){
                if(res_head)
                    (res_head)->data=((res_head)->data)*-1;
                }
            break;
        }

        case '/':  //case for Division
        {
            if(head2==NULL){
                printf(RED"Division by zero error!\n"RESET); return 0;
            }
            division(&head1,&tail1,&head2,&tail2,&res_head,&res_tail);
            if((n1==-1 && n2==1) || (n1==1 && n2==-1))
                (res_head)->data=((res_head)->data)*-1;
            break;
        }
    }
    print_list(res_head);  //print final result
    free(res_head);
  }
   else{
    printf(RED"Failed!,Try again...\n"RESET); //prompt for failure
    printf(RED"CLA syntax Error: <filename> <1st operand> <operator> <2nd operand>\n"RESET);
    printf(RED"Addition \t->  +\nSubtraction \t->  -\nMultiplication  -> '*'\nDivision \t->  /\n"RESET);
    return FAILURE;
   }
}

