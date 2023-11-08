from astrosimpy.bodies import Body
from astrosimpy.engine import AstroEngine
from astrosimpy.numerical import Euler

import time

sun = Body("SUN", 1, [0, 0, 0, 0, 0, 0])
moon = Body("MOON", 0.1, [1, 0, 0, 0, 1, 0])

ae = AstroEngine()
ae.add_bodies([sun, moon])

integrator = Euler(1)
ae.set_integrator(integrator)

# Record the start time
start_time = time.time()

ae.run(1e6)

end_time = time.time()

# Calculate the elapsed time
elapsed_time = end_time - start_time

print(f"Time taken: {elapsed_time} seconds")

