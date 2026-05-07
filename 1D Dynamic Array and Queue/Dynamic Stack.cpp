#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Stack{
	private:
		vector<char> st;
	public:
		void push(char ch){
		   st.push_back(ch);
		}
		void pop() {
        if(!st.empty()) {
            st.pop_back();
        }
    }
        char peek() {
        if(!st.empty()) {
            return st.back();
        }
        return '\0';
    }
    bool isEmpty() {
        return st.empty();
    }
     void reverse(string sentence) {
        string result = "";
        for(int i = 0; i < sentence.length(); i++) {
            if(sentence[i] != ' ') {
                push(sentence[i]);
            }
            else {
                while(!isEmpty()) {
                    result += peek();
                    pop();
                }

                result += ' ';
            }
        }
         while(!isEmpty()) {
            result += peek();
            pop();
        }
      cout << "Reversed Words Sentence: " << result << endl;
    }
};
int main() {
    Stack s;
    string sentence;
    cout<<"Enter a sentence: ";
    getline(cin, sentence);
    s.reverse(sentence);
    return 0;
}




