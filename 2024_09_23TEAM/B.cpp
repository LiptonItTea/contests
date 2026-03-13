#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Node {
    public:
        vector<Node*> outLinks;
};

int main() {
    map<string, Node*> dict;
    Node* rock = new Node;
    Node* scissors = new Node;
    Node* paper = new Node;
    Node* lizard = new Node;
    Node* spock = new Node;

    rock->outLinks.push_back(scissors);
    rock->outLinks.push_back(lizard); 

    paper->outLinks.push_back(rock);
    paper->outLinks.push_back(spock); 

    scissors->outLinks.push_back(paper);
    scissors->outLinks.push_back(lizard);

    spock->outLinks.push_back(rock);
    spock->outLinks.push_back(scissors);

    lizard->outLinks.push_back(spock);
    lizard->outLinks.push_back(paper);

    dict["Rock"] = rock;
    dict["Scissors"] = scissors;
    dict["Paper"] = paper;
    dict["Lizard"] = lizard;
    dict["Spock"] = spock;

    string first;
    string second;
    cin >> first >> second;

    Node* fNode = dict[first];
    Node* sNode = dict[second];
    for (Node* next : fNode->outLinks){
        if(sNode == next){
            cout << "First";
            return 0;
        }
    }
    for (Node* next : sNode->outLinks){
        if(fNode == next){
            cout << "Second";
            return 0;
        }
    }
    cout << "Tie";
}