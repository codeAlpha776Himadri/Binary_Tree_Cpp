#include<iostream>
#include<queue>
#include<stack>
#include<cmath>

using namespace std ;

template <class X>
class node {
  public :
    node *left ;
    X data ;
    node *right ;
};

template <class Y>
class binary_tree {
  private :
    node<Y> *root ;
    node<Y> *temp ;
    int dump;
    int no_of_nodes ;
    queue<node<Y> *> Q ;
  public : 
    
    binary_tree() {
        root = temp = nullptr ;
    }
    
    void create_tree() {
        temp = new node<Y> ;
        root = temp ;
        cout<<"Enter root data :"<<endl;
        cin>>root->data;
        Q.push(root);
        root->left = root->right = temp = nullptr ;
        
        while(!Q.empty())
        {
            node<Y> *N ;
            N= Q.front() ;
            Q.pop();
            cout<<"Doe's "<<N->data<<" have left child | press -1 for NO | any other no for YES  :  ";
            cin>>dump;
            cout<<endl;
            if(dump != -1) {
                node<Y> *P = new node<Y> ;
                cout<<"Enter left child : "<<endl;
                cin>>P->data;
                P -> left = P -> right = nullptr ;
                N -> left = P ;
                Q.push(P) ;
            }
            cout<<"Doe's "<<N->data<<" have right child | press -1 for NO | any other no for YES  :  ";
            cin>>dump;
            cout<<endl;
            if(dump != -1) {
                node<Y> *P = new node<Y> ;
                cout<<"Enter right child : "<<endl;
                cin>>P->data;
                P -> left = P -> right = nullptr ;
                N -> right = P ;
                Q.push(P) ;
            }
        }

    }
    
    void Traverse() {
        cout<<"\n1. For Preorder Recursive Traversal press 1 \n2. For Postorder Recursive Traversal press 2\n3. For Inorder Recursive Traversal press 3\n4. For Levelorder Traversal press 4\n5. For Preorder Iterative Traversal press 5\n6. For Inorder Iterative Traversal press 6\n7. For Postorder Iterative Traversal press 7\n";
        cin>>dump;
        switch(dump) {
            case 1 :cout<<endl; 
                    Preorder(root);
                    break ;
            case 2 :cout<<endl;
                    Postorder(root);
                    break ;
            case 3 :cout<<endl;
                    Inorder(root);
                    break ;
            case 4 :cout<<endl;
                    Levelorder(root);
                    break ;
            case 5 :cout<<endl;
                    Preorder_Iterative(root);
                    break ;
            case 6 :cout<<endl;
                    Inorder_Iterative(root);
                    break ;
            case 7 :cout<<endl;
                    Postorder_Iterative(root);
                    break ;
            default : cout<<"You Entered wrong choice!!"<<endl;
                    break ;
        }
    }
    
    void Height() {
        cout<<"\nHeight of tree : "<<HeightOfTree(root)<<endl;
    }
    
    void NoOfNodesOfTree() {
        cout<<"\nNodes count of this tree is : "<<countNodes(root)<<endl;
    }
    
    void NoOfLeafNodes() {
        cout<<"\nLeaf Nodes count of this tree is : "<<countLeafNodes(root)<<endl;
    }
    
    void NoOfNodesWithAtLeastDegree_1() {
        cout<<"\nNodes with at least Degree 1 : "<<countNodesWithAtLeastDegree_1(root)<<endl;
    }
    
    void NoOfNodesWithDegree_2() {
        cout<<"\nNodes with at Degree 2 : "<<countNodesWithDegree_2(root)<<endl;
    }
    
    void NoOfNodesWithDegree_1() {
        cout<<"\nNodes with at Degree 1 : "<<countNodesWithDegree_1(root)<<endl;
    }
    
    void getSumTotal() {
        if(sizeof(root->data)==4){
            cout<<"\nSum of all Nodes of tree is : "<<getSum(root)<<endl;
        }else{
            cout<<"Cant sum string / char"<<endl;
        }
    }
    
    void Preorder(node<Y> *N);
    void Preorder_Iterative(node<Y> *N);
    void Postorder(node<Y> *N);
    void Postorder_Iterative(node<Y> *N);
    void Inorder(node<Y> *N);
    void Inorder_Iterative(node<Y> *N);
    void Levelorder(node<Y> *N);
    int  HeightOfTree(node<Y> *N);
    int  countNodes(node<Y> *N); 
    int  countLeafNodes(node<Y> *N);
    int  countNodesWithAtLeastDegree_1(node<Y> *N);
    int  countNodesWithDegree_2(node<Y> *N);
    int  countNodesWithDegree_1(node<Y> *N);
    Y    getSum(node<Y> *N);
    
};

template <class Y>
void binary_tree<Y>::Preorder(node<Y> *N) {
    // cout<<endl;
    if(N!=nullptr) {
        cout<<N->data<<" ";
        Preorder(N->left);
        Preorder(N->right);
    }
}

template <class Y>
void binary_tree<Y>::Postorder(node<Y> *N) {
    // cout<<endl;
    if(N!=nullptr) {
        Preorder(N->left);
        Preorder(N->right);
        cout<<N->data<<" ";
    }
}

