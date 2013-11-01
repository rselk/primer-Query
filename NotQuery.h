#ifndef NOTQUERY_H
#define NOTQUERY_H

#include <iostream>
#include <string>

#include "QueryBase.h"
#include "Query.h"

class NotQuery : public QueryBase
{
  friend Query operator~(const Query&);
  
  private:
    NotQuery(const Query &q): query(q) {}
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query &operand)
{
  return std::shared_ptr<QueryBase>(new NotQuery(operand));
}


#endif
