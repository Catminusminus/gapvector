#ifndef GAPVECTOR_IMPLEMENT_HPP
#define GAPVECTOR_IMPLEMENT_HPP

template <typename T>
gapvector<T>::gapvector()
{
	inner_vector.resize(N);
}

template <typename T>
gapvector<T>::gapvector(std::initializer_list<T> init_list)
{
	inner_vector.resize(N);

	for (auto &&e : init_list)
	{
		inner_vector.push_back(e);
	}
}

template <typename T>
gapvector<T> &gapvector<T>::operator=(std::initializer_list<T> init_list)
{
	this->clear();

	for (auto &&e : init_list)
	{
		inner_vector.push_back(e);
	}

	return *this;
}

template <typename T>
void gapvector<T>::format_gapvector(size_t index)
{
	if (index == gap_begin)
		return;

	inner_vector.erase(inner_vector.begin() + gap_begin, inner_vector.begin() + gap_last + 1);

	for (size_t i = 0; i < gap_last - gap_begin + 1; ++i)
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
template <class inputIterator, std::enable_if_t<!std::is_integral<inputIterator>::value, std::nullptr_t>>
void gapvector<T>::assign(inputIterator first, inputIterator end)
{
	this->clear();

	std::for_each(first, end, [this](auto input) { inner_vector.push_back(input); });
}

template <typename T>
void gapvector<T>::assign(size_t size, const T &value)
{
	this->clear();

	for (size_t i = 0; i < size; ++i)
	{
		inner_vector.push_back(value);
	}
}

template <typename T>
void gapvector<T>::assign(std::initializer_list<T> init_list)
{
	assign(init_list.begin(), init_list.end());
}

template <typename T>
void gapvector<T>::insert(size_t index, const T &value)
{
	format_gapvector(index);
	inner_vector[index] = value;
	++gap_begin;
	gap_alloc();
	return;
}

template <typename T>
void gapvector<T>::insert(size_t index, T &&value)
{
	format_gapvector(index);
	inner_vector[index] = std::move(value);
	++gap_begin;
	gap_alloc();
	return;
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::insert(iterator itr, const T &value)
{
	size_t index = itr.index;
	insert(index, value);

	auto gap_v_itr = this->begin();
	gap_v_itr.advance(index);
	return gap_v_itr;
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::insert(const_iterator itr, const T &value)
{
	size_t index = itr.index;
	insert(index, value);

	auto gap_v_itr = this->begin();
	gap_v_itr.advance(index);
	return gap_v_itr;
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::insert(iterator itr, T &&value)
{
	size_t index = itr.index;
	insert(index, std::move(value));

	auto gap_v_itr = this->begin();
	gap_v_itr.advance(index);
	return gap_v_itr;
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::insert(const_iterator itr, T &&value)
{
	size_t index = itr.index;
	insert(index, std::move(value));

	auto gap_v_itr = this->begin();
	gap_v_itr.advance(index);
	return gap_v_itr;
}

template <typename T>
void gapvector<T>::insert(iterator itr, size_t number, const T &value)
{
	for (size_t i = 0; i < number; ++i)
	{
		itr = insert(itr, value);
	}
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::insert(const_iterator itr, size_t number, const T &value)
{
	for (size_t i = 0; i < number; ++i)
	{
		itr = insert(itr, value);
	}

	return itr;
}

template <typename T>
template <class inputIterator>
void gapvector<T>::insert(iterator itr, inputIterator first, inputIterator end)
{
	std::for_each(first, end, [this, &itr](auto input) {itr = insert(itr, input); ++itr; });
}

template <typename T>
template <class inputIterator>
typename gapvector<T>::iterator gapvector<T>::insert(const_iterator itr, inputIterator first, inputIterator end)
{
	std::for_each(first, end, [this, &itr](auto input) {itr = insert(itr, input); ++itr; });

	return first == end ? itr : --itr;
}

template <typename T>
inline void gapvector<T>::emplace([[maybe_unused]] size_t index)
{
}

template <typename T>
template <class Head, class... Tail>
void gapvector<T>::emplace(size_t index, Head &&head, Tail &&... tail)
{
	insert(index, std::forward<Head>(head));
	emplace(index + 1, std::forward<Tail>(tail)...);
}

template <typename T>
template <class... Args>
typename gapvector<T>::iterator gapvector<T>::emplace(const_iterator itr, Args &&... args)
{
	size_t index = itr.index;
	emplace(index, std::forward<Args>(args)...);

	auto gap_v_itr = this->begin();
	size_t size = sizeof...(args);
	gap_v_itr.advance(index + size);
	return size == 0 ? gap_v_itr : --gap_v_itr;
}

template <typename T>
void gapvector<T>::push_back(const T &value)
{
	inner_vector.push_back(value);
}

template <typename T>
void gapvector<T>::push_back(T &&value)
{
	inner_vector.push_back(std::move(value));
}

template <typename T>
template <class... Args>
void gapvector<T>::emplace_back(Args &&... args)
{
	inner_vector.emplace_back(std::forward<Args>(args)...);
}

template <typename T>
void gapvector<T>::erase(size_t index)
{
	format_gapvector(index);
	++gap_last;
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::erase(typename gapvector<T>::iterator itr)
{
	size_t index = itr.index;
	erase(index);

	auto gap_v_itr = this->begin();
	gap_v_itr.advance(index);
	return gap_v_itr;
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
void gapvector<T>::clear() noexcept
{
	inner_vector.clear();

	inner_vector.resize(N);
	gap_begin = 0;
	gap_last = N - 1;
}

template <typename T>
int gapvector<T>::size() const noexcept
{
	return inner_vector.size() - (gap_last - gap_begin + 1);
}

template <typename T>
T &gapvector<T>::operator[](size_t index)
{
	return const_cast<T &>((const_cast<const gapvector<T> &>(*this))[index]);
}

template <typename T>
const T &gapvector<T>::operator[](size_t index) const
{
	if (index < gap_begin)
	{
		return inner_vector[index];
	}
	return inner_vector[index + (gap_last - gap_begin + 1)];
}

template <typename T>
T &gapvector<T>::at(size_t index)
{
	return const_cast<T &>((const_cast<const gapvector<T> &>(*this)).at(index));
}

template <typename T>
const T &gapvector<T>::at(size_t index) const
{
	if (index < gap_begin)
	{
		return inner_vector.at(index);
	}
	return inner_vector.at(index + (gap_last - gap_begin + 1));
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::begin() noexcept
{
	return gapvectorIterator<T>(this, 0);
}

template <typename T>
typename gapvector<T>::const_iterator gapvector<T>::begin() const noexcept
{
	return gapvectorConstIterator<T>(this, 0);
}

template <typename T>
typename gapvector<T>::iterator gapvector<T>::end() noexcept
{
	return gapvectorIterator<T>(this, this->size());
}

template <typename T>
typename gapvector<T>::const_iterator gapvector<T>::end() const noexcept
{
	return gapvectorConstIterator<T>(this, this->size());
}

template <typename T>
typename gapvector<T>::const_iterator gapvector<T>::cbegin() const noexcept
{
	return gapvectorConstIterator<T>(this, 0);
}

template <typename T>
typename gapvector<T>::const_iterator gapvector<T>::cend() const noexcept
{
	return gapvectorConstIterator<T>(this, this->size());
}

template <typename T>
typename gapvector<T>::reverse_iterator gapvector<T>::rbegin() noexcept
{
	return gapvectorReverseIterator<T>(this, this->size());
}

template <typename T>
typename gapvector<T>::const_reverse_iterator gapvector<T>::rbegin() const noexcept
{
	return gapvectorConstReverseIterator<T>(this, this->size());
}

template <typename T>
typename gapvector<T>::reverse_iterator gapvector<T>::rend() noexcept
{
	return gapvectorReverseIterator<T>(this, 0);
}

template <typename T>
typename gapvector<T>::const_reverse_iterator gapvector<T>::rend() const noexcept
{
	return gapvectorConstReverseIterator<T>(this, 0);
}

template <typename T>
typename gapvector<T>::const_reverse_iterator gapvector<T>::crbegin() const noexcept
{
	return gapvectorConstReverseIterator<T>(this, this->size());
}

template <typename T>
typename gapvector<T>::const_reverse_iterator gapvector<T>::crend() const noexcept
{
	return gapvectorConstReverseIterator<T>(this, 0);
}

template <typename T>
bool gapvector<T>::empty() const noexcept
{
	return (size() == 0);
}

template <typename T>
T &gapvector<T>::front()
{
	return const_cast<T &>((const_cast<const gapvector<T> &>(*this)).front());
}

template <typename T>
const T &gapvector<T>::front() const
{
	return (*this)[0];
}

template <typename T>
T &gapvector<T>::back()
{
	return const_cast<T &>((const_cast<const gapvector<T> &>(*this)).back());
}

template <typename T>
const T &gapvector<T>::back() const
{
	return (*this)[(*this).size() - 1];
}

template <typename T>
T *gapvector<T>::data() noexcept
{
	return const_cast<T *>((const_cast<const gapvector<T> &>(*this)).data());
}

template <typename T>
const T *gapvector<T>::data() const noexcept
{
	return addressof(front());
}

#endif
