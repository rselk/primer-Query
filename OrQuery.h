#ifndef ORQUERY_H
#define ORQUERY_H

#include <iostream>
#include <memory>

#include "BinaryQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

class OrQuery: public BinaryQuery
{
  friend Query operator|(const Query&, const Query&);

  private:
    OrQuery(const Query &left, const Query &right):
      BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
  return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif
