#include <iostream>

#include "TextQuery.h"
#include "QueryResult.h"
#include "RunQuery.h"

int main()
{
  std::ifstream file("text.txt");
  runQueries(file);
}
