package com.company;


public class BinaryTree<T extends Comparable<T>>  {

    private class Node {
        private T value;
        private Node left;
        private Node right;

        Node(T value) {
            this.value = value;
            right = null;
            left = null;
        }
    }

    Node root;

    private Node addRecursive(Node current, T value) {
        if (current == null) {
            return new Node(value);
        }
        int compare = value.compareTo(current.value);
        if (compare<0) {
            current.left = addRecursive(current.left, value);
        } else if (compare>0) {
            current.right = addRecursive(current.right, value);
        }
        return current;
    }

    private boolean findNodeRecursive(Node current, T value) {
        if (current == null) {
            return false;
        }
        if (value.compareTo(current.value)==0) {
            return true;
        }
        return value.compareTo(current.value) < 0
                ? findNodeRecursive(current.left, value)
                : findNodeRecursive(current.right, value);
    }

    public void add(T value) {
        root = addRecursive(root, value);
    }
    public boolean find(T value) {
        return findNodeRecursive(root, value);
    }
    //Обход дерева «Левый-Корень-Правый».
    private void traverseInOrderRecursive(Node node) {
        if (node != null) {
            traverseInOrderRecursive(node.left);
            System.out.print(" " + node.value);
            traverseInOrderRecursive(node.right);
        }
    }
    public void traverseInOrder(){
        traverseInOrderRecursive(root);
        System.out.println();
    }
    //Обход дерева «Корень-Левый-Правый»;
    private void traversePreOrderRecursive(Node node) {
        if (node != null) {
            System.out.print(" " + node.value);
            traversePreOrderRecursive(node.left);
            traversePreOrderRecursive(node.right);
        }
    }
    public void traversePreOrder(){
        traversePreOrderRecursive(root);
        System.out.println();
    }
    //Обход дерева «Левый-Правый-Корень»;
    private void traversePostOrderRecursive(Node node) {
        if (node != null) {
            traversePostOrderRecursive(node.left);
            traversePostOrderRecursive(node.right);
            System.out.print(" " + node.value);
        }
    }
    public void traversePostOrder(){
        traversePostOrderRecursive(root);
        System.out.println();
    }
}
