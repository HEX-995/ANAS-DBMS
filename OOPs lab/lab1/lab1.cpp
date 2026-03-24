#include<iostream>
using namespace std;

class students{
    private:
    int roll_no;
    string name;
    string branch;

    public:

    void set_data(int roll, string n, string b){
        this->roll_no = roll;
        this->name = n;
        this->branch = b;
    }

    void print_data(){
        cout<<this->roll_no << endl << this->name <<endl <<this->branch <<endl;
    }
};

class employee{
    private:
    int employee_id;
    int age;

    public:
    void enter_data(int employee_id, int age){
        this-> employee_id = employee_id;
        this->age = age;
    }

    void get_data(){
        cout<<"Employee id is "<<this->employee_id<<endl<<"Age is "<<this->age<<endl;

    }

};

class library{
    private:
    string book_name;
    int no_of_days;
    int fees;

    public:
    void enter_data(string book_name, int no_of_days, int fees){
    this-> book_name = book_name;
    this->no_of_days = no_of_days;
    this-> fees = fees;
    }

    void print(){
        cout << "book name is " <<this->book_name<<endl<<"no of days for which book is issued is "<<this->no_of_days <<endl<<"Fees is "<<this->fees<<endl;
    }

};

class loan{
    private:
        int price;
        string typeof_loan;
        int date;
    public:
        void fill_data(int price, string typeof_loan, int date){
            this-> price = price;
            this->typeof_loan = typeof_loan;
            this-> date = date;
        }

        void write_data(){
            cout<<price<<" "<<typeof_loan<<" "<<date<<" "<<endl;
        }

};

int main(){

   students s1;
   s1.set_data(24152, "rehan", "CSE");
   s1.print_data();
   cout<<".......................................";
   cout<<endl;

   employee e1;
   e1.enter_data(984217, 30);
   e1.get_data();
   cout<<".......................................";
   cout<<endl;

   library b1;
   b1.enter_data("Let us C++", 20, 120);
   b1.print();
   cout<<".......................................";
   cout<<endl;

   loan l1;
   l1.fill_data(200000, "Home", 29);
   l1.write_data();
   cout<<".......................................";
   cout<<endl;

    return 0;
}



