#include <iostream>
using namespace std;
class lab_2{
    private:
    static int id;
    public:
    static void setid(int num){
        id=num;
    }
    static void showid(){
        cout<<id;
    }
};
int lab_2::id=0;
int main()
{
    lab_2::setid(101);
    lab_2::showid();
    return 0;
}