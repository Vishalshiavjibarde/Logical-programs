#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    public :
    PNODE First;
    int icount;

    DoublyLL();

    void insertFirst(int iNo);
    void insertLast(int iNo);
    void insertatPos(int iNo,int ipos);
    void deleteFirst();
    void deleteLast();
    void deleteatPos(int ipos);
    void Display();
};

DoublyLL::DoublyLL()
{
    First=NULL;
    icount=0;
}
void DoublyLL::insertFirst(int iNo)
{
    PNODE newn=new NODE;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(First==NULL)
    {
        First=newn;
        icount++;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
        icount++;
    }

}
void DoublyLL::insertLast(int iNo)
{
    PNODE temp=First;
    PNODE newn=new NODE;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(First==NULL)
    {
        First=newn;
        icount++;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
        icount++;
    }
}

void DoublyLL::insertatPos(int iNo,int ipos)
{
 
    if((ipos<1)||(ipos>icount+1))
    {
        return;
    }
    if(ipos==1)
    {
        insertFirst(iNo);
    }
    else if(ipos==icount+1)
    {
        insertLast(iNo);
    }
    else
    {
       PNODE newn=new NODE;
        newn->data=iNo;
        newn->next=NULL;
        newn->prev=NULL;

        PNODE temp=First;
       
        for(int icnt=1;icnt<ipos-1;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    }
        icount++;
}

void DoublyLL::deleteFirst()
{
    PNODE temp=First;

    if(First==NULL)
    {
        return;
    }
    else if((First)->next==NULL)
    {
        delete(First);
        First=NULL;
        icount--;
    }
    else
    {
        First=First->next;
        delete First->next->prev;
        First->next->prev=NULL;
        icount--;

    }
}

void DoublyLL::deleteLast()
{
    PNODE temp=First;

    if(First==NULL)
    {
        return;
    }
      else if((First)->next==NULL)
    {
        delete(First);
        First=NULL;
        icount--;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;

    }
        icount--;
}

void DoublyLL::deleteatPos(int ipos)
{
    PNODE temp1=NULL;
    PNODE temp2=NULL;

    if((ipos<1)||ipos>icount)
    {
        return;
    }
    if(ipos==1)
    {
        deleteFirst();
    }
    else if(ipos==icount)
    {
        deleteLast();
    }
    else
    {
        temp1=First;

        for(int icnt=1;icnt<ipos-1;icnt++)
        {
            temp1=temp1->next;

        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next->prev=temp1;
        delete temp2;
        icount--;
    }

}

void DoublyLL :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";
    PNODE temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()

{
    DoublyLL obj;

    obj.insertFirst(51);
    obj.insertFirst(21);
    obj.insertFirst(11);
    obj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj.icount<<"\n";

    obj.insertLast(101);
    obj.insertLast(111);
    obj.insertLast(121);
    obj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj.icount<<"\n";

    obj.insertatPos(61,4);
    obj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj.icount<<"\n";

    obj.deleteatPos(4);
    obj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj.icount<<"\n";

    obj.deleteFirst();
    obj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj.icount<<"\n";


    obj.deleteLast();
    obj.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj.icount<<"\n";

    return 0;
}