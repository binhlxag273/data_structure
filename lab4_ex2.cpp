#include <iostream>
#include <string>
class StudentBuilder
{
private:
	struct Node
	{
		int id;
		std::string fullName;
		double score;
		Node* next;
		Node() : next(NULL) { }
		Node(int id, std::string fullName, double score) : id(id), fullName(fullName), score(score), next(NULL) { }
	};
	Node* head;

	void splitList(Node* mid, Node* right)
	{
		Node* premid = mid;
		while (right->next != NULL)
		{
			right = right->next;
			if (right->next != NULL)
			{
				premid = premid->next;
				right = right->next;
			}
		}
		mid = premid->next;
		premid->next = NULL;
	}

public:

	StudentBuilder() { }
	~StudentBuilder()
	{
		Node* temp = head, * curr = head;
		while (curr != NULL)
		{
			temp = curr;
			curr = curr->next;
			delete temp;
		}
	}
	void addFirst(int id, std::string fullName, double score)
	{
		Node* newNode = new Node(id, fullName, score);
		if (head == NULL) head = newNode;
		else newNode->next = head;
		head = newNode;
	}

	void printList()
	{
		Node* currNode = head;
		std::cout << "head->";
		while (currNode != NULL)
		{
			std::cout << currNode->id << " | " << currNode->fullName << " | " << currNode->score << "->" << std::endl;
			currNode = currNode->next;
		}
		std::cout << "NULL";
	}

	void sortList()
	{
		
		for (Node* curr_1 = head; curr_1 != NULL; curr_1 = curr_1->next)
		{
			for (Node* curr_2 = head; curr_2 != NULL; curr_2 = curr_2->next)
			{
				if (curr_1->score < curr_2->score)
				{
					Node* temp = new Node(curr_2->id, curr_2->fullName, curr_2->score);
					curr_2->id = curr_1->id;
					curr_2->fullName = curr_1->fullName;
					curr_2->score = curr_1->score;
					curr_1->id = temp->id;
					curr_1->fullName = temp->fullName;
					curr_1->score = temp->score;
					delete temp;
				}
			}
		}
	}
};

int main()
{
	StudentBuilder list;
	list.addFirst(1, "Balebom", 6.5);
	list.addFirst(2, "Andrew", 8);
	list.addFirst(3, "Michel", 7);
	list.addFirst(4, "Tim", 8.5);
	list.addFirst(5, "Agie", 7.5);
	list.sortList();
	list.printList();
	return 0;
}

