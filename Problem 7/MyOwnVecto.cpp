#include<iostream>
#include<vector>
#include<chrono>
using namespace std;
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
int main()
{
    
    vector<int> vec_i(1000);
    int counter = -1;
    
    auto begin = steady_clock::now();

    for(int i = 0; i < vec_i.size(); i++)
    {
        vec_i[i] = ++counter;
        cout << i << "     " <<  vec_i[i] << endl;
    }
    cout << endl;
    
    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - begin);
    cout << duration.count() << " milliseconds.";
    

    return 0;
}
