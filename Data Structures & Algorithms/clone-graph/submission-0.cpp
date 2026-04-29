/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,map<int,Node*> hmap){
        if(node==nullptr) return nullptr;
        Node* root;
        root->val = node->val;
        hmap[root->val] = root;
        for(auto it:node->neighbors){
            if(hmap.find(it->val)!=hmap.end()) node->neighbors.push_back(hmap[it->val]);
            else node->neighbors.push_back(dfs(it,hmap));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
       map<int,Node*> hmap;
       return dfs(node,hmap);   
    }
};
