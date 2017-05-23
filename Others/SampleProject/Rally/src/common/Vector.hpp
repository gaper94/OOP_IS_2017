template<typename T>
Vector<T>::Vector()
    : m_data(nullptr), m_size(0), m_capacity(0)
{
}

/////////////////////////////////////////////////////////////////
template<typename T>
Vector<T>::Vector(const T* data, size_type size)
    : m_data(nullptr), m_size(0), m_capacity(0)
{
    if (data != nullptr && size > 0)
    {
        m_size = m_capacity = size;
        m_data = new T[m_size];
        for (size_type i = 0; i < size; i++)
        {
            m_data[i] = data[i];
        }
    }
}

/////////////////////////////////////////////////////////////////
template<typename T>
Vector<T>::Vector(const Vector<T>& other)
    : m_data(nullptr), m_size(0), m_capacity(0)
{
    if (other.data != nullptr && other.m_size > 0)
    {
        m_size = m_capacity = other.m_size;
        m_data = new T[m_size];
        for (size_type i = 0; i < size; i++)
        {
            m_data[i] = data[i];
        }
    }
}

/////////////////////////////////////////////////////////////////
template<typename T>
Vector<T>::Vector(Vector<T>&& other)
{
    m_data = other.data;
    other.m_data = nullptr;
    
    m_size = other.m_size;
    m_capacity = other.m_capacity;
}

/////////////////////////////////////////////////////////////////
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> rhs)
{
    std::swap(data, rhs.data);
    size = rhs.size;
    capacity = rhs.capacity;
    return *this;
}

/////////////////////////////////////////////////////////////////
// Use forwarding ?
template<typename T>
void Vector<T>::push_back(const T& value)
{
    if ((m_size + 1) > m_capacity)
    {
        size_type new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        resize(new_capacity);
    }

    m_data[m_size] = value;
    m_size++;
}

/////////////////////////////////////////////////////////////////
template<typename T>
void Vector<T>::push_back(T&& value)
{
    if ((m_size + 1) > m_capacity)
    {
        size_type new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
        resize(new_capacity);
    }

    m_data[m_size] = value;
    m_size++;
}

/////////////////////////////////////////////////////////////////
template<typename T>
T* Vector<T>::data()
{
    return m_data;
}

/////////////////////////////////////////////////////////////////
template<typename T>
const T* Vector<T>::data() const
{
    return m_data;
}

/////////////////////////////////////////////////////////////////
template<typename T>
T& Vector<T>::operator[](size_type idx)
{
    return m_data[idx];
}

/////////////////////////////////////////////////////////////////
template<typename T>
const T& Vector<T>::operator[](size_type idx) const
{
    return m_data[idx];
}

/////////////////////////////////////////////////////////////////
template<typename T>
size_type Vector<T>::size() const
{
    return m_size;
}

/////////////////////////////////////////////////////////////////
template<typename T>
size_type Vector<T>::capacity() const
{
    return m_capacity;
}

/////////////////////////////////////////////////////////////////
template<typename T>
bool Vector<T>::empty() const
{
    return size == 0;
}

/////////////////////////////////////////////////////////////////
template<typename T>
void Vector<T>::resize(size_type count)
{
    if (count == 0)
    {
        clear();
        return;
    }

    T* temp = new T[count];
    m_capacity = count;
    m_size = count > m_size ? m_size : count;

    for (size_type i = 0; i < m_size; i++)
    {
        temp[i] = m_data[i];
    }
    
    delete[] m_data;
    m_data = temp;
}

/////////////////////////////////////////////////////////////////
template<typename T>
void Vector<T>::clear()
{
    for (size_type i = 0; i < m_size; i++)
    {
        m_data[i].~T();
    }
    m_size = 0;
}