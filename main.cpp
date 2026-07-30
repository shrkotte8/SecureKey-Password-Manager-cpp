#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

struct Account{
    string website;
    string username;
    string password;
};
vector<Account> accounts;

void addAccount();
void viewAccount();
void searchAccount();
void deleteAccount();
void checkPasswordStrength();

int main(){
    int choice;
    while(true){
        cout<<"Welcome to SecureKey, your trusted password manager!\n";
        cout<<"1. Add Account"<<endl;
        cout<<"2. View Account"<<endl;
        cout<<"3. Search Account"<<endl;
        cout<<"4. Delete Account"<<endl;
        cout<<"5. Password Strength Checker"<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"Enter your choice"<<endl;
        cin>>choice;


        switch(choice)
        {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                checkPasswordStrength();
                break;
            case 6:
                cout<<"Thank you!\n";
                return 0;
            default:
                cout<<"Invalid choice"<<endl;
        }
       
    }
}

void addAccount(){
    Account temp;
    cout<<endl<<"Enter website: ";
    cin>>temp.website;
    cout<<"Enter username: ";
    cin>>temp.username;
    cout<<"Enter password: ";
    cin>>temp.password;

        accounts.push_back(temp);
        cout<<"\nAccount added successfully!\n\n";
    
}
void viewAccount(){
    if(accounts.empty()){
        cout<<"No accounts found\n\n";
        return;
    }
    for(int i=0;i<accounts.size();i++){
        cout<<"Account "<<i+1<<":\n";
        cout<<"Website: "<<accounts[i].website<<endl;
        cout<<"Username: "<<accounts[i].username<<endl;
        cout<<"Password: "<<accounts[i].password<<endl<<endl<<"============================="<<endl;
        
    }
}

void searchAccount(){
    cout<<"Enter website to search: ";
    string website;
    cin >> website;
    for(int i=0; i<accounts.size(); i++){
        if(accounts[i].website==website){
            cout<<"Account Found!"<<endl;
            cout<<"Website: "<<accounts[i].website<<endl;
            cout<<"Username: "<<accounts[i].username<<endl;
            cout<<"Password: "<<accounts[i].password<<endl<<endl;

            return;
        }
    }
    cout<<"Account not found.\n\n";
}
void deleteAccount(){
    string website;
    cout<<"Enter website to delete: ";
    cin >> website;
    for(int i=0; i<accounts.size(); i++){
        if(accounts[i].website==website){
            accounts.erase(accounts.begin() + i);
            cout<<"\nAccount deleted successfully!\n\n";
            return;
        }
    }
    cout<<"\nAccount not found.\n";
}
void checkPasswordStrength(){
    string password;
    cout<<"Enter Password: ";
    cin>>password;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    for(int i=0; i<password.length(); i++){
        if(isupper(password[i])){
            hasUpper= true;
        }
        if(islower(password[i])){
            hasLower= true;
        }
        if(isdigit(password[i])){
            hasDigit= true;
        }
        if(!isalnum(password[i])){
            hasSpecial= true;
        }
    }
    int score=0;
    if(password.length()>=8){
        score++;
    }
    if(hasUpper){
        score++;
    }
    if(hasLower){
        score++;
    }
    if(hasDigit){
        score++;
    }
    if(hasSpecial){
        score++;
    }
    if(password.length()<8 || score<=2){
        cout<<"Weak Password\n\n";
    }
    else if(score==5){
        cout<<"Strong Password\n\n";
    }
    else{
        cout<<"Medium Password\n\n";
    }
}