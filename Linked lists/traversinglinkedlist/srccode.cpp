#include <iostream>

using namespace std;

class Node
{
    public:
    int dataItem;
    Node * next;
    //constructor method to initialize the data entry to the next node
    Node(int newItem){
    dataItem=newItem;
    next=NULL;
    }
    void printList()
    {
        Node * currentdata=this;
       do
        {
            cout<< currentdata->dataItem<< " ";
        } while(currentdata=currentdata->next);
        //do while is best as it adds the first node to the list. while alone does not cover the first node as the parameter excludes it

    }//to print the list
};


// main function to test your code
int main() {
  // create the handle to the linked list
  Node * myList, *node2, *node3;

  // initialize pointer to the head node
  int temp;
  cout << "Enter data value of first node: ";
  cin >> temp; // assume 10 is entered
  myList= new Node(temp);

  // create another node
  cout << "Enter data value of next node: ";
  cin >> temp; // assume 20 is entered
  node2= new Node(temp);
  myList->next = node2;

  // create a third node
  cout << "Enter data value of next node: ";
  cin >> temp; // assume 30 is entered
  node3= new Node(temp);
  node2->next = node3;

  cout << "The state of the linked list is as follows: ";
  myList->printList(); // output should be: 10 20 30

  return 0;
}

