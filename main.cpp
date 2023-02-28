#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T1, typename T2>
class PairClass{
public:
    T1 key;
    T2 value;

    PairClass(T1 key, T2 value) : key(key), value(value) {};
};

template<typename T1, typename T2>
class Register{
public:
vector<PairClass<T1, T2> > registry;


    void add(PairClass<T1, T2> p){
        registry.push_back(p);
        cout << "Element: " << p.key << " " << p.value << " was added "<< endl;

    }

    void remove(T1 key){
        int removeCount = 0;
        for (auto it = registry.begin(); it != registry.end(); )
        {
            if (it->key == key)
            {
                cout << "Element \"" << it->key << " : " << it->value << "\" is removed.\n";
                it = registry.erase(it);
                ++removeCount;
            }
            else
            {
                ++it;
            }
        }
        if (removeCount == 0)
            cout << "Key \"" << key << "\" is not found.\n";
    }


    void print(){
        if (registry.size() == 0) cout << "Registry is empty.\n" ;
        else {
            cout << "Registry: " << endl;
            for (auto it = registry.begin(); it != registry.end(); it++) {
                cout << "Key: " << it->key << " Value: " << it->value << endl;
            }
        }
    }

    void find(T1 key){
        int notfind = 0;
        for (auto it = registry.begin(); it != registry.end(); it++)
        {
            if (it->key == key)
            {
                cout << "Element \"" << it->key << "\" : " << it->value << endl;
                notfind++;
            }
        }
        if (notfind == 0)
            cout << "Key \"" << key << "\" is not found.\n";
    }

};


int main() {

    Register<string, int> data;
    string command;
    cin >> command;
    while(command != "end"){

        if (command == "add") {
            string a; int n;
            cin >> a >> n;
            PairClass<string, int> p(a, n);
            data.add(p);
        }
        else if (command == "remove"){
            string keydel;
            cin >> keydel;
            data.remove(keydel);
        }
        else if (command == "print"){
            data.print();
        }
        else if (command == "find"){
            string a;
            cin >> a;
            data.find(a);
        }
        else throw runtime_error("Unknown command");

        cin >> command;
    }

    return 0;
}
