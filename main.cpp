#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    
    //Initializating Variables
    vector<string> str_arr;
    vector<pair<int, string>> q;
    vector<string> completed;
    string str;
    string word = "";
    int flag = 0;
    
    while(true){
        //Command Line Input
        getline(cin, str);
        
        //Splitting Words from Input 
        for (auto x : str) 
        {
            if (flag == 1 && x != '"'){
                word = word + x;
            }
            else if (x == '"'){
                if(flag == 0){
                    flag = 1;
                    continue;
                }
                break;
            }
            else if (x == ' ')
            {
                str_arr.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        
        str_arr.push_back(word);
        word = "";
        flag = 0;
        
        int n = str_arr.size();
        
        // Handling Each Case Individually
        if(str_arr[0] == "./task") {
            if(n == 1 || (n == 2 && str_arr[1] == "help")){
                cout << "Usage :-";
                cout << "$ ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list" << endl;
                cout << "$ ./task ls                   # Show incomplete priority list items sorted by priority in ascending order" << endl;
                cout << "$ ./task del INDEX            # Delete the incomplete item with the given index" << endl;
                cout << "$ ./task done INDEX           # Mark the incomplete item with the given index as complete" << endl;
                cout << "$ ./task help                 # Show usage" << endl;
                cout << "$ ./task report               # Statistics";
            }
            else if(n == 2){
                if(str_arr[1] == "ls"){
                    sort(q.begin(), q.end());
                    int i = 1;
                    for(auto a: q){
                        cout<< i++ <<". "<<a.second<<" "<<"["<<a.first<<"]"<<endl;
                    }
                }
                else if(str_arr[1] == "report"){
                    cout<<"Pending : "<<q.size()<<endl;
                    sort(q.begin(), q.end());
                    int i = 1;
                    for(auto a: q){
                        cout<< i++ <<". "<<a.second<<" "<<"["<<a.first<<"]"<<endl;
                    }
                    cout<<endl;
                    cout<<"Completed : "<<completed.size()<<endl;
                    i = 1;
                    for(auto a: completed){
                        cout<< i++ <<". "<<a<<endl;
                    }
                }
            }
            else if(n > 2){
                if(str_arr[1] == "add"){
                    q.push_back({stoi(str_arr[2]), str_arr[3]});
                    cout << "Added task: \"" << str_arr[3] << "\" with priority " << str_arr[2] << endl;
                }
                else if(str_arr[1] == "del"){
                    int index = stoi(str_arr[2]);
                    if(index > q.size()){
                        cout<<"Error: item with index 5 does not exist. Nothing deleted."<<endl;
                    } else {
                        q.erase(q.begin() + index - 1);
                        cout << "Deleted item with index 3" <<endl;
                    }
                }
                else if(str_arr[1] == "done"){
                    int index = stoi(str_arr[2]);
                    if(index > q.size()){
                        cout<<"Error: no incomplete item with index 5 exists."<<endl;
                    } else {
                        completed.push_back(q[index-1].second);
                        q.erase(q.begin() + index - 1);
                        cout<<"Marked item as done."<<endl;
                    }
                }
            }
        }
        str_arr.clear();
    }
    return 0;
}
