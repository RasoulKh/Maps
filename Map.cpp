#include <iostream>
#include <map>
#include <string>
#include <list>
#include <vector>
using namespace std;

    class Person {
    private:
        int _age;
        string _name;

    public:
        Person () {          /* ِDefault Constructor */
            _age = 0;
            _name = "";
        }
        Person (int age, string name) {   /* Constructor  */
            _age = age;
            _name = name;
        }
        Person (const Person &others) {  /* Copy Constructors */
            _age = others._age;
            _name = others._name;
        }
        void print () {
            cout << _name << ": " << _age << endl;
        }
        
    };
//*********************************//
//***********   Main   ************//
//*********************************//
int main()
{
    /* Map in C++ is like Dictionary in other languages like Pyhton */
    /* Map consists of two parts of "Key" and "Value" */
    map<string, string> Eng_to_Norsk_Dictionary; /* In maps, we can NOT use pairs with the same Keys */
    map<string, list<string>> Plants;
    map<int, Person> People;
    multimap<int, string> Multi_Map;    /* In multimaps, we can have different pairs with the same Keys */

    /* ---------- First map:  Eng_to_Norsk_Dictionary ----------- */
    /* Inserting "Keys" and "Values" into the dictionary */
    Eng_to_Norsk_Dictionary.insert(pair<string, string>("Apple", "Eple"));
    Eng_to_Norsk_Dictionary.insert(pair<string, string>("Orange", "Eplesin"));
    Eng_to_Norsk_Dictionary.insert(pair<string, string>("Cucumber","Agurk"));
    Eng_to_Norsk_Dictionary.insert(pair<string, string>("Banana","BBBB"));

    /* Accessing to the "Keys" and changing the "Value" */
    Eng_to_Norsk_Dictionary["Banana"] = "Banan";

    /* Size of a Dictionary */
    cout << "Size is: " << Eng_to_Norsk_Dictionary.size() << endl;

    int temp = 1;
    for(auto pair : Eng_to_Norsk_Dictionary){
        cout << temp << " " << pair.first << "-->" << pair.second << endl;
        temp ++;
    }

/* ---------- Second map:  Plants ----------- */

/* ---------- Values are a list type ----------- */
    

    list<string> monstera {"Deliciosa", "Adansonii", "siltepecana", "dubia"};
    list<string> philodendron {"Pink Princess", "Pinantrum", "Silver sword"};
    list<string> ficus {"Elastica", "Lyrata"};

    Plants.insert(pair<string, list<string>>("Monstera", monstera));
    Plants.insert(pair<string, list<string>>("Philodendron", philodendron));
    /* Another way of inserting map using "make_pair" function */
    Plants.insert(make_pair("Ficus", ficus));

    /* Size of a Dictionary */
    cout << "---------" << endl;
    cout << "Size is: " << Plants.size() << endl;

    int count = 1;
    for (auto pair : Plants){
        cout << count << " " << pair.first << " ---> ";

        for (auto plants : pair.second){
            cout << plants << " , ";
        }
        cout << endl;
        count ++;
    }

    /* ---------- Third map:  Age and the vector of employees with the same age ----------- */
    
    /* ---------- Values are a class type ----------- */

    Person P1 = Person(35, "Rasoul");
    Person P2 = Person(31, "Ida");
    Person P3 = Person(31, "Katie");
    People.insert(pair<int, Person>(0, P1));
    People.insert(pair<int, Person>(1, P2));
    People.insert(pair<int, Person>(2, P3));
    /* Another way of inserting map using "make_pair" function */
    People.insert(make_pair(3,Person(37, "Russ")));
    People.insert(make_pair(4,Person(33, "John")));

    /* Size of a Dictionary */
    cout << "---------" << endl;
    cout << "Size is: " << People.size() << endl;
 
    for(map<int, Person >::iterator it = People.begin(); it != People.end(); it++) {
        cout << it->first << " ";
        it->second.print();
    }  

    /* Another way of getting map "Keys" and "Values" using Pair*/
    cout << endl;
    cout << "Another way of getting map Keys and Values using Pair" << endl;
     for(map<int, Person >::iterator it = People.begin(); it != People.end(); it++) {
        pair<int, Person> People = *it;
        cout << People.first << " ";
        People.second.print();
    }  
    /* **************************************************************** */
    /* Multimap Applications */
    Multi_Map.insert(make_pair(1, "Bob"));
    Multi_Map.insert(pair<int, string>(1, "Russ"));
    Multi_Map.insert(pair<int, string>(2, "Ida"));
    Multi_Map.insert(make_pair(2, "Katie"));

    cout << endl;
    cout << "Multimap: " << endl;
    for (multimap<int, string>:: iterator it = Multi_Map.begin(); it != Multi_Map.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << endl;
    cout << "Multimap: using find() function" << endl;
    for (multimap<int, string>:: iterator it = Multi_Map.find(2); it != Multi_Map.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    /* Applying equal_range() function to fid the range of the key*/
    cout << endl;   
    pair<multimap<int, string>:: iterator, multimap<int, string>:: iterator> its = Multi_Map.equal_range(2);

    cout << "Multimap: using equal_range() function" << endl;
    for (multimap<int, string>:: iterator it = its.first; it != its.second; it++) {
        cout << it->first << ": " << it->second << endl;
    }


    system("pause>0");
}
