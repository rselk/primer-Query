#ifndef QUERY_RESULT
#define QUERY_RESULT 

#include <iostream>
#include <memory>
#include <set>
#include <vector>

#include "TextQuery.h"

class QueryResult
{
  
  friend std::ostream &print(std::ostream&, const QueryResult&);

  public:
    using line_no = TextQuery::line_no;

    QueryResult (std::string s, std::shared_ptr<std::set<line_no>> p,
	std::shared_ptr<std::vector<std::string>> f):
      sought(s), lines(p), file(f) {}

  private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif
