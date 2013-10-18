using namespace study{
  void rotate90(uint32_t* im, int N)
  {
    //assume anti clock wize
    uint32_t temp1,temp2;
    int ctr = N/2; //no value after decimal
    int i_current, j_current;
    int i_rotate,j_rotate;
    int i_shift, j_shift;
    for (int j=0; j<N/2;j++)//j is row number
      for (int i=j; i<N-j-1; i++)//i is col number
      {
        //calc position use 2D rotate matrix
        //R = [cos -sin; sin cos]
        //do coordinate shift
        i_current = i;
        j_current = j;
        temp1 = im[j*N+i];
        do
        {
          i_shift = i_current-ctr;
          j_shift = j_current+ctr;
          if (i_shift==0 && j_shift==0)
            break;
          //rotate
          i_rotate = -j_shift;
          j_rotate = i_shift;
          //do inverse coordinate shift
          i_current = i_rotate+ctr;
          j_current = j_rotate-ctr;
          //update value
          temp2 = im[j_current*N+i_current]; 
          im[j_current*N+i_current]=temp1;           
          temp1 = temp2;
        }
        while(!(i_current==i&&j_current==j))
      }    
  }

}
