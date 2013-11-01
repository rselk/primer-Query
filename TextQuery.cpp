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



/*
void runQueries (std::ifstream &infile)
{
  TextQuery tq(infile);

  while (true)
  {
    std::cout<<"Enter word to look for: (q to quit) " <<std::endl;
    std::string input;
    if (!(std::cin>>input) || input == 'q') break;

    print(std::cout, tq.query(s)) << std::endl;
  }
}
*/
