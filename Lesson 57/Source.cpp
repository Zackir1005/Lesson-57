#include <iostream>
#include <string>
#include <fstream> // file stream (�������� �����). ����., ����������� �������� � ��������,������������������ �������
// ������ - �������� ����� ��������, ������� ��������� � ���� ���� � ������
using namespace std;

// ofstream - output file stream 
// ifstream - input file stream 
// fstream - file stream 

/* 
  ������ �������� ����� ��� ������:
  1. �������� ���� � �����;
  2. ��� ������� ��� �������� �����;
  3. ���� �������.
   ������ �������� ����� ��� ������:
   1. �������� ���� � �����;
   2. ��� ������� ��� �������� �����;
   3.����� �� ����������;
   ������ �������� �����:
   1. �������� ���� � �����;
   2. ��� ������� ��� �������� �����;
   3.����� �� ����������;
   4. ���� �������.
*/

bool statistic(string& word);
void printFile();
void clear();

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	/*string path = "file.txt"; // ���� � �����
	//  ������ � ���� - ofstream
	//����������� ������ - �����, ������� �����������, ����� ��������
	ofstream out /*(path)* /;
	out.open(path, ios::out); //��������� ����. �a�� �������� ���� ���� ��� ��� 
	if (out.is_open()) {
		cout << "���� ������ ��� ������.\n";
		string str;
		cout << "������� ������:\n";
		getline(cin, str);
		out << str + "\n"; //��������� ������ str � ����
		cout << "������ �������� � ����.\n";
		out << "Bye!\n"; //��������� ������ Bye!\n � ���� 
	}
	else
		cout << "������ �������� �����.\n";

	out.close(); // ��������� ����

	//������ �� ����� - ifstream
	ifstream in/*(path)* /;
	in.open(path); //�������� ������������� ����� ��� ������

	if (in.is_open()) {
		cout << "���� ������ ��� ������.\n";
		string fileStr;
		// ������������ ����������
		/*char sym;
		while (in.get(sym))
			fileStr += sym;
		cout << fileStr;* /
		// ��������� ����������
		/*while (!in.eof()) { //end of file
			string str;
			in >> str;
			fileStr += str + "\n";
		}* /
		// ���������� ����������
		/*while (!in.eof()) { //end of file
			string tmp;
			getline(cin, path);
			fileStr += tmp + "\n";
		}* /
		cout << fileStr;
	}
	else
		cout << "������ �������� �����.\n";

	in.close();

	if (!remove("file.txt"))
		cout << "���� �����.\n";
	else
		cout << "������ �������� �����.\n";*/

	//������ 1
	cout << "������ 1.\n������� �����: ";
	int answer;
	do {
		cout << "�������� ��������:\n";
		cout << "1.�������� ����;\n";
		cout << "2.�������� ���������� �����;\n";
		cout << "3.�������� ����;\n";
		cout << "4.��������� ������;\n";
		cout << "����--> ";
		cin >> answer;
		string str;
		switch (answer) {
		case 1:
			cin >> str;
			cin.ignore();
			if (statistic(str))
				cout << "����� ��������.\n";
			else
				cout << "����� �� ��������.\n";
			break;
		case 2:
			cout << "���������� �����:\n";
			printFile();
			break;
		case 3:
			clear();
			cout << "���� ������.\n";
			break;
		case 4:
			cout << "���������� ������...\n";
				break;
		default:
			cout << "������ �����!\n";
		}
		system("pause");
		system("cls");
	} while (answer != 4);
	cout << "��������� ���������.\n";

	return 0;
}
//������ ����� � ����
bool statistic(string& word) {
	ofstream out;
	out.open("words.txt", ios::app);
	if (out.is_open()) {
		out << word + " " << word.length() << "\n";
		out.close();
		return true;
	}
	out.close();
	return false;
}
//����� ����������� �����
void printFile() {
	ifstream in;
	in.open("words.txt");
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			cout << sym;
	}
	else
		cout << "������";
}
//�������� �����
void clear() {
	ofstream out;
	out.open("words.txt");
	out.close();
}