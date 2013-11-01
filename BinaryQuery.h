#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include <iostream>
#include <string>

class BinaryQuery: public QueryBase
{
  protected:
    BinaryQuery(const Query &l, const Query &r, std::string s):
      lhs(l), rhs(r), opSym(s) {}

    std::string rep() cosnt { return "(" + lhs.rep() + " " + opSym + " " + 
      rhs.rep() + ")"; }

    Query lhs, rhs;
    std::string opSym;
};

#endif
