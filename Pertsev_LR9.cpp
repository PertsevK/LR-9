#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int max_size = 200; // Максимальний розмір строки

void Task1(); // string& erase (size_t pos = 0, size_t len = npos);

void Task2(); // Дано рядок. Якщо він є записом цілого числа, то вивести 1, якщо
// дійсного(з дробовою частиною) - вивести 2; якщо рядок не можна
// перетворити в число, то вивести 0. Вважати, що дробова частина
// дійсного числа відокремлюється від його цілої частини десятковою точкою «.».

void my_method(char*, int, int); // Функція видалення символів зі строки
void search_dots(string&); // Функція введення даних
bool is_valid(string str); // Функція перевірки даних

bool cor_main(int); // Допоміжнi функції

int main()
{ // Перемикання між завданнями
    setlocale(LC_ALL, "Ukrainian");
    int num; // Оголошення
    do
    {
        cout << "Введiть номер завдання (вихiд - 3)\n";
        cin >> num; // Введення даних
        if (cor_main(num))
        {
            switch (num)
            {
            case 1: Task1(); break; // Завдання 1
            case 2: Task2(); break; // Завдання 2
            case 3: cout << "Вихiд..."; break;
            }
        }
        else cout << "Помилка. Потрiбно ввести 1, 2, 3\n"; // Повідомлення про помилку
    } while (num != 3);
}

bool cor_main(int n) // Допоміжна
{
    if (n == 1 || n == 2 || n == 3) return true;
    else return false;
}

void Task1()
{
    int pos, len; 
    char text[max_size];
    cout << "Введiть строку\n";
    cin >> text;
    string str = text;
    cout << "Введiть pos та len\n";
    cin >> pos >> len;
    cout << "Вихiдний рядок -> " << str << endl;
    str = str.erase(pos, len);
    cout << "Результат (string) -> " << str << endl;
    my_method(text, pos, len);
    cout << "Результат -> " << str << endl;
}

void my_method(char* source_s, int pos, int len) // Свій метод видалення символів зі строки
{
    for (int k = pos; k <= pos + len;k++)
    {
        source_s[k] = source_s[k + len];
        source_s[k + len] = ' ';
    }
}

void Task2()
{
    char filename[max_size] = "input.txt"; // Назва вихідного файлу
    string number;
    ifstream fin(filename);
    while (getline(fin, number)) // Цикл проходження по строкам файлу
        search_dots(number);
    fin.close(); // Закриття файлу
}

void search_dots(string& str)
{
    char filename[max_size] = "output.txt"; // Ім'я файлу для виведення
    ofstream fout(filename, ios_base::app);
    try {
        if (is_valid(str)) // Чи є точка в строці?
        {
            double resd = stod(str); // Якщо в строці число з плаваючою точкою
            cout << "2- " << resd << endl; // Виведення в консоль
            fout << "2- " << resd << endl; // Виведення в файл
        }
        else
        {
            int resi = stoi(str); // Якщо в строці ціле число
            cout << "1- " << resi << endl; // Виведення в консоль
            fout << "1- " << resi << endl; // Виведення в файл
        }
    }
        catch (invalid_argument e) { // Якщо в строці не число
            cout << "0- " << str << endl; // Виведення в консоль
            fout << "0- " << str << endl; // Виведення в файл
        }
    fout.close(); // Закриття файлу
}

bool is_valid(string str) // Пошук точки в строці
{
    if (!str[0]) return false;
    for (int i = 0; str[i]; i++) {
        if (str[i] == ',') return true;
    }
    return false;
}