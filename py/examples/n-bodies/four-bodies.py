from astrosimpy import bodies
from base import n_body


b1 = bodies.Body(2.5e10, [0, 1, 0, 1, 0, 0])
b2 = bodies.Body(2.5e10, [1, 0, 0, 0, -1, 0])
b3 = bodies.Body(2.5e10, [0, -1, 0, -1, 0, 0])
b4 = bodies.Body(2.5e10, [-1, 0, 0, 0, 1, 0])

step = 5e-4
time = 20

bodies_ = [b1, b2, b3, b4]

n_body(bodies_, time, step, 1e-10, "four-bodies")
