#ifndef QUERYBASE_H
#define QUERYBASE_H

//QueryBase is an abstract base class

class QueryBase
{
  protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

  private:
    //QueryResult and rep are pure virtual functions
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

#endif
