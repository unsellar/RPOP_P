#include <iostream>
#include <fstream>
using namespace std;

//+-/*~
int task1(){
    stack<int> nums;
    string input;
    ifstream file ("/Users/vsevolod/Documents/RPOP_P/RPOP_P/output.txt");
    
    while(file >> input){
        if(input != "+" and input != "-" and input != "/" and input != "*" and input != "~"){
            nums.push(stoi(input));
        }else if (input == "+"){
            int a, b;
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            nums.push(a + b);
            
        }else if (input == "-"){
            int a, b;
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            nums.push(a - b);

        }else if (input == "/"){
            int a, b;
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            nums.push(a / b);

        }else if (input == "*"){
            int a, b;
            a = nums.top();
            nums.pop();
            b = nums.top();
            nums.pop();
            nums.push(a * b);

        }else if (input == "~"){
            int a;
            a = nums.top();
            nums.pop();
            nums.push(-a);

        }
    }
    return nums.top();
}

string task2(){
    //2 + 5 * 2 + 4
    //2 5 2 * + 4 +
    stack<string> opers;
    string output;
    string input;
    ifstream file ("/Users/vsevolod/Documents/RPOP_P/RPOP_P/input.txt");
    while(file >> input){
        if(input != "+" and input != "-" and input != "/" and input != "*" and input != "~"){
            output += input + " ";
            
        }else if (input == "+" or input == "-"){
            if(opers.empty() == true or (opers.top() != "*" and opers.top() != "/" and opers.top() != "~")){
                opers.push(input);
            }else{
                while(opers.empty() != 1){
                    output += opers.top() + " ";
                    opers.pop();
                }
                opers.push(input);
            }
        }else if (input == "*" or input == "/"){
            if(opers.top() != "~" or opers.empty() == true){
                opers.push(input);
            }else{
                while(opers.empty() != 1){
                    output += opers.top() + " ";
                    opers.pop();
                }
                opers.push(input);
            }
        }else if (input == "~"){
            file >> input;
            output += input + " ";
            output += "~ ";
        }
    }
    while(opers.empty() != 1){
        output += opers.top() + " ";
        opers.pop();
    }
    return output;
}

int main() {
    ofstream output;
    output.open("/Users/vsevolod/Documents/RPOP_P/RPOP_P/output.txt");
    int num;
    cout << "Task num: ";
    cin >> num;
    if(num == 1){
        task1();
    }
    if(num == 2){
        output << task2() << endl;
        output << task1();
    }
    cout << "end" << endl;
    return 0;
}
