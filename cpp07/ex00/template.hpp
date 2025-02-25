#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

#include <string>
#include <iostream>

template <typename T> void swap(T &x, T &y)
{
    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

template <typename T> T min(T x, T y)
{
  return (x > y ? y : x);
}

template <typename T> T max(T x, T y)
{
   return (y > x ? y : x);
}

#endif