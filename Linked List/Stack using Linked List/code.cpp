class Stack
{
    Node *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        ++size;
        if(head==NULL){
            head = temp;
        }
        else {
           temp->next = head;
           head = temp;
        }
    }

    void pop()
    {
        if(head == NULL) return;
        size--;
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }

    int getTop()
    {
        if(head==NULL){
           return -1;
        }
        return head->data;
    }
};
