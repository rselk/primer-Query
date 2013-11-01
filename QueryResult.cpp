#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
  os << qr.sought << " occours " << 
    qr.lines->size() << " times" <<std::endl;

  for (auto num : *qr.lines)
  {
    os << "\t(line " << num + 1 << ") " 
      << *(qr.file->begin() + num) << std::endl;
  }

  return os;
}

QueryResult TextQuery::query(const std::string &sought) const
{
  static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
  auto loc = wm.find(sought);

  if (loc == wm.end())
    return QueryResult(sought, nodata, file); // not found
  else
    return QueryResult(sought, loc->second, file);
}
