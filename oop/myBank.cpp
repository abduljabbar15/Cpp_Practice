#include<bits/stdc++.h>

using namespace std;

class AjBank {
    public:
        string account_holder;
        string account_number;
    private:
        string password;
    protected:
        int balance;
    public:
        AjBank(string account_holder, string password){
        this->account_holder = account_holder;
        this->password = password;
        this->balance = 0;
        this->account_number = (rand()%100000)+10000;
        };
        int money_deposit(string password, int amount){
        if(this->password==password){
            this->balance+=amount;
            return 1;
        }else return -1;
        };
        int get_money (string pass){
        if(this->password == pass)  return balance;
        else return -1;
        }
};
AjBank* create_account(){
    string name,pass;
    cout<<"Let's create an account\n";
    cout<<"What's Your name\n";
    cin>>name;
    cout<<"Create your password\n";
    cin>>pass;
    AjBank *myAccount = new AjBank(name,pass);
    cout<<"\n";
    cout<<"\n";
    cout<<"Congratulation "<<myAccount->account_holder<<" Your account id is "<<myAccount->account_number<<endl;
    return myAccount;

}

void welcomeBank(int *customer_behavior){
    cout<<"........................"<<endl;
    cout<<"1. Deposit money"<<endl;
    cout<<"2. Exit AJ Bank"<<endl;
    cout<<"........................"<<endl;
    cin>>*customer_behavior;
}

void deposit_money(AjBank *myAccount){
string pass;
int add_money;
cout<<"How many money you want to add: "<<endl;
cin>>add_money;

cout<<"Enter your password: "<<endl;
cin>>pass;

 int isDeposit = myAccount->money_deposit(pass,add_money);
 if(isDeposit==1){
    int newBalance = myAccount->get_money(pass);
    if(newBalance!=-1) cout<<add_money<<"$ is added ;)"<<" Now your new Balance: "<<newBalance;
    else cout<<"Try again";
 }


}

int main(){
cout<<"Wellcome to AJ Bank"<<endl;
 AjBank *myAccount = create_account();
while(1){
    int customer_behavior=NULL;
    welcomeBank(&customer_behavior);

    if(customer_behavior==2) {

    cout<<"Thank for visit AJ Bank\n";
        return 0;

    }else if( customer_behavior==1){

        deposit_money(myAccount);
    }
}
return 0;
}
