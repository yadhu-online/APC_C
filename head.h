/* #ifndef HEAD_H
#define HEAD_H */

#define RESET   "\033[0m"
#define RED     "\033[1;91m"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{  //structure for double linked list
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

typedef enum{
    SUCCESS,
    FAILURE
}status;

status validate(int ,char *argv[]);  //validate function

int stringsize(char argv[]);  //finding string size

status convert_str_to_list(char argv[],Dlist **head,Dlist **tail); //convert string to linked lis

void print_list(Dlist *head);  //print list

status insert_last(Dlist **head,Dlist **tail,int ndata); //insert element to last of list

void addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail,int n1,int n2); //addition

void sub(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail); //check for various sign cases for subtraction

void subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail,int n1,int n2,int len1,int len2); //Subtraction

status insert_first(Dlist **head,Dlist **tail,int data); //function to insert element in first

void delprecedingzero(Dlist **res_head,Dlist **res_tail); //function to remove zero's at front

status delete_first(Dlist **res_head,Dlist **res_tail);  //delete elemnt at first

void multiply(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail); //Mulitipication

void freelist(Dlist *head); //function for free each node in a list

void division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **res_head,Dlist **res_tail); //Division


