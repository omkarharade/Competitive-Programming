#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void display(vector<int> &v){
    vector<int> :: iterator iter;

    for (iter = v.begin() ; iter != v.end(); iter++)
    {
        cout << *(iter) << " ";
    }
    cout << "\n";
    
}

int main(){
    
    vector<int> vec;
    vec.push_back(20);
    vec.push_back(30); 
    vec.push_back(40); 
    vec.push_back(50); 
    vec.push_back(60); 
    vec.push_back(70); 
    vec.push_back(80); 
    vec.push_back(90); 
    display(vec);
    cout << vec.at(2) << endl;
    display(vec);
    vec.insert(vec.begin(), 1000);
    display(vec);
    vec.pop_back();
    display(vec);
    sort(vec.begin(), vec.begin()+4);
    display(vec);
    sort(vec.begin(), vec.end());
    display(vec);
    return 0;
}