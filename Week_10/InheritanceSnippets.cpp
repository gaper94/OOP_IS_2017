#include <stddef.h>
#include <string>
// 1. Публичен интерфейс
// Какво е интерфейс (потребителски) ?
// Потребителски интерфейс е функционалността, която ни предоставя класът
// функциите, които са в 'public' секцията на класа
template<typename T>
class Vector
{
public:
    enum class BoundsCheckStatus
    {
        NoBoundsCheck,
        BoundsCheck
    };

    Vector() = delete;
    Vector(T* data, size_t size, BoundsCheckStatus eBoundCheckStatus = BoundsCheckStatus::NoBoundsCheck);
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(const Vector& rhs);

    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;

    size_t getSize() const;

protected:
private:
    T* m_data;
    size_t m_size;
    BoundsCheckStatus m_eBoundCheckStatus;
};

// Какво е overload на функция
void foo();
void foo(char* pszString); // Не е добра практика да overload-вате функции
void foo(int number);      // с параметри указатели и цели числа, но е позволено

extern "C"
{
    void bar();
    //void bar(int number); // Функции със "C" linkeage не е позволено
                            // да бъдат overload-вани
}

// Наследяване
// - Подчертаване на общи черти
// - Избягване на дублиране на код
// - Улесняване на подръжката и бъдещи подобрения
// 2. Публичното наследяване -> "е също"
class Person
{
    //...
};

class Student : public Person // Всеки Студент е Човек
{
    //...
};

// Студентите са хора, но хората не са студенти

// Всичко, което е вярно за един човек (притежава дата на раждане)
// е изпълнено и за един стундент, но всичко което се отнася до един студент (записан в даден университет)
// не е валидно за хората като цяло. Човек е по-общо понятие от студент, студентите са по-тясна категория хора.
// В С++ всяка фунцкия приемаща като аргумент псевдоним или указател от тип Person
// може да приеме псевдоним или указател от тип Student (все пак всеки студент е човек)

//    void play(const Person& p){}   // Всички могат да играят
//    void study(const Student& st){} // Само студентите учат :(
//    Person Pencho;
//    Student Racho;
//    play(Pencho); // Вярно, Pencho е Person (търси да да играй)
//    play(Racho); // Вярно, Racho e Student, a Student е също така Person
//    study(Racho); // Вярно,  Racho e Student
//     Пенчо бре, чети!
//    study(Pencho); // Грешно, Pencho не е студент -> Пенчо не чете.
// Забележка! - Фактът, че един обект от тип Student e също Person не означава, че масив
// от обекти от Student e също масив от от обекти Person!!!!!

// Публичното наследяване се грижи всичко, което е приложимо към обект от базовия клас да може
// да се прави и с обекти от наследния клас.

// Разлчните видове наследявания и техните значения:
// 1. 'public' -> "e също"
namespace PublicInheritance
{

    class Foo
    {
    public:
        void publicFoo() const;

    protected:
        void protectedFoo() const;

    private:
        void privateFoo() const;
    };

    class Bar : public Foo
    {
    public:
        // void publicFoo() const; - publicFoo остава в публичният интерфейс на класът (може да бъде извикана от потребителят)
    protected:
        // void protectedFoo() const; - остава защитена функция (всички функции на Bar и нейните наследници имат достъп до нея)
    private:
        // void privateFoo() const; - Нито Bar, нито нейните наследници имат достъп до нея
    };
}
// 2. 'protected' -> "e реализиран с помоща на" (рядко намира употреба, подобрява достъпа на полетата в наследните класове)
namespace ProtectedInheritance
{
    class Foo
    {
    public:
        void publicFoo() const;

    protected:
        void protectedFoo() const;

    private:
        void privateFoo() const;
    };

    class Bar : protected Foo
    {
    protected:
        // void publicFoo() const; - става защитена фунцкия (всички функции на Bar и нейните наследници имат достъп до нея)
        // void protectedFoo() const; - остава защитена функция (всички функции на Bar и нейните наследници имат достъп до нея)
    private:
        // void privateFoo() const; - Нито Bar, нито нейните наследници имат достъп до нея
    };
}
// 3. 'private' -> "e реализиран с помоща на"
//     (не винаги е най-добрият избор, когато можете използвайте агрегация)
namespace PrivateInheritance
{
    class Foo
    {
    public:
        void publicFoo() const;

