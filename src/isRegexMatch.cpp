//test
class RegularExpressionMatch
{

bool isMatch(const char* s, const char* p)
{

    unsigned int i = 0; // i is index for s
    unsigned int j = 0; // j is index for p
    char eos = '\0';
    // I assume there is a '\0' at the end of each input string
    //if (s[i]==eos || p[j]==eos ||p[j]=='*') return false; //error regex or empty input
    while (p[j]!=eos)
    {
        char suffix = p[j+1];
        if (suffix == '*')
        {
                while (s[i]==p[j]||p[j]=='.')
                {
                    if (isMatch(s+i, p+j+2))
                        return true;
                    else
                        i++;
                }
                j+=2;
        }
        else
        {
            if (s[i]==p[j]||p[j]=='.')
            {
                i++; j++;
            }
            else
                return false;
        }
        
    }
    if (p[j]==eos&&s[i]==eos)
        return true;
    else
        return false;
}
};
