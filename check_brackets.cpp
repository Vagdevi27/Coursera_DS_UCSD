#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int mismatched;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
        	// Process opening bracket, write your code here
        	// create a bracket with position
        	Bracket *bracket = new  Bracket(next, position);
        	// Push the bracket into stack if its an opening bracket
            opening_brackets_stack.push(*bracket);
        }

        if (next == ')' || next == ']' || next == '}') {
        	
        	// no opening bracket, and started with closing bracket.
        	if(opening_brackets_stack.size() == 0){
        		mismatched = position + 1;
        		cout << mismatched;
        		return 0;
			}
            // Process closing bracket, write your code here
            //if((top.type == '(' && next != ')') || (top.type == '[' && next != ']')  || (top.type == '{' && next != '}')) {
            if(opening_brackets_stack.top().Matchc(next) == false) {

				// If the unmatched closing is found, print that
            	mismatched = position + 1;
            	cout << mismatched;
            	return 0;
			}
			else{
				// Pop the opening bracket as we found the matching closing bracket
				opening_brackets_stack.pop();
			}
        }

   }
    // if stack has any elements, unmatched opening bracket is present. 
    if(!opening_brackets_stack.empty()){
    	mismatched = opening_brackets_stack.top().position + 1;
    	cout << mismatched;
    	return 0;
	}
	// the stack is empty.
    // Printing answer, write your code here
    printf("Success");
    return 0;
}