    protected:
        void protectedFoo() const;

    private:
        void privateFoo() const;
    };

    class Bar : private Foo
    {
    protected:
        // void publicFoo() const; - става скрита функция (само функции на Bar имат достъп до нея и приятелите на класът)
        // void protectedFoo() const; - става скрита функция (само функции на Bar имат достъп до нея и приятелите на класът)
        // void privateFoo() const; - Нито Bar, нито нейните наследници имат достъп до нея
    };
}

//             |  public      |   protected   |   private   |
//             |--------------|---------------|-------------|
//  public:    |   'public'   |  'protected'  |  'private'  |
//  protected: | 'protected'  |  'protected'  |  'private'  |
//  private:   |  'private'   |   'private'   |  'private'  |

// Забележка!
// В С++ приятелството не се наследява

// Наследяване на структура и клас
namespace
{
    struct Point2D { public: void foo(); };
    class  CPoint2D { public: void foo(); };
    class CPoint : Point2D {}; // Ако пропуснем спецификаторът за наследяване (public, protected или private )
                               // когато наследяваме структури той е по подразбиране 'public'
    class CSecondPoint : CPoint {}; // Ако пропуснем спецификаторът за наследяване (public, protected или private )
                                    // когато наследяваме класове той е по подразбиране 'private'
}

// Извикване на базов контруктор & деструктор
namespace Implementation
{
    enum class Gender
    {
        Male,
        Female,
    };

    class Person
    {
    public:

        Person(const char* pszName, const char* pszEGN, Gender _eGender)
            : name(nullptr), EGN(nullptr), eGender(_eGender)
        {
            SetName(pszName);
            SetEGN(pszEGN);
        }

        Person()
            : name(nullptr), EGN(nullptr), eGender(Gender::Male) // Понеже трябва да решим дали нашият човек
        {                                                        // по подразбиране е от мъжки или женски пол, когато 
            SetName("");                                         // пишем клас описващ човек, трябва да решим дали наистина 
            SetEGN("");                                          // искаме да можем да създаваме обекти по подразбиране
        }                                                        // Понякога нямаме избор (например искаме да създадем масив от Person), 
                                                                 // но можем да използваме заобиколни методи (ще създадем масив от указатели към Person).
        Person(const Person& other)
            : name(nullptr), EGN(nullptr), eGender(other.eGender)
        {
            SetName(other.name);
            SetName(other.EGN);
        }

        ~Person()
        {
            delete[] name;
            delete[] EGN;
        }

        Person& operator=(const Person& rhs);

        // Setters
        void SetName(const char * pszName) {}
        void SetEGN(const char * pszName) {}
        void SetGender(Gender eGender) {}

        // Getters
        const char* GetName() const { return name; }
        const char* GetEGN() const { return EGN; }
        Gender GetGender() const { return eGender; }

        // Other function
        size_t CalculateAge() { return 0; }

    private:
        char* name;
        char* EGN;
        Gender eGender;
    };

    class Student : public Person
    {
    public:
        Student(const char* pszName, const char* pszEGN,  Gender eGender, const char* pszFn)
            : Person(pszName, pszEGN, eGender), fn(nullptr)
        {
            SetFN(pszFn);
        }

        Student()
            : Person(), fn(nullptr)
        {
            SetFN("");
        }

        Student(const Student& other)
            : Person(other), fn(nullptr)
        {
            SetFN(other.fn);
        }

        Student& operator=(const Student& rhs)
        {
            if (this == &rhs) return *this;

            Person::operator=(rhs);
            SetFN(rhs.fn);
            return *this;
        }

        ~Student()
        {
            delete[] fn;
        }

        // Setters
        void SetFN(const char* pszFn) {}
        // Getters
        const char* GetFN() const { return fn; }

    private:
        char* fn;
    };
}

