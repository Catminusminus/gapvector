#ifndef GAPVECTOR_IMPLEMENT
#define GAPVECTOR_IMPLEMENT

template <typename T>
gapvector<T>::gapvector()
{
	inner_vector.resize(N);
}

template <typename T>
void gapvector<T>::format_gapvector(int index)
{
	if (index == gap_begin)
		return;
	inner_vector.erase(inner_vector.begin() + gap_begin, inner_vector.begin() + gap_last + 1);
	for (auto i = 0; i < gap_last - gap_begin + 1; ++i)
	{
		inner_vector.insert(inner_vector.begin() + index, 0);
	}
	gap_last = index + gap_last - gap_begin;
	gap_begin = index;
}

template <typename T>
void gapvector<T>::gap_alloc()
{
	if (gap_begin == gap_last)
	{
		inner_vector.erase(inner_vector.erase(inner_vector.begin() + gap_begin));
		gap_begin = inner_vector.size();
		gap_last = gap_begin + N - 1;
		inner_vector.resize(inner_vector.size() + 10);
	}
}

template <typename T>
void gapvector<T>::insert(int index, const T &value)
{
	format_gapvector(index);
	inner_vector[index] = value;
	++gap_begin;
	gap_alloc();
	return;
}

template <typename T>
void gapvector<T>::insert(int index, T &&value)
{
	format_gapvector(index);
	inner_vector[index] = std::forward<T>(value);
	++gap_begin;
	gap_alloc();
	return;
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::insert(typename gapvector<T>::iterator itr, const T &value)
{
	size_t index = itr.index;
	insert(index, value);
	gapvectorIterator<T> gap_v_itr;
	gap_v_itr.advance(index);
	return gap_v_itr;
}

template <typename T>
void gapvector<T>::push_back(const T &value)
{
	inner_vector.push_back(value);
}

template <typename T>
void gapvector<T>::push_back(T &&value)
{
	inner_vector.push_back(std::forward<T>(value));
}

template <typename T>
void gapvector<T>::erase(int index)
{
	format_gapvector(index);
	++gap_last;
}

template <typename T>
void gapvector<T>::pop_back()
{
	if (inner_vector.size() - 1 = gap_last)
	{
		if (gap_begin == 0)
			return;
		--gap_begin;
	}
	inner_vector.pop_back();
}

template <typename T>
void gapvector<T>::clear()
{
	inner_vector.clear();

	inner_vector.resize(N);
	gap_begin = 0;
	gap_last = 0;
}

template <typename T>
int gapvector<T>::size()
{
	return inner_vector.size() - (gap_last - gap_begin + 1);
}

template <typename T>
T &gapvector<T>::operator[](int index)
{
	if (index < gap_begin)
	{
		return inner_vector[index];
	}
	return inner_vector[index + (gap_last - gap_begin + 1)];
}

template <typename T>
T &gapvector<T>::at(int index)
{
	if (index < gap_begin)
	{
		return inner_vector.at(index);
	}
	return inner_vector.at(index + (gap_last - gap_begin + 1));
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::begin()
{
	return gapvectorIterator<T>(this);
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::end()
{
	return gapvectorIterator<T>(NULL);
}
#endif