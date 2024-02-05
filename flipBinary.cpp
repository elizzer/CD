#include<iostream>
#include<string>

using namespace std;

void decToBinary(int n,int len) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    }

    while(i<len){
        binaryNum[i]=0;
        i++;
    }
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 
 

int main(){

    string in;    
    cin>>in;
    string mask="";
    int len=in.length();

    for(int i=0;i<len/2;i++){
        mask+="10";
    }
    if(len%2!=0){
        mask+="1";
    }
    cout<<endl<<mask;
    int maskValue=stoi(mask,0,2);
    int inputValue=stoi(in,0,2);
    int result = inputValue^maskValue;
    cout<<endl;
    decToBinary(result,len);
    return 0;
}