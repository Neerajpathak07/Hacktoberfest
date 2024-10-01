#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node*Next;
};

void LinkedListTraversal(struct Node*Head){
    struct Node*ptr=Head;
    printf("Element is :- %d\n ",ptr->Data); 
        ptr=ptr->Next;

    do
    {
        printf(" Element is :- %d\n ",ptr->Data);
        ptr=ptr->Next;
    }while (ptr!=Head);
    
}

//inserting data at first element 
struct Node* InsertAtFirst(struct Node*head,int Data){
    struct Node*ptr =(struct Node*)malloc(sizeof(struct Node));
    ptr->Data=Data;
    struct Node* p=head->Next;
    while (p->Next!=head)
    {
     p=p->Next          ;  
    }
    // at this point p points to the last node of this circular linked list
    p->Next=ptr;
    ptr->Next=head ;
    head=ptr;
    return head;
}

int main(int argc, char const *argv[])
{
    struct Node*Head;
    struct Node*Second;
    struct Node*Third;
    struct Node*Fourth;
    
    //Allocate Memory for nodes in Linked List in Heap
    Head=(struct Node*)malloc(sizeof(struct Node));
    Second=(struct Node*)malloc(sizeof(struct Node));
    Third=(struct Node*)malloc(sizeof(struct Node));
    Fourth =(struct Node*)malloc(sizeof(struct Node));
    
    //Link frist and Second Node
    Head->Data=7;
    Head->Next=Second;

    Second->Data=12;
    Second->Next=Third;

    Third->Data=73;
    Third->Next=Fourth;

    //Circular LL
    //Linking The last node to the first one Hence creating a Circular Linked List
    Fourth->Data=94;
    Fourth->Next=Head;
    
    LinkedListTraversal(Head);

    Head=InsertAtFirst(Head,80);
    LinkedListTraversal(Head);

    return 0;
}
