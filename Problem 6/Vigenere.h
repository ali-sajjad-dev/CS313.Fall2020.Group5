#pragma once

using namespace std;

// cracking the vigenere cipher using a genetic recombination algorithm

void fillVector(vector<char>& plaintext, string str);

vector<char> vigenere(vector<char>& plaintext, vector<char>& key);

int char_rotation(char x);

vector<char> randomKey(int length);

int test_cipher(const vector<char>& ciphertext, vector<char>& new_cipher);

void register_keys(vector<vector<char>>& registry, vector<char>& plaintext, vector<char>& ciphertext, int amount, int threshold);

void recombination(vector<char>& key1, vector<char>& key2);

void generation(vector<vector<char>>& registry, vector<char>& plaintext, vector<char>& ciphertext);

void mutation(vector<char>& key);

void run_and_print_successive_generations(vector<vector<char>>& registry, vector<vector<char>>& generation1, vector<char>& plaintext, vector<char>& ciphertext, int cycles, int threshold);

void select_winners(vector<vector<char>>& registry, vector<vector<char>>& generation, vector<char>& plaintext, vector<char>& ciphertext);