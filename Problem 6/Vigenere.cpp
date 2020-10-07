#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Vigenere.h"

using namespace std;

// problem 6
// Muhammad Abbas Ali Sajjad
// CS313 - group 5

int main()
{
	// seed
	srand(time(nullptr));

	// arbitrary plaintext - "I love computers and programming code."
	string str = "Ilovecomputersandprogrammingcode";

	// arbitrary pseudo-key set at length: 32
	const string key_32 = "Iwenttotheshopandboughtmealaptop";

	vector<char> plaintext;
	vector<char> key;

	// vector of vector keys
	vector<vector<char>> registry;

	// best of recombination;
	vector<vector<char>> generation1;

	// fill in initial vectors
	fillVector(plaintext, str);
	fillVector(key, key_32);

	// encrypt plaintext into ciphertext using key
	vector<char> ciphertext = vigenere(plaintext, key);

	register_keys(registry, plaintext, ciphertext, 25, 8);

	// prints out registry
	for (int i = 0; i < registry.size(); i++)
	{
		vector<char> test = vigenere(plaintext, registry[i]);
		cout << "score : " << test_cipher(ciphertext, test) << " ";
		cout << "Key " << i + 1 << ": ";
		for (int j = 0; j < registry[i].size(); j++)
		{
			cout << registry[i][j];
		}
		cout << endl;
	}
	cout << "------------------------" << endl;

	/* The number of cycles to run with an increasing threshold has no fixed values,
		only through successive trials can you determine what works vs doesn't work vs takes too long
	*/

	// The number of recombination cycles set to 100 with a score threshold of 10
	run_and_print_successive_generations(registry, generation1, plaintext, ciphertext, 100, 10);

	for (int i = 0; i < generation1.size(); i++)
	{
		vector<char> test = vigenere(plaintext, generation1[i]);

		int score = test_cipher(ciphertext, test);

		cout << "score : " << score;
		cout << " Key " << i + 1 << ": ";
		for (int j = 0; j < generation1[i].size(); j++)
		{
			cout << generation1[i][j];
		}
		cout << endl;
	}
	cout << "______________________________________" << endl;

	// select top performers and replace old registry with new
	select_winners(registry, generation1, plaintext, ciphertext);

	// The number of recombination cycles set to 100 with a score threshold of 15
	run_and_print_successive_generations(registry, generation1, plaintext, ciphertext, 100, 15);

	// printing generation registry for viewing
	for (int i = 0; i < generation1.size(); i++)
	{
		vector<char> test = vigenere(plaintext, generation1[i]);

		int score = test_cipher(ciphertext, test);

		cout << "score : " << score;
		cout << " Key " << i + 1 << ": ";
		for (int j = 0; j < generation1[i].size(); j++)
		{
			cout << generation1[i][j];
		}
		cout << endl;
	}
	cout << "______________________________________" << endl;

	// see line 77
	select_winners(registry, generation1, plaintext, ciphertext);

	// The number of recombination cycles set to 100 with a score threshold of 20
	run_and_print_successive_generations(registry, generation1, plaintext, ciphertext, 100, 20);

	// see line 77
	select_winners(registry, generation1, plaintext, ciphertext);

	// printing new generation for viewing 
	cout << "Updates registry: " << endl;
	for (int i = 0; i < registry.size(); i++)
	{
		vector<char> test = vigenere(plaintext, registry[i]);
		cout << "score : " << test_cipher(ciphertext, test) << " ";
		cout << "Key " << i + 1 << ": ";
		for (int j = 0; j < registry[i].size(); j++)
		{
			cout << registry[i][j];
		}
		cout << endl;
	}
	cout << "------------------------" << endl;


}

// fills an empty vector with text, either plaintext, cipher or key
void fillVector(vector<char> &text, string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		text.push_back(str[i]);
	}
}

// encodes a plaintext into ciphertext using the key provided
vector<char> vigenere(vector<char> &plaintext, vector<char> &key)
{
	vector<char> ciphertext;
	
	for (int i = 0; i < plaintext.size(); i++)
	{
		// encrypts plaintext to ciphertext
		if (isupper(plaintext[i]))
		{
			ciphertext.push_back((char_rotation(plaintext[i]) + char_rotation(key[i % key.size()])) % 26 + 'A');
		}
		else ciphertext.push_back((char_rotation(plaintext[i]) + char_rotation(key[i % key.size()])) % 26 + 'a');
	}
	return ciphertext;
}

// implements the caesar cipher character rotation
int char_rotation(char x)
{
	if (isupper(x))
	{
		return x - 'A';
	}
	else return x - 'a';
}

// generates a random key with specified length 
vector<char> randomKey(int length)
{
	vector<char> str;

	for (int i = 0; i < length; i++)
	{
		char c = rand() % 26 + 'a';
		str.push_back(c);
	}
	return str;
}

