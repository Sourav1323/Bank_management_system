#include<iostream>
#include<fstream>
using namespace std;
class Bank{
private:
  char first_name[100];
  char last_name[100];
  int account_number;
  char mobile_number[10];
  int balance;
  char password[100];
public:
int Account_number(){
    Bank b;
    int a;
    ifstream fin;
    fin.open("details.bin",ios::binary|ios::in|ios::ate);
    fin.seekg(0,ios::end);
    if(fin.tellg()==0){
        a=100011;
    }
    else{
    fin.seekg(-320,ios::end);
    fin.read((char*)&b,sizeof(b));
    a=b.account_number+1;
    }
    fin.close();
    return a;
}
void Create_account(){
    ofstream fout;
    fout.open("details.bin",ios::binary|ios::app|ios::out);
     if(!fout){
        cout<<"File not opened";
        exit(1);
    }
    fout.seekp(0,ios::end);
    Bank b;
           cout<<"\n\nEnter your first name = ";
           cin>>b.first_name;
           cout<<"\nEnter your last name = ";
           cin>>b.last_name;
           cout<<"\nEnter your mobile number = ";
           cin>>b.mobile_number;
           cout<<"\nEnter the amount to be deposited(in rs) = ";
           cin>>b.balance;
           while(b.balance<1000){
           cout<<"\nPlease enter amount greater than 1000 = ";
           cin>>b.balance;
           }
           cout<<"\nPlease set your password = ";
           cin>>b.password;
          cout<<"\nYour account number generated is = ";
          b.account_number=b.Account_number();
          cout<<b.account_number;
          fout.write((char*)&b,sizeof(b));
          fout.close();
          cout<<"\nAccount has been created. ";
          return;
}
void Check_balance(int x){
    ifstream file;
    Bank b;
    int match=0;
    char pass[100];
    file.open("details.bin",ios::binary|ios::in);
    if(!file){
        cout<<"\nFile could not opened.";
        exit(1);
    }
    while(1){
        file.read((char*)&b,sizeof(b));
        if(file.eof())
        break;
        if(x==b.account_number){
            cout<<"\nEnter the password = ";
            cin>>pass;
            for(int i=0;pass[i];i++){
                if(pass[i]==b.password[i])
                match=1;
                else{
                    match=0;
                    break;
                }
            }
            if(match==1){
                 cout<<endl<<b.first_name<<" "<<b.last_name<<" your account balance is "<<b.balance<<"rs";
                file.close();
                return;
            }
            else{
                cout<<"\nWrong password. Please try again!";
                file.close();
                return;
            }
        }
    }
     cout<<"Account not found.";
             file.close();
             return;
}
void Deposit(int x){
    fstream file;
    Bank b;
    int match=0;
    int d;
    char pass[100];
    file.open("details.bin",ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"\nFile could not opened.";
        exit(1);
    }
    while(1){
        file.read((char*)&b,sizeof(b));
        if(file.eof())
        break;
        if(x==b.account_number){
            file.seekp(-320,ios::cur);
            cout<<"\nEnter the password = ";
            cin>>pass;
            for(int i=0;pass[i];i++){
                if(pass[i]==b.password[i])
                match=1;
                else{
                    match=0;
                    break;
                }
            }
            if(match==1){
                cout<<"\nEnter the amount to be deposited(in rs) = ";
                cin>>d;
                b.balance=b.balance+d;
                cout<<d<<"rs has been deposited in your account.";
                cout<<endl<<b.first_name<<" "<<b.last_name<<" now your account balance is "<<b.balance<<"rs";
                file.write((char*)&b,sizeof(b));
                file.close();
                return;
            }
            else{
                cout<<"\nWrong password. Please try again";
                file.close();
                return;
            }
        }
    }
     cout<<"Account not found.";
             file.close();
             return;
}
void Withdrawal(int x){
    fstream file;
    Bank b;
    int match=0;
    int d;
    char pass[100];
    file.open("details.bin",ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"\nFile could not opened.";
        exit(1);
    }
    while(1){
        file.read((char*)&b,sizeof(b));
        if(file.eof())
        break;
        if(x==b.account_number){
            cout<<"\nEnter the password = ";
            cin>>pass;
            for(int i=0;pass[i];i++){
                if(pass[i]==b.password[i])
                match=1;
                else{
                    match=0;
                    break;
                }
            }
            if(match==1){
                cout<<"\nEnter the amount to be withdrawal(in rs) = ";
                cin>>d;
                if(b.balance-d>1000)
                b.balance=b.balance-d;
                else{
                cout<<"You cannot withdrawal money atleast 1000rs should be in account.";
                file.close();
                return;
                }
                cout<<d<<"rs has been withdrawl from your account.";
                cout<<endl<<b.first_name<<" "<<b.last_name<<" now your account balance is "<<b.balance<<"rs";
                file.seekp(-320,ios::cur);
                file.write((char*)&b,sizeof(b));
                file.close();
                return;
            }
            else{
                cout<<"\nWrong password. Please try again";
                file.close();
                return;
            }
        }
    }
     cout<<"Account not found.";
             file.close();
             return;
}
void Update(int x){
     fstream file;
    Bank b;
    int match=0;
    int d;
    char pass[100];
    file.open("details.bin",ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"\nFile could not opened.";
        exit(1);
    }
    while(1){
        file.read((char*)&b,sizeof(b));
        if(file.eof())
        break;
        if(x==b.account_number){
            cout<<"\nEnter the password = ";
            cin>>pass;
            for(int i=0;pass[i];i++){
                if(pass[i]==b.password[i])
                match=1;
                else{
                    match=0;
                    break;
                }
            }
            if(match==1){
                int n;
                bool r=true;
                while(r){
                    file.seekp(-320,ios::cur);
                    cout<<"1. First name";
                    cout<<"\n2. Last name";
                    cout<<"\n3. Mobile number ";
                    cout<<"\n4. Password";
                    cout<<"\nWhat you want to update : ";
                    cin>>n;
                    if(n==1){
                    cout<<"\nEnter first name : ";
                    cin>>b.first_name;
                    }
                    else if(n==2){
                        cout<<"\nEnter last name : ";
                        cin>>b.last_name;
                    }
                    else if(n==3){
                        cout<<"\nEnter mobile number : ";
                        cin>>b.mobile_number;
                    }
                    else if(n==4){
                        cout<<"\nEnter new password :";
                        cin>>b.password;
                    }
                    file.write((char*)&b,sizeof(b));
                    cout<<"Your Account has been updated.";
                    cout<<"\nDo you want to do any other changes in your account(y/n) : ";
                    char t;
                    cin>>t;
                    if(t=='y' || t=='Y')
                    r=true;
                    else 
                    r=false;
                }
                file.close();
                return;
            }
            else{
                cout<<"\nWrong password. Please try again";
                 file.close(); 
                 return;
            }
        }
    }
     cout<<"Account not found.";
             file.close();
             return;
}
void Close(int x){
     fstream file;
    Bank b,p;
    int match=0;
    int d;
    char pass[100];
    file.open("details.bin",ios::binary|ios::in|ios::out);
    if(!file){
        cout<<"\nFile could not opened.";
        exit(1);
    }
    while(1){
        file.read((char*)&b,sizeof(b));
        if(file.eof())
        break;
        if(x==b.account_number){
            cout<<"\nEnter the password = ";
            cin>>pass;
            for(int i=0;pass[i];i++){
                if(pass[i]==b.password[i])
                match=1;
                else{
                    match=0;
                    break;
                }
            }
            if(match==1){
               char a;
               cout<<"Are you sure you want to close account(y/n) : ";
               cin>>a;
               if(a=='y' || a=='Y'){
                   ofstream fout("temp.bin",ios::binary|ios::out);
                   ifstream fin("details.bin",ios::binary|ios::in);
                   while(1){
                    fin.read((char*)&p,sizeof(p)); 
                    if(fin.eof())
                    break;
                    if(p.account_number!=x){
                        fout.write((char*)&p,sizeof(p));
                    }
                   }
                    cout<<"\nYour account has been deleted.";
                   fin.close();
                   fout.close();
                   file.close();
                   remove("details.bin");
                   rename("temp.bin","details.bin");
                   return;
               }
               else
               return;
            }
            else{
                cout<<"\nWrong password. Please try again";
                file.close();
                return;
            }
        }
    }
     cout<<"Account not found.";
             file.close();
             return;
}
void Admin(){
    Bank b;
    ifstream fin;
    fin.open("details.bin",ios::binary|ios::in);
    cout<<"Enter admin password : ";
    char admin[100]={"Sourav"};
    char pass[100];
    cin>>pass;
    int match=0;
     for(int i=0;pass[i];i++){
                if(pass[i]==admin[i])
                match=1;
                else{
                    match=0;
                    break;
                }
            }
    if(match==1){
    while(1){
        fin.read((char*)&b,sizeof(b));
        if(fin.eof())
        break;
        cout<<b.first_name<<" "<<b.last_name<<" "<<b.account_number<<" "<<b.mobile_number<<" "<<b.balance<<"\n\n";
    }
    fin.close();
    return;
    }
    else{
        cout<<"\nWrong password..";
        return;
    }
}
};
int main(){
     int n;
     fstream file;
     file.open("details.bin",ios::binary|ios::app|ios::out);
      if(!file){
        cout<<"File not opened";
        exit(1);
    }
    else
    file.close();
    bool repeat=true;
    cout<<"========================================================================================================================="<<endl;
    cout<<"                                        Welcome to the Bank! "<<endl;
    cout<<"=========================================================================================================================";
    while(repeat){
        Bank b;
        cout<<"\n\n1. Create your account ";
        cout<<"\n2. Check balance ";
        cout<<"\n3. Deposit money in account ";
        cout<<"\n4. Withdrawal money from account ";
        cout<<"\n5. To update Account credential  ";
        cout<<"\n6. To close an Account ";
        cout<<"\n7. Admin Access ";
        cout<<"\n=========================================================================================================================";
        cout<<"\n\nPlease select the option you want to acces by pressing number ";
        cin>>n;
        if(n==1){
            b.Create_account();
        }
       else if(n==2){
            int ac;
            cout<<"\nEnter the account number = ";
            cin>>ac;
            b.Check_balance(ac);
        }
       else if(n==3){
             int ac;
            cout<<"\nEnter the account number = ";
            cin>>ac;
             b.Deposit(ac);
        }
        else if(n==4){
             int ac;
            cout<<"\nEnter the account number = ";
            cin>>ac;
            b.Withdrawal(ac);
        }
        else if(n==5){
              int ac;
            cout<<"\nEnter the account number = ";
            cin>>ac;
            b.Update(ac);
        }
        if(n==6){
             int ac;
            cout<<"\nEnter the account number = ";
            cin>>ac;
            b.Close(ac);
        }
        if(n==7){
            b.Admin();
        }
         char a;
        cout<<"\nDo you want to access any other facility of Bank (Y/N) = ";
        cin>>a;
        if(a=='y' || a=='Y')
        repeat=true;
        else{
        repeat=false;
        cout<<"-------------------------------------Thank You!----------------------------------------------------";
        }
}
}