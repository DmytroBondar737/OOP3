#include "ModelWindow.h"

// 1. Конструктор з усіма параметрами
ModelWindow::ModelWindow(string t, int posX, int posY, int w, int h, string col, bool visible, bool border) {
    if (w <= 0 || h <= 0) {
        throw invalid_argument("Розміри вікна повинні бути додатніми");
    }

    title = t;
    x = posX;
    y = posY;
    width = w;
    height = h;
    color = col;
    isVisible = visible;
    hasBorder = border;

    // Перевірка початкового положення
    if (!isWithinScreen(x, y, width, height)) {
        throw invalid_argument("Початкове положення вікна виходить за межі екрана");
    }
}

// 2. Конструктор з мінімальними параметрами
ModelWindow::ModelWindow(string t, int w, int h) {
    if (w <= 0 || h <= 0) {
        throw invalid_argument("Розміри вікна повинні бути додатніми");
    }

    title = t;
    width = w;
    height = h;
    x = 100;  // значення за замовчуванням
    y = 100;  // значення за замовчуванням
    color = "сірий";  // значення за замовчуванням
    isVisible = true;
    hasBorder = true;

    if (!isWithinScreen(x, y, width, height)) {
        throw invalid_argument("Розміри вікна завеликі для екрана");
    }
}

// 3. Конструктор копіювання
ModelWindow::ModelWindow(const ModelWindow& other) {
    title = other.title + " (копія)";
    x = other.x + 20;  // зміщуємо копію трохи праворуч
    y = other.y + 20;  // зміщуємо копію трохи вниз
    width = other.width;
    height = other.height;
    color = other.color;
    isVisible = other.isVisible;
    hasBorder = other.hasBorder;

    // Перевірка, чи копія не виходить за межі екрана
    if (!isWithinScreen(x, y, width, height)) {
        x = other.x;  // якщо виходить - повертаємо оригінальні координати
        y = other.y;
    }
}

// Решта методів залишаються незмінними
bool ModelWindow::isWithinScreen(int newX, int newY, int newWidth, int newHeight) const {
    return (newX >= 0 && newY >= 0 &&
        newX + newWidth <= SCREEN_WIDTH &&
        newY + newHeight <= SCREEN_HEIGHT);
}

void ModelWindow::moveHorizontal(int deltaX) {
    int newX = x + deltaX;
    if (isWithinScreen(newX, y, width, height)) {
        x = newX;
        cout << "Вікно пересунуто по горизонталі на " << deltaX << " пікселів" << endl;
    }
    else {
        throw out_of_range("Пересування виходить за межі екрана по горизонталі");
    }
}

void ModelWindow::moveVertical(int deltaY) {
    int newY = y + deltaY;
    if (isWithinScreen(x, newY, width, height)) {
        y = newY;
        cout << "Вікно пересунуто по вертикалі на " << deltaY << " пікселів" << endl;
    }
    else {
        throw out_of_range("Пересування виходить за межі екрана по вертикалі");
    }
}

void ModelWindow::resize(int newWidth, int newHeight) {
    if (newWidth <= 0 || newHeight <= 0) {
        throw invalid_argument("Розміри повинні бути додатніми");
    }

    if (isWithinScreen(x, y, newWidth, newHeight)) {
        width = newWidth;
        height = newHeight;
        cout << "Розмір вікна змінено на " << newWidth << "x" << newHeight << endl;
    }
    else {
        throw out_of_range("Новий розмір виходить за межі екрана");
    }
}

void ModelWindow::setWidth(int newWidth) {
    resize(newWidth, height);
}

void ModelWindow::setHeight(int newHeight) {
    resize(width, newHeight);
}

void ModelWindow::setColor(string newColor) {
    color = newColor;
    cout << "Колір вікна змінено на: " << newColor << endl;
}

void ModelWindow::toggleVisibility() {
    isVisible = !isVisible;
    cout << "Стан видимості змінено на: " << (isVisible ? "видиме" : "невидиме") << endl;
}

void ModelWindow::toggleBorder() {
    hasBorder = !hasBorder;
    cout << "Стан рамки змінено на: " << (hasBorder ? "з рамкою" : "без рамки") << endl;
}

string ModelWindow::getTitle() const { return title; }
int ModelWindow::getX() const { return x; }
int ModelWindow::getY() const { return y; }
int ModelWindow::getWidth() const { return width; }
int ModelWindow::getHeight() const { return height; }
string ModelWindow::getColor() const { return color; }
bool ModelWindow::getVisibility() const { return isVisible; }
bool ModelWindow::getBorderState() const { return hasBorder; }

void ModelWindow::display() const {
    cout << "=== Інформація про вікно ===" << endl;
    cout << "Заголовок: " << title << endl;
    cout << "Координати: (" << x << ", " << y << ")" << endl;
    cout << "Розміри: " << width << "x" << height << endl;
    cout << "Колір: " << color << endl;
    cout << "Видимість: " << (isVisible ? "видиме" : "невидиме") << endl;
    cout << "Рамка: " << (hasBorder ? "так" : "ні") << endl;
    cout << "=============================" << endl;
}
