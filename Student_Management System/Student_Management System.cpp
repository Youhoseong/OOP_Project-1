#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student
{
public:
	Student() { nextStudent = NULL; };
	Student(string name, int id, string email, string tel)
	{
		_Name = name;
		_studentID = id;
		_Email = email;
		_Tel = tel;
		nextStudent = NULL;
	}

	string _Name;
	int _studentID;
	string _Email;
	string _Tel;

	Student* nextStudent;

	void showInfo()
	{
		cout << _Name << "\t" << _studentID << "\t" << _Email << "\t" << _Tel << "\n";
	}

};

class studentInfo
{
public:
	Student* head;
	Student* tail;

	studentInfo() { head = NULL; tail = NULL; };

	void append(Student* newStudent)
	{

		if (head == NULL)
		{
			head = newStudent;
			tail = head;
		}
		else
		{
			tail->nextStudent = newStudent;
			tail = newStudent;
		}

		length++;
		//showList();
	}

	int getLength() { return length; }

	Student getStudent(int index)
	{
		Student* temp = head;
		for (int i = 0; i < index; i++)
			temp = temp->nextStudent;

		return *temp;
	}

	void showList()
	{
		Student* temp = head->nextStudent;
		while (!temp == NULL)
		{
			cout << temp->_Name << "\n";
			temp = temp->nextStudent;
		}
	}
private:
	int length = -1;

};

class StudentManager
{
public:
	void Insert(studentInfo* list)
	{
		//새로운 노드 추가시 사용될 임시저장 변수들
		string tempName;
		int tempID;
		string tempEmail;
		string tempTel;

		//정보입력받고 파일 쓰기 테스트, 추후 클래스 내 멤버함수 형태로 변환 예정
		cout << "\nName : ";
		cin >> tempName;
		cout << "ID : ";
		cin >> tempID;
		cout << "Email : ";
		cin >> tempEmail;
		cout << "Tel : ";
		cin >> tempTel;

		Student* newStudent = new Student(tempName, tempID, tempEmail, tempTel);
		list->append(newStudent);
	}

	void Seaech()
	{

	}

	void Sort()
	{

	}
};

int main()
{
	//상태 입력 변수
	int inputNum;
	//파일 객체
	ifstream _fileIn;
	ofstream _fileOut;

	studentInfo* list = new studentInfo();	//프로그램 실행 내 학생 정보 관련 연산들을 실행할 정보들을 모아둔 리스트

	StudentManager _studentmanager;			//연산을 수행할 함수들을 모아둔 객체


	//시작하자마자 텍스트 파일에 있던 정보들을 리스트로 옮기기
	_fileIn.open("test.txt", ios::in);
	_fileIn.seekg(0, ios::beg);

	while (!_fileIn.eof())
	{
		Student* newstudent = new Student();
		_fileIn >> newstudent->_Name >> newstudent->_studentID >> newstudent->_Email >> newstudent->_Tel;
		list->append(newstudent);
	}
	_fileIn.close();
	//

	cout << "1. Insertion\n2. Search\n3. Sorting Option\n4. Exit\n";
	cin >> inputNum;

	//입력값에 따라 연산 시행
	while (inputNum != 4)
	{
		if (inputNum == 1)
		{
			_studentmanager.Insert(list);
		}
		else if (inputNum == 2)
		{

		}
		else if (inputNum == 3)
		{

		}
		else if (inputNum == 4)
		{

		}
		else
		{
			std::cout << "Error! Put the right Number(1~4)";
		}

		cin >> inputNum;
	}


	//쓰기형식으로 열기
	_fileOut.open("test.txt", ios::out);
	//
	//연산된 리스트 파일에 한꺼번에 쓰기
	_fileOut << list->getStudent(1)._Name << " " << list->getStudent(1)._studentID << " " << list->getStudent(1)._Email << " " << list->getStudent(1)._Tel << "\n";

	int t_length = list->getLength();
	for (int i = 1; i < t_length + 1; i++)
	{
		if (i == t_length)
			_fileOut << list->getStudent(i)._Name << " " << list->getStudent(i)._studentID << " " << list->getStudent(i)._Email << " " << list->getStudent(i)._Tel;
		else
			_fileOut << list->getStudent(i)._Name << " " << list->getStudent(i)._studentID << " " << list->getStudent(i)._Email << " " << list->getStudent(i)._Tel << "\n";
	}
	_fileOut.close();
}


