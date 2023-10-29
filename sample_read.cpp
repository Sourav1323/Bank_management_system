#include<iostream>
#include<fstream>
using namespace std;
struct details{
  char first_name[100];
  char last_name[100];
  int account_number;
  char mobile_number[10];
  int balance;
  char password[100];
};
int main(){
    details b;
    int g;
    char pass[100];
    ifstream fin;
    fin.open("temp.bin",ios::binary|ios::in );
    int match=0;
    while(1){
  // fin.seekg(-320,ios::end);
   fin.read((char*)&b,sizeof(b));
  // cout<<fin.tellg()<<" ";
   if(fin.eof())
   break;
  //  if(g==b.account_number){
  //   for(int i=0;pass[i];i++){
  //   //  if(pass[i]==b.password[i])
  //   //  match=1;
  //   }
   // if(match==1)
 cout<<b.first_name<<" "<<b.last_name<<" "<<b.account_number<<" "<<b.mobile_number<<" "<<b.balance<<" "<<b.password<<"\n\n";
    }
    }
 