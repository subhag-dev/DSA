class Solution {
    
    static class AVLTree {

        static class Node {
            long key;
            int size;
            int height;
            Node left;
            Node right;
            int frequency;

            Node(long key) {
                this.key = key;
                this.size = 1;
                this.frequency = 1;
            }
        }

        static class Counter {
            int count;
        }

        Node root;

        List<Integer> insert(int[] keys) {
            int N = keys.length;
            Integer[] ans = new Integer[N];
            for (int i = N - 1; i >= 0; i--) {
                Counter cntr = new Counter();
                this.root = insert(this.root, keys[i], cntr);
                ans[i] = cntr.count;
            }
            return Arrays.asList(ans);
        }

        Node insert(Node root, long key, Counter cntr) {
            if (root == null) {
                return new Node(key);
            }
            root.size++;
            if (root.key == key) {
                root.frequency++;
                cntr.count = cntr.count + size(root.left);
            } else if (key < root.key) {
                root.left = insert(root.left, key, cntr);
            } else {
                root.right = insert(root.right, key, cntr);
                cntr.count = cntr.count + size(root.left) + root.frequency;
            }
            return balance(root);
        }


        Node balance(Node root) {
            fixSizeAndHeight(root);
            int balance = getBalance(root);
            if (balance > 1) {
                if (getBalance(root.left) >= 0) {
                    return rightRotate(root);
                } else {
                    root.left = leftRotate(root.left);
                    return rightRotate(root);
                }
            }
            if (balance < -1) {
                if (getBalance(root.right) <= 0) {
                    return leftRotate(root);
                } else {
                    root.right = rightRotate(root.right);
                    return leftRotate(root);
                }
            }

            return root;
        }

        Node rightRotate(Node root) {
            Node newRoot = root.left;
            root.left = newRoot.right;
            newRoot.right = root;
            fixSizeAndHeight(root);
            fixSizeAndHeight(newRoot);
            return newRoot;
        }

        Node leftRotate(Node root) {
            Node newRoot = root.right;
            root.right = newRoot.left;
            newRoot.left = root;
            fixSizeAndHeight(root);
            fixSizeAndHeight(newRoot);
            return newRoot;
        }

        void fixSizeAndHeight(Node node) {
            fixSize(node);
            fixHeight(node);
        }

        void fixSize(Node node) {
            if (node != null) {
                node.size = node.frequency + size(node.left) + size(node.right);
            }
        }

        void fixHeight(Node node) {
            if (node != null) {
                node.height = 1 + max(height(node.left), height(node.right));
            }
        }

        int getBalance(Node node) {
            return node == null ? 0 : height(node.left) - height(node.right);
        }

        int size(Node node) {
            return node == null ? 0 : node.size;
        }

        int height(Node node) {
            return node == null ? -1 : node.height;
        }

        int max(int a, int b) {
            return a > b ? a : b;
        }
    }
    
    public List<Integer> countSmaller(int[] nums) {
        AVLTree tree = new AVLTree();
        List<Integer> res = tree.insert(nums);
        return res;
    }
}