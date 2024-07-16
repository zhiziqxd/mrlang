#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <unistd.h>
using namespace std;
string in;
map<string,long long int> var_num;
map<string,string> var_str;
int wh;
string c[10000];
int cnt;
bool flag;
void cl(){
    if(flag==true&&in!="endwh"){
        cnt++;
        in[cnt]=in;
    }
    else if(in=="endwh"){
        flag=false;
        for(int i=1;i<=cnt;i++){
            cl(c[i]);
        }
        cnt=0;
    }
    else if(in=="assign_str"){
        string name,value;
        cin>>name;
        getline(cin,value);
        var_str[name]=value;
    }
    else if(in=="assign_num"){
        string name;
        int value;
        cin>>name>>value;
        var_num[name]=value;
    }
    else if(in=="for"){
       string name;
       cin>>name;
       wh=var_num[wh];
       flag=true;//接受之后的指令
    }
    else if(in=="input1"){
        string name;
        int a;
        cin>>name;
        freopen("CON","r",stdin);
        cin>>a;
        var_num[name]=a;
        freopen("mrlang.txt","r",stdin);
    }
    else if(in=="input2"){
        string name;
        string a;
        cin>>name;
        freopen("CON","r",stdin);
        cin>>a;
        var_str[name]=a;
        freopen("mrlang.txt","r",stdin);
    }
    else if(in=="out"){
        string name;
        getline(cin,name);
        if(name[0]==':'){
            for(int i=1;i<name.size();i++){
                cout<<name[i];
            }
        }
        else if(name=="endl"){
            cout<<endl;
        }
        else{
            if(var_str[name]!=""){
                cout<<var_str[name];
            }
            else{
                cout<<var_num[name];
            }
        }
    }
    else if(in=="system"){
        string command;
        getline(cin,command);
        system(command.c_str);
    }
    else if(in=="num_count"){
        string n1,n2;
        char x;
        cin>>n1>>x>>n2;
        if(x=='+'){
            var_num["flag"]=n1+n2;
        }
        else if(x=='-'){
            var_num["flag"]=n1-n2;
        }
        else if(x=='*'){
            var_num["flag"]=n1*n2;
        }
        else if(x=='/'){
            var_num["flag"]=n1/n2;
        }
        else if(x=='%'){
            var_num["flag"]=n1%n2;
        }
        else{
            cout<<"出现错误"<<endl;
            exit(0);
        }
    }
    else if(in=="str+"){
        string n1,n2;
        cin>>n1>>n2;
        n1+=n2;
    }
    else if(in=="sleep"){
        int time_long;
        cin>>time_long;
        sleep(time_long);
    }
    else{
        cout<<"出现错误"<<endl;
    }
}
int main(){
    freopen("mrlang.txt","r",stdin);
    while(cin>>in){
      cl(in);
    }
    cout<<"-------------------"<<endl;
    cout<<"运行完成"<<endl;
    return 0;
}
