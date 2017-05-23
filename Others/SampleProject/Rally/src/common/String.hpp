template<typename CharT>
basic_string<CharT>::basic_string()
{
	m_data = new CharT[1];
	m_data[0] = CharT();
}

template<typename CharT>
size_type _len(const CharT* s)
{
	basic_string::size_type len = basic_string::size_type();
	while (s != nullptr)
	{
		len++;
		s++;
	}
	return len;
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::basic_string(const CharT* s)
{
	if (s != nullptr)
	{
		size_type length = _len(CharT);
	}
}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::basic_string(const basic_string& other)
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::basic_string(basic_string&& other)
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>::~basic_string()
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
basic_string<CharT>& basic_string<CharT>::operator=(basic_string rhs)
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
CharT& basic_string<CharT>::operator[](size_type pos)
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
const CharT& basic_string<CharT>::operator[](size_type pos) const
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
CharT* basic_string<CharT>::data()
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
const CharT* basic_string<CharT>::data() const
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
size_type basic_string<CharT>::size()
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
size_type basic_string<CharT>::length()
{

}

/////////////////////////////////////////////////////////////////
template<typename CharT>
bool basic_string<CharT>::empty()
{

}