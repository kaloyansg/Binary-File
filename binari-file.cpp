#include <iostream>
#include <fstream>
#include "Customer.h"

int getFileMax(const char* fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file)
        throw "File not found!";

    int result = INT_MIN;

    int num;
    file.read((char*)&num, sizeof(num));
    while (!file.eof())
    {
        if (result < num)
            result = num;
        file.read((char*)&num, sizeof(num));
    }
    file.close();
    return result;
}

struct Order
{
    double price;
    double vat;
    int customerID;
};

//struct Customer
//{
//    int id;
//    unsigned orders;
//    double spentMoney;
//    double mostExpenciveOrder;
//};

void addOrder(Order*& orders, size_t& size, size_t& capacity, const Order& newOrder)
{
    if (size == capacity)
    {
        Order* temp = new (std::nothrow) Order[size * 2];
        if (!temp)
        {
            std::cerr << "Not enough memory!";
            return;
        }
        for (size_t i = 0; i < size; ++i)
        {
            temp[i] = orders[i];
        }
        delete[] orders;
        orders = temp;
        capacity *= 2;
    }
    orders[size] = newOrder;    
    ++size;
}

void getOrders(Order*& orders, size_t& size, size_t& capacity, const char* fileName)
{
    std::ifstream file(fileName, std::ios::binary);
    if (!file)
    {
        std::cerr << "File not found!\n";
        return;
    }

    Order tempOrder;

    file.read((char*)&tempOrder, sizeof(tempOrder));
    while (!file.eof())
    {
        addOrder(orders, size, capacity, tempOrder);

        file.read((char*)&tempOrder, sizeof(tempOrder));
    }
}

int main()
{
    //std::cout << getFileMax("numbers.dat") << '\n'; //reding number from binary file

    /*Order* orders = new Order[1]; //reding order from binary file and saving the information in an array
    size_t ordersSize = 0;
    size_t ordersCapacity = 1;
    getOrders(orders, ordersSize, ordersCapacity, "storeOrders.dat");
    delete[] orders; */

    size_t nameSize;
    /*Customer customers[3]; //saving customers info in a binary file
    customers[0].setName("Kaloyan");
    customers[0].setId(0);
    customers[0].setAge(20);
    customers[1].setName("Pesho");
    customers[1].setId(1);
    customers[1].setAge(45);

    std::ofstream writingFile("customers.dat", std::ios::binary);
    for (size_t i = 0; i < 3; ++i)
    {
        nameSize = strlen(customers[i].getName())+1;
        writingFile.write((const char*)&nameSize, sizeof(nameSize));
        writingFile.write(customers[i].getName(), nameSize);
        writingFile.write((const char*)&customers[i], sizeof(Customer));
    }
    writingFile.close();*/


    std::ifstream readingFile("customers.dat", std::ios::binary); //reding customers from binary file
    if (!readingFile)
        return -1;
    Customer currCustomer;
    char* name;
    readingFile.read((char*)&nameSize, sizeof(nameSize));

    while (!readingFile.eof())
    {
        name = new char[nameSize];
        readingFile.read(name, nameSize);
        readingFile.read((char*)&currCustomer, sizeof(Customer));
        currCustomer.addName(name);
        delete[] name;
        std::cout << currCustomer << '\n';
        readingFile.read((char*)&nameSize, sizeof(nameSize));
    }
    

    readingFile.close();
}