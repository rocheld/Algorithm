priority_queue<node *, vector<node *>, cmp> que;

struct cmp
{
    bool operator()(const node *lhs, const node *rhs)
    {
        return lhs->val < rhs->val;
    }
};