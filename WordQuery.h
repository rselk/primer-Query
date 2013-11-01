#ifndef WORDQUERY_H
#define WORDQUERY_H

#include <iostream>
#include <string>

#include "TextQuery.h"
#include "QueryResult.h"
#include "QueryBase.h"

class WordQuery: public QueryBase
{
  friend class Query;

  private:
  WordQuery(const std::string &s) : query_word(s) {}
  QueryResult eval(const TextQuery &t) const
    { return t.query(query_word); }
  std::string rep() const { return query_word; }
  std::string query_word;
};

#endif