// Създаване на обект от тип Student
// 1. Kонструктор за общо ползване
//   За да създадем един валиден обект от тип Student, първо трябва да конструираме базовата
//   част наследена от Person -> трябва да извикаме конструкторът за общо ползване на Person.
//   Това означава че всички аргументи, които са необходими за извикване на конструкторът на Person
//   са необходими и на конструкторът на Student. Останалите параметри, специфични за класът Student
//   може да ги изредим след параметрите необходими за конструиране на частта за Person.
//
//   Student(const char* pszName, const char* pszEGN, Gender eGender, const char* pszFn)
//   : Person(pszName, pszEGN, eGender), fn(nullptr)
//   {
//      SetFN(pszFn);
//   }
//
//   Извикването на конструкторът за общо ползване на Person става в инициализиращият списък на конструкторът на Student (трябва да имаме достъп до него).
//   Ако пропуснем да го извикаме, ще се извика конструкторът по подразбиране на Person (ако има такъв и имаме достъп до него).
//   Ако нямаме конструктор по подразбиране или не можем да го достъпим от Student ще имаме компилационна грешка.
//
// 2. Kонструктор по подразбиране
//   За да създадем един валиден обект по подразбиране от тип Student, трбява да конструираме
//   базовата част наследена от Person -> трябва да извикаме конструкторът по подразбиране на Person.
//
//   Student()
//     : Person(), fn(nullptr)
//   {
//      SetFN("");
//   }
//
//   Извикването на конструкторът по подразбиране на Person става в инициализиращият списък на конструкторът на Student (трябва да имаме достъп до него).
//   Ако пропуснем да го извикаме, той ще се извика автоматично. Ако нямаме конструктор по подразбиране или не можем да го достъпим от Student 
//   ще имаме компилационна грешка.
//   Въпреки че конструкторът по подразбиране се извиква дори и без да го добавим в инициализиращият списък, добра практика е да се извика явно за да 
//   стане ясно на другите, които четат кода ни после какво сме искали да постигнем (смятам че 8 букви написани повече(Person()) изрязват 
//   по-добре какво сме искали да кажем).
//
// 3. Конструктор за копиране
//    За да копираме/създадем валиден обект от Person от друг обект от Person, трябва да конструираме базовата част наследена
//    от Person -> трябва да използваме конструкторът за копиране на Person (ако има такъв и имаме достъп до него).
//
//    Student(const Student& other)
//    : Person(other), fn(nullptr)
//    {
//       SetFN(other.fn);
//    }
//
//    Извикаването на конструкторът за копиране на Person става в инициализиращият списък на конструкторът на Student (трябва да имаме достъп до него)
//    Ако пропуснем да извикаме конструкторът за копиране, ще се извика конструкторът по подразбиране на Person (ако има такъв и имаме достъп до него).
//    Ако нямаме конструктор по подразбиране или не можем да го достъпим от Student ще имаме компилационна грешка.
//    
//    Малко по-объркващ е случаят, когато наследяваме частно(private) или защитено (public), нека имаме следните класове:
//
//      class Foo
//      {
//      public:
//          Foo(){}
//      
//          Foo(const Foo& other)
//          {
//          }
//      };
//      
//      class ProtectedFoo : protected Foo
//      {
//      public:
//          ProtectedFoo()
//              : Foo()
//          {
//          }
//      
//          ProtectedFoo(const ProtectedFoo& other)
//              : Foo(other)
//          {
//          }
//      };
//      
//      class PrivateFoo : private Foo
//      {
//      public:
//          PrivateFoo()
//              : Foo()
//          {
//          }
//      
//          PrivateFoo(const PrivateFoo& other)
//              : Foo(other)
//          {
//          }
//      };
//      
//      void useBaseFoo(const Foo& base)
//      {
//          // ...
//      }
//      
//      Foo baseFoo;
//      ProtectedFoo protectedFoo;
//      PrivateFoo privateFoo;
//      useBaseFoo(baseFoo); // Валидно, useBaseFoo приема като параметър Foo
//      useBaseFoo(protectedFoo); // Класът ProtectedFoo наследява защитено класът Foo.
//                                // По този начин сме казали че ProtectedFoo се реазлизира с помощта на Foo
//                                // -> не е вярно че ProtectedFoo е Foo и няма как да бъде използван във функцията useBaseFoo
//
//      useBaseFoo(protectedFoo); // Класът ProtectedFoo наследява частно класът Foo 
//                                // -> подобно на ProtectedFoo, не е вярно че PrivateFoo е Foo и няма как да бъде използван във функцията useBaseFoo
//    
//    Добре, защо тогава в конструкторът за копиране можем да преобразуваме PrivateFoo и ProtectedFoo до Foo, а във функцията useBaseFoo() не ?
//    Причината компилаторът да го позволява тук е защото за да създадем един валиден обект, използвайки конструкторът за копиране на PrivateFoo или ProtectedFoo, 
//    трябва да използваме конструкторът за копиране на Foo (разбира се трябва да имаме и достъп до него). Ако трябва да сме на 100% коректни
//    само в класовете ProtectedFoo и PrivateFoo може да преобразуваме обект от тип 'PrivateFoo' и 'ProtectedFoo' до 'Foo' - ако имаме клас, който наследява
//    ProtectedFoo и PrivateFoo не може да го преобразуваме до Foo:
//
//    class Foo
//    {
//    public:
//        Foo(){}
//        Foo(const Foo& other){}
//    };
//    
//    class Bar : private Foo
//    {
//    public:
//        Bar(){}
//        Bar(const Bar& other) : Foo(other){ callAsBase(other); } // Валидно извикване
//        void callAsBase(const Foo& ref){}
//    };
//    
//    class Chunky : public Bar
//    {
//    public:
//        Chunky() {}
//        Chunky(const Chunky& other) : Bar(other){}
//        void tryToCallAsBase(const Foo& other){} // Не се компилира, не може да преозбразуваме Chunky до Foo
//    };
//    
//   Редът в който се извикват конструкторите е следната:
//       1. Конструира се базовата част
//       2. Конструира се частта на наследника
//
//   4. Оператор за присвояване - тук поведението е много сходно с конструкторът за копиране, за да присвоим цялата част на обект от наследен тип
//      трябва да извикаме оператора за присвояване на базовият тип:
//
//      Student& operator=(const Student& rhs)
//      {
//          if (this == &rhs) return *this;
//      
//          Person::operator=(rhs);
//          SetFN(rhs.fn);
//          return *this;
//      }
//
//      Спецификите, споменати по-горе за конструкторът за копиране, важат и за оператора за присвояване (все пак приемат еднакви аргументи и имат доста сходна задача)
//
//   5. Деструктор - за да освободим всички ресурси необходими за създаването на един валиден обект от тип Student трябва да освободим и ресурсите за Person.
//      Тук извикването на деструкторите става в обратен ред спрямо изивкването на конструкторите - първо се извиква деструктора на наследника и след това на базовият клас.
//      Причината за това е следната - ако първо извикаме базовият деструктор нашият обект би бил в полу-валидно(недефинирано) състояние, само наследената част ще е валидна.
//      Ппример: в базовият клас имаме отворен файл (използваме го за четене/писане) и в деструктора на наследника добавяме инфорамация в този файл 
//      (например кога сме затворили дадена връзка), как бихме могли да го направим ако първо затворим файлът ?
//      Когато строим една къща последно слагаме покривът и когато решим да я разглобим първо заповаме  от него
//      (освен ако не решим да използваме експлозив, но тогава ефектът ще е същият като да извикаме първо базовият деструктор)
//
//      Базовите деструктори се извикват автоматично - дори и да не дефинираме деструктор в наследника (нямаме ресурси за освобождаване). В нашият случай деструкторът
//      на Person ще се извика автоматично, дори и да нямахме деструктор в Student.


