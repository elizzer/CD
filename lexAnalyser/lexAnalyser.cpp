#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

class token{
    public:
        string name;
        string type;
        token(string n){
            name=n;
        }
};

class token_list{
    public:
    vector <token> list;
        int size(){
            return list.size();
        }
        token get_token(int index){
            return list[index];
        }
        void insert_token(string tok){
            token temp_token(tok);
            list.push_back(temp_token);
        }

        void token_dump(){
            for(int i=0;i<list.size();i++){
                cout<<endl<<list[i].name<<" "<<list[i].type;
            }
        }
};

//return 0 of it is not a delimiter
int is_delimiter(char ch){
    switch (ch)
    {
    case ' ':
    case '\n':
    case '\t':
        return 1;
        break;
    case '(':
    case ')':
    case '<':
    case '>':
    case '{':
    case '}':
    case '\"':
    case '=':
    case '+':
    case '-':
    case '#':
    case '*':
    case '&':
    case '|':
    case '%':
    case ']':
    case '[':
    case ';':
        return 2;
        break;
    default:
        break;
    }
    return 0;
}

bool is_keyword(const string &identifier) {
    // List of some C keywords (you can extend this list as needed)
    vector<string> keywords = {"int", "char", "float", "if", "else", "while", "for", "return","include","printf"};

    for (const string &kw : keywords) {
        if (identifier == kw) {
            return true;
        }
    }
    return false;
}

bool is_numeric_literal(const string &token) {
    // Check if the token is a numeric literal (integer in this example)
    for (char ch : token) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

void tokenize(string file_name,token_list &tokens){

    string line;
    ifstream c_file_stream;
    c_file_stream.open(file_name);
    while(getline(c_file_stream,line)){


        // cout<<endl<<line.length();
        string buffer;
        if(line.length()>0){

            for(int i=0;i<line.length();i++){
                char cur_ch=line[i];
                int delimiter_code=is_delimiter(cur_ch);

                if(delimiter_code==0){
                    //this block handles if it is not a delimiter push the char to the end of the buffer
                    buffer+=cur_ch;
                }else if(delimiter_code==1 && buffer[0]!='\0'){
                    //this block needs to handle if it is a delimiter => then process the buffer
                    tokens.insert_token(buffer);
                    buffer='\0';
                }else if(delimiter_code==2){
                    if(buffer.length()!=0){
                        tokens.insert_token(buffer);
                        buffer='\0';
                        buffer+=cur_ch;
                        tokens.insert_token(buffer);
                        buffer='\0';
                        
                    }
                }
                
            }
        }

        tokens.insert_token(buffer);
        buffer='\0';


    }
    cout<<"\nPrinting token list";
    // token_list.push_back(new token);
    // tokens.token_dump();
}


int main(int argc, char* argv[]){
    string file_name=argv[1];

    token_list tokens;
    tokenize(file_name,tokens);

    for(int i=0;i<tokens.size();i++){
        if(is_keyword(tokens.get_token(i).name)){
            tokens.list[i].type="KEYWORD";
        }else if(is_numeric_literal(tokens.get_token(i).name)){
            tokens.list[i].type="LITREL";
        }
    }

    tokens.token_dump();

    return 0;
}
