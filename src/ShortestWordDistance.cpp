#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "CodingStudy.h"
using namespace std;
namespace study{
int hamming(string A, string B)
{
  if (A.size()!=B.size())
    return -1;
  else
  {
    int na = A.size();
    string::iterator a = A.begin();
    string::iterator b = B.begin();
    unsigned int num_mismatches = 0;
    while (na) {
        if (*a != *b)
            ++num_mismatches;
        --na;
        ++a;
        ++b;
    }
    return num_mismatches;
  }
}

void readwords(string filename, vector<string>& output)
{
  ifstream file;
  file.open(filename);
  string line;
  int count =0;
  if (file.is_open())
  {
    while (getline(file,line))
    {
      if (*(line.end()-1)=='\t')
          line = line.substr(0,line.size()-1);
      output.push_back(line);
      count++;
    }
    file.close();
  }
  printf("read %d words\n",count);
}

int ShortestWordDistance(string filename)
{
  vector<string> words;
  readwords(filename,words);
  return 0;
}
}