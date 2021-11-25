class Node:
    def __init__(self,data):
        self.data = data
        self.parent = None
        self.left = None
        self.right = None
        self.color = 1

class RedBlackTree():
    def __init__(self):
        self.TNULL = Node(0)
        self.TNULL.color = 0
        self.TNULL.left = None
        self.TNULL.right = None
        self.root = self.TNULL
    
    def _pre_order_helper(self, node) -> None:
        if node != self.TNULL:
            print(node.data, end=" ")
            self._pre_order_helper(node.left)
            self._pre_order_helper(node.right)
    
    def _in_order_helper(self,node) -> None:
        if node!=self.TNULL:
            self._in_order_helper(node.left)
            print(node.data,end=" ")
            self._in_order_helper(node.right)
    
    def _post_order_helper(self, node) -> None:
        if node != self.TNULL:
            self._post_order_helper(node.left)
            self._post_order_helper(node.right)
            print(node.data,end=" ")
    
    def _search_tree_helper(self, node, key):
        if node == self.TNULL or node.data == key:
            return node
        if key < node.data:
            return self._search_tree_helper(node.left,key)
        return self._search_tree_helper(node.right,key)
    
    def _fix_delete(self, x):
        while x!=self.root and x.color == 0:
            if x == x.parent.left:
                s = x.parent.right
                if s.color == 1:
                    s.color = 0
                    x.parent.color = 1
                    self.lef_rotate(x.parent)
                    s = x.parent.right
                if s.left.color == 0 and s.right.color == 1:
                    s.color = 1
                    x = x.parent 
                else: 
                    if s.right.color == 0:
                        s.left.color = 0
                        s.color = 1
                        self.right_rotate(s)
                        s = x.parent.right
                    s.color = x.parent.color
                    x.parent.color = 0
                    s.right.color = 0
                    self.left_rotate(x.parent)
                    x = self.root
            else: 
                s = x.parent.left
                if s.color == 1:
                    s.color = 0
                    x.parent.color = 1
                    self.right_rotate(x.parent)
                    s = x.parent.left
                if s.left.color == 0 and s.right.color == 0:
                    s.color = 1
                    x = x.parent
                else:
                    if s.left.color == 0:
                        s.right.color = 0
                        s.color = 1
                        self.left_rotate(s)
                        s = x.parent.left
                    s.color = x.parent.color
                    x.parent.color = 0
                    s.left.color = 0
                    self.right_rotate(x.parent)
                    x=self.root
        x.color  =0 
    
    def _rb_transplant(self, u,v):
        if u.parent == None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        v.parent = u.parent
    
    def _delete_node_helper(self, node, key):
        z = self.TNULL
        while node != self.TNULL:
            if node.data ==key:
                z = node
            if node.data <= key:
                node = node.right
            else:
                node = node.left
        if z == self.TNULL:
            print("No node with given value found")
            return
        y = z
        y_og_color = y.color
        if z.left == self.TNULL:
            x = z.right
            self._rb_transplant(z,z.right)
        elif z.right == self.TNULL:
            x = z.left
            self._rb_transplant(z,z.left)
        else:
            y = self.minimum(z.right)
            y_og_color = y.color
            x = y.right
            if y.parent == z:
                x.parent = y
            else:
                self._rb_transplant(y,y.right)
                y.right = z.right
                y.right.parent = y
            self._rb_transplant(z,y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
            if y_og_color == 0:
                self._fix_delete(x)
    
    def _fix_insert(self,k):
        while k.parent.color == 1:
            if k.parent == k.parent.parent.right:
                u = k.parent.parent.left
                if u.color == 1:
                    u.color = 0
                    k.parent.color = 0
                    k.parent.parent.color=1
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent 
                        self.right_rotate(k)
                    k.parent.color = 0
                    k.parent.color = 0
                    k.parent.parent.color = 1
                    self.left_rotate(k.parent.parent)
            else:
                u = k.parent.parent.right

                if u.color == 1:
                    u.color = 0
                    k.parent.color = 0
                    k.parent.parent.color = 1
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent 
                        self.left_rotate(k)
                    k.parent.color = 0
                    k.parent.parent.color = 1
                    self.right_rotate(k.parent.parent)
            if k == self.root:
                break
        self.root.color = 0
    
    def _print_helper(self,node,indent,last) -> None:
        if node!=self.TNULL:
            print(indent, end="")
            if last:
                print("R---",end="")
                indent +="     "
            else:
                print("L---",end="")
                indent+="|     "
            s_color = "RED" if node.color ==1 else "BLACK"
            print(str(node.data) + "(" + s_color + ")")
            self._print_helper(node.left,indent,False)
            self._print_helper(node.right,indent,True)
    
    def preorder(self):
        self._pre_order_helper(self.root)
    
    def inorder(self):
        self._in_order_helper(self.root)
    
    def postorder(self):
        self._post_order_helper(self.root)
    
    def searchTree(self,k):
        return self._search_tree_helper(self.root,k)
    
    def minimum(self,node):
        while node.left!=self.TNULL:
            node = node.left
        return node
    
    def maximum(self, node):
        while node.right != self.TNULL:
            node = node.right
        return node
    
    def successor(self,x):
        if x.right !=self.TNULL:
            return self.minimum(x.right)
        y = x.parent
        while y !=self.TNULL and x == y.right:
            x = y
            y = y.parent
        return y
    
    def predecessor(self,x):
        if x.left != self.TNULL:
            return self.maximum(x.left)
        y = x.parent
        while y!=self.TNULL and x==y.left:
            x = y
            y = y.parent
        return y
    
    def left_rotate(self, x):
        y = x.right
        x.right = y.left 
        if y.left!=self.TNULL:
            y.left.parent = x
        y.parent = x.parent 
        if x.parent == None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.TNULL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent == None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent=y

    def insert(self,key):
        node = Node(key)
        node.parent = None
        node.data = key
        node.left = self.TNULL
        node.right = self.TNULL
        node.color = 1

        y = None
        x = self.root

        while x!=self.TNULL:
            y = x
            if node.data < x.data:
                x = x.left
            else:
                x = x.right
        node.parent = y
        if y == None:
            self.root = node
        elif node.data < y.data:
            y.left = node
        else:
            y.right = node
        
        if node.parent == None:
            node.color = 0
            return
        
        if node.parent.parent == None:
            return
        
        self._fix_insert(node)
    
    def get_root(self):
        return self.root
    
    def delete_node(self, data):
        self._delete_node_helper(self.root,data)
    
    def pretty_print(self):
        self._print_helper(self.root,"",True)
        print("\n",end="")

if __name__ == "__main__":
    bst = RedBlackTree()
    bst.insert(10)
    bst.insert(18)
    bst.insert(7)
    bst.insert(15)	
    bst.insert(16)	
    bst.insert(30)
    bst.insert(25)	
    bst.insert(40)
    bst.insert(60)	
    bst.insert(2)
    bst.insert(1)
    bst.insert(70)
    bst.pretty_print()
