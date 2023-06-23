class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
        
    def insert(self, data): #NODE 삽입
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
            else:
                self.data = data
        else:
            self.data = data

    def PreorderTraversal(self, root):  #전위순회
        res = []
        if root:
            res.append(root.data)
            res = res + self.PreorderTraversal(root.left)
            res = res + self.PreorderTraversal(root.right)
        return res
    
    def PostorderTraversal(self, root):     #후위순회
        res = []
        if root:
            res = self.PostorderTraversal(root.left)
            res = res + self.PostorderTraversal(root.right)
            res.append(root.data)
        return res
    
    def InorderTraversal(self, root):       #중위순회
        res = []
        if root:
            res = self.InorderTraversal(root.left)
            res.append(root.data)
            res = res + self.InorderTraversal(root.right)
        return res
            
input_data =  [ 27, 15, 14, 6, 31, 45, 10, 42, 38, 17 ]
bst_chu = Node(27)
for i in input_data[1:]:
    bst_chu.insert(i)

print("pre-order : ", bst_chu.PreorderTraversal(bst_chu))
print("in-order : ",bst_chu.InorderTraversal(bst_chu))
print("post-order : ",bst_chu.PostorderTraversal(bst_chu))