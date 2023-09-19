from astrosimpy import numerical, engine, utils

from matplotlib import pyplot as plt
import numpy as np
from matplotlib import animation
from matplotlib.animation import PillowWriter


def n_body(bodies_, t, step, name, speed=1, legend=False, save=False, momentum=False):
    integrator = numerical.RK4(step)

    astro_engine = engine.AstroEngine()
    astro_engine.add_bodies(bodies_)
    astro_engine.set_integrator(integrator)

    astro_engine.run(t)

    sv = []
    t = []

    for ti, svi in integrator.get_data():
        sv.append(svi)
        t.append(ti)

    sv = np.array(sv)
    t = np.array(t)

    N = speed * 5e3 / (len(t)*step)
    print(f"N = {N}")
    N = int(N)
    if N == 0:
        N = 1

    x = sv[::N, 0::6]
    y = sv[::N, 1::6]
    z = sv[::N, 2::6]
    vx = sv[::N, 3::6]
    vy = sv[::N, 4::6]
    vz = sv[::N, 5::6]

    r = np.stack((x, y, z), axis=2)
    v = np.stack((vx, vy, vz), axis=2)

    t = t[::N]
    p = np.zeros((len(t), 3))
    L = np.zeros((len(t), 3))

    for i in range(len(t)):
        for j in range(len(bodies_)):
            pj = bodies_[j].get_mass() * v[i, j]
            rj = r[i, j]
            Lj = utils.cross(utils.vec(rj), utils.vec(pj))
            p[i] = p[i] + pj
            L[i] = L[i] + Lj

    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot()

    num_of_points = len(bodies_)
    interval = 1
    num_of_frames = x.shape[0]

    points = [ax.plot([], [], 'o')[0] for i in range(len(bodies_))]
    title = ax.set_title('N-body problem')
    angular = ax.text(np.min(x) + 0.4 * (np.max(x) - np.min(x)), np.min(y) + 0.95 * (np.max(y) - np.min(y)), '')
    delta_angular = ax.text(np.min(x) + 0.4 * (np.max(x) - np.min(x)), np.min(y) + 0.9 * (np.max(y) - np.min(y)), '')
    linear = ax.text(np.min(x) + 0.4 * (np.max(x) - np.min(x)), np.min(y) + 0.85 * (np.max(y) - np.min(y)), '')
    delta_linear = ax.text(np.min(x) + 0.4 * (np.max(x) - np.min(x)), np.min(y) + 0.8 * (np.max(y) - np.min(y)), '')

    def update_points(n):
        for j in range(len(bodies_)):
            points[j].set_data(np.array([x[n, j], y[n, j]]))
        title.set_text(f'N-body problem (n={len(bodies_)})\nt: {t[n]:.2f}')
        if momentum:
            angular.set_text(f'Angular momentum: {np.linalg.norm(L[n]):.2e}')
            delta_angular.set_text(f'$\Delta e_L$: {np.linalg.norm(L[0] - L[n]):.2e}')
            linear.set_text(f'Linear momentum: {np.linalg.norm(p[n]):.2e}')
            delta_linear.set_text(f'$\Delta e_p$: {np.linalg.norm(p[0] - p[n]):.2e}')
        return points, title, angular, delta_angular, linear, delta_linear

    ax.set_xlim([1.05 * np.min(x), 1.05 * np.max(x)])
    ax.set_ylim([1.05 * np.min(y), 1.05 * np.max(y)])
    ax.set_aspect('equal')
    if legend:
        ax.legend([body.get_name() for body in bodies_], loc='upper left', bbox_to_anchor=(1, 1))

    ani = animation.FuncAnimation(fig, update_points, num_of_frames, interval=interval, blit=False, repeat=True)
    if save:
        ani.save(f'gif/{name}.gif', PillowWriter(fps=20))
    else:
        plt.show()
