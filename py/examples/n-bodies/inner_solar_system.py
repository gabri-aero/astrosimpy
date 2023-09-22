from astrosimpy.bodies import Body
from base import n_body
import numpy as np


sun = Body("sun", 1.989e30, [0, 0, 0, 0, 0, 0])
mercury = Body("Mercury", 3.3011e23, [6.981e10, 0, 0, 0, 43593, 0])
venus = Body("Venus", 4.8675e24, [1.0894e11, 0, 0, 0, 34896, 0])
mars = Body("Mars", 6.4171e23, [2.279e11, 0, 0, 0, 24127, 0])
earth = Body("earth", 5.972e24, [149e9, 0, 0, 0, 29780, 0])

day = 24*3600
time = 10*365*day
step = day/5

solar_system = [earth, sun, venus, mars, mercury]

n_body(solar_system, time, step, 1, "inner-solar-system", legend=True, save=False, secs=15)
