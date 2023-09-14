#include <iostream>

using namespace std;

class Node
{
    private:
        int num;
        Node *next;
        
        friend class List;
    public:
        Node(int n)
        {
            num = n;
            next = 0;
        };
};

class List
{
    private:
        Node *head;
        Node *last;
        int len;
        
    public:
        List()
        {
            head = 0;
            last = 0;
            len = 0;
        };
    
        ~List()
        {
            Node *tmp;
            
            while (head)
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
        };
    
        void    make_list(int n)
        {
            Node *now;
            
            for (int i = 0; i < n; i++)
            {
                now = new Node(i + 1);
                if (!head)
					head = now;
				else
					last->next = now;
				last = now;
            }
            len = n;
        };
    
        int    card_queue(void)
        {
            Node* now, *prev, *tmp;
            
            if (!len)
                return 0;
            while (len != 1)
            {
				now = head;
				prev = head;
				while (now)
				{
					tmp = now;
					if (now == last)
						last = prev;
					prev->next = now->next;
					now = now->next;
					prev = now;
					if (tmp == head)
						head = prev;
					if (now)
						now = now->next;
					delete tmp;
				}
				if (len % 2)
				{
					last->next = head;
					head = head->next;
					last = last->next;
					last->next = 0;
				}
                len /= 2;
            }
            return head->num;
        };
};

int main()
{
    int num;
    List list;
    
    cin >> num;
    list.make_list(num);
    cout << list.card_queue() << endl;
    return 0;
}