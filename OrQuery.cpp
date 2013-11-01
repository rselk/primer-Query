#include "OrQuery.h"

QueryResult OrQuery::eval(const TextQuery &text) const
{
  auto right = rhs.eval(text), left = lhs.eval(text);
  auto ret_lines = 
      std::make_shared<std::set<line_no>>(left.begin(), left.end());

  ret_lines->insert(right.begin(), right.end());

  return QueryResult(rep(), ret_lines, left.get_file());
}
