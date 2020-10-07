#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<chrono>
#include<time.h>
using namespace std;
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

class RandomMov{
   
public:
    //Default constructor with one argument
    RandomMov(int size): size(size)
    {
        cout << "Default constructor" << endl;
        a = new char[size];
        for(int i = 0; i <= size; i++)
        {
            a[i] = rand() % 128;
            //a[i] = setRand(65,90) % 128 ;
        }
    }
    //destructor
    ~RandomMov()
    {
        cout <<"destructor" << endl;
        delete [] a;
    }
    //copy constructor
    RandomMov(const RandomMov& orig) noexcept
    {
        cout << "This is the copy constructor" << endl;
        this->size = orig.size;
        a = new char[size];

        for(int i = 0; i < size; i++)
        {
            a[i] = orig.a[i];
        }
    }
    //assignment operator
    RandomMov& operator=(const RandomMov& orig) noexcept {
		cout << "In operator equals\n";

		if (this != &orig) {
			if (size > 0) {
				delete[] a;
			}
			
			this->size = orig.size;
			a = new char[this-> size];
			for (int i = 0; i < size; i++)
			{
				this->a[i] = orig.a[i];
			}
		}
		return *this;
	}
    //move assignment operator
    RandomMov& operator=(RandomMov&& orig) noexcept 
    {
		cout << "In move assignment operator\n";

		if (this != &orig) {
			delete[] a;

			this->size = orig.size;
			a = orig.a;

			orig.a = nullptr;
		}
		return *this;
	}
    //move constructor
	RandomMov(RandomMov&& orig) noexcept 
    {
		cout << "In move constructor\n";


		this->size = orig.size;
		a = orig.a;

		orig.a = nullptr;
	}
    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout << i << " " << a[i] << endl;
        }
    }
    /*
    int setRand(int low, int high)
    {
        return rand() %(high - low) + low;
    }
    */
    
protected:
    char *a;
    int size;

};

void RandomMain()
{
    RandomMov x(1000);
    
    RandomMov y(move(x));
    
    auto begin = steady_clock::now();
    y.print();
    cout << endl << endl;
    auto end = steady_clock::now();
    auto duration = duration_cast<milliseconds>(end - begin);
    cout << duration.count() << " milliseconds.";
    cout << endl;
}

int main()
{
    RandomMain();
    cout << endl;
    return 0;
}