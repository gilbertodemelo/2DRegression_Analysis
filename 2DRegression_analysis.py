import pandas as pd
import matplotlib.pyplot as plt
import subprocess

try:
    subprocess.run(["g++", "-o",  "main",  "main.cpp"], check=True)
    subprocess.run(["./main"], check=True)
except subprocess.CalledProcessError as e:
    print(f"Command failed with error: {e}")


df = pd.read_csv("points.csv", delimiter=",")

print(df)

fig, ax = plt.subplots(figsize=((10, 10)))

x = df["x"].values
y = df["y"].values

ax.scatter(x, y, s=5, alpha=0.5)
plt.grid(True)

plt.show()