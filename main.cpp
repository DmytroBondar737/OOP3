#include "ModelWindow.h"
#include <Windows.h>

int main() {
    SetConsoleCP(1252);
    SetConsoleOutputCP(1251);
    try {
        cout << "=== ДЕМОНСТРАЦІЯ ТРЬОХ КОНСТРУКТОРІВ ===" << endl << endl;

        // 1. Конструктор з усіма параметрами
        cout << "1. Конструктор з усіма параметрами:" << endl;
        ModelWindow window1("Головне вікно", 100, 150, 800, 600, "синій", true, true);
        window1.display();

        // 2. Конструктор з мінімальними параметрами
        cout << "\n2. Конструктор з мінімальними параметрами:" << endl;
        ModelWindow window2("Допоміжне вікно", 400, 300);
        window2.display();

        // 3. Конструктор копіювання
        cout << "\n3. Конструктор копіювання:" << endl;
        ModelWindow window3(window1);  // створюємо копію window1
        window3.display();

        cout << "\n=== ТЕСТУВАННЯ ФУНКЦІОНАЛУ ===" << endl;
        window1.moveHorizontal(50);
        window1.setColor("зелений");
        window1.toggleVisibility();
        window1.display();

    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    return 0;
}
