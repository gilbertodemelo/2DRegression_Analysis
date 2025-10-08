import pandas as pd
import matplotlib.pyplot as plt
import subprocess
import re


subprocess.run(["g++", "-o",  "main",  "main.cpp"], check=True)
result = subprocess.run(["./main"], capture_output=True, text=True, check=True)
a, b, mse, r2 = map(float, result.stdout.split())
print(a, b, mse, r2)





df = pd.read_csv("points.csv", delimiter=",")

fig, ax = plt.subplots(figsize=((10, 10)))

x = df["x"].values
y = df["y"].values

ax.scatter(x, y, s=5, alpha=0.5)
ax.plot(x, a + b * x, color="red",linewidth=2, label=f"Fit: y={a:.2f}+{b:.2f}x")
plt.grid(True)
plt.legend()
plt.title("Linear Regression Fit")
plt.xlabel("x")
plt.ylabel("y")
plt.show()

plt.show()