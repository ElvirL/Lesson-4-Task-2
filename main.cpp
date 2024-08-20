/*
������� 2. ������������
��� ����� �������
�������� ��������� �������������.
�� ���� ��������� �������� ������ � ��������� ��� ������ Next. ��������� ���� ���������� � �������, � �� ������� Next ���������� 
������� � ������������ �������� � ��������, ������ ������ � ������������������ ������� (�� ��������), � ������� ��� ������� �� �����. 
������� ��������� ����� �����������.
������ ������ (�� ���������� � �����) ������ �������� �� O(logn).

������:

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

���-���� ��� �������� ������
� ��������� ��������� ������� ������� � ������������������ �������.
� ��������� ���������� ������ ������������ ����� <iostream>, <string>, <map>.

��� ��������� ������� �� ��������
�������� ������ �� repl.it ��� ���� .��� � �������� ����� ����� ��� ����� ��������� �������.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    map<string,int> registry;
    
    cout << "������� ������� (Next) (stop ��� ������): " << endl;
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
        cout << "������� ������� (Next) (stop ��� ������): " << endl;
        cin >> in_line;
    }
}