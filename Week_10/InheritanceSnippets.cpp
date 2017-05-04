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
	                        // да бъдат overloadvani
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

// Всичко, което е вярно за един човек ( притежава дата на раждане)
// е изпълнено и за един стундент, но всичко което се отнася до един студент (записан в даден университет)
// не е валидно за хората като цяло. Човек е по-общо понятие от студент, студентите
// са по-тясна категория хора.
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
//    study(Pencho); // Грешно, Pencho не е студент (Пенчо не чете.)
// Забележка! - Фактът, че един обект от тип Student e също Person не означава, че масив
// от обекти от Student e също масив от от обекти Person!!!!!

// Публичното наследяване се грижи всичко, което е приложимо към обект от базовия клас да може
// да се прави и с обекти от наследния клас.

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

// Разлчните видове наследявания и техните значения
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
//     (не винаги е най-добрият избор, когато можете използвайте агрегиране)
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

	class Bar : protected Foo
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
// В С++ приятелството не се налседява

// Наследяване на struct и class
namespace
{
	struct Point2D { public: void foo(); };
	class  CPoint2D { public: void foo(); };
	class CPoint : Point2D {}; // Ако пропуснем спецификаторът за наследяване (public, protected или private )
	                           // , когато наследяваме структури той е по подразбиране 'public'
	class CSecondPoint : CPoint {}; // Ако пропуснем спецификаторът за наследяване (public, protected или private )
									// , когато наследяваме класове той е по подразбиране 'private'
}

// Пример:
class NewSquare : private Rectangle
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

//    Rectangle r1(10, 10);
//    Square sq1(10);
//    r1 = sq1; // Всеки квадрат е правоъгълник
//    //sq1 = r1; // Всеки правоъгълник не е квадрат 
//    
//    makeBigger(r1);
//    cout << "Width = " << r1.GetWidth() << endl;
//    makeBigger(sq1); // Всеки квадрат е правоъгълник
//    if (sq1.GetWidth() != sq1.GetHeight())
//    {
//    	cout << "Аз не съм квадрат вече :O" << endl;
//    }


// Примери
// 1. Умело комбинране на шаблони и указатели с цел намаляване на обектният код

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

	void push(void* obj); // Лесно може да добавяме указатели към обекти от различни типове
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

// 2. Изчистване на потребителският интерфейс, но запазване на възможностт за разширяване на
//    функционалността ако ни потрябва

// Какво е override
// 2.1 Пример с животниска верига
// 3. Различни типове наследявания
// 4. Извикване на базови конструктори/деструктор, последователност/ред
//    и автоматично изивкване ?
// 5. Приятелски деклрации при наследяване
// 6. Наслояване/агрегация срещу частно наследяване
// 8. Пример с предефиниране на невиртуалн фунцкия (спомени early binding)
// 9. Пример с различните наследнявания и достъпъ на полетата (шаблонен пример със Singletone)
// 10. Разлика между "има" и "реализира се чрез" и частно наследяване пример с GenericStack ?
// 11. Не предефинирайте невиртуални функции (early binding)
// 12. Наследяване на структури - разлика спрямо наследяване на класове
#include <iostream>
using namespace std;

int main()
{
	return 0;
}