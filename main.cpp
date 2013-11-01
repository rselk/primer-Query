#include <iostream>

#include "TextQuery.h"
#include "QueryResult.h"
#include "RunQuery.h"
#include "Query.h"

int main()
{
  std::ifstream file("text.txt");
//  runQueries(file);
  Query q = Query("fiery") & Query("bird") | Query("wind");

}
