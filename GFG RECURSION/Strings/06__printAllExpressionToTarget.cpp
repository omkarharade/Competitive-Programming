#include <bits/stdc++.h>
using namespace std;


void printExpToTarget(vector<string>&res, string currExp, string input, int target, int pos, int curVal, int last){

    if(pos == input.length()){

        if(curVal == target){
            res.push_back(currExp);

        }
        return;
    }

    for (int i = pos; i < input.length(); i++)                              
    {
        if(i != pos && input[pos] == '0' ){
            break;
        }

        string part = input.substr(pos, i+1 - pos );
        int curr  = atoi(part.c_str());

        if(pos == 0){

            printExpToTarget(res, part, input, target, i+1, curr, curr ); // last variable is kept curr instead of 0  because for last = 0 -->  if 1*2 is there then 1-0 + 1*2 = 3 , which should be 2 
        }

        else{
            printExpToTarget(res, currExp+"+"+part , input, target, i+1, curVal + curr , curr );
            printExpToTarget(res, currExp+"-"+part , input, target, i+1, curVal - curr , -curr ); // important step last = -curr;
            printExpToTarget(res, currExp+"*"+part , input, target, i+1, curVal - last + (last * curr) , last * curr );
        }
    }
}

vector<string> getExprs(string input, int target){

    vector<string> res;
    printExpToTarget(res, "", input, target, 0, 0, 0); 

    return res;
}

int main(){
    string str = "12345";
    int n = str.length();
    int target = 10;

    vector<string> res = getExprs(str, target);

    for(auto s : res){
        cout << s <<"\n";
    }
    return 0;
}