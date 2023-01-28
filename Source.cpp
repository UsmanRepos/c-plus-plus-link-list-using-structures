#include<iostream>
#include<string>
#define SIZE 70
#define SUB 3
using namespace std;

struct student {
	int    regNo;
	string name;
	int    subMarks[SUB];
	double average;
	char   grade;

	student* next;
};

void createDB(student*& first, student*& cur, student*& prev)
{
	char ch;
	while (true)
	{
		int sum = 0;
		cur = new student;
		cur->next = NULL;

		cout << " Enter RegNo: ";
		cin >> cur->regNo;

		cin.ignore(10, '\n');
		cout << " Enter Name: ";
		getline(cin, cur->name);
		cout << " Enter Marks: ";
		for (int i = 0; i < SUB; i++)
		{
			cin >> cur->subMarks[i];
			sum += cur->subMarks[i];
		}
		cur->average = (sum * 1.0) / SUB;

		if (cur->average >= 80)
			cur->grade = 'A';
		else if (cur->average >= 70)
			cur->grade = 'B';
		else if (cur->average >= 60)
			cur->grade = 'C';
		else if (cur->average >= 50)
			cur->grade = 'D';
		else
			cur->grade = 'F';

		

		if (first == NULL)
		{
			first = prev = cur;
		}
		else
		{
			prev->next = cur;
			prev = cur;
		}
		cout << "\n Do you Want to Enter Another Student Data: ";
		cin >> ch;

		if (toupper(ch) == 'N')
			break;
	}

}
void myGetter(student* first, student* cur)
{
	cur = first;
	while (cur != NULL)
	{
		cout <<"  " << cur->regNo << "\t" << cur->name << "\t";
		for (int i = 0; i < SUB; i++)
		{
			cout << cur->subMarks[i] << "   ";
		}
		cout << cur->average << "\t" << cur->grade << endl;

		cur = cur->next;
	}
}
void myInsertion(student*& first, student*& cur, student*& prev)
{
	student* newStudent = new student;
	newStudent->next = NULL;

	int sum = 0;

	cout << " Enter RegNo: ";
	cin >> newStudent->regNo;

	cin.ignore(10, '\n');
	cout << " Enter Name: ";
	getline(cin, newStudent->name);
	cout << " Enter Marks: ";
	for (int i = 0; i < SUB; i++)
	{
		cin >> newStudent->subMarks[i];
		sum += newStudent->subMarks[i];
	}
	newStudent->average = (sum * 1.0) / SUB;

	if (newStudent->average >= 80)
		newStudent->grade = 'A';
	else if (newStudent->average >= 70)
		newStudent->grade = 'B';
	else if (newStudent->average >= 60)
		newStudent->grade = 'C';
	else if (newStudent->average >= 50)
		newStudent->grade = 'D';
	else
		newStudent->grade = 'F';

	prev = cur = first;
	if (first == NULL)
	{
		first = cur = prev = newStudent;
	}
	else if (newStudent->regNo < first->regNo)
	{
		newStudent->next = first;
		first = newStudent;
	}
	else
	{
		while (cur != NULL)
		{
			if (cur->regNo < newStudent->regNo)
			{
				prev = cur;
				cur = cur->next;
			}
			else
			{
				prev -> next = newStudent;
				newStudent->next = cur;
				break;
			}

		}
		if (cur == NULL)
		{
			prev->next = newStudent;
		}
	}
}
void myDeletion(student*& first, student*& cur, student*& prev)
{

	int regNo;
	cout << "\n Enter The RegNo Of Student You Want To Delete: ";
	cin >> regNo;

	cur = prev = first;
	if (cur->regNo == regNo)
	{
		first = cur->next;
		delete cur;
		cout << "\n Record Deleted Successfully ..!!!\n";
	}
	else
	{
		while (cur != NULL)
		{
			if (cur->regNo != regNo)
			{
				prev = cur;
				cur = cur->next;
			}
			else
			{
				prev->next = cur->next;
				delete cur;
				cout << "\n Record Deleted Successfully ..!!!\n";
				break;
			}
		}
		if (cur == NULL)
			cout << "\n RegNo Not Found ...!!!\n";
	}
}
void mySort(student* first, student* cur, student* prev)
{

	cur = prev = first;
	while (prev->next != NULL)
	{
		cur = prev->next;
		while (cur != NULL)
		{
			if (prev->regNo > cur->regNo)
			{
				swap(prev->regNo, cur->regNo);
				swap(prev->name, cur->name);
				for (int i = 0; i < SUB; i++)
				{
					swap(prev->subMarks[i], cur->subMarks[i]);
				}
				swap(prev->average, cur->average);
				swap(prev->grade, cur->grade);
			}
			else
			{
				cur = cur->next;
			}
		}
		prev = prev->next;
	}
	cout << "\n Sort The Record Successfully ..!!!\n";
}
void myUpdate(student* first, student* cur)
{
	int regNo;
	cout << "\n Enter The RegNo Of Student You Want To Update: ";
	cin >> regNo;

	while (cur != NULL)
	{
		if (cur->regNo != regNo)
		{
			cur = cur->next;
		}
		else
		{
			int sum = 0;
			cout << " RegNo: " << cur->regNo << endl;

			cin.ignore(10, '\n');
			cout << " Enter Name: ";
			getline(cin, cur->name);
			cout << " Enter Marks: ";
			for (int i = 0; i < SUB; i++)
			{
				cin >> cur->subMarks[i];
				sum += cur->subMarks[i];
			}
			cur->average = (sum * 1.0) / SUB;

			if (cur->average >= 80)
				cur->grade = 'A';
			else if (cur->average >= 70)
				cur->grade = 'B';
			else if (cur->average >= 60)
				cur->grade = 'C';
			else if (cur->average >= 50)
				cur->grade = 'D';
			else
				cur->grade = 'F';

			cout << "\n Record Updated Successfully ..!!!\n";
			break;
		}
	}
	if (cur == NULL)
		cout << "\n RegNo Not Found ...!!!\n";
	

}
int main() {
	student* first = NULL;
	student* cur = NULL;
	student* prev = NULL;
	
	char ch;
	while (true) {
		cout << "\n ------------(MAIN MENU)-----------\n";
		cout << " 1) CREATE DATABASE \n";
		cout << " 2) GETTER \n";
		cout << " 3) INSERTION \n";
		cout << " 4) DELETION \n";
		cout << " 5) UPDATION \n";
		cout << " 6) SORTING \n";
		cout << " 7) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			createDB(first, cur, prev);
			break;
		case '2':
			if (first == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Getter Operation ....\n";
			else
				myGetter(first, cur);
			break;
		case '3':
			myInsertion(first, cur, prev);
			break;
		case '4':
			if (first == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Delete Operation ....\n";
			else
				myDeletion(first, cur, prev);
			break;
		case '5':
			if (first == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Update Operation ....\n";
			else
				myUpdate(first, cur);
			break;
		case '6':
			if (first == NULL)
				cout << "\n Database Is Empty.\n First Create Database Then Perfom Sort Operation ....\n";
			else
				mySort(first, cur, prev);
			break;
		case '7':
			exit(-1);
			break;
	
		}

	}




}