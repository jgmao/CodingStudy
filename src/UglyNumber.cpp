namespace study{

  bool isUgly(string& s)
  {
    long n = atoi(s.c_str());//temporaly doing like this.
     if (n == 0 || n % 2 == 0 || n % 3 == 0
                || n % 5 == 0 || n % 7 == 0)
            return true;
     else
       return false;
  }
  
  string add(string& left, string& right)
  {
    long a = atoi(left.c_str());
    long b = atoi(right.c_rtr());
    long c = a+b;
    return to_string(c);
  }  
  
  string minus(string& left, string& right)
  {
    long a = atoi(left.c_str());
    long b = atoi(right.c_rtr());
    long c = a-b;
    return to_string(c);
  }  
  
  int countUgly(string& s)
  {
    //s is the input string, i is where to cut
    int count=0;
    int n = s.size();
    if (n==1)
    {
      count=(int)isUgly(s);
    }
    for (int i=n-1; i>0;i++)
    {
      count+= countUgly(s.substr(0,i))+countUgly(s.substr(i+1,n-i));
    }
    return count;
  }


}













}
