#pragma once

using namespace std;

// cracking the vigenere cipher using a genetic recombination algorithm



// fills an empty vector with text, either plaintext, cipher or key
void fillVector(vector<char>& plaintext, string str);

// encodes a plaintext into ciphertext using the key provided
vector<char> vigenere(vector<char>& plaintext, vector<char>& key);

// implements the caesar cipher character rotation
int char_rotation(char x);

// generates a random key with specified length 
vector<char> randomKey(int length);

/* compares your newly created ciphertext to the original ciphertext,
   returns a score based on matches
*/
int test_cipher(const vector<char>& ciphertext, vector<char>& new_cipher);

// initial load of the registry with random keys of a specified amount that meet a certain score threshold
void register_keys(vector<vector<char>>& registry, vector<char>& plaintext, vector<char>& ciphertext, int amount, int threshold);

// recombine 2 parent keys to produce to offspring keys at 25% recombination
void recombination(vector<char>& key1, vector<char>& key2);

// tournament style recombination, grabs keys at random and sets them up for recombination
void generation(vector<vector<char>>& registry, vector<char>& plaintext, vector<char>& ciphertext);

// mutate key at 1% or a rate of 0.01
void mutation(vector<char>& key);

// recombine->show us new keys at user specified cycle number with specified score threshold
void run_and_print_successive_generations(vector<vector<char>>& registry, vector<vector<char>>& generation1, vector<char>& plaintext, vector<char>& ciphertext, int cycles, int threshold);

// select the winners of after recombination
void select_winners(vector<vector<char>>& registry, vector<vector<char>>& generation, vector<char>& plaintext, vector<char>& ciphertext);