class Rectangle
{
public:
    Rectangle(int width, int height)
        : m_width(width), m_height(height)
    {
    }

    Rectangle() = delete;
    Rectangle(const Rectangle& other) = default;
    Rectangle& operator=(const Rectangle& rhs) = default;

    // Setters
    void SetWidth(int width)
    {
        m_width = width;
    }

    void SetHeight(int height)
    {
        m_height = height;
    }

    // Getters
    int GetWidth() const
    {
        return m_width;
    }

    int GetHeight() const
    {
        return m_height;
    }

    int GetPerimeter() const
    {
        return (m_height * 2) + (m_width * 2);
    }

    int GetArea() const
    {
        return m_height * m_width;
    }

private:
    int m_width;
    int m_height;
};

class Square : public Rectangle
{
public:
    Square(int side)
        : Rectangle(side, side)
    {
    }
};

//    Rectangle r1(10, 10);
//    Square sq1(10);
//    r1 = sq1; // Всеки квадрат е правоъгълник
//    //sq1 = r1; // Всеки правоъгълник НЕ Е квадрат
//
//    makeBigger(r1);
//    cout << "Width = " << r1.GetWidth() << endl;
//    makeBigger(sq1); // Всеки квадрат е правоъгълник
//    if (sq1.GetWidth() != sq1.GetHeight())
//    {
//        cout << "Аз не съм квадрат вече :O" << endl;
//    }

