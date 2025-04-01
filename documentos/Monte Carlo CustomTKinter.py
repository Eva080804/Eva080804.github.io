import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import customtkinter as ctk

# Función de la curva
f = lambda x: np.sin(x)

def calcular_area():
    try:
        # Leer valores ingresados
        a = float(entry_a.get())
        b = float(entry_b.get())
        N = int(entry_N.get())

        # Validar rango
        if a >= b or N <= 0:
            label_resultado.configure(text="Error: Verifica los valores.", text_color="red")
            return

        # Generar puntos aleatorios
        x_aleatoria = np.random.uniform(a, b, N)
        y_aleatoria = np.random.uniform(0, 1, N)
        y_curva = f(x_aleatoria)

        # Identificar puntos dentro y fuera
        dentro = y_aleatoria <= y_curva
        area = (b - a) * 1 * np.sum(dentro) / N

        # Mostrar el resultado
        label_resultado.configure(text=f"Área aproximada: {area:.4f}", text_color="green")

        # Graficar
        fig.clear()
        ax = fig.add_subplot(111)
        x = np.linspace(a, b, 500)
        ax.plot(x, f(x), 'r-', label=r'$f(x) = \sin(x)$')
        ax.scatter(x_aleatoria[dentro], y_aleatoria[dentro], color='green', s=10, label='Puntos dentro')
        ax.scatter(x_aleatoria[~dentro], y_aleatoria[~dentro], color='blue', s=10, label='Puntos fuera')
        ax.axhline(0, color='black', linewidth=0.8, linestyle='--')
        ax.axvline(a, color='black', linewidth=0.8, linestyle='--')
        ax.axvline(b, color='black', linewidth=0.8, linestyle='--')
        ax.set_title("Área bajo la curva")
        ax.set_xlabel("x")
        ax.set_ylabel("y")
        ax.legend()

        # Dibujar en el canvas
        canvas.draw()

    except Exception as e:
        label_resultado.configure(text=f"Error: {str(e)}", text_color="red")

# Configuración inicial de CustomTkinter
ctk.set_appearance_mode("light")
ctk.set_default_color_theme("blue")

# Ventana principal
root = ctk.CTk()
root.title("Monte Carlo - Área bajo la curva")
root.geometry("800x600")

# Contenedor principal
frame = ctk.CTkFrame(root)
frame.pack(padx=20, pady=20, fill="both", expand=True)

# Entradas de parámetros
title_label = ctk.CTkLabel(frame, text="Cálculo del área bajo la curva", font=("Arial", 20))
title_label.pack(pady=10)

entry_a = ctk.CTkEntry(frame, placeholder_text="Valor de a (inicio del intervalo)")
entry_a.pack(pady=5)

entry_b = ctk.CTkEntry(frame, placeholder_text="Valor de b (fin del intervalo)")
entry_b.pack(pady=5)

entry_N = ctk.CTkEntry(frame, placeholder_text="Número de puntos aleatorios")
entry_N.pack(pady=5)

# Botón para calcular
button_calcular = ctk.CTkButton(frame, text="Calcular Área", command=calcular_area)
button_calcular.pack(pady=10)

# Etiqueta para mostrar el resultado
label_resultado = ctk.CTkLabel(frame, text="", font=("Arial", 16))
label_resultado.pack(pady=10)

# Espacio para la gráfica
fig = plt.Figure(figsize=(5, 4), dpi=100)
canvas = FigureCanvasTkAgg(fig, master=frame)
canvas.get_tk_widget().pack(pady=10)

# Iniciar la aplicación
root.mainloop()

