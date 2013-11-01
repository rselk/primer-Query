#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include <iostream>
#include <string>

#include "QueryBase.h"
#include "Query.h"


//BinaryQuery does not define eval function
//BinaryQuery is an abstract base class

class BinaryQuery: public QueryBase
{
  protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
      lhs(l), rhs(r), opSym(s) {}

    std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + 
      rhs.rep() + ")"; }

    Query lhs, rhs;
    std::string opSym;
};

#endif
