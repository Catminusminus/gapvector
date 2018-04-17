#ifndef GAPVECTOR_HPP
#define GAPVECTOR_HPP

#include <vector>

#include "gapvector_iterator.hpp"

namespace my
{
constexpr int N = 10;

template <typename T>
class gapvectorIterator;

template <typename T>
class gapvector
{
  template <typename>
  friend class gapvectorIterator;

public:
  using iterator = gapvectorIterator<T>;
  gapvector::iterator begin();
  gapvector::iterator end();

private:
  std::vector<T> inner_vector;
  int gap_begin = 0;
  int gap_last = N - 1;
  void format_gapvector(int);
  void gap_alloc();

public:
  gapvector();
  void insert(int, const T &);
  void insert(int, T &&);
  void push_back(const T &);
  void push_back(T &&);
  void erase(int);
  void pop_back();
  void clear();
  int size();
  T &operator[](int);
  T &at(int);
};
#include "gapvector_implement.hpp"
};

#endif