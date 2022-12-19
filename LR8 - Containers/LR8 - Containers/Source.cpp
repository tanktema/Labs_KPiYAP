#include <iostream>
#include <string>

using namespace std;


template <typename T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node(T data) : data(data), next(nullptr) {}
    
};



template <typename T>
class ListOne
{
public:
    Node<T>* first;
    Node<T>* last;

    ListOne() : first(nullptr), last(nullptr) {}
   
    
    bool empty_list()
    {
        return first == nullptr;
    }
   
    void push_back(T value)
    {
        Node<T>* newnode = new Node<T>(value);
        if (empty_list())
        {
            first = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }

    void remove_last()
    {
        if (empty_list())
        {
            cout << "Список пуст!" << endl;
        }
        Node<T>* p = first;
        while (p->next != last)
            p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }
    void remove(T value) {
        if (empty_list()) return;

        Node<T>* slow = first;
        Node<T>* fast = first->next;
        while (fast && fast->data != value) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "Такого элемента не существует!" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    void print_list()
    {
        if (empty_list()) return;
        Node<T>* p = first;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;   
    }

};

int main()
{
    system("chcp 1251");
    ListOne<int> list;
    bool menu = 0;
    int menu_checker, menu_input;
    while (menu == 0)
    {
        cout << "Список: \n1 - Добавить значение\n2 - Удалить последнее значение\n3 - Удалить значение\n4 - Вывод списка\n5 - Выход" << endl;
        cin >> menu_checker;
        switch (menu_checker)
        {
        case 1:
            cin >> menu_input;
            list.push_back(menu_input);
            break;
        case 2:
            list.remove_last();
            break;
        case 3:
            cin >> menu_input;
            list.remove(menu_input);
            break;
        case 4:
            list.print_list();
            break;
        case 5:
            menu = 1;
            break;
        }
    }
        
    return 0;
}
