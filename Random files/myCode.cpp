#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, p, q, num; 
    cin >> n;
    int lvl[n];
    fill(lvl, lvl+n, 0);
    cin >> p;
    for(int i=0; i < p; i++ ){
        cin >> num;
        lvl[num -1]++;
    }

    cin >> q;
    for(int i=0; i < q; i++ ){
        cin >> num;
        lvl[num -1]++;
    }

    for (int  i = 0; i < n; i++)
    {
        if(lvl[i] == 0){
            cout << "Oh, my keyboard!";
            return 0;
        }
    }
    cout <<  "I become the guy.";
    return 0;
}