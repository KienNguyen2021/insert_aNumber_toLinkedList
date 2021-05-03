#include<iostream>

using namespace std;

struct Node
{
	int datum;
	Node * pNext;  // 1 Node contains 2 parts : Data and pNext or called Linked component

				   // Open a construct to initialize this NODE at the beginning :

	Node()
	{
		datum = 0;
		pNext = nullptr;
	};

	// Open a construct to take some Arguments as Parameters  :

	Node(int DataPoint, Node *link)    // 1 is data, 1 is the next pointer
	{
		datum = DataPoint;
		pNext = link;
	}
	// to check if the Linked List is empty or not :

};

class SortedLinkedList
{
private:
	Node *pHead;
public:
	SortedLinkedList()        // a constructor
	{
		pHead = nullptr;     // Initialize pHead
	}

	SortedLinkedList(Node * link)     // a Constructor takes parameters
	{
		pHead = link;          // Initialize pHead

	}

	bool isEmpty()
	{
		return(pHead == nullptr);  // Output : 1 - True at the beginning witout any values
	}

	void CreateList()
	{
		cout << " Enter a number of Nodes that you want to have in the LinkedList :" << endl;

		int numberOfNodes;          // Declare a variable of Input from User
		cin >> numberOfNodes;       // To store the entered value from User input

		Node *pCurrentNode;     // Declare a variable for current Pointer
		Node *pNewNode;        //  Declare a variable for next Pointer

		cout << " Enter the value to store in 0th node " << endl;

		int inputValue;          // Declare a variable for this Value
		cin >> inputValue;       // To store this input value

		pNewNode = new Node(inputValue, nullptr);     // this constructor : (this is the first Node) data is the input Value, link is last NODE that pointer should reach - NULL
		pHead = pNewNode;      // pHead copy address of new Node when a value Input for Current Node entered
		pCurrentNode = pHead;   //  Now in pHead contains the addres of CurrentNode

		int count = 0;   // initialize the count at begin = 0

		while (count != (numberOfNodes - 1))  // because, 1 first exists above
		{
			cout << " Enter the value to store in the " << count + 1 << " Node" << endl;

			cin >> inputValue;  // store the address of new Node

			pNewNode = new Node(inputValue, nullptr);

			pCurrentNode->pNext = pNewNode;

			pCurrentNode = pNewNode;       // in PcurrentNode, we store the address of new Node

			count++;
		}
	}

// A linkedList : pH, 2,5,7,9,14,17
// We want to insert 11, it will be between 9, 14

  Node * searchLinkedList(Node *pHead, int x)
	{
		Node *pPrevious = nullptr;      // to return the addres of previous Node 9 is NULL
		Node *pCurrent = pHead;        // Assign Pointer of current Node = pHead : pHeat at the beginning is now NULL

		while (pCurrent != nullptr && pCurrent->datum <x )   // x = 11 - Loop go from pHead at the beginning with NULL
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent ->pNext;
		}
		return pPrevious;
	}

// use Void to inser number :

  void insertNode (int x)   //  To find the position where we want to insert
  {
	  Node * pPrevious = searchLinkedList(pHead, x);
	  Node *pCurrent = new Node;
	  pCurrent->datum = x;

	  if (pPrevious == nullptr)
	  {
		  pCurrent->pNext = pHead;      // because pHead = NULL
		  pHead = pCurrent;
	  }
	  else
	  {
		  pCurrent->pNext = pPrevious->pNext;    // Pointer of Current Node contains the Address of previous Node
		  pPrevious ->pNext  = pCurrent;             // Just corrected : added ->pNext
	  }
  }


	void printLinkedList()
	{
		cout << " Our Linked List is as follows : " << endl;

		for (const Node * p = pHead; p != nullptr; p = p->pNext)
		{
			cout << p->datum << endl;     // print value of for each node
		}

		cout << endl;

	}
};


int main()
{

	SortedLinkedList list1;
	list1.CreateList();         // Calling function CreateList

	list1.printLinkedList();      // Calling the function printLinkedList

	list1.insertNode(11);           // Calling the function Insert - insert Number 11


	cout << list1.isEmpty() << endl;   // Output, at the end : 0 - because bool function - 0 means the list is not empty




	return 0;
}
