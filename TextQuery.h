#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <memory>
#include <map>
#include <vector>
#include <set>
#include <sstream>


class QueryResult;
class TextQuery
{
  public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;

  private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr <std::set<line_no>>> wm;
};

#endif
