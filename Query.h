#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>

#include "TextQuery.h"
#include "Query_bash.h"

class Query
{
  friend Query operator~(const Query&);
  friend Query operator|(const Query&, const Query&);
  friend Query operator&(const Query&, const Query&);

  public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const
      { return q->eval(t); }
    std::string rep() const { return q->rep(); }
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;

};

#endif