#include<iostream>
#include<string>
#include<fstream>
#include<cstdio>
using namespace std;
string s= "C:\\";
string e=".txt";
bool signin(){
    string username,password,us,pw;
    cout<<"Enter username here: ";
    cin>>username;
    cout<<"Enter password here: ";
    cin>>password;
    ifstream read(s+username+e);
    getline(read,us);
    getline(read,pw);
    if((us == username )&& (pw == password)){
        return true;
    }
    else{ return false;}

}
int main(){
    int choice;
 cout<<"1.Sign up to create file\n2.Sign in to open exsisting file\n3.Delete file";
 cout<<"\nYour choice: ";
 cin>>choice;

    if(choice==1){ string username,password;
            cout<<"Select a username : ";
            cin>>username;
            cout<<"Select a password : ";
            cin>>password;
            ofstream file;
            file.open(s+ username+ e);
            file<<username<<endl<<password<<endl;
            file.close();
            main();}

    else if(choice ==2){ bool status = signin();
            if(status){
                cout<<"Successfully signed in!"<<endl;
                system("pause");
                main();

            }else{
                cout<<"Failed sign in"<<endl;
                system("pause");
                main();

            }}
    else if(choice ==3){ string filename,filename1;
            cout<<"Enter the file to be deleted: ";
            cin.ignore();
            getline(cin,filename);
            filename1= s+filename+e;
            if(remove(filename1.c_str())){
                perror("OOPS! couldn't delete the file or file doesn't exist");
                        return 0;    }
            else{
                cout<<"Successfully deleted!"<<endl;
                      return 1;      }

            }
    else{  cout<<"Choice out of the menu cannot be fullfilled.";
            return 0; }

}