// Композиция
// Пример:
class NewSquare : private Rectangle // еквивалентно на class NewSquare : Rectangle
{
public:
    NewSquare(int side)
        : Rectangle(side, side)
    {
    }

    int GetWidth() const
    {
        return Rectangle::GetWidth();
    }

    int GetHeight() const
    {
        return Rectangle::GetHeight();
    }
};

// Пример за агрегация
class AgregateRectangle
{
public:
    AgregateRectangle(int side)
        : rec(side, side)
    {
    }

    int GetWidth() const
    {
        return rec.GetWidth();
    }

    int GetHeight() const
    {
        return rec.GetHeight();
    }
private:
    Rectangle rec;
};

void makeBigger(Rectangle& rec)
{
    // Modify only width
    rec.SetWidth(rec.GetWidth() * 2);
}


// Примери
// 1. Умело комбинране на шаблони и указатели с цел намаляне на обектният код

class GeneralStack
{
public:
    GeneralStack();
    ~GeneralStack();

    void push(void* obj); // Лесно може да добавяме указатели към обекти от различни типове
    void* pop();

    bool empty() const;
private:
    // ....
};

namespace TypeSafe
{
    class IntStack
    {
    public:
        void push(int* obj);
        int* pop();
        bool empty() const;
    private:
        GeneralStack s;
    };

    class DoubleStack
    {
    public:
        void push(int* obj);
        int* pop();
        bool empty() const;
    private:
        GeneralStack s;
    };
}

class GenericStack
{
protected:
    GenericStack();
    ~GenericStack();

    void push(void* obj);
    void* pop();

    bool empty() const;
private:
    // ....
};

class IntStack : private GenericStack
{
public:
    void push(int* obj);
    int* pop();
    bool empty() const;
};

class DoubleStack : private GenericStack
{
public:
    void push(double* obj);
    double* pop();
    bool empty() const;
};

template<typename T>
class Stack : private GenericStack
{
public:
    void push(T* obj);
    T* pop();
    bool empty() const;
};

// 2. Изчистване на потребителският интерфейс, но запазване на възможността за разширяване на
//    функционалността ако искаме

class ComplexNumber
{
public:
    ComplexNumber(double realPart, double imaginaryPart);
    ComplexNumber();
    ComplexNumber(const ComplexNumber& other) = default;

    // Getters
    double GetRealPart() const;
    double GetImaginaryPart() const;
    // Setter
    void SetRealPart(double newRealPart);
    void SetImaginaryPart(double newImaginaryPart);

    // Overloaded operators
    ComplexNumber& operator=(const ComplexNumber&) = default;

    ComplexNumber& operator+=(const ComplexNumber& rhs);
    const ComplexNumber operator+(const ComplexNumber& rhs);

    ComplexNumber& operator-=(const ComplexNumber& rhs);
    const ComplexNumber operator-(const ComplexNumber& rhs);

    template<typename T>
    friend const ComplexNumber operator+(const ComplexNumber& lhs, const T& rhs);

    template<typename T>
    friend const ComplexNumber operator+(const T& lhs, const ComplexNumber& rhs);

    template<typename T>
    friend const ComplexNumber operator-(const ComplexNumber& lhs, const T& rhs);

    template<typename T>
    friend const ComplexNumber operator-(const T& lhs, const ComplexNumber& rhs);

private:
    double realPart;
    double imaginaryPart;
};

class ByteInputStream
{
public:
    ByteInputStream();
    ~ByteInputStream();

    // Overloaded operators for built in types
    ByteInputStream& operator>>(int);
    ByteInputStream& operator>>(double);
    ByteInputStream& operator>>(char*);
    ByteInputStream& operator>>(const std::string&);

    template<typename T>
    friend ByteInputStream& operator>>(ByteInputStream& bs, const T&);

private:
    // ByteStremImpl impl;
};

// Източници:
// 1. Effective C++ (second & third editions), Scott Meyers