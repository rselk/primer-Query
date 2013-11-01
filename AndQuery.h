#ifndef ANDQUERY_H
#define ANDQUERY_H

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>

#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"

class AndQuery: public BinaryQuery
{
  friend Query operator& (const Query&, const Query&); //see below

  private:
    AndQuery(const Query &left, const Query &right):
      BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
  return std::shared_ptr<QueryBase>(new AndQuery(lhs,rhs));
}

#endif
