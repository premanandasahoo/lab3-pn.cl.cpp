#include<iostream>
using namespace std;

class Node
{
	public:
		//Data IS giving
		int data;
		//Pointer to the next node IS AVAILABLE	
		Node *next;
		//Constructor that makes the pointer Null IS GIVEN
		Node()
		{
			next=NULL;
		}
		
};


class LinkedList
{
	//Head + Nodes inside linked with each other IS TAKEN
	public:
	//Head -> Node type pointer IS GIVEN
	Node *head;
	Node *tail;
	//constructor
	LinkedList()
	{
		head=NULL;
		tail=NULL;
	}
	//circled inside linked with each other
	//rules how circles will be linked
	//Insert
	void insert(int value)
	{
		//If first node is added
		Node *temp = new Node;
		//insert data in the node
		temp->data = value;
		//1st Node only
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		//Any other Node only
		else
		{
			tail->next=temp;
		}
		tail=temp;
		tail->next=head;
	}
	//Deletion of last element
	void delet()
	{
	  
	//store the tail in temp
	Node *temp=tail;
	//before tail has to point to NULL
	Node *current=head;
	while(current->next!=tail)
	{
	    current=current->next;
	}
	current->next=head;
	//update tail
	tail=current;
	//delete temp
	delete temp;
	}
	void display()
	{
		cout<<"The linked list is: ";
		Node *current=head;
		while((current->next)!=head)
		{
			cout<<current->data<<"->";
			current=current->next;
		}
		cout<<current->data<<"->";
		cout<<endl;
	}
	void insertAt(int pos, int value)
	{
	    //Reach the place before the position
	    Node *current=head;
	    int i=1;
	    if(pos!=1)
	    {
	        while(i<pos-1)
	        {
	            i++;
	            current=current->next;
	        }
	        //Create a node
	        Node *temp=new Node;
	        temp->data=value;
	        //moving pointers
	        temp->next=current->next;
	        current->next=temp;
	    }
	    else
	        
	        {
	            //create new node IS REQUIRED
	            Node *temp=new Node;
	            //insert value in the Node
	            temp->data=value;
	            //point the new first node to the previously first node
	            temp->next=head;
	            //point the head to the new first node 
	            head=temp;
	            tail->next=head;
	        }     
	}
	//Delete at a particular position
	void deleteAt(int pos)
	{
	    int i=1;
	    int j=1;
    	//for all cases except position=1
    	//reach the nodes before and after the node to be deleted 
    	if(pos!=1)
    	{
    	    //the node before
    	    Node *current=head;
    	    //the node after
    	    Node *current2=head;
    	    //reaching the node before
    	    while(i<pos-1)
    	    {
    	        i++;
    	        current=current->next;
    	    }
    	    //reaching the node after
    	    while(j<pos+1)
    	    {
    	        j++;
    	        current2=current2->next;
    	    }
    	    //store the node to be deleted in a temp variable
    	    Node *temp=current->next;
    	    //link the two nodes:before and after
    	    current->next=current2;
    	    //point the node to be deleted to NULL
    	    temp->next=NULL;
    	    //delete temp
    	    delete temp;
    	}
    	//for position = 1
    	else
    	{
    	    //Store the first node in a  temp variable
    	    Node *temp=head;
    	    //point head to the 2nd Node
    	    head=head->next;
    	    //delete temp
    	    delete temp;
    	}
	}
	//Counting no of items in the linked list
	int countItems()
	{
	    //setting up a count variable
	    int count=0;
	    //create a current variable to reach the end of the linked list
	    Node *current=head;
	    //reach the end of the linked list
	    while((current->next)!=head)
	    {
	        current=current->next;
	        count++;
	    }
	    count++;
	    //display the count
	    cout<<"The number of items in the linked list is: "<<count<<endl;
	    
	}
	
	
	
};


int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	l1.countItems();
	l1.delet();
	l1.display();
	l1.countItems();
	l1.insertAt(1,3);
	l1.insertAt(2,6);
	l1.display();
	l1.countItems();
    l1.display();
	
	
	return 0;
}