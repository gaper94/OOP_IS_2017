#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#if __cplusplus < 201103L
#define nullptr NULL
#endif

class Point2D
{
public:
   Point2D(int newX = 0, int newY = 0)
       :x(newX), y(newY)
   {
   }

    void SetX(int newX)
    {
        x = newX;
    }

    void SetY(int newY)
    {
        y = newY;
    }

    int GetX() const
    {
        return x;
    }

    int GetY() const
    {
        return y;
    }

    double Distance(const Point2D& otherPoint) const
    {
        return sqrt(pow(GetX() - otherPoint.GetX(), 2) + pow(GetY() - otherPoint.GetY(), 2));
    }

    void PrintInfo() const
    {
        cout << "[" << x << ", " << y << "]";
    }

private:
    int x;
    int y;
};

// Проверявайте винаги за валиден указател
void printString(const char* str)
{
    if (str != nullptr)
    {
        cout << "Printing string \'" << str << "\' with length = " << strlen(str) << endl;
    }
    else
    {
        cout << "Trying to print null pointer!\n";
    }
}

class Order
{
public:
    Order(const char* = "", const char* = "");
    ~Order();

    void SetCustomerName(const char*);
    const char* GetCustomerName() const;

    void SetCustomerAddress(const char*);
    const char* GetCustomerAddress() const;

    long long int GetOrderId() const;
private:
    char* customerName;
    char* customerAddress;
    static long long int ordersCounter;
    const long long int orderId;
};

long long int Order::ordersCounter = 0; // Зануляваме броячът отговарящ за уникалният номер
                                        // на поръчка при всяко стартиране на програмата (дефиниране на статично поле на клас)

Order::Order(const char* customerName, const char* customerAddress)
    : customerName(nullptr), customerAddress(nullptr)
    , orderId(ordersCounter++) // Стойността на констнатни полета, трябва да се укаже в декларацията на класа
                               // или да се подаде стойност в инициализиращият списък
{
    SetCustomerName(customerName);
    SetCustomerAddress(customerAddress);
}

Order::~Order()
{
    delete[] customerName;
    delete[] customerAddress;
}

void Order::SetCustomerName(const char* str)
{
    // Tрябва първо да освободим заетата памет
    delete[] customerName;

    if (str)
    {
        size_t len = strlen(str);
        if (len != 0)
        {
            customerName = new char[len + 1];
            strcpy(customerName, str);
        }
        else
        {
            customerName = new char[1];
            customerName[0] = '\0';
        }
    }
    else
    {
        customerName = new char[1];
        customerName[0] = '\0';
    }
}
const char* Order::GetCustomerName() const
{
    return customerName;
}

void Order::SetCustomerAddress(const char* str)
{
    // Tрябва първо да освободим заетата памет
    delete[] customerAddress;

    if (str)
    {
        size_t len = strlen(str);
        if (len != 0)
        {
            customerAddress = new char[len + 1];
            strcpy(customerAddress, str);
        }
        else
        {
            customerAddress = new char[1];
            customerAddress[0] = '\0';
        }
    }
    else
    {
        customerAddress = new char[1];
        customerAddress[0] = '\0';
    }
}

const char* Order::GetCustomerAddress() const
{
    return customerAddress;
}

long long int Order::GetOrderId() const
{
    return orderId;
}

