#include <iostream>
#include <cmath>

// Создание класса Point для представления точек в трехмерном пространстве
class Point {
public:
    // Конструктор класса Point, принимает координаты точки
    Point(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    // Геттеры для получения координат точки
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }
private:
    double x, y, z;
};

// Создание класса Vector для представления векторов в трехмерном пространстве
class Vector
{
public:
    // Методы для получения координат вектора
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    // Конструктор класса Vector, принимает координаты вектора
    Vector(double x1, double y1, double z1)
    {
        x = x1;
        y = y1;
        z = z1;
    }

    // Конструктор класса Vector, принимает две точки и создает вектор между ними
    Vector(Point point1, Point point2)
    {
        // Вычисляем координаты вектора по координатам точек
        x = point2.getX() - point1.getX();
        y = point2.getY() - point1.getY();
        z = point2.getZ() - point1.getZ();
    }

    // Далее идут методы для выполнения операций с векторами

// Сложение векторов.
    Vector vectorAddition(Vector otherVector)
    {
        return Vector(x + otherVector.x, y + otherVector.y, z + otherVector.z);
    }
    // Вычитание векторов.
    Vector vectorSubtraction(Vector otherVector)
    {
        return Vector(x - otherVector.x, y - otherVector.y, z - otherVector.z);
    }

    // Вычисление обратного вектора
    Vector negativeVector()
    {
        return Vector(-x, -y, -z);
    }
    // Вычисление длины вектора
    double length()
    {
        return sqrt(x * x + y * y + z * z);
    }

    // Вычисление единичного вектора
    Vector unitVector()
    {
        double len = length();
        if (len > 0)
        {
            return Vector(x / len, y / len, z / len);
        }
        else
        {
            return *this;
        }
    }

    // Вычисление скалярного произведения с другим вектором
    double scalarProduct(Vector otherVector)
    {
        return x * otherVector.getX() + y * otherVector.getY() + z * otherVector.getZ();
    }

    // Вычисление векторного произведения с другим вектором
    Vector vectorProduct(Vector otherVector)
    {
        return Vector(
            y * otherVector.getZ() - z * otherVector.getY(),
            z * otherVector.getX() - x * otherVector.getZ(),
            x * otherVector.getY() - y * otherVector.getX()
        );
    }
    // Вычисление смешанного произведения с другими векторами
    double mixedProduct(Vector otherVector1, Vector otherVector2)
    {
        return this->scalarProduct(otherVector1.vectorProduct(otherVector2));
    }

    // Проверка, коллинеарен ли вектор другому вектору
    bool isCollinear(Vector otherVector)
    {
        // Векторы коллинеарны, если их векторное произведение равно нулю
        return this->vectorProduct(otherVector).length() == 0;
    }

    bool isCoplanar(Vector otherVector1, Vector otherVector2)
    {
        // Три вектора компланарны, если их смешанное произведение равно нулю
        return this->mixedProduct(otherVector1, otherVector2) == 0;
    }


    // Вычисление угла между векторами
    double angleWith(Vector otherVector)
    {
        double scalarProd = scalarProduct(otherVector);
        double len1 = length();
        double len2 = otherVector.length();
        // Вычисление угла между векторами по формуле
        return 57.2958 * acos(scalarProd / (len1 * len2));
    }
private:
    double x, y, z;// Координаты вектора оставили приватными
};
int main()
{
    double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;


    // Ввод координат первой точки.
    std::cout << "Enter the coordinates of the first point:";//введем координаты первой точки 
    std::cin >> x1 >> y1 >> z1;
    // Ввод координат второй точки.
    std::cout << "Enter the coordinates of the second point: ";//введем координаты второй точки 
    std::cin >> x2 >> y2 >> z2;
    // Ввод координат второго вектора.
    std::cout << "Enter the coordinates of the second vector: ";//введем координаты второго вектора 
    std::cin >> x3 >> y3 >> z3;
    // Ввод координат третьего вектора.
    std::cout << "Enter the coordinates of the third vector: ";//введем координаты третьего вектора
    std::cin >> x4 >> y4 >> z4;


    // Создание объектов классов Point и Vector с заданными координатами.
    Point point1(x1, y1, z1);
    Point point2(x2, y2, z2);

    Vector vector1(point1, point2);
    Vector vector2(x3, y3, z3);
    Vector vector3(x4, y4, z4);

    // Вывод координат векторов
    std::cout << "Vector 1: " << vector1.getX() << " " << vector1.getY() << " " << vector1.getZ() << std::endl;
    std::cout << "Vector 2: " << vector2.getX() << " " << vector2.getY() << " " << vector2.getZ() << std::endl;
    std::cout << "Vector 3: " << vector3.getX() << " " << vector3.getY() << " " << vector3.getZ() << std::endl;

    // Выполнение операций над векторами:

// Сложение векторов.
    Vector sum = vector1.vectorAddition(vector2);

    // Вычитание векторов.
    Vector difference = vector1.vectorSubtraction(vector2);

    // Получение обратного вектора.
    Vector negative = vector1.negativeVector();

    // Получение единичного вектора.
    Vector unit = vector1.unitVector();

    // Вычисление скалярного произведения векторов.
    double scalarProd = vector1.scalarProduct(vector2);

    // Вычисление векторного произведения векторов.
    Vector vectorProd = vector1.vectorProduct(vector2);

    // Вычисление смешанного произведения векторов.
    double mixedProd = vector1.mixedProduct(vector2, vector3);

    // Проверка коллинеарности векторов.
    bool collinear = vector1.isCollinear(vector2);

    // Проверка компланарности векторов.
    bool coplanar = vector1.isCoplanar(vector2, vector3);

    // Вычисление угла между векторами.
    double angle = vector1.angleWith(vector2);
    // Вывод результатов операций над векторами.
    std::cout << "Addition: " << sum.getX() << " " << sum.getY() << " " << sum.getZ() << std::endl;//Сложение
    std::cout << "Subtraction: " << difference.getX() << " " << difference.getY() << " " << difference.getZ() << std::endl;//Вычитание
    std::cout << "Reverse vector: " << negative.getX() << " " << negative.getY() << " " << negative.getZ() << std::endl; //Обратный вектор
    std::cout << "Unit vector:" << unit.getX() << " " << unit.getY() << " " << unit.getZ() << std::endl;// Единичный вектор
    std::cout << "Scalar product: " << scalarProd << std::endl;// Скалярное произведение
    std::cout << "Vector product: " << vectorProd.getX() << " " << vectorProd.getY() << " " << vectorProd.getZ() << std::endl; //Векторное произведение
    std::cout << "Mixed work: " << mixedProd << std::endl; //Смешанное произведение
    std::cout << "Collinear: " << (collinear ? "Yes" : "No") << std::endl; //Коллинеарны, да или нет
    std::cout << "Are coplanar: " << (coplanar ? "Yes" : "No") << std::endl; //Компланарны, да или нет
    std::cout << "Angle between vectors: " << angle << " degrees" << std::endl; //Угол между векторами

    return 0;
}