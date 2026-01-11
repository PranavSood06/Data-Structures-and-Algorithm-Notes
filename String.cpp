#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
char arrays are not resizeable dynamically which makes them them
unusable during change in size or initialising the array that's  why we use
string class because we can resize/modify the string at runtime and even apply runtime operations
on it like concatenation
*/

void revAstring(string &str)
{
    int start = 0, end = str.length() - 1;
    while (start <= end)
    {
        swap(str[start++], str[end--]);
        // start++;end--;
    }
}

void str_Basics()
{
    string str = "Hello";
    string str1 = "Apnaa";
    string str2 = str + str1;                // concatenation
    cout << (str.length() == str1.length()); // comparison
    // we can even take it as input
    string str3;
    // cin>>str3; // it stops taking input after space
    cout << "\n";
    getline(cin, str3);
    // cout<<str2;
    cout << "\n"
         << str3 << endl;
}

// Valid palindrone and Remove all occurences
/*
s.find("substring") is used to find the first index where the subtring started in s string
s.erase(s.begin(),s.end()) is used to erase a substring with its iterators/pointers
*/

// Permutation in string  (567)
/*
->if we have to check permutation of [1]"abcd" in [2]"efghcbadqwer"  then the no. of characters in [1] and frequency of charcters should match..
->If it is a only english lower case characters then will use array if not i.e special characters or numbers are included then we will used unordered map
->Steps :
  - make an array for frequency of characters f[26] and initialise it with {0}
  - increase the frequency of that character in the array by ++
  - Go with the sliding window approach and check all windows
  - create a seperate array for window and increse the frequency then match it with the permutation window
  - if it matches then return true
  - if not then reset window frequency array
  - repeat till the end
  - if nothing matched then return false
*/

bool permutation_in_string(string s1, string s2)
{
    // total char
    const int Tchar = 26;
    // frequency of s1
    vector<int> f1(Tchar, 0);
    for (char s : s1)
    {
        f1[s - 'a']++;
    }
    // sliding window ends
    int start = 0, end = s1.length() - 1;
    while (end < s2.length())
    {
        // frequency of window in s2
        vector<int> f2(Tchar, 0);
        for (int i = start; i <= end; i++)
        {
            f2[s2[i] - 'a']++;
        }
        if (f1 == f2)
        {
            // both are equl
            return true;
        }
        else
        {
            start++;
            end++;
            f2.clear();
        }
    }
    return false;
}
// In main func
/*
    string s1 = "vnaa";
    string s2 = "pranav sood";
    cout<<permutation_in_string(s1,s2)<<" !";
*/

// Reverse words in  string (151)
/*
reverse(s.begin(),s.begin()+x) -> reverse till << s.begin+x-1 >>
*/
string reverseWords(string s)
{
    int n = s.length();
    // reversing the string
    reverse(s.begin(), s.end());

    string ans = "";

    // iterating through every character
    for (int i = 0; i < n; i++)
    {
        string word = "";
        // extracting a word
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // skips during multiple spaces

        // reversing the word and storing in ans
        if (word.length() > 0)
        {
            reverse(word.begin(), word.end());
            ans += " " + word;
        }
    }
    // removing leading space
    return ans.substr(1);
}


//String compression (443)
int compress(vector<char>& chars) {
    // for overwriting in chars
    int idx = 0;

    for (int i = 0; i < chars.size(); i++) {
        // selecting char
        char a = chars[i];
        int count = 0; 
        // Frequency of char
        while (i<chars.size()&&chars[i] == a) {
            count++;
            i++;
        }
        // converting int count to string count
        std::string count_ = std::to_string(count);
        // overwriting in chars
        chars[idx++]=a;
        // countering i++ in for loop
        i--;
        // not storing count in chars when == 1
        if(count==1){
            continue;
        }
        // storing count char by char
        for (char c : count_) {
            chars[idx++]=c;
        }
    }
    // erasing the vector from idx
    chars.resize(idx);
    return chars.size();
}
