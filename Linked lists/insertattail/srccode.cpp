#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// YOUR CODE (CLASS IMPLEMENTATION) GOES HERE ////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
class Node
{
    public:
    int dataItem;
    Node* next;
    Node(int newItem)//constructor method to initialize data input and point null
    {
        dataItem=newItem;
        next=NULL;
    }
    void printList()//prints the list
    {
        Node * currentdata=this;// this pointer used to point currentdata to its address
        do
    {
        cout<<currentdata->dataItem<<" ";
    }while(currentdata=currentdata->next);
    }

    void insertTail(int newElement)//method to insert at tail
    {
        Node*currentdata=this;// this pointer is used to point currentdata to its address
        /*traverse the list using a while loop as currentdata points to next upto the end of the list
        and assign the last pointer a value newElement*/
        while(currentdata->next)
        {
            currentdata=currentdata->next;
        };
            currentdata->next=new Node(newElement);

    }



};
int main() {
  // create the handle to the linked list
  Node * myList, *node2, *node3;

  // initialize pointer to the head node
  cout << "Enter the elements of the linked list: ";
  int temp;
  cin >> temp; // assume 10 is entered
  myList= new Node(temp);

  // insert another node manually
  cin >> temp; // assume 20 is entered
  node2 = new Node(temp);
  myList->next = node2;

  // insert another node manually
  cin >> temp; // assume 30 is entered
  node3 = new Node(temp);
  node2->next = node3;

  myList->printList(); // output should be: 10 20 30

  // Insert automatic using the proper method
  myList->insertTail(11);
  myList->insertTail(22);

  myList->printList(); // output should be: 10 20 30 11 22

  return 0;
}
