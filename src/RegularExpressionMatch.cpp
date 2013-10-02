//test
namespace study{
bool isMatch(const char* s, const char* p)
{

    unsigned int i = 0; // i is index for s
    unsigned int j = 0; // j is index for p
    char eos = '\0';
    // I assume there is a '\0' at the end of each input string
    //if (s[i]==eos || p[j]==eos ||p[j]=='*') return false; //error regex or empty input
     
    if (p[j]==eos&&s[i]==eos)
        return true;
    if (p[j]==eos&&s[i]!=eos)
        return false;
  //  if (p[j]!=eos&&s[i]==eos)
  //      return false;

    char suffix = p[j+1];
    if (suffix == '*')
    {
        while (s[i]==p[j]||p[j]=='.')
        {
            if (s[i]==eos)
                break;
             ++i;
             if (isMatch(s+i, p+j+2))
                return true;
        }
        j+=2;
        return isMatch(s,p+j);
    }
    else
    {
        if (s[i]==p[j]||p[j]=='.')
        {
            i++; j++;
            return isMatch(s+i,p+j);
        }
        else
            return false;
    }
        
   
}
}