/* compares your newly created ciphertext to the original ciphertext,
   returns a score based on matches
*/
int test_cipher(const vector<char> &ciphertext, vector<char> &new_cipher)
{
	int match_count = 0;
	for (int i = 0; i < ciphertext.size(); i++)
	{
		if (ciphertext[i] == new_cipher[i])
		{
			match_count++;
		}
	}
	return match_count;
}

// initial load of the registry with random keys of a specified amount that meet a certain score threshold 
void register_keys(vector<vector<char>> &registry, vector<char> &plaintext, vector<char> &ciphertext, int amount, int threshold)
{
	// seed our random key generator
	//srand(time(nullptr));

	int count = 0;
	while (count < amount)
	{
		// generate random keys
		vector<char> key_rand = randomKey(32);

		// generate new ciphers based on new random key
		vector<char> new_cipher = vigenere(plaintext, key_rand);

		// determine if new_cipher meets threshold 
		if (test_cipher(ciphertext, new_cipher) >= threshold)
		{
			// add key to registry and update count
			registry.push_back(key_rand);
			count++;
		}
	}
}

// recombine 2 parent keys to produce to offspring keys at 25% recombination
void recombination(vector<char> &key1, vector<char> &key2)
{
	// recombination at 25%, multipoint cross-over
	// ensure cross over points are different and not out of bounds;
	int cross_over_point1 = rand() % (key1.size() - 7);
	int cross_over_point2 = cross_over_point1 + 7;

	// cross over
	for (int i = cross_over_point1; i <= cross_over_point2; i++)
	{
		char tmp = key1[i];
		key1[i] = key2[i];
		key2[i] = tmp;
	}
}

// mutate key at 1% or a rate of 0.01
void mutation(vector<char> &key)
{
	// seed our rand
	//srand(time(nullptr));

	// key mutation at 1%
	for (int i = 0; i < 2; i++)
	{
		int index_rand = rand() % key.size();
		char c_rand = rand() % 26 + 'a';
		key[index_rand] = c_rand;
	}
}

// tournament style recombination, grabs keys at random and sets them up for recombination
void generation(vector<vector<char>> &registry, vector<char> &plaintext, vector<char> &ciphertext)
{
	static int mutation_count = 0;
	int index1 = 0;
	int index2 = 0;

	// grabs 2 random keys
	while (index1 == index2)
	{
		index1 = rand() % registry.size();
		index2 = rand() % registry.size();
	}

	recombination(registry[index1], registry[index2]);

	// 1 character every 192 characters is mutated
	if (mutation_count % 3 == 0)
		mutation(registry[index1]);
	
	mutation_count++;
}



// exactly what its name says, i.e recombine -> show us new keys at user specified cycle number with specified score threshold
void run_and_print_successive_generations(vector<vector<char>> &registry, vector<vector<char>> &generation1, vector<char> &plaintext, vector<char> &ciphertext, int cycles, int threshold)

{
	// empty old generation 
	generation1.clear();

	for (int i = 0; i < cycles; i++)
	{
		// recombine 2 keys from registry at random
		generation(registry, plaintext, ciphertext);

		cout << "recombination count " << i+1 << endl;
		for (int k = 0; k < registry.size(); k++)
		{
			// generate cipher from test key
			vector<char> test = vigenere(plaintext, registry[k]);

			// compare new ciphertext to ciphertext of hidden key
			int score = test_cipher(ciphertext, test);

			// scan for improvment
			if (score > threshold) generation1.push_back(registry[k]);

			cout << "score : " << score;
			cout << " Key " << k + 1 << ": ";
			for (int j = 0; j < registry[k].size(); j++)
			{
				cout << registry[k][j];
			}
			cout << endl;
		}
		cout << "_____________________" << endl;
	}
	cout << endl;
	cout << "Best of recombination: " << endl;
}

// select the winners of after recombination
void select_winners(vector<vector<char>> &registry, vector<vector<char>> &generation, vector<char> &plaintext, vector<char> &ciphertext)
{
	int count = 0;

	vector<char> new_cipher = vigenere(plaintext, generation[0]);
	int max = test_cipher(ciphertext, new_cipher);
	int max_index = 0;

	// select best from the generation to replace registry.
	while (count < registry.size())
	{
		// find max
		for (int i = 0; i < generation.size(); i++)
		{
			vector<char> new_cipher = vigenere(plaintext, generation[i]);
			int x = test_cipher(ciphertext, new_cipher);
			if (x > max)
			{
				max = x;
				max_index = i;
			}
		}
		// swap keys
		registry[count].swap(generation[max_index]);
		count++;
		//reset max
		max = 0;
	}

}