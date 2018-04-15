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
  std::shared_ptr<gapvector<T>> gap_vector;
  int index = 0;

public:
  void increment();
  void decrement();
  T &dereference() const;
  bool equal(const gapvectorIterator<T> &) const;
  size_t distance_to(const gapvectorIterator<T> &) const;
  void advance(size_t);
  /*size_t index;
  std::shared_ptr<gapvector<T>> ptr_gap_vector;
  gapvectorIterator();
  gapvectorIterator(std::shared_ptr<gapvector<T>>, int);
*/
public:
  gapvectorIterator(const gapvectorIterator<T> &);
};
#include "gapvector_iterator_implement.hpp"
};

#endif