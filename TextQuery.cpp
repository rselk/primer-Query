#include <iostream>

#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream &is) : file (new std::vector<std::string>)
{
  std::string text;
  while (getline(is, text))
  {
    file->push_back(text);
    int n = file -> size () - 1;
    std::istringstream line(text);
    std::string word;
    while (line >> word)
    {
      auto &lines = wm[word];
      if (!lines)
      {
	lines.reset(new std::set<line_no>);
      }
      lines->insert(n);
    }
  }
}

