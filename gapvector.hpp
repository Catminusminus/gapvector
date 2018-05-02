#ifndef GAPVECTOR_HPP
#define GAPVECTOR_HPP

#include <vector>

#include "gapvector_iterator.hpp"
#include "gapvector_const_iterator.hpp"

namespace my
{
constexpr size_t N = 10;

template <typename T>
class gapvectorIterator;
template <typename T>
class gapvectorConstIterator;

template <typename T>
class gapvector
{
  template <typename>
  friend class gapvectorIterator;
  template <typename>
  friend class gapvectorConstIterator;

public:
  using iterator = gapvectorIterator<T>;
  using const_iterator = gapvectorConstIterator<T>;
  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;

  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

private:
  std::vector<T> inner_vector;
  size_t gap_begin = 0;
  size_t gap_last = N - 1;
  void format_gapvector(size_t);
  void gap_alloc();

public:
  gapvector();
  void insert(size_t, const T &);
  void insert(size_t, T &&);
  iterator insert(iterator, const T &);
  iterator insert(iterator, T &&);
  void push_back(const T &);
  void push_back(T &&);
  void erase(size_t);
  iterator erase(iterator);
  void pop_back();
  void clear() noexcept;
  int size() const noexcept;
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
