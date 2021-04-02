#include <iostream>
#include <string>
class StaffBuilder
{
private:
	struct Node
	{
		int id;
		std::string fullName;
		int baseSalary = 1150000;
		double coeff;
		int workdates;
		double salary;
		Node* next = NULL;
	
		Node() { }
		Node(int id, std::string fullName, double coeff, int workdates) : id(id), fullName(fullName), coeff(coeff), workdates(workdates) { }
	};
	Node* head;


	void SalaryCal(Node * curr)
	{
		curr->salary = curr->baseSalary * curr->coeff * curr->workdates / 26;
	}

public:
	StaffBuilder() { }
	~StaffBuilder() 
	{
		Node* delNode = head, * currNode = head;
		while (currNode != NULL)
		{
			delNode = currNode;
			currNode = currNode->next;
			delete delNode;
		}
	}

	void addStaff(int id, std::string fullName, int baseSalary, double coeff, int workdates)
	{
		Node* staff = new Node(id, fullName, coeff, workdates);
		SalaryCal(staff);
		if (head == NULL) head = staff;
		else
		{
			staff->next = head;
			head = staff;
		}
	}

	void printSalaryTable()
	{
		Node* curr = head;
		std::cout << "id | fullName | baseSalary | coeff | workdates | basicSalary " << std::endl;
		while (curr->next != NULL)
		{
			std::cout << curr->id << " | " << curr->fullName << " | " << curr->baseSalary << " | " << curr->coeff << " | "
				<< curr->workdates << " | " << curr->baseSalary * curr->coeff * curr->workdates / 26 << std::endl;
			curr = curr->next;
		}
	}

	void findStaff(std::string name)
	{
		Node* curr = head;
		while (curr != NULL)
		{

		}
	}
};

int main()
{
	return 0;
}
