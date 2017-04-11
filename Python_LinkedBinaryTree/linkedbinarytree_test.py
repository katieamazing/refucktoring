import unittest
from linkedbinarytree import *
from hypothesis import given
import hypothesis.strategies as st


class LinkedBinaryTreeTests(unittest.TestCase):

    def test_empty_tree_len(self):
        sut = LinkedBinaryTree()
        self.assertEqual(len(sut), 0)

    def test_empty_tree(self):
        sut = LinkedBinaryTree()
        self.assertTrue(sut.is_empty())

    @given(st.lists(st.integers()))
    def test_replace_with_list_then_empty(self, numbers):
        sut = LinkedBinaryTree()

        for i, num in enumerate(numbers):
            if i == 0:
                root = sut._add_root(num)
            else:
                self.assertEqual(sut._replace(root, num), numbers[i-1])

        if not sut.is_empty():
            self.assertEqual(sut._delete(root), numbers[-1])

        self.assertTrue(sut.is_empty())

    @given(st.lists(st.integers()))
    def test_left_left_left_left(self, numbers):
        sut = LinkedBinaryTree()

        for i, num in enumerate(numbers):
            if i == 0:
                p = sut._add_root(num)
            else:
                p = sut._add_left(p, num)

        q = sut.root()
        for i, num in enumerate(numbers):
            self.assertEqual(q.element(), num)
            q = sut.left(q)

    @given(st.lists(st.integers()))
    def test_right_right_right_right(self, numbers):
        sut = LinkedBinaryTree()

        for i, num in enumerate(numbers):
            if i == 0:
                p = sut._add_root(num)
            else:
                p = sut._add_right(p, num)

        q = sut.root()
        for i, num in enumerate(numbers):
            self.assertEqual(q.element(), num)
            q = sut.right(q)

    @given(st.lists(st.integers()), st.lists(st.integers()))
    def test_attach(self, list_a, list_b):
        sut = LinkedBinaryTree()
        root = sut._add_root(2)

        scratch_a = LinkedBinaryTree()
        for i, num in enumerate(list_a):
            if i == 0:
                pa = scratch_a._add_root(num)
            else:
                pa = scratch_a._add_right(pa, num)

        scratch_b = LinkedBinaryTree()
        for i, num in enumerate(list_b):
            if i == 0:
                pb = scratch_b._add_root(num)
            else:
                pb = scratch_b._add_right(pb, num)

        sut._attach(root, scratch_a, scratch_b)
        q = sut.left(root)
        for i, num in enumerate(list_a):
            self.assertEqual(q.element(), num)
            if i < (len(list_a)-1):
                q = sut.right(q)
        while list_a:
            temp = sut.parent(q)
            self.assertEqual(sut._delete(q), list_a.pop())
            q = temp

        q = sut.right(root)
        for i, num in enumerate(list_b):
            self.assertEqual(q.element(), num)
            if i < (len(list_b)-1):
                q = sut.right(q)
        while list_b:
            temp = sut.parent(q)
            self.assertEqual(sut._delete(q), list_b.pop())
            q = temp






















                ###
