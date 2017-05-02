

// Какво е интерфейс (потребителски) ?
// Потребителски е функционалността, която ни предоставя класът
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
void foo(int number);      // с указатели и цели числа, но е позволено

extern "C"
{
	void bar();
	//void bar(int number); // Функции със "C" linkeage не е позволено
	                        // да бъдат overloadvani
}

// Какво е override

// 1. Публичен интерфейс
// 2. public -> "е  също"
// 2.1 Пример с животниска верига
// 3. Различни типове наследявания
// 4. Извикване на базови конструктори/деструктор, последователност/ред
//    и автоматично изивкване ?
// 5. Приятелски деклрации при наследяване
// 6. Наслояване/агрегация срещу частно наследяване
// 7. Грешна употреба на публично наследняване, пример с Rectangle
// 8. Пример с предефиниране на невиртуалн фунцкия (спомени early binding)
// 9. Пример с различните наследнявания и достъпъ на полетата (шаблонен пример със Singletone)
// 10. Разлика между "има" и "реализира се чрез" и частно наследяване пример с GenericStack ?

int main()
{
	return 0;
}