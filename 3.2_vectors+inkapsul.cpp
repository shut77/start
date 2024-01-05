

#include <iostream> 
#include <cmath> 
using namespace std;

class Vector {
private: 
    double x;
    double y;
    double z, kk;

public:
    Vector() { 
    }
    Vector(double a, double b, double c) { 
        x = a; y = b; z = c;
    }

    // методы для арифметических операций
    Vector summa(Vector b) {
        Vector res;
        res.x = x + b.x;
        res.y = y + b.y;
        res.z = z + b.z;

        return res;
    }

    Vector razn(Vector b) {
        Vector res;
        res.x = x - b.x;
        res.y = y - b.y;
        res.z = z - b.z;

        return res;
    }

    Vector  scalar_ymnozen(Vector b) {
        Vector res;
        res.kk = x * b.x + y * b.y + z * b.z;
        return res;
    }


    Vector vect_ymnozen(Vector b) {
        Vector res;
        res.x = y * b.z - z * b.y; // индекс  i
        res.y = -(x * b.z - z * b.x); // индекс j
        res.z = x * b.y - y * b.x; // индекс k

        return res;
    }

    double dlina() { 
        return sqrt(x * x + y * y + z * z); 
    }

    double ygol(Vector b) { 
        return (x * b.x + y * b.y + z * b.z) / (dlina() * b.dlina());
    }

    void print() {
        cout << "Вектор:  (" << x << ", " << y << ", " << z << ")" << endl;
    }

    void prin_sc() {
        cout << "Скалярн. произв. равноo = " << kk << endl;
    }

    void prin_yg(Vector b) {
        cout << "Угол между векторами равен = " << acos(ygol(b)) * 180 / 3.14 << " градусов" << endl; 
    }
     
    void print_vect_ym() {
        cout << x << "i ";
        int d = 1, f = 1;
        if (y < 0) {
            cout << y << "j ";
        }
        else { cout << "+" << y << "j "; }

        if (z < 0) {
            cout << z << "k ";
        }
        else { cout << "+" << z << "k "; }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    int n = 0;

    Vector a, b, res;

    while (n != 9) {
        cout << "Программа работает, что делаем:  " << endl;
        cout << "1. Вводим первый вектор " << endl;
        cout << "2. Вводим второй вектор " << endl;
        cout << "3. Сумма " << endl;
        cout << "4. Разность " << endl;
        cout << "5. Скалярное Умножение " << endl;
        cout << "6. Векторное умножение " << endl;
        cout << "7. Длина векторов " << endl;
        cout << "8. Угол между векторами.(финалочка)" << endl;
        cout << "9. Заканчиваем. фух" << endl;

        cin >> n;

        switch (n) {
        case 1:
            double ax, ay, az; 
            cout << "Введите первый вектор:  ";
            cin >> ax >> ay >> az;
            a = Vector(ax, ay, az); //в конструктор с параметрами
            break;
        case 2:
            double bx, by, bz; 
            cout << "Введите второй вектор: ";
            cin >> bx >> by >> bz;
            b = Vector(bx, by, bz); //в конструктор с параметрами
            break;
        case 3:
            res = a.summa(b);
            cout << "Ответ:  ";
            res.print();
            break;
        case 4:
            res = a.razn(b);
            cout << "Ответ:  ";
            res.print();
            break;
        case 5:
            res = a.scalar_ymnozen(b);
            res.prin_sc();
            break;
        case 6:
            res = a.vect_ymnozen(b);
            cout << "Ответ: ";
            res.print_vect_ym();
            break;
        case 7:
            cout << "Длина первого вектора = " << a.dlina() << endl;
            cout << "Длина второго вектора = " << b.dlina() << endl;
            break;
        case 8:
            a.prin_yg(b);
            break;
        case 9:
            cout << "Пока пока" << endl;
            break;
        default:
            cout << "Такой программы еще не существует" << endl; //исправляем опечатку
        }
    }

    return 0;
}
