#include <iostream>

using namespace std;

class Node
{
    public:
    int dataItem;
    Node *next;
    Node(int newItem)//constructor method
    {
        dataItem=newItem;
        next=NULL;
    }
    void printList()//prints the list
    {
        Node *currentdata=this;
        do
        {
            cout<<currentdata->dataItem;
        }while(currentdata=currentdata->next);
    }
    void insertTail(int newElement)
    {
        Node *currentdata=this;
        while(currentdata->next)
        {
            currentdata=currentdata->next;
        }
        currentdata->next=new Node(newElement);
    }
    Node *insertHead(int newElement)
    {
        Node*head=new Node(newElement);
        head->next=this;
        return head;
    }

    //insert at middle method
    void insertMiddle(int newElement, int position)
    {
        //declare node current data and assign its pointer using this
        Node *currentdata=this;
        int i=0;
        //traverse the list using while from first node to the node assigned by position  variable
        while(currentdata->next && ++i < position)
            currentdata=currentdata->next;
        //assign the middle node a value newElement
        Node *middle=new Node(newElement);
        //middle points to next
        middle->next= currentdata->next;
        currentdata->next=middle;
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
  cout << "State of the list: ";
  myList->printList(); // output should be 10 20 30  => assuming that is what was entered above

  // insert a new element in the middle (at index position 2)
  myList->insertMiddle(25, 2);

  cout << "After inserting an element at index position 2 the list is like so: ";
  myList->printList(); // output should be 10 20 25 30

  return 0;
}