template <class Y>
void binary_tree<Y>::Inorder(node<Y> *N) {
    // cout<<endl;
    if(N!=nullptr) {
        Preorder(N->left);
        cout<<N->data<<" ";
        Preorder(N->right);
    }
}

template <class Y>
void binary_tree<Y>::Levelorder(node<Y> *N) {
    cout<<N->data<<" ";
    Q.push(N);
    while(!Q.empty()){
        N = Q.front();
        Q.pop();
        if( N -> left != nullptr ){
            cout<<N -> left -> data<<" ";
            Q.push(N -> left);
        }
        if( N -> right != nullptr ){
            cout<<N -> right -> data<<" ";
            Q.push(N -> right);
        }
    }
}

template <class Y>
void binary_tree<Y>::Preorder_Iterative(node<Y> *N) {
    stack<node<Y>*> st ;
    while( N!=nullptr || !st.empty() ){
        if( N!=nullptr ){
            cout<<N->data<<" ";
            st.push(N);
            N=N->left;
        }else{
            N = st.top() ;
            st.pop();
            N = N -> right ;
        }
    }
}

template <class Y>
void binary_tree<Y>::Inorder_Iterative(node<Y> *N) {
    stack<node<Y>*> st ;
    while( N!=nullptr || !st.empty() ){
        if( N!=nullptr ){
            st.push(N);
            N=N->left;
        }else{
            N = st.top() ;
            st.pop();
            cout<<N->data<<" ";
            N = N -> right ;
        }
    }
}

template <class Y>
void binary_tree<Y>::Postorder_Iterative(node<Y> *N) {
    stack<node<Y>*> st ;
    long int t ;
    while( N!=nullptr || !st.empty() ){
        if( N!=nullptr ){
            st.push(N);
            N=N->left;
        }else{
            t = (long int)st.top() ;
            st.pop();
            if(t > 0){
                st.push((node<Y>*)(-t)) ;
                N = ((node<Y>*)t)->right ;
            }else{
                cout<<((node<Y>*)t)->data<<" ";
                N = nullptr ;
            }
        }
    }
}

template <class Y>
int binary_tree<Y>::HeightOfTree(node<Y> *N) {
    int x=0,y=0 ;
    if( N == nullptr ){
        return 0 ;
    }
    x = HeightOfTree( N -> left ) ;
    y = HeightOfTree( N -> right ) ;
    if(x>y)
        return x+1 ;
    else
        return y+1 ;
}

template <class Y>
int binary_tree<Y>::countNodes(node<Y> *N) {
    if(N == nullptr){
        return 0 ;
    }
    return countNodes(N->left) + countNodes(N->right) + 1 ;
}

template <class Y>
int binary_tree<Y>::countLeafNodes(node<Y> *N) {
    int x, y;
    if(N != nullptr){
        x = countLeafNodes(N -> left);
        y = countLeafNodes(N -> right);
        if( N->left == nullptr && N->right == nullptr ){
            return x+y+1 ;
        }else{
            return x+y ; ;
        }
    }
    return 0 ;
}

template <class Y>
int binary_tree<Y>::countNodesWithAtLeastDegree_1(node<Y> *N) {
    int x, y;
    if(N != nullptr){
        x = countNodesWithAtLeastDegree_1(N -> left);
        y = countNodesWithAtLeastDegree_1(N -> right);
        if( N->left != nullptr || N->right != nullptr ){
            return x+y+1 ;
        }else{
            return x+y ; ;
        }
    }
    return 0 ;
}

template <class Y>
int binary_tree<Y>::countNodesWithDegree_2(node<Y> *N) {
    int x, y;
    if(N != nullptr){
        x = countNodesWithDegree_2(N -> left);
        y = countNodesWithDegree_2(N -> right);
        if( N->left != nullptr && N->right != nullptr ){
            return x+y+1 ;
        }else{
            return x+y ; ;
        }
    }
    return 0 ;
}

template <class Y>
int binary_tree<Y>::countNodesWithDegree_1(node<Y> *N) {
    int x, y;
    if(N != nullptr){
        x = countNodesWithDegree_1(N -> left);
        y = countNodesWithDegree_1(N -> right);
        if( N->left != nullptr ^ N->right != nullptr ){
            return x+y+1 ;
        }else{
            return x+y ; ;
        }
    }
    return 0 ;
}

template <class Y>
Y binary_tree<Y>::getSum(node<Y> *N) {
    Y x, y;
    if(N != nullptr){
        x = getSum(N -> left);
        y = getSum(N -> right);

        return x+y+N->data ;
    }
    return 0 ;
}


int main() {
    binary_tree<int> BT;
    BT.create_tree();
    BT.Traverse();
    BT.Height();
    BT.NoOfNodesOfTree();
    BT.NoOfLeafNodes();
    BT.getSumTotal();
    BT.NoOfNodesWithAtLeastDegree_1();
    BT.NoOfNodesWithDegree_2();
    BT.NoOfNodesWithDegree_1();
    
    return 0 ;
}

