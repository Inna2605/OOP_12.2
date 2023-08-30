//Дан текстовый файл. Необходимо переписать его строки в другой файл. 
//Порядок строк во втором файле должен совпадать с порядком строк в заданном файле.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    //даний початковий файл Skald
    cout << "Данный текстовый файл Skald\n\n";
    ifstream inf("Skald.txt");
    if (!inf) {
        cerr << "Невозможно открыть файл для чтения!";
        exit(1);
    }
    string strInput;
    while (!inf.eof())
    {
        getline(inf, strInput);
        cout << strInput << endl;
    }
    inf.seekg(0);

   //копіюємо початковий файл Skald в файл Copy
    cout << "\n\nФайл Copy - копия файла Skald\n\n";
    ofstream outf("Copy.txt");
    if (!outf) {
        cerr << "Невозможно открыть файл!";
        exit(1);
    }
    while (getline(inf, strInput)) {
        outf << strInput << endl;
    }

    //виводимо на екран скопійований файл
    ifstream infCopy("Copy.txt");
    if (!infCopy) {
        cerr << "Невозможно открыть файл для чтения!";
        exit(1);
    }
    while (!infCopy.eof())
    {
        getline(infCopy, strInput);
        cout << strInput << endl;
    }
}

