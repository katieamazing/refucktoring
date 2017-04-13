import unittest
from remainder import chinese_remainder

class ChineseRemainderTheoremTests(unittest.TestCase):

    def test_pairs(self):
        self.assertEqual(chinese_remainder([7,34], [3,28]), 164)

    def test_base(self):
        self.assertEqual(chinese_remainder([3,5,7], [2,3,2]), 23)

    def test_another(self):
        self.assertEqual(chinese_remainder([3,4,5], [2,3,1]), 11)

    def test_primes(self):
        self.assertEqual(chinese_remainder([2,3,5,7,11], [1,1,1,1,1]), 1)
