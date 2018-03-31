#ifndef GAPVECTOR_HPP
#define GAPVECTOR_HPP

#include <vector>

namespace my
{
template <typename T>
class gapvector
{
  /*friend gapvectorIterator;

public:
  using iterator = gapvectorIterator;
  gapvector::iterator begin();
  gapvector::iterator end();*/

private:
  std::vector<T> inner_vector;
  int gap_begin = 0;
  int gap_last = 0;
  void format_gapvector(int);
  void gap_alloc();

public:
  gapvector();
  void insert(int, const T &);
  void push_back(const T &);
  void erase(int);
  void pop_back();
  int size();
  T &operator[](int);
  T &at(int);
};
#include "gapvector_implement.hpp"
};

#endif