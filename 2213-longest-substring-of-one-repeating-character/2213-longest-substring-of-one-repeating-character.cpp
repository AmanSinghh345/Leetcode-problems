class Solution {
public:

    struct Node {
        int len;
        int pref;
        int suff;
        int mx;
        char lc, rc;

        Node() {}

        Node(char c) {
            len = 1;
            pref = 1;
            suff = 1;
            mx = 1;
            lc = c;
            rc = c;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        if (a.pref == a.len && a.rc == b.lc)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.rc == b.lc)
            res.suff = b.len + a.suff;

        res.mx = max(a.mx, b.mx);

        if (a.rc == b.lc)
            res.mx = max(res.mx, a.suff + b.pref);

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int k = queryIndices.size();
        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < k; i++) {

            s[queryIndices[i]] = queryCharacters[i];

            update(1, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(seg[1].mx);
        }

        return ans;
    }
};