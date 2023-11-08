import pyvista as pv
from pyvista import examples
import numpy as np
from .._core.orbit import Orbit
from .._core.bodies import Body


class Plotter:
    def __init__(self, *args, **kwargs):
        self.plotter = pv.Plotter(*args, **kwargs)
        self.set_background('black')
        self.add_camera_orientation_widget()

    # Delegate method calls to the internal plotter instance
    def show(self, *args, **kwargs):
        self.plotter.show(*args, **kwargs)

    def add_mesh(self, *args, **kwargs):
        self.plotter.add_mesh(*args, **kwargs)

    def set_background(self, *args, **kwargs):
        self.plotter.set_background(*args, **kwargs)

    def add_camera_orientation_widget(self, *args, **kwargs):
        self.plotter.add_camera_orientation_widget()

    def add_planet(self, r=1., texture_file=f"../data/planet_surface/earth.png"):
        sphere = pv.Sphere(
            radius=1, theta_resolution=120, phi_resolution=120, start_theta=270.001, end_theta=270
        )

        # Initialize the texture coordinates array
        sphere.active_t_coords = np.zeros((sphere.points.shape[0], 2))

        # Populate by manually calculating
        for i in range(sphere.points.shape[0]):
            sphere.active_t_coords[i] = [
                0.5 + np.arctan2(sphere.points[i, 1], sphere.points[i, 0]) / (2 * np.pi),
                0.5 + np.arcsin(sphere.points[i, 2]) / np.pi,
            ]

        # And let's display it with the texture
        tex = pv.read_texture(texture_file)
        sphere = sphere.scale(r)
        self.add_mesh(sphere, texture=tex)

    def add_orbit(self, orbit: Orbit, body: Body, *args, **kwargs):
        def r(theta):
            orbit_mod = Orbit(*list(orbit.get_oe())[:5], theta)
            return list(orbit_mod.to_sv(body).get_rv())[:3]

        pos = np.array([r(theta) for theta in np.linspace(0, 2*np.pi, 100)])
        spline = pv.Spline(pos, 500)
        self.add_mesh(spline, *args, **kwargs)

    def add_satellite(self, orbit: Orbit, body: Body, s=0.5e6, plot_orbit=True, *args, **kwargs):
        pos = np.array(list(orbit.to_sv(body).get_rv())[:3])
        satellite = pv.Sphere(
            radius=1, theta_resolution=120, phi_resolution=120, start_theta=270.001, end_theta=270
        )
        satellite = satellite.scale(s)
        satellite.points = satellite.points + pos

        self.add_mesh(satellite, *args, **kwargs)

        if plot_orbit:
            self.add_orbit(orbit, body, *args, **kwargs)

    def __del__(self):
        pass
