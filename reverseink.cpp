#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head = NULL,*t;

void createNode(int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        t = temp;
    }
    else
    {
        t->next = temp;
        t = t->next;
    }

}

void display(struct node *temp)
{
    while(temp != NULL)
    {
        cout << temp->data <<"->";
        temp = temp->next;
    }

}

struct node* reverse(struct node *temp,int k)
{
    struct node *p,*q,*r;
    p=NULL;
    q=NULL;
    r=temp;
    int c = 0;
    while(r && c<k)
    {
        p=q;
        q=r;
        r=r->next;

        q->next = p;
        c++;
    }
    if(r!=NULL)
    {
        struct node * f = reverse(r,k);
        temp->next = f;
    }
    return q;
}
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9};
    int n,data;
    createNode(arr[0]);
    for(int i=1;i<9;i++)
    {
        createNode(arr[i]);
    
    }
    display(head);
    cout << "\nAfter reversing the list :\n";
    head = reverse(head,2);
    display(head);
    return 0;
}