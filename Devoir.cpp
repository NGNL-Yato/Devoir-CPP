#include <iostream>

using namespace std;

class Stack {
    private:
        int* stack_;
        int input_size;
        int max_size;
    public:
        Stack(const int& size = 20) : input_size(size), max_size(-1) {  /*constrcteur*/
            stack_ = new int[input_size];
        }
        bool Full_stack() {     /*verifie si la pile est pleine*/
            return max_size == (input_size - 1);
        }
        bool Empty_stack() {    /*verifie si la pile est vide*/
            return max_size == -1;
        }
        Stack& operator<<(int new_element) {    /*equivalent de push*/
            if (!Full_stack()) {
                stack_[++max_size] = new_element;
            } else {
                std::cout << "La pile est pleine." << std::endl;
            }
            return *this;
        }
        Stack& operator>>(int& Input) { /*equivalent de pop*/
            if (!Empty_stack()) {
                Input = stack_[max_size--];
            } else {
                std::cout << "La pile est vide. Opération Impossible." << std::endl;
                Input = -1;
            }
            return *this;
        }
        int operator--() {         
            if (Empty_stack()) {
                return 1;
            } else {
                return 0;
            }
        }
        ~Stack() {
            delete[] stack_;
        }
    };
    int main(){
        Stack p(3);
        int n1=10,n2=20,n3=50;
        p << n1 << n2 << n3 ;
        p >> n1 >> n2 << n3 ;
        p << 100;
        int temp;
        while (!p.Empty_stack()) {
            p >> temp;
            std::cout<<temp<<endl;
        }
        p>>temp;        /* testing empty stack*/
        return 0;
    }