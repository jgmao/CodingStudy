#include "CodingStudy.h"
#include <map>
#include <set>
namespace study{
  void removeDuplicateBitMap(std::string& str)
  {
    //assume only lower case a-z
    //assume the alphabet is not too long 
    //then I can use a integer as bit map
    //for 26 chars use 32bit int is fine
    int32_t map=0;
    int i=0;
    while (i<str.size())//the size is vary during loop
    {
      unsigned int index = (unsigned int)(str[i]-'a');
      if (map && (1<<index))
      {
        str.erase(i,1);
      }
      else
      {
        map+=(1<<index);
        i++;
      }
    }
  }
    void removeDuplicateHashMap(std::string& str)
  {
    std::set<char> map;
    int i=0; 
    while (i<str.size())
    {
      if (map.end()==map.find(str[i]))
      {
        str.erase(i,1);
      }
      else
      {
        map.insert(str[i]);
        i++;
      }
    }
  }
    
    bool isAnagram(const std::string& str1, const std::string& str2)
  {
    if (str1.size()!=str2.length())
      return false;
    if (str1.size()==0)
      return true;
    std::map<char,int> map;
    //build map by str1
    for (int i=0; i< str1.size(); i++)
    {
      if (map.end()!=map.find(str1[i]))
        map.at(str1[i])++;
      else
        map.insert(std::pair<char,int>(str1[i],1));
    }
    for (int i=0; i < str2.size(); i++)
    {
      if (map.end()!=map.find(str2[i]))
      {
        if (map.at(str2[i])==0)
          return false;
        else
        {
          map.at(str2[i])--;
        }       
      }
      else
        return false;
    }
    return true;
  
  }
}
