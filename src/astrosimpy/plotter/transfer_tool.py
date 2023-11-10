import customtkinter as ctk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
from matplotlib.figure import Figure
import numpy as np


class PlotControlFrame(ctk.CTkFrame):
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
        self.plot_frame = None

        self.button = ctk.CTkButton(self, text="Find optimum", command=self.optimum)
        self.button.grid(row=0, column=0, padx=10, pady=10, sticky="ew", columnspan=3)

        self.label = ctk.CTkLabel(self, text="n")
        self.label.grid(row=1, column=0, padx=(15, 10), pady=0, sticky="ew")
        self.slider_n = ctk.CTkSlider(self, from_=1, to=10, command=self.update_n)
        self.slider_n.grid(row=1, column=1, padx=(0, 0), pady=0, sticky="ew")
        self.slider_n_value = ctk.CTkLabel(self, text=str(self.slider_n.get()), width=40)
        self.slider_n_value.grid(row=1, column=2, padx=(0, 10), pady=0)

        self.label_z = ctk.CTkLabel(self, text="z")
        self.label_z.grid(row=2, column=0, padx=(15, 10), pady=0, sticky="ew")
        self.slider_z = ctk.CTkSlider(self, from_=0, to=2, command=self.update_z)
        self.slider_z.grid(row=2, column=1, padx=(0, 0), pady=0, sticky="ew")
        self.slider_z_value = ctk.CTkLabel(self, text=str(self.slider_z.get()), width=40)
        self.slider_z_value.grid(row=2, column=2, padx=(0, 10), pady=0)

        self.label_e = ctk.CTkLabel(self, text="e")
        self.label_e.grid(row=3, column=0, padx=(15, 10), pady=0, sticky="ew")
        self.slider_e = ctk.CTkSlider(self, from_=0, to=2, command=self.update_e)
        self.slider_e.grid(row=3, column=1, padx=(0, 0), pady=0, sticky="ew")
        self.slider_e_value = ctk.CTkLabel(self, text=str(self.slider_z.get()), width=40)
        self.slider_e_value.grid(row=3, column=2, padx=(0, 10), pady=0)

    def set_plot(self, plot_frame):
        self.plot_frame = plot_frame
        self.plot_frame.update()

    def optimum(self):
        n = self.slider_n.get()
        z = 2*n/(n+1)
        e = (n-1)/(n+1)

        self.slider_e.set(e)
        self.slider_z.set(z)

        self.update_n(n)
        self.update_z(z)
        self.update_e(e)

    def update_z(self, *args):
        z = args[0]
        self.plot_frame.z = z
        self.slider_z_value.configure(text=f"{z:.2f}")
        self.master.update()

    def update_n(self, *args):
        n = args[0]
        self.plot_frame.n = n
        self.slider_n_value.configure(text=f"{n:.2f}")
        self.master.update()

    def update_e(self, *args):
        e = args[0]
        self.plot_frame.e = e
        self.slider_e_value.configure(text=f"{e:.2f}")
        self.master.update()


def r(p, e, theta):
    r_ = p / (1 + e * np.cos(theta))
    x = r_ * np.cos(theta)
    y = r_ * np.sin(theta)
    return x, y


class PlotFrame(ctk.CTkFrame):
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
        self.n = 2
        self.z = 2*self.n/(self.n+1)
        self.e = (self.n-1)/(self.n+1)
        self.mu = 1

    def compute_transfer(self):
        p = self.z
        cos_theta_1 = np.round((self.z-1)/self.e, 6)
        cos_theta_2 = np.round((self.z/self.n-1)/self.e, 6)
        if np.abs(cos_theta_1) <= 1 and np.abs(cos_theta_2) <= 1:
            theta_1 = np.arccos(cos_theta_1)
            theta_2 = np.arccos(cos_theta_2)
            theta = np.linspace(theta_1, theta_2, 100)
        else:
            theta = []
        return p, self.e, theta

    def update(self):
        w = self.winfo_width() / 100
        h = self.winfo_height() / 100

        fig = Figure(figsize=(w, h), dpi=100)
        ax = fig.add_subplot(111)

        theta = np.linspace(0, 2 * np.pi, 1000)
        p_t, e_t, theta_t = self.compute_transfer()
        x1, y1 = r(1, 0, theta)
        x2, y2 = r(self.n, 0, theta)
        xt, yt = r(p_t, e_t, theta_t)
        ax.plot(x1, y1, 'r')
        ax.plot(x2, y2, 'b')
        ax.plot(xt, yt, 'k')

        ax.set_title('Orbit transfer')
        ax.set_aspect('equal')

        canvas = FigureCanvasTkAgg(fig, master=self)
        canvas.draw()
        canvas.get_tk_widget().place(relx=0, rely=0)


class EzPlotFrame(ctk.CTkFrame):
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
        self.plot_frame = None

    def set_main_plot(self, plot_frame):
        self.plot_frame = plot_frame
        self.plot_frame.update()

    def update(self):
        w = self.winfo_width() / 100
        h = self.winfo_height() / 100

        fig = Figure(figsize=(w, h), dpi=100)
        ax = fig.add_subplot(111)

        n = self.plot_frame.n
        zh = 2*n/(n+1)
        z1 = np.linspace(0, zh)
        z2 = np.linspace(zh, 2)
        e1 = 1-z1/n
        e2 = z2-1
        ax.plot(z1, e1, 'k')
        ax.plot(z2, e2, 'k')
        ax.fill_between(z1, e1, color='#d3d3d3')
        ax.fill_between(z2, e2, color='#d3d3d3')
        ax.plot(self.plot_frame.z, self.plot_frame.e, 'ko')

        ax.set_title('ez-space')
        ax.set_xlim([0,2])
        ax.set_ylim([0,2])
        ax.set_aspect('equal')

        canvas = FigureCanvasTkAgg(fig, master=self)
        canvas.draw()
        canvas.get_tk_widget().place(relx=0, rely=0)


class ResultsFrame(ctk.CTkFrame):
    def __init__(self, master, title, **kwargs):
        super().__init__(master, **kwargs)

        self.title = ctk.CTkLabel(self, text=title, fg_color="gray70", corner_radius=6)
        self.title.grid(row=0, column=0, padx=10, pady=(10, 0), sticky="ew", columnspan=2)

        self.label = ctk.CTkLabel(self, text="Delta-V=")
        self.label.grid(row=1, column=0, padx=(15, 10), pady=10, sticky="ew")

    def update(self):
        dV = 2
        self.label.configure(text=f"Delta-V={dV}")


class App(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.resizable(False, False)

        self.title("Orbit transfer analysis tool")
        self.geometry("800x600")

        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure(0, weight=1)

        self.plot_frame = PlotFrame(self)
        self.plot_frame.grid(row=0, column=0, padx=10, pady=10, sticky="nsew", rowspan=5)

        self.control_frame = PlotControlFrame(self)
        self.control_frame.grid(row=1, column=1, padx=10, pady=10, sticky="nsew")

        self.results_frame = ResultsFrame(self, "Coplanar transfer results")
        self.results_frame.grid(row=0, column=1, padx=10, pady=10, sticky="nsew")

        self.ez_plot_frame = EzPlotFrame(self)
        self.ez_plot_frame.grid(row=2, column=1, padx=10, pady=10, sticky="sew")

        self.control_frame.set_plot(self.plot_frame)
        self.ez_plot_frame.set_main_plot(self.plot_frame)

    def update(self):
        self.plot_frame.update()
        self.ez_plot_frame.update()
        self.results_frame.update()


app = App()
app.mainloop()
