#include<iostream>
#include<list>
#include<iomanip>
#include<windows.h>

using namespace std;

void insertAfterNegatives(list<double>& dlist) {
    auto firstPositiveIt = dlist.end();
    for (auto it = dlist.begin(); it != dlist.end(); ++it) {
        if (*it > 0) {
            firstPositiveIt = it;
            break;
        }
    }

    if (firstPositiveIt == dlist.end()) {
        return;
    }

    for (auto it = dlist.begin(); it != dlist.end(); ) {
        if (*it < 0) {
            it = dlist.insert(++it, *firstPositiveIt);
        }
        ++it;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    list<double> dlist;
    int n;

    cout << "������ ������� �������� ������: ";
    cin >> n;

    cout << "������ " << n << " ������ �����:" << endl;
    for (int i = 0; i < n; ++i) {
        double value;
        cin >> value;
        dlist.push_back(value);
    }

    insertAfterNegatives(dlist);

    cout << "������� ������:" << endl;
    for (const auto& value : dlist) {
        cout << fixed << setprecision(2) << value << " ";
    }
    cout << endl;

    return 0;
}
