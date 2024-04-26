// AbstractFactory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//Задача
/*
Используя паттерн AbstractFactory запрограммируйте следующую
задачу. Есть два вида застройки: высокой и низкой этажности. Высокоэтажная застройка
подразумевает создание жилых домов (9-20 этажей) и офисов (12-20 этажей). Низкоэтажная
застройка подразумевает создание жилых коттеджей (1-2 этажа) и школ (1-4 этажа).
Напишите соответствующие иерархии классов (или структур) для жилых (дома, коттеджи) и
нежилых помещений (офисы, школы), напишите соответствующие фабрики для
низкоэтажной и высокоэтажной застройки. Продемонстрируйте применение фабрик в
программе
*/
#include <iostream>

// Абстрактный класс для жилых зданий
class ResidentialBuilding {
public:
    virtual void type() = 0;
};

// Классы для конкретных типов жилых зданий
class House : public ResidentialBuilding {
public:
    void type()  {
        std::cout << "  Дом" << std::endl;
    }
};

class Cottage : public ResidentialBuilding {
public:
    void type()  {
        std::cout << "  Коттедж" << std::endl;
    }
};

// Абстрактный класс для нежилых зданий
class NonResidentialBuilding {
public:
    virtual void type() = 0;
};

class Office : public NonResidentialBuilding {
public:
    void type()  {
        std::cout << "  Офис" << std::endl;
    }
};

class School : public NonResidentialBuilding {
public:
    void type() {
        std::cout << "  Школа" << std::endl;
    }
};

// Абстрактная фабрика
class BuildingFactory {
public:
    virtual ResidentialBuilding* createResidentialBuilding() = 0;
    virtual NonResidentialBuilding* createNonResidentialBuilding() = 0;
};

// Конкретная Фабрика для низкоэтажной застройки
class LowBuildingFactory : public BuildingFactory {
public:
    ResidentialBuilding* createResidentialBuilding() {//конкретный продукт
        return new Cottage();
    }

    NonResidentialBuilding* createNonResidentialBuilding()  {//конкретный продукт
        return new School();
    }
};

//Конкретная Фабрика для высокоэтажной застройки
class HighBuildingFactory : public BuildingFactory {
public:
    ResidentialBuilding* createResidentialBuilding() {//конкретный продукт
        return new House();
    }

    NonResidentialBuilding* createNonResidentialBuilding(){//конкретный продукт
        return new Office();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    BuildingFactory* lowFactory = new LowBuildingFactory();
    ResidentialBuilding* lowResidential = lowFactory->createResidentialBuilding();
    NonResidentialBuilding* lowNonResidential = lowFactory->createNonResidentialBuilding();
    std::cout << "Низкоэтажные здания" << std::endl;
    lowResidential->type();
    lowNonResidential->type();

    BuildingFactory* highFactory = new HighBuildingFactory();
    ResidentialBuilding* highResidential = highFactory->createResidentialBuilding();
    NonResidentialBuilding* highNonResidential = highFactory->createNonResidentialBuilding();
    std::cout << "Высокоэтажные здания" << std::endl;
    highResidential->type();
    highNonResidential->type();

    delete lowFactory;
    delete lowResidential;
    delete lowNonResidential;

    delete highFactory;
    delete highResidential;
    delete highNonResidential;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
