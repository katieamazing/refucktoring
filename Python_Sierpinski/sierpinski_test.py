import unittest
from sierpinski import sierpinski

class SierpinskiOutputTests(unittest.TestCase):

    def test_0(self):
        self.assertEqual(sierpinski(0), ['*'])

    def test_1(self):
        self.assertEqual(sierpinski(1), [' * ', '* *'])

    def test_2(self):
        self.assertEqual(sierpinski(2), ['   *   ', '  * *  ', ' *   * ', '* * * *'])

    def test_5(self):
        stars = 0
        for c in '\n'.join(sierpinski(5)):
            if c == '*':
                stars += 1
        self.assertEqual(stars, 243)

    def test_12(self):  ## feel free to comment this one out if your computer is slower
        stars = 0
        for c in '\n'.join(sierpinski(12)):
            if c == '*':
                stars += 1
        self.assertEqual(stars, 531441)
