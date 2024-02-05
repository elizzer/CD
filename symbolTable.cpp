#include<iostream>
#include<string.h>

using namespace std;


struct symbol{
    string key;
    string value;
    symbol *next;

    symbol(){
        key="";
        value="";
        next=NULL;
    }
    symbol(string key,string value){
        key=key;
        value=value;
        next=NULL;

    }
};

class symbolTable{
    static const int size = 100;
    symbol table[size];
    public:
    symbolTable(){
        for(int i=0;i<size;i++){
            symbol temp;
            table[i] = temp;
        }
    }

    void printTable(){
        for(int i=0;i<size;i++){
            symbol *current=&table[i];
            cout<<i<<" ==> ";
            while(current!=NULL){
                cout<<"Key: "<<current->key<<" value: "<<current->value<<" ==>   ";
                current=current->next;
            }
            cout<<endl;
        }
    }

    int hash(char* key){
        int hashvalue=0;
        for(char ch=key[0]; ch!='\0'; ch=*key++){
            hashvalue+=ch;
        }

        return hashvalue%size;
    }

    void insert(string key,string value){
        int hashvalue=hash(&key[0]);
        if (table[hashvalue].key==""){

            symbol newSymbol; 
            newSymbol.key=key;
            newSymbol.value=value;
            table[hashvalue]=newSymbol;
        }else{
            symbol *current=&table[hashvalue];
            while (current->next!=NULL)
            {
                current=current->next;
            }
            current->next=new symbol();
            current=current->next;
            current->key=key;
            current->value=value;
        }
        cout<<"\nInserted at "<<hashvalue;
    }

    string read(string key){
        int hashvalue=hash(&key[0]);

        symbol *current=&table[hashvalue];
    }
};




int main(){

    symbolTable st;
    st.insert("hel","hel");
    st.insert("hel","hel");
    st.insert("hel","hel");
    st.insert("hel","hel");
    st.printTable();
    // st.hash("helo");
    return 0;
}