int main()
{
    char* dynString;
    const char* const message = "We love C";
    int lenMessage = strlen(message);
    dynString = new char[lenMessage + 1]; // Винаги заделяме памет за дължината на низа + 1 заради терминиращата нула
    strcpy(dynString, message);
    printString(dynString);

    const char* const message2 = "We love C++ more";
    int lenMessage2 = strlen(message2);

    delete[] dynString; // Първо трябва да освободим паметта заделена за message
    dynString = new char[lenMessage2 + 1]; // Ако пропуснем да освободим паметта преди да променим
                                           // стойността на dynString, ще загубим адресът на паметта заделена
                                           // за message => ще имаме загуба на памет
    strcpy(dynString, message2);
    printString(dynString);
    delete[] dynString;  // Освобождаваме паметта заделена за message2
    dynString = nullptr; // Добра практика е след като освободим динамична памет да дадем нулева стойност на указателят
                         // Причината за това е че след като извикаме delete/delete[] върху указател той не се занулява
                         // и продължава да сочи към адрес в памета => валиден указател е. Опит за четене или промяна
                         // на данните сочени от този указател водят до недефинирано поведение!

    // Ако искаме да имаме празен низ ни трябва низ с един елемент, който съдържа само терминиращата нула
    // "" e литерал, който съдържа единствено терминиращата нула
    char* emptyString = new char[1];
    emptyString[0] = '\0';
    printString(emptyString);
    delete[] emptyString;
    emptyString = nullptr;

    int numberSize = 5; // Тук вече размерът на масивът не трябва да е константа, както масивите заделени на стека
                        // но внимавайте когато подавате инициализиращ списък на динамично заделени масиви (от С++11)
    //int* numbers = new int[numberSize] {25, 3, 1, -50, 4, 152, 13}; // Тук ще се задели памет за 5 цели числа, но сме
                                                                      // подали инициализиращ списък със 7 елемента =>
                                                                      // ще се направи побитово копие на 7-те елемента в памет
                                                                      // за 5 елемента и ще получим недефинарано поведение
    numberSize = 7;
    int* numbers = new int[numberSize](); // Инициализираме всички елементи на 0
    numbers[0] = 123;
    numbers[1] = 56;
    numbers[2] = -50;
    numbers[3] = 33;
    numbers[4] = 18;
    numbers[5] = 36;
    numbers[6] = 12;

    cout << endl;
    cout << "Unsorted: ";
    for (int i = 0; i < 7; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < numberSize - 1; i++)
    {
        for (int j = 0; j < numberSize - i - 1; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    cout << "Sorted: ";
    for (int i = 0; i < 7; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    delete[] numbers;
    numbers = nullptr;

    // Масив от елементи от тип дефиниран от потребителят
    Point2D points[10]; // За да може да създадем масив(заделен на стека) от тип, дефиниран  
                        // от потребителят, той трябва да има конструктор по подразбиране
                        // Заделя се памет за 10 променливи(на стека) от тип Point2D и се извикват конструкторите им по подразбиране

    Point2D* pointFrom = new Point2D(1, 2);
    Point2D* otherPoints = new Point2D[5]; // Тук също трябва да имаме конструктор по подразбиране
                                           // Заделя се памет за 5 променливи(на heap-a)от тип Point2D и се извикват конструкторите им по подразбиране
    otherPoints[0].SetX(1);
    otherPoints[0].SetY(2);

    otherPoints[1].SetX(5);
    otherPoints[1].SetY(10);

    otherPoints[2].SetX(4);

    for (int i = 0; i < 3; i++)
    {
        cout << "Distance from ";
        pointFrom->PrintInfo();
        cout << " to ";
        otherPoints[i].PrintInfo();
        cout << " is : " << pointFrom->Distance(otherPoints[i]) << endl;
    }
    delete pointFrom;
    pointFrom = nullptr;
    delete[] otherPoints;
    otherPoints = nullptr;

    // Ако искаме да имаме обекти, заделени динамично с конструкторът им за общо ползване, трябва да направим масив от указатели към Point2D
    Point2D** dynamicPoints;
    dynamicPoints = new Point2D*[3];
    dynamicPoints[0] = new Point2D(1, 2);
    dynamicPoints[1] = new Point2D(3, 4);
    dynamicPoints[2] = new Point2D(5, 6);
    delete dynamicPoints[0];
    delete dynamicPoints[1];
    delete dynamicPoints[2];
    delete[] dynamicPoints;
    dynamicPoints = nullptr;

    return 0;
}