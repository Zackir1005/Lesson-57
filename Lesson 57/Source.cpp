#include <iostream>
#include <string>
#include <fstream> // file stream (файловый поток). Библ., позволяющая работать с классами,взаимодействующими файлами
// Классы - описания групп объектов, которые содержать в себе поля и методы
using namespace std;

// ofstream - output file stream 
// ifstream - input file stream 
// fstream - file stream 

/* 
  Ошибки открытия файла для записы:
  1. Неверный путь к файлу;
  2. Нет доступа для открытия файла;
  3. Файл открыть.
   Ошибки открытия файла для чтение:
   1. Неверный путь к файлу;
   2. Нет доступа для открытия файла;
   3.Файла не существует;
   Ошибки удаления файла:
   1. Неверный путь к файлу;
   2. Нет доступа для открытия файла;
   3.Файла не существует;
   4. Файл открыть.
*/

bool statistic(string& word);
void printFile();
void clear();

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	/*string path = "file.txt"; // путь к файлу
	//  Запись в файл - ofstream
	//Конструктор класса - метод, который выполняется, когда создаётся
	ofstream out /*(path)* /;
	out.open(path, ios::out); //Открываем файл. Фaйл создаётся даже если его нет 
	if (out.is_open()) {
		cout << "Файл открыт для записы.\n";
		string str;
		cout << "Введите строку:\n";
		getline(cin, str);
		out << str + "\n"; //помещение строки str в файл
		cout << "Запись помещена в файл.\n";
		out << "Bye!\n"; //помещение строки Bye!\n в файл 
	}
	else
		cout << "Ошибка открытия файла.\n";

	out.close(); // Закрываем файл

	//Чтение из файла - ifstream
	ifstream in/*(path)* /;
	in.open(path); //открытие существующего файла для чтение

	if (in.is_open()) {
		cout << "Файл открыт для чтения.\n";
		string fileStr;
		// Посимвольное считывание
		/*char sym;
		while (in.get(sym))
			fileStr += sym;
		cout << fileStr;* /
		// Пословное считывание
		/*while (!in.eof()) { //end of file
			string str;
			in >> str;
			fileStr += str + "\n";
		}* /
		// Построчное считывание
		/*while (!in.eof()) { //end of file
			string tmp;
			getline(cin, path);
			fileStr += tmp + "\n";
		}* /
		cout << fileStr;
	}
	else
		cout << "Ошибка открытия файла.\n";

	in.close();

	if (!remove("file.txt"))
		cout << "Файл удалён.\n";
	else
		cout << "Ошибка удаление файла.\n";*/

	//Задача 1
	cout << "Задача 1.\nВведите слово: ";
	int answer;
	do {
		cout << "Виберите действие:\n";
		cout << "1.Записать файл;\n";
		cout << "2.Показать содержимое файла;\n";
		cout << "3.Очистить файл;\n";
		cout << "4.Завершить работу;\n";
		cout << "Ввод--> ";
		cin >> answer;
		string str;
		switch (answer) {
		case 1:
			cin >> str;
			cin.ignore();
			if (statistic(str))
				cout << "Слово записано.\n";
			else
				cout << "Слово не записано.\n";
			break;
		case 2:
			cout << "Содержимое файла:\n";
			printFile();
			break;
		case 3:
			clear();
			cout << "Файл очищен.\n";
			break;
		case 4:
			cout << "Завершение работы...\n";
				break;
		default:
			cout << "Ошибка ввода!\n";
		}
		system("pause");
		system("cls");
	} while (answer != 4);
	cout << "Программа завершена.\n";

	return 0;
}
//Запись слова в файл
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
//Вывод содержимого файла
void printFile() {
	ifstream in;
	in.open("words.txt");
	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			cout << sym;
	}
	else
		cout << "Ошибка";
}
//Очищение файла
void clear() {
	ofstream out;
	out.open("words.txt");
	out.close();
}