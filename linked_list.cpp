#include<bits/stdc++.h>

using namespace std;
//DISPLAY ALL ELEMENTS
//DETECT LOOP
//CREATE LOOP
//DELETE WITHOUT HEAD POINTER
//MID IN SINGLE ITERATION USING TWO POINTER
//REVERSE A LINKED LIST IN O(N) -- IN ONE ITERATION(Window sliding technique)
//Nth NODE FROM THE END IN SINGLE ITERATION
//REVRESE A LINKED LIST RECURSIVELY


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
void creatLoop(struct node *temp)
{
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head->next->next;
}

int detectLoop(Node* temp)
{
    Node *slow_p = temp, *fast_p = temp;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

void deleteNode(struct node *node)
{
   int temp = node->data;
   node->data = node->next->data;
   node->next->data = temp;

   node->next = node->next->next;
}

int Mid(struct node *head)
{
    struct node *p = head,*q = head;
    while(p != NULL && p->next != NULL)
    {
        q = q->next;
        p = p->next;
        if(p)
            p=p->next;
    }
    return q->data;

}
void elementRec(struct node *temp)
{
    if(temp == NULL)
        return ;
    cout << temp->data << " ";
    elementRec(temp->next);
}

void reverseLL(struct node *temp)
{
    struct node *p = temp;
    struct node *q = NULL,*r = NULL;

    while(p!= NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;

    }
    head = q;

}
int NthNodeFromEnd(struct node *temp,int n)
{
    struct node *t = head;
    for(int i=0;i<n;i++)
    {
        t = t->next;
    }
    while(t!= NULL)
    {
        temp = temp->next;
        t = t->next;
    }
    return temp->data;

}
void reverseLRec(struct node *temp)
{
    if(temp->next == NULL){
        head = temp;
        return ;
    }
    else{
        reverseLRec(temp->next);
        temp->next->next = temp;
        temp->next = NULL;
    }
}
int main()
{
    int arr[10] = {1,2,3,4};
    int n,data;
    createNode(arr[0]);
    for(int i=1;i<4;i++)
    {
        createNode(arr[i]);
    }
    //cout << "2nd node from end : "<<NthNodeFromEnd(head,2)<<endl;
    //display(head);
    reverseLRec(head);
    display(head);
    return 0;
}
