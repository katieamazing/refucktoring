import unittest
from raycasting import *


class RaycastingTests(unittest.TestCase):
    def setup_method(self, method):
        self.polys = [
          Poly(name='square', edges=(
            Edge(a=Pt(x=0, y=0), b=Pt(x=10, y=0)),
            Edge(a=Pt(x=10, y=0), b=Pt(x=10, y=10)),
            Edge(a=Pt(x=10, y=10), b=Pt(x=0, y=10)),
            Edge(a=Pt(x=0, y=10), b=Pt(x=0, y=0))
            )),
          Poly(name='square_hole', edges=(
            Edge(a=Pt(x=0, y=0), b=Pt(x=10, y=0)),
            Edge(a=Pt(x=10, y=0), b=Pt(x=10, y=10)),
            Edge(a=Pt(x=10, y=10), b=Pt(x=0, y=10)),
            Edge(a=Pt(x=0, y=10), b=Pt(x=0, y=0)),
            Edge(a=Pt(x=2.5, y=2.5), b=Pt(x=7.5, y=2.5)),
            Edge(a=Pt(x=7.5, y=2.5), b=Pt(x=7.5, y=7.5)),
            Edge(a=Pt(x=7.5, y=7.5), b=Pt(x=2.5, y=7.5)),
            Edge(a=Pt(x=2.5, y=7.5), b=Pt(x=2.5, y=2.5))
            )),
          Poly(name='strange', edges=(
            Edge(a=Pt(x=0, y=0), b=Pt(x=2.5, y=2.5)),
            Edge(a=Pt(x=2.5, y=2.5), b=Pt(x=0, y=10)),
            Edge(a=Pt(x=0, y=10), b=Pt(x=2.5, y=7.5)),
            Edge(a=Pt(x=2.5, y=7.5), b=Pt(x=7.5, y=7.5)),
            Edge(a=Pt(x=7.5, y=7.5), b=Pt(x=10, y=10)),
            Edge(a=Pt(x=10, y=10), b=Pt(x=10, y=0)),
            Edge(a=Pt(x=10, y=0), b=Pt(x=2.5, y=2.5))
            )),
          Poly(name='exagon', edges=(
            Edge(a=Pt(x=3, y=0), b=Pt(x=7, y=0)),
            Edge(a=Pt(x=7, y=0), b=Pt(x=10, y=5)),
            Edge(a=Pt(x=10, y=5), b=Pt(x=7, y=10)),
            Edge(a=Pt(x=7, y=10), b=Pt(x=3, y=10)),
            Edge(a=Pt(x=3, y=10), b=Pt(x=0, y=5)),
            Edge(a=Pt(x=0, y=5), b=Pt(x=3, y=0))
            )),
          ]
        self.testpoints = (Pt(x=5, y=5), Pt(x=5, y=8),
                      Pt(x=-10, y=5), Pt(x=0, y=5),
                      Pt(x=10, y=5), Pt(x=8, y=5),
                      Pt(x=10, y=10))

    def test_all(self):
        self.assertEqual([ispointinside(point, poly)
            for point in self.testpoints
            for poly in self.polys],
            [True, False, True, True, True, True, False, True, False, False,
            False, False, False, False, False, False, True, True, True, True,
            True, True, True, True, False, False, False, False])
