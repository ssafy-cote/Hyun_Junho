#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
	Student(string& name, int day, int month, int year)
	{
		this->name = name;
		this->day = day;
		this->month = month;
		this->year = year;
	};
	~Student() {};

	string name;
	int year;
	int month;
	int day;
};

bool Compare(Student* s1, Student* s2)
{
	if (s1->year == s2->year)
	{
		if (s1->month == s2->month)
			return s1->day > s2->day;
		else
			return s1->month > s2->month;
	}
	return s1->year > s2->year;
}

int main()
{
	//이름이 같거나, 생일이 같은 사람은 없다.
	int N;
	cin >> N;

	string s = "";
	int dd = 0;
	int mm = 0;
	int yy = 0;
	vector<Student*> vec;

	while (N--)
	{
		cin >> s  >> dd >> mm >> yy;
		Student* student = new Student(s, dd, mm, yy);
		vec.push_back(student);
	}

	sort(vec.begin(), vec.end(), Compare);


	cout << (*vec.begin())->name << '\n';
	cout << (*(--vec.end()))->name;

	for (Student* s : vec)
		delete(s);

}