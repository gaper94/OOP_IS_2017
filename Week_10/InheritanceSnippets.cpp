

// ����� � ��������� (�������������) ?
// ������������� � ����������������, ����� �� ���������� ������
// ���������, ����� �� � 'public' �������� �� �����
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

// ����� � overload �� �������
void foo();
void foo(char* pszString); // �� � ����� �������� �� overload-���� �������
void foo(int number);      // � ��������� � ���� �����, �� � ���������

extern "C"
{
	void bar();
	//void bar(int number); // ������� ��� "C" linkeage �� � ���������
	                        // �� ����� overloadvani
}

// ����� � override

// 1. �������� ���������
// 2. public -> "�  ����"
// 2.1 ������ � ���������� ������
// 3. �������� ������ ������������
// 4. ��������� �� ������ ������������/����������, ����������������/���
//    � ����������� ��������� ?
// 5. ���������� ��������� ��� �����������
// 6. ����������/��������� ����� ������ �����������
// 7. ������ �������� �� �������� ������������, ������ � Rectangle
// 8. ������ � ������������� �� ���������� ������� (������� early binding)
// 9. ������ � ���������� ������������� � ������� �� �������� (�������� ������ ��� Singletone)
// 10. ������� ����� "���" � "��������� �� ����" � ������ ����������� ������ � GenericStack ?

int main()
{
	return 0;
}