#ifndef GAPVECTOR_HPP
#define GAPVECTOR_HPP

#include <vector>
#include <algorithm>
#include <initializer_list>

#include "gapvector_iterator.hpp"
#include "gapvector_const_iterator.hpp"
#include "gapvector_reverse_iterator.hpp"
#include "gapvector_const_reverse_iterator.hpp"

namespace my
{
constexpr size_t N = 10;

template <typename T>
class gapvectorIterator;
template <typename T>
class gapvectorConstIterator;
template <typename T>
class gapvectorReverseIterator;
template <typename T>
class gapvectorConstReverseIterator;

template <typename T>
class gapvector
{
  template <typename>
  friend class gapvectorIterator;
  template <typename>
  friend class gapvectorConstIterator;
  template <typename>
  friend class gapvectorReverseIterator;
  template <typename>
  friend class gapvectorConstReverseIterator;

public:
  using iterator = gapvectorIterator<T>;
  using const_iterator = gapvectorConstIterator<T>;
  using reverse_iterator = gapvectorReverseIterator<T>;
  using const_reverse_iterator = gapvectorConstReverseIterator<T>;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;

  iterator end() noexcept;
  const_iterator end() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  reverse_iterator rbegin() noexcept;
  const_reverse_iterator rbegin() const noexcept;

  reverse_iterator rend() noexcept;
  const_reverse_iterator rend() const noexcept;

  const_reverse_iterator crbegin() const noexcept;
  const_reverse_iterator crend() const noexcept;

private:
  std::vector<T> inner_vector;
  size_t gap_begin = 0;
  size_t gap_last = N - 1;

  void format_gapvector(size_t);
  void gap_alloc();

public:
  gapvector();
  gapvector(const gapvector &) = default;
  gapvector(gapvector &&) = default;
  gapvector(std::initializer_list<T>);

  gapvector &operator=(const gapvector &) = default;
  gapvector &operator=(gapvector &&) = default;
  gapvector &operator=(std::initializer_list<T>);

  template <class inputIterator, std::enable_if_t<!std::is_integral<inputIterator>::value, std::nullptr_t> = nullptr>
  void assign(inputIterator, inputIterator);
  void assign(size_t, const T &);
  void assign(std::initializer_list<T>);

  void insert(size_t, const T &);
  void insert(size_t, T &&);
  iterator insert(iterator, const T &);
  iterator insert(const_iterator, const T &);
  iterator insert(iterator, T &&);
  iterator insert(const_iterator, T &&);
  void insert(iterator, size_t, const T &);
  iterator insert(const_iterator, size_t, const T &);
  template <class inputIterator>
  void insert(iterator, inputIterator, inputIterator);
  template <class inputIterator>
  iterator insert(const_iterator, inputIterator, inputIterator);

  void emplace(size_t);
  template <class Head, class... Tail>
  void emplace(size_t, Head &&, Tail &&...);
  template <class... Args>
  iterator emplace(const_iterator, Args &&...);

  void push_back(const T &);
  void push_back(T &&);

  template <class... Args>
  void emplace_back(Args &&...);

  void erase(size_t);
  iterator erase(iterator);

  void pop_back();
  void clear() noexcept;
  int size() const noexcept;
  bool empty() const noexcept;
  void swap(gapvector &);

  T &operator[](size_t);
  const T &operator[](size_t) const;

  T &at(size_t);
  const T &at(size_t) const;

  T &front();
  const T &front() const;

  T &back();
  const T &back() const;

  T *data() noexcept;
  const T *data() const noexcept;
};
#include "gapvector_implement.hpp"
};

#endif
