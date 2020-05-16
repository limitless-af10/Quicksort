//2018058 lab 7_Q_2
#include <iostream>
#include<string>
using namespace::std;

class list
{
	struct book
	{
		int id;
		string name;
		book *next;
		book *prev;

		book() //default constructor
		{
			id = 0;
			name = "NULL";
			next = NULL;
			prev = NULL;
		}
	};

	book *head;
	int length;

	void add()  //function to add node to tail
	{
		int id_;
		string name_;
		
		cout << "\n Enter book id";
		cin >> id_;

		cout << "\n Enter book name";
		cin.ignore();
		getline(cin, name_);

		book *newnode = new book;
		newnode->id = id_;
		newnode->name = name_;

		if (head == NULL)
		{
			head = newnode;
			head->prev = NULL;
			head->next = NULL;
		}

		else
		{
			book *traversal = head;

			while (traversal->next != NULL)
			{
				traversal = traversal->next;
			}

			traversal->next = newnode;
			newnode->prev = traversal;
			newnode->next = NULL;
		}

		length++;


	}

	void disp()  //function to display list
	{
		book *traversal = head;

		cout << " Id\t\tName"<<endl;



		while (traversal != NULL)
		{
			cout <<" "<< traversal->id<< "\t\t" << traversal->name<<endl;
			traversal = traversal->next;
		}
	}

	void quick_sort_id(book *start , int front , int rear)
	{
		book *traverse = head;
		book *sub_head;
		book *pivot= head;

		if (front < rear)
		{
			//getting head of sub list
			for (int i = 0; i < front; i++)
			{
				traverse = traverse->next;

			}

			sub_head = traverse;

			//choosing last element of sub element as pivot
			for (int i = 0; i < rear-1; i++)
			{
				pivot = pivot->next;
			}

			book *greaterPtr = pivot;
			bool pivot_most_min = true;
			traverse = sub_head;

			for (int i = 0; i < (rear - front)-1; i++)  //
			{
				book *temp_traverse = traverse->next;
				
				//putting elements greater than pivot after it
				if (traverse->id > pivot->id)
				{
					
					
					if (traverse == head)
					{
						head = traverse->next;
						head->prev = NULL;
					}

					else
					{
						traverse->prev->next = traverse->next;
						traverse->next->prev = traverse->prev;
					}
					
					traverse->prev = greaterPtr;
					traverse->next = greaterPtr->next;
					
					if(greaterPtr->next!=NULL)
					greaterPtr->next->prev = traverse;

					greaterPtr->next = traverse;

					greaterPtr = greaterPtr->next;

				}

				traverse = temp_traverse;
			}

			int partition=0;

			traverse = head;

			//finding partition index
			while (traverse != pivot)
			{
				traverse = traverse->next;
				partition++;
			}


			quick_sort_id(head, front, partition);
			quick_sort_id(head, partition + 1, rear);
		}

	}


	void quick_sort_name(book *start, int front, int rear)
	{
		book *traverse = head;
		book *sub_head;
		book *pivot = head;

		if (front < rear)
		{
			//getting head of sub list
			for (int i = 0; i < front; i++)
			{
				traverse = traverse->next;
			}

			sub_head = traverse;

			//getting pivot for sub list
			for (int i = 0; i < rear - 1; i++)
			{
				pivot = pivot->next;
			}

			book *greaterPtr = pivot;
			bool pivot_most_min = true;
			traverse = sub_head;

			for (int i = 0; i < (rear - front) - 1; i++)  //
			{
				book *temp_traverse = traverse->next;

				//putting elements of pivot after it
				if (traverse->name > pivot->name)
				{


					if (traverse == head)
					{
						head = traverse->next;
						head->prev = NULL;
					}

					else
					{
						traverse->prev->next = traverse->next;
						traverse->next->prev = traverse->prev;
					}

					traverse->prev = greaterPtr;
					traverse->next = greaterPtr->next;

					if (greaterPtr->next != NULL)
						greaterPtr->next->prev = traverse;

					greaterPtr->next = traverse;

					greaterPtr = greaterPtr->next;

				}

				traverse = temp_traverse;
			}

			int partition = 0;

			traverse = head;

			//finding partition index
			while (traverse != pivot)
			{
				traverse = traverse->next;
				partition++;
			}


			quick_sort_name(head, front, partition);
			quick_sort_name(head, partition + 1, rear);
		}
	}

	public:

		list()
		{
			head = NULL;
			length = 0;
		}

		void menu()
		{
			int option;

			do
			{
				cout << "\n Enter 1 to add a book";
				cout << "\n Enter 2 to sort by ID";
				cout << "\n Enter 3 to sort by name";
				cout << "\n Enter 4 to quit";
				cout << "\n option: ";
				cin >> option;

				if (option == 1)
				{
					system("cls");

					this->add();

					cout << endl << " ";
					system("pause");

				}

				if (option == 2)
				{
					system("cls");

					cout << " Before sorting" << endl<<endl;
					this->disp();

					this->quick_sort_id(head,0,length);
					
					cout << "\n\n After sorting" << endl << endl;
					this->disp();

					cout << endl << " ";
					system("pause");

				}


				if (option == 3)
				{
					system("cls");

					cout << " Before sorting" << endl << endl;
					this->disp();

					this->quick_sort_name(head, 0, length);

					cout << "\n\n After sorting" << endl << endl;
					this->disp();

					cout << endl << " ";
					system("pause");
				}



			} while (option != 4);
			
		}

};



int main()
{
	list l1;
	l1.menu();
}

