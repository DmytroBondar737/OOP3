#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class ModelWindow {
private:
    string title;
    int x, y;           // координати лівого верхнього кута
    int width, height;  // розміри
    string color;
    bool isVisible;
    bool hasBorder;

    // Константи для меж екрана
    static const int SCREEN_WIDTH = 1920;
    static const int SCREEN_HEIGHT = 1080;

    // Метод перевірки меж екрана
    bool isWithinScreen(int newX, int newY, int newWidth, int newHeight) const;

public:
    // ТРИ КОНСТРУКТОРИ:

    // 1. Конструктор з усіма параметрами
    ModelWindow(string t, int posX, int posY, int w, int h, string col, bool visible = true, bool border = true);

    // 2. Конструктор з мінімальними параметрами (тільки заголовок і розміри)
    ModelWindow(string t, int w, int h);

    // 3. Конструктор копіювання
    ModelWindow(const ModelWindow& other);

    // Операції пересування
    void moveHorizontal(int deltaX);
    void moveVertical(int deltaY);

    // Операції зміни розміру
    void resize(int newWidth, int newHeight);
    void setWidth(int newWidth);
    void setHeight(int newHeight);

    // Інші операції
    void setColor(string newColor);
    void toggleVisibility();
    void toggleBorder();

    // Опитування стану
    string getTitle() const;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    string getColor() const;
    bool getVisibility() const;
    bool getBorderState() const;

    // Вивід на екран
    void display() const;
};
