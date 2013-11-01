#ifndef QUERYBASE_H
#define QUERYBASE_H

#include <string>
//QueryBase is an abstract base class

class Query; //usat
class QueryBase
{
  friend Query; //usat
  protected:
    using line_no = TextQuery::line_no;
    virtual ~QueryBase() = default;

  private:
    //QueryResult and rep are pure virtual functions
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

#endif
