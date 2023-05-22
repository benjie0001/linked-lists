#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////// YOUR CODE (CLASS IMPLEMENTATION) GOES HERE ////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
class Node
{
    public:
    int dataItem;
    Node * next;
    Node(int newItem)//constructor method
    {
        dataItem=newItem;
        next=NULL;
    }
    void printList()//prints list
    {
        Node *currentdata=this;
        do
        {
            cout<<currentdata->dataItem<<" ";
        }while(currentdata=currentdata->next);
    }
    void insertTail(int newElement)
    {
        Node *currentdata=this;
        while(currentdata->next)
        {
            currentdata=currentdata->next;
        };
        currentdata->next=new Node(newElement);

    }
    //method to insert at the head of list
    Node *insertHead(int newElement)
    {
        //initialize a new node at the head of list to hold newElement
        Node *head=new Node(newElement);
        //initialized node points to next pointer
        head->next=this;
        return head; //returns address of inserted elements at head
    }

};

int main() {
  // create the handle to the linked list
  Node * myList;

  // Intended size of list
  int n, temp;
  cout << "How many elements do you want to enter? ";
  cin >> n;

  // Create the first node aka the head
  cout << "Enter the first element: ";
  cin >> temp;
  myList = new Node(temp);

  // Insert the rest of the elements. Take careful note of the limits of the loop
  for(int i = 0; i < n - 1; i++){
    cout << "Enter the next element: ";
    cin >> temp;
    myList->insertTail(temp);
  }

  //Print the list to confirm its status
  myList->printList();

  // insert two new elements at the front of the list
  int newElement;
  cout << "Enter an element to insert at the head: ";
  cin >> newElement;
  myList = myList->insertHead(newElement);

  cout << "Enter another element to insert at the head: ";
  cin >> newElement;
  myList = myList->insertHead(newElement);

  myList->printList();

  return 0;
}
