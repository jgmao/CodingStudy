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
class AJRNode
{
public:
    string word;
    vector<AJRNode*> next;
public:
    AJRNode(string wd){this->word=wd;}
};

void buildALR(vector<string>& words, vector<AJRNode*>& nodes)
{
    for (int i=0; i< words.size(); i++)
    {
        nodes[i] = new AJRNode(words[i]);
    }
    for (int i=0; i< words.size(); i++)
    {
        for (int j=0;j<words.size();j++)
        {
            if (i!=j)
            {
                if (hamming(words[i],words[j])==1)
                {
                    nodes[i]->next.push_back(nodes[j]);
                }
            }
        }
    }
}

void AstarSearch(AJRNode* start, AJRNode* end)
{


}

int ShortestWordDistance(string filename, string A, string B)
{
  vector<string> words;
  readwords(filename,words);
  vector<AJRNode*> nodes(words.size());
  buildALR(words,nodes);
  if (A.compare(B)==0)
      return 0;
  AJRNode* start=NULL;
  AJRNode* end=NULL;
  bool foundA=false,foundB=false;
  for (int i=0; i<words.size();i++)
  {
      if (A.compare(words[i])==0)
      {
          start = nodes[i];
          foundA=true;
      }
      if (B.compare(words[i])==0)
      {
          end = nodes[i];
          foundB=true;
      }
  }
  if (foundA&&foundB )
    AstarSearch(start,end);
  return 0;
}
}