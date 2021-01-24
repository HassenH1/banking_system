#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class Person {
    private: 
        std::string name;
        int account_number;
        double balance;

    public:
        //constructor overload
        Person(){
        }
        Person(std::string n, int acc_num, double bal = 0)
            : name(n), account_number(acc_num), balance(bal)
        { 
        }

        //Destructor
        ~Person(){
        }

        //getters
        std::string get_name(){
            return name;
        }
        int get_acc_num(){
            return account_number;
        }
        double get_bal(){
            return balance;
        }

        void set_bal(double amount, std::string d_w){
            if(d_w == "deposit"){
                balance += amount;
                std::cout << "==============Deposit was successful=================" << std::endl;	
                std::cout << "Account balance is " << get_bal() << std::endl;
                std::cout << std::endl;
            } else if(d_w == "withdrawal"){
                balance -= amount;
                std::cout << "==============Withdrawal was successful=================" << std::endl;
                std::cout << "Account balance is " << get_bal() << std::endl;
                std::cout << std::endl;
            }
        }

        void print(){
            std::cout << std::endl;
            std::cout << "==========Account Details==========" << std::endl;
            std::cout << "Account Num: " << account_number << std::endl;
            std::cout << "name: " << name << std::endl;
            std::cout << "Balance: " <<  balance << std::endl;
        }

        //deposit money into account
        double deposit(){
            std::cout << std::endl;
            std::cout << "==========Deposit==========" << std::endl;
            std::cout << "How much would you like to Deposit? ";
            double dep{};
            std::cin >> dep;
            return dep;
        }
        double withdrawal(){
            std::cout << std::endl;
            std::cout << "==========Withdrawal==========" << std::endl;
            std::cout << "How much would you like to Withdraw? ";
            double dep{};
            std::cin >> dep;
            return dep;
        }

};

Person null_person;

class Account {
    private:
        std::vector<Person> list_acc;
        //Person p;
    public: 
        //create new Account and Using the person class to create new person
        void new_account(int acc_num, std::string n, double dep = 0){
            Person p(n, acc_num, dep);
            list_acc.push_back(p);
            std::cout << std::endl;
            std::cout << "==========Account was Created Successfully==========" << std::endl;
            p.print();
        }

        //print all accounts 
        void print_all_acc(){
            if(list_acc.size() > 0){
                for(auto i : list_acc){
                    std::cout << "==============================" << std::endl;
                    std::cout << "Account Number: " << i.get_acc_num() << std::endl;
                    std::cout << "Name: " << i.get_name() << std::endl;
                    std::cout << "Balance: " << i.get_bal() << std::endl;
                    std::cout << "==============================" << std::endl;
                }

            } else {
                std::cout << "There are no accounts in the List" << std::endl;
            }
        }

        //this is not working right
        Person& find_acc(int id){
            for(Person& i : list_acc){
                if(id == i.get_acc_num()){
                    std::cout << i.get_name() << std::endl;
                    std::cout << i.get_bal() << std::endl;
                    return i;
                }
            }
            return null_person; //problem here,
        }
};

class Menu {
    public:
        Account a;
        Person p;
        //the menu
        void menu(){
            std::cout << std::endl;
            std::cout << "==========Menu==========" << std::endl;
            std::cout << "1. Create Account" << std::endl;
            std::cout << "2. Print List of Accounts" << std::endl;
            std::cout << "3. Deposit into Account" << std::endl;
            std::cout << "4. Withdrawal from Account" << std::endl;
        }

        //menu choices based on input
        void menu_choice(char &input){
            std::cout << std::endl;
            std::cout << "Please make a Choice or press e to exit: ";
            std::cin >> input;
            switch(input){
                case '1': {
                              std::cout << std::endl;
                              std::cout << "==============Creating an Account===============" << std::endl;
                              std::cout << "Enter your name: ";
                              std::string name;
                              std::cin.ignore();
                              std::getline(std::cin, name);
                              int account_number = rand() % 100 + 1; //gets random number for account
                              /*
                                 std::cout << "Checking or Savings?(C/S)?";
                                 if(input == 's' || input == 'S'){
                                 p.savings_acc();
                                 } else if(input == 'c' || input == 'C'){
                                 p.checkings_acc()
                                 }*/
                              std::cout << "Would you like to deposit?(Y/N) ";																								
                              double deposit_amount{};
                              char input{};
                              std::cin >> input;
                              if(input == 'y' || input == 'Y'){
                                  deposit_amount = p.deposit();
                              }
                              a.new_account(account_number, name, deposit_amount);
                              std::cout << "================================================" << std::endl;
                              break;
                          }
                case '2': {
                              std::cout << std::endl;
                              std::cout << "=================List of Accounts=============" << std::endl;
                              a.print_all_acc();
                              std::cout << "==============================================" << std::endl;
                              break;	  
                          }
                case '3': {
                              std::cout << std::endl;
                              std::cout << "==============Deposit into Account=============" << std::endl;
                              std::cout << "Enter your Account ID: ";
                              int input{};
                              std::cin >> input;
                              Person &p = a.find_acc(input);
                              if(p.get_acc_num() == 0){
                                  std::cout << "Account does not exists" << std::endl;
                                  break; 
                              } else {
                                  double new_amount{};
                                  new_amount = p.deposit();
                                  p.set_bal(new_amount, "deposit");
                                  break;
                              }
                          }
                case '4': {
                              std::cout << std::endl;
                              std::cout << "==============Withdrawal from Account=============" << std::endl;
                              std::cout << "Enter your Account ID: ";
                              int input{};
                              std::cin >> input;
                              Person &p = a.find_acc(input);
                              if(p.get_acc_num() == 0){
                                  std::cout << "Account does not exists" << std::endl;
                                  break;
                              } else {
                                  double withdrawal_amount{};
                                  withdrawal_amount = p.withdrawal();
                                  p.set_bal(withdrawal_amount, "withdrawal");
                                  break;
                              }
                          }
                default: {
                             if(input == 'e'){
                                 std::cout << "Goodbye" << std::endl;
                             } else{
                                 std::cout << "please choose or exit" << std::endl;
                             } 
                             break;
                         }
            }
        }
};

int main() {
    Menu m;
    char input{};
    srand(time(NULL));
    do{
        m.menu();
        m.menu_choice(input);
    } while(input != 'e');

    return 0;
}
