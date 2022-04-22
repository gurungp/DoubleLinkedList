//
//  DoubleLinked.h
//  DoubleLinkedList
//
//  Created by Prashant Gurung on 22/04/2022.
//

#ifndef DoubleLinked_h
#define DoubleLinked_h

struct node{
  
    int value;
    struct node *prev;
    struct node *next;
    
};

class DoubleLink
{
public:
    
    node *head=NULL;
    node *tail=NULL;
    
    node *createNode(int val)
    {
        node* newNode = new node;
        newNode->value = val;
       
        return newNode;
    }
    void addAtBegining(int val)
    {
        node *newNode = createNode(val);
        
        if(head==NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            
        }
        else
        {
            newNode->next = head;
            newNode->prev = nullptr;
            
            head->prev = newNode;
            
            head=newNode;
           
            
        }
    }
    void addAtLast(int val)
    {
        node *newNode = createNode(val);
        if(tail==NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            
        }
        else
        {
            newNode->next=nullptr;
            tail->next=newNode;
            newNode->prev=tail;
            tail = newNode;
            
        }
    }
    
    void addatPos(int pos, int val)
    {
        if(head==nullptr)
            return;
        
        node *temp1=head;
        node *temp2=head->next;
        
        if(pos==1 || pos==0)
        {
            addAtBegining(val);
            return;
        }
        int count = 2;
        while(temp2!=nullptr)
        {
            if(count==pos)
            {
                node *newNode = createNode(val);
                temp1->next = newNode;
                newNode->prev = temp1;
                newNode->next = temp2;
                temp2->prev = newNode;
                break;
            }
            temp1=temp1->next;
            temp2=temp2->next;
            count++;
        }
    }
    
    void deleteAtPos(int pos)
    {
        if(head==nullptr) // if empty list
            return;
        
        
        node *temp1=head;
        node *temp2=head->next;
        
        int count = 1;
        
        if(temp2==nullptr && temp1!=nullptr) // only one element in the list
        {
            if(count==0 || count ==1)
            {
                head=nullptr;
                tail=nullptr;
                delete temp1;
            }
            return;
        }
        
        while(temp2!=nullptr)
        {
            
            if(count==0 || count ==1) // delete at Begining
            {
                head=temp2;
                temp2->prev = nullptr;
                delete temp1; //free the memory of the head;
                break;
            }
            
            if(count==pos)
            {
                temp1->prev->next = temp2;
                temp2->prev = temp1->prev;
                delete temp1;
                break;
            }
            count++;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
    }
    
    void deleteAtLast()
    {
        if(head==nullptr) // if empty list
            return;
        
        node *temp1=head;
        node *temp2=head->next;
        
        
        if(temp2==nullptr && temp1!=nullptr) // only one element in the list
        {
          
                head=nullptr;
                tail=nullptr;
                delete temp1;
            
            return;
        }
        
        while(temp2!=nullptr)
        {
            if(temp2->next==nullptr)
            {
                temp1->next = nullptr;
                tail=temp1;
                delete temp2;
                
            }
            
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    
    void deleteAtBegining()
    {
        deleteAtPos(0);
    }
    
    void display()
    {
        if(head==nullptr)
            std::cout << "EMPTY LIST" ;
        
        node *newNode = head;
        while(newNode!=nullptr)
        {
            std::cout << newNode->value;
            
            if(newNode->next!=nullptr)
                std::cout << " -> " ;
          
            newNode = newNode->next;
            
        }
        std::cout << std::endl;
    }
};


#endif /* DoubleLinked_h */
