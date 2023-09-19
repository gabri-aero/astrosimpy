from astrosimpy import bodies
from base import n_body


b1 = bodies.Body(7.5e9, [-0.5, 0, 0, 0.5, 0, 0])
b2 = bodies.Body(7.5e9, [0.5, 0, 0, 0.5, -1, 0])

# v_circ = sqrt(Gm/2r) because we are in an inertial ref frame

step = 1e-3
time = 20

bodies_ = [b1, b2]

n_body(bodies_, time, step, "two-bodies-moving", True)


