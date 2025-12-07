import matplotlib.pyplot as plt
import numpy as np

# Secuencia de bits
bits = [1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1]

samples_per_bit = 1000  # resolución de la señal
t = np.linspace(0, len(bits), len(bits)*samples_per_bit, endpoint=False)

def nrz_l(bits):
    return np.repeat([1 if b == 1 else -1 for b in bits], samples_per_bit)

def nrz_i(bits):
    signal = []
    level = -1
    for b in bits:
        if b == 1:
            level *= -1
        signal.append(level)
    return np.repeat(signal, samples_per_bit)

def rz(bits):
    signal = []
    for b in bits:
        if b == 1:
            signal.extend([1,0])
        else:
            signal.extend([-1,0])
    return np.repeat(signal, samples_per_bit//2)

def ami(bits):
    signal = []
    last = -1
    for b in bits:
        if b == 1:
            last *= -1
            signal.append(last)
        else:
            signal.append(0)
    return np.repeat(signal, samples_per_bit)

def manchester(bits):
    signal = []
    for b in bits:
        if b == 1:
            signal.extend([1,-1])
        else:
            signal.extend([-1,1])
    return np.repeat(signal, samples_per_bit//2)

def diff_manchester(bits):
    signal = []
    last = 1
    for b in bits:
        if b == 1:  # transición al inicio
            last *= -1
            signal.extend([last,-last])
        else:  # no transición al inicio
            signal.extend([last,-last])
        last = -last
    return np.repeat(signal, samples_per_bit//2)

# ---------------- PLOTEO ----------------
plt.figure(figsize=(12,10))

plt.subplot(3,2,1)
plt.title("NRZ-L")
plt.plot(t, nrz_l(bits))
plt.axhline(y=0, color='black', linewidth=0.8)
plt.ylim(-2,2)
plt.grid(True)

plt.subplot(3,2,2)
plt.title("NRZ-I")
plt.plot(t, nrz_i(bits))
plt.axhline(y=0, color='black', linewidth=0.8)
plt.ylim(-2,2)
plt.grid(True)

plt.subplot(3,2,3)
plt.title("RZ")
plt.plot(t, rz(bits))
plt.axhline(y=0, color='black', linewidth=0.8)
plt.ylim(-2,2)
plt.grid(True)

plt.subplot(3,2,4)
plt.title("AMI")
plt.plot(t, ami(bits))
plt.axhline(y=0, color='black', linewidth=0.8)
plt.ylim(-2,2)
plt.grid(True)

plt.subplot(3,2,5)
plt.title("Manchester")
plt.plot(t, manchester(bits))
plt.axhline(y=0, color='black', linewidth=0.8)
plt.ylim(-2,2)
plt.grid(True)

plt.subplot(3,2,6)
plt.title("Manchester Diferencial")
plt.plot(t, diff_manchester(bits))
plt.axhline(y=0, color='black', linewidth=0.8)
plt.ylim(-2,2)
plt.grid(True)

plt.tight_layout()
plt.show()
