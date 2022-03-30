class MyLinkedList {
    Node head, tail;
    int length;
    
    public MyLinkedList() {
        this.head = null;
        this.tail = null;
        this.length = 0;
    }
    
    public int get(int index) {
        if (!(0 <= index && index <= length - 1)) return -1;
        
        Node current = head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        
        return current.data;
    }
    
    public void addAtHead(int val) {
        Node temp = new Node(val, null, null);
        
        if (head == null) {
            head = tail = temp;
            length++;
            return;
        }
        
        temp.prev = null;
        temp.next = head;
        head.prev = temp;
        head = temp;
        length++;
    }
    
    public void addAtTail(int val) {
        Node temp = new Node (val, null, null);
        
        if (tail == null) {
            head = tail = temp;
            length++;
            return;
        }
        
        temp.prev = tail;
        temp.next = null;
        tail.next = temp;
        tail = temp;
        length++;
    }
    
    public void addAtIndex(int index, int val) { // Add before index
        if (index == length) {
            addAtTail(val);
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        if (!(0 <= index && index <= length - 1)) return;
        
        Node current = head;
        Node temp = new Node(val, null, null);
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        
        temp.prev = current.prev;
        temp.next = current;
        current.prev.next = temp;
        current.prev = temp;
        length++;
    }
    
    public void deleteAtIndex(int index) {
        if(!(0 <= index && index <= length - 1)) return;
        if (index == 0) {
            deleteAtHead();
            return;
        }
        if (index == length - 1) {
            deleteAtTail();
            return;
        }
        
        Node current = head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        
        Node prev = current.prev;
        Node next = current.next;
        prev.next = next;
        next.prev = prev;
        length--;
    }
    
    public void deleteAtTail() {
        if (tail == null) return;
        if (length == 1) {
            head = tail = null;
            length--;
            return;
        }
        
        Node prev = tail.prev;
        prev.next = null;
        tail = prev;
        length--;
    }
    
    public void deleteAtHead() {
        if (head == null) return;
        if (length == 1) {
            head = tail = null;
            length--;
            return;
        }
        
        head = head.next;
        head.prev = null;
        length--;
    }
    
    class Node {
        int data;
        Node next;
        Node prev;
        
        public Node(int data, Node next, Node prev) {
            this.data = data;
            this.next = next;
            this.prev = prev;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */