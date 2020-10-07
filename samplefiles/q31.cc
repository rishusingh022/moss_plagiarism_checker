#include <iostream>

using namespace std;
class Node {
    int data;
    Node* next;
    Node* head = NULL;
    int* table = new int[500];
    Node* NodeTable[500];
public:
    int N = 0;
    bool isCircular = false;
    int* getTable() {
        return table;
    }
    Node() {
        for (int i = 0; i < 500; i++) { table[i] = 0; };
        for (int i = 0; i < 500; i++) { NodeTable[i] = NULL; }
    }
    //declaration of functions
    void caseZero();
    void caseOne();
    void beforeInsertion(int y, int x);
    void afterInsertion(int y, int x);
    void caseTwo();
    int Search(int x);
    void print();
    void U(int x);
    void GenerateTable();
    void printTable();

};


void Node::caseZero() {
    int x;
    cin >> x;

    Node* temp2 = new Node;
    temp2->data = x;
    temp2->next = NULL;

    NodeTable[x] = temp2;
    N++;


    if (head == NULL) {
        head = temp2;
        table[head->data] = 0;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = temp2;
}

void Node::caseOne() {
    int x, y;
    cin >> x >> y;
    N++;
    int q;
    q = Search(x);
    if (q == 1) afterInsertion(x, y);
    if(q==0) beforeInsertion(x,y);
}
void    Node::beforeInsertion(int y, int x) {
    Node* temp = new Node;
    temp->data = y;
    temp->next = NULL;

    NodeTable[y] = temp;

    if (head->data == x) {
        temp->next = head;
        head = temp;
        return;
    }

    Node* temp2 = head;
    while (temp2->next->data != x) {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}
void Node::afterInsertion(int y, int x) {

    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;

    NodeTable[x] = temp;

    Node* temp2 = head;
    while (temp2->data != y) {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}
void Node::caseTwo() {
    int x, y, z;
    cin >> x >> y >> z;
    Node* temp2 = new Node;
    temp2->data = z;
    temp2->next = NULL;

    NodeTable[z] = temp2;
    int pos = 0;


    Node* temp = head;
    while (temp->data != x) {
        temp = temp->next;
    }


    Node* Initial = temp;
    while (temp->data != y) {
        temp = temp->next;
        pos++;
    }
    pos /= 2;

    while (pos != 0) {
        Initial = Initial->next;
        pos--;
    }

    temp2->next = Initial->next;
    Initial->next = temp2;
    N++;
}
// searching for a node
int Node::Search(int x) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) { return 1; }
        temp = temp->next;
    }
    if (temp == NULL) return 0;

}


//printing element
void Node::print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void Node::U(int x) {
    int p;
    cin >> p;
    if (Search(x) == 0) { return; }


    Node* temp = NodeTable[x];
    while (p != 0) {
        if (temp->next == NULL) {
            temp->next = head;
            temp = head;
            isCircular = true;
            p--;
        }

        else { temp = temp->next; p--; }

    }
    NodeTable[x]->next = temp;
}

void Node::GenerateTable() {
    int i = 1;
    while (i < 500) {
        if (NodeTable[i] != NULL) {
            if (NodeTable[i]->next != NULL) {
                table[NodeTable[i]->next->data]++;
            }
        }
        i++;
    }
}

void Node::printTable() {
    for (int i = 1; i < 10; i++) {
        cout << i << " " << table[i] << endl;
    }
}


int main()
{
    Node A;
    int N;
    cin >> N;
    char a;
    int b;
    //testcase loop
    for (int i = 0; i < N; i++) {
        cin >> a;
        cin >> b;
        //checking a
        if (a == 'I') {
            if (b == 0) {

                A.caseZero();
            }
            else if (b == 1) {

                A.caseOne();
            }
            else if (b == 2) {

                A.caseTwo();
            }
            else
                continue;
        }
        //checking U
        if (a == 'U')
        {

            A.U(b);
        }

    }
    A.GenerateTable();
    int* ansTable = A.getTable();
    int countMultiple = 0;
    A.isCircular ? cout << 1 << endl : cout << 0 << endl;
    int i = 1;
    //iterating through the loop
    while (i < 500) {
        if (ansTable[i] >= 2) { countMultiple++; }
        i++;
    }
    if (countMultiple == 0) { cout << "0" << endl; A.print(); }
    else {
        cout << countMultiple << endl;
        int i = 1;
        while (i < 500) {
            if (ansTable[i] >= 2) cout << i << " ";
            i++;
        }
        cout << endl;
        int j = 1;
        while (j < 500) {
            if (ansTable[j] >= 2) cout << ansTable[j] << " ";
            j++;
        }
    }
    cout << endl;

    return 0;
}
