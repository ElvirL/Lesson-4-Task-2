/*
Задание 2. Регистратура
Что нужно сделать
Напишите программу «Регистратура».
На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди становятся в очередь, а по запросу Next необходимо 
вызвать в регистратуру человека с фамилией, идущей первой в лексикографическом порядке (по алфавиту), и вывести его фамилию на экран. 
Фамилии пациентов могут повторяться.
Каждый запрос (на добавление и вывод) должен работать за O(logn).

Пример:

? Sidorov
? Ivanov
? Ivanov
? Petrov
? Next
? Ivanov
? Next
? Ivanov
? Next
? Petrov

Чек-лист для проверки задачи
• Программа корректно выводит фамилии в лексикографическом порядке.
• Программа использует только заголовочные файлы <iostream>, <string>, <map>.

Как отправить задание на проверку
Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    map<string,int> registry;
    
    cout << "Введите фамилию (Next) (stop для выхода): " << endl;
    string in_line;
    cin >> in_line;

    while (in_line != "stop"){
        if (in_line == "Next"){
            if (registry.begin()->second > 1){
                cout << registry.begin()->first << endl;
                --registry.begin()->second;
            }
            else {
                cout << registry.begin()->first << endl;
                registry.erase(registry.begin());
            }
        }
        else {
            if (registry.count(in_line)){
                ++registry[in_line];
            }
            else{
                registry[in_line] = 1;
            }
        }
        cout << "Введите фамилию (Next) (stop для выхода): " << endl;
        cin >> in_line;
    }
}