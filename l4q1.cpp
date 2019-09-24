#include <bits/stdc++.h> 
#include<iostream>
#include<stdlib.h>
//#include<map.h>
using namespace std; 
  
// Structure for Trie 
struct Trie { 
    bool isEndOfWord; 
    map<char,struct Trie*> map; 
    string meaning; 
}; 
  
// Function to create a new Trie node 
Trie* getNewTrieNode() 
{ 
    Trie* node = new Trie; 
    node->isEndOfWord = false; 
    return node; 
} 
  
// Function to insert a word with its meaning 
// in the dictionary built using a Trie 
void insert(Trie*& root, const string& str, 
            const string& meaning) 
{ 
  
    // If root is null 
    if (root == NULL) 
        root = getNewTrieNode(); 
  
    Trie *temp = root; 
    for (int i = 0; i < str.length(); i++) { 
        char x = str[i]; 
  
        // Make a new node if there is no path 
        if (temp->map.find(x) == temp->map.end()) 
            temp->map[x] = getNewTrieNode(); 
  	
        temp = temp->map[x]; 
    } 
  
    // Mark end of word and store the meaning 
    temp->isEndOfWord = true; 
    temp->meaning = meaning; 
} 
  
// Function to search a word in the Trie 
// and return its meaning if the word exists 
string getMeaning(Trie* root, const string& word) 
{ 
  
    // If root is null i.e. the dictionary is empty 
    if (root == NULL) 
        return ""; 
  
    Trie* temp = root; 
  
    // Search a word in the Trie 
    for (int i = 0; i < word.length(); i++) { 
        temp = temp->map[word[i]]; 
        if (temp == NULL) 
            return ""; 
    } 
  
    // If it is the end of a valid word stored 
    // before then return its meaning 
    if (temp->isEndOfWord) 
        return temp->meaning; 
    return ""; 
} 
  
// Driver code 
int main() 
{ 
char ch;
    int countl=0,i=0,j=0,quotes=0,k=0,l=0,y=0,count=0;
    Trie* root = NULL;
    FILE *fp=fopen("L4_P1_input.csv","r");

    char keys[100][100];

    char keys1[100][100];


    if(fp==NULL) printf("not found");
    while(EOF!=fscanf(fp,"%c",&ch)){ y=0;
    if(ch=='\n'){ y=1;  i++; k++; countl--; count++; }
if(ch=='\"'){ y=1; quotes++; if(quotes%2==0){  l=0; j=0; } }
    if(quotes%2==0) {if(ch==','){ y=1; countl++; j=0; l=0;  } }
    if(y==0){
    if(countl%2==0) { keys[i][j]=ch; j++; }
    else{ keys1[k][l]=ch; l++; }
}
}
    for (i = 0; i < count; i++)
       {
   insert(root, keys[i],keys1[i]);
}
cout<<"Enter text to be searched: ";
    string str;
    cin>>str;
    cout << getMeaning(root, str);

    return 0;
} 
