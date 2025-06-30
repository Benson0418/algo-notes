#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)x.size())
#define g0(t) get<0>(t)
#define g1(t) get<1>(t)
#define g2(t) get<2>(t)
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tii = tuple<int, int, int>;
using tll = tuple<ll, ll, ll>;
const int INT_INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
template <typename T> using maxpq = priority_queue<T>;
template <typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;

struct Node{
    int val;
    Node* pre;
    Node* next;
    Node(int val = 0, Node * pre = nullptr, Node * next = nullptr)
    :val(val), pre(pre), next(next){}
};

struct DoublyLinkedList {
    //初始化雙向鏈表
    private:
        Node *head = nullptr;
        Node *tail = nullptr;
    public:
        //友誼函數，讓ostream輸出流訪問私有成員head, tail
        friend ostream& operator<<(ostream& os, DoublyLinkedList& DLL);

        //建構函數
        DoublyLinkedList() = default;

        //拷貝函數重載
        DoublyLinkedList(const DoublyLinkedList& DLL):head(nullptr), tail(nullptr){ //深拷貝
            head = new Node(DLL.head->val);
            Node * curr = head;
            Node * src = DLL.head->next;
            while (src!=nullptr){
                curr->next = new Node(src->val, curr);
                curr = curr->next;
                src = src->next;
            }
            tail = curr;
        }
        //析構函數重載
        ~DoublyLinkedList(){
            while (head!=nullptr){
                Node * temp = head;
                head = head->next;
                delete temp;
            }
        }

        bool isempty(){
            return head == nullptr;
        }

        void append(Node * node){
            if (isempty()){
                head = node;
                tail = node;
            }
            else{
                node->pre = tail;
                tail->next = node;
                tail = node;
            }
        }
        void preappend(Node * node){
            if (isempty()){
                head = node;
                tail = node;
            }
            else{
                node->next = head;
                head->pre = node;
                head = node;
            }
        }
        int pop(){
            if (!head) return INT_INF; //待處理，比如raise Error
            else{
                int res = tail->val;
                if (tail->pre == nullptr){
                    delete tail;
                    head = nullptr;
                    tail = nullptr;
                }
                else{
                    Node* temp = tail;
                    tail = tail->pre;
                    tail->next = nullptr;
                    delete temp;

                }
                return res;
            }
        }
        int prepop(){
            if (!head) return INT_INF; //同 pop() 問題
            else{
                int res = head->val;
                if (head->next == nullptr){
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                else{
                    Node * temp = head;
                    head = head->next;
                    head->pre = nullptr;
                    delete temp;
                }
                return res;
            }
        }
        int getlength(){
            Node * curr = head;
            int res = 0;
            while (curr!=nullptr){
                ++res;
                curr=curr->next;
            }
            return res;
        }



ostream& operator<<(ostream& os, DoublyLinkedList& DLL){
    if (DLL.head==nullptr) return os<<"doubly-linked-list is empty";
    Node * curr = DLL.head;
    while (curr!=nullptr){
        os<<curr->val;
        if (curr->next!=nullptr){
            os<<" <-> ";
        }
        curr = curr->next;
    }
    return os;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DoublyLinkedList DLL;
    DLL.append(new Node(1));
    DLL.append(new Node(2));
    DLL.preappend(new Node(0));
    cout<< DLL.getlength()<<endl; //輸出3
    cout<< DLL << endl;
    cout<< DLL.prepop()<<endl; //輸出0
    cout<< DLL.pop()<<endl; //輸出2
    DoublyLinkedList nDLL = DLL;
    cout<< nDLL.getlength()<<endl; //輸出1

    DoublyLinkedList list1;
    list1.append(new Node(1));
    list1.append(new Node(2));

    DoublyLinkedList list2;
    list2.append(new Node(3));
    list2.append(new Node(4));

    DoublyLinkedList combined = list1 + list2;
    cout << combined << endl;  // 輸出: 1 <-> 2 <-> 3 <-> 4

    return 0;
}

