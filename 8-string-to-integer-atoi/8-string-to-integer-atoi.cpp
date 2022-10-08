class Solution {
public:
    int myAtoi(string s) {
  bool flag=false;
//For spaces
     int currentIndex=0;
     while(currentIndex<s.size()){
        if(s[currentIndex]==' ') currentIndex++;
        else break;
     }
   //Special character
     if(s[currentIndex]=='-'){
          currentIndex++;

         flag=true;
        
     }else if(s[currentIndex]=='+') currentIndex++;

     long long num=0;
   for(int j=currentIndex;j<s.size();j++){
       if(s[j]>='0' and s[j]<='9')
      { num=num*10+(s[j]-'0');
      //Integer Out of range
       if(num>=INT_MAX) break;
       
       }else 
      //Only Integer No characters allowed 
       break;
   }

    if(flag==true)
    num*=-1;
    //Out of range exception
    if(num<=INT_MIN)return INT_MIN;         
    else if(num>=INT_MAX) return INT_MAX;
    return num;





    }
};