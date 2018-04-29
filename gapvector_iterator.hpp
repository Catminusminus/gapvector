#ifndef GAPVECTOR_ITERATOR_HPP
#define GAPVECTOR_ITERATOR_HPP

#include "gapvector.hpp"
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <memory>

namespace my
{
template <typename T>
class gapvector;

template <typename T>
class gapvectorIterator : public boost::iterator_facade<gapvectorIterator<T>, T, boost::random_access_traversal_tag>
{
  template <typename>
  friend class gapvector;

private:
  friend class boost::iterator_core_access;
  gapvector<T> *gap_vector;
  int index = 0;

  gapvectorIterator();
  gapvectorIterator(gapvector<T> *);

public:
  void increment();
  void decrement();
  T &dereference() const;
  bool equal(const gapvectorIterator<T> &) const;
  size_t distance_to(const gapvectorIterator<T> &) const;
  void advance(size_t);
};
#include "gapvector_iterator_implement.hpp"
};

#endif
