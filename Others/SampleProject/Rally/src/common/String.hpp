template<typename CharT>
basic_string<CharT>::basic_string()
{
	m_data = new CharT[1];
	m_data[0] = CharT();
}

template<typename CharT>
size_type _len(const CharT* s)
{
    size_type len = size_type();
    while (*s != CharT())
	{
		len++;
		s++;
	}
	return len;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::basic_string(const CharT* s)
    : m_size(size_type())
{
    if (s != nullptr)
    {
        size_type length = _len(s);
        if(length > 0)
        {
            m_data = new CharT[length + 1];
            m_size = length;
            std::memcpy(m_data, s, length + 1);
            return;
        }
    }
    m_data = new CharT[1];
    m_data[0] = CharT();
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::basic_string(const basic_string<CharT>& other)
{
    size_type length = _len(other.m_data);
    if(length > 0)
    {
        m_data = new CharT[length + 1];
        m_size = length;
        std::memcpy(m_data, other.m_data, length + 1);
        return;
    }
    m_data = new CharT[1];
    m_data[0] = CharT();
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::basic_string(basic_string<CharT>&& other)
{
    std::swap(m_data, other.m_data);
    other.m_data = nullptr;
    m_size = other.m_size;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::~basic_string()
{
    delete[] m_data;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>& basic_string<CharT>::operator=(basic_string<CharT> rhs)
{
    std::swap(m_data, rhs.data);
    m_size = rhs.size;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
CharT& basic_string<CharT>::operator[](size_type pos)
{
    return m_data[pos];
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
const CharT& basic_string<CharT>::operator[](size_type pos) const
{
    return m_data[pos];
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
CharT* basic_string<CharT>::data()
{
    return m_data;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
const CharT* basic_string<CharT>::data() const
{
    return m_data;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
size_type basic_string<CharT>::size()
{
    return m_size;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
size_type basic_string<CharT>::length()
{
    return m_size;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
bool basic_string<CharT>::empty()
{
    return m_size == size_type();
}
