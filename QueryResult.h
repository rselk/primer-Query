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
   
    std::set<line_no>::iterator begin() const
    {
      return lines->begin();
    }
    
    std::set<line_no>::iterator end() const
    {
      return lines->end();
    }

    std::shared_ptr<std::vector<std::string>> get_file() const
    {
      return file;
    }

  private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif
