#include<vector>
#include<iostream>
#include<time.h>
#include<string>
#include<chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

using namespace std;


int main()
{
    srand(time(NULL));

    int a = 1000;
    vector<char> vec_i(a);
    auto begin = steady_clock::now();
   for(int i = 0; i <= vec_i.size(); ++i)
   {
        
        vec_i[i] = rand() % 128;

        cout << i << "  " << vec_i[i] << endl;
   }

   cout << endl;
   auto end = steady_clock::now();
   auto duration = duration_cast<milliseconds>(end - begin);
   cout << duration.count() << " milliseconds.";
   return 0;
}