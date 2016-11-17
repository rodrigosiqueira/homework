#include <iostream>
#include <string>

#include <sample.hpp>

using namespace std;

int sum_test(int v1, int v2)
{
  return v1 + v2;
}

int sub_test(int v1, int v2)
{
  return v1 - v2;
}

string concatenate_with(string to_concat)
{
  return "Hello: " + to_concat;
}
