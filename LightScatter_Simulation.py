import matplotlib.pyplot as plt
import numpy as np
import math


distance = np.linspace(0,5,1000)
r = 0.4
n = 1.36
NA= 0.22
scatter_coefficient = lambda x: (x ** (-2.07)) * 4.72
scatter_980 = scatter_coefficient(0.98)
scatter_808 = scatter_coefficient(0.808)
scatter_1532 = scatter_coefficient(1.532)
scatter_450 = 11.7
scatter_510 = 10.6
scatter_630 = 9.0


def transmit(d,S):
    p = r * math.sqrt((n / NA) ** 2 - 1)
    t_bottom = (d + p) ** 2 * (S * d + 1)
    transmittance = p ** 2 / t_bottom
    return transmittance

#cot_theta = math.sqrt((1.000292 / NA) ** 2 - 1)
#h_from_output_to_skull = 2
#light_spot_area = 3.1415925 * (cot_theta**2) * (h_from_output_to_skull + r / cot_theta)**2
#print cot_theta, light_spot_area
power808_output = 1086 
power980_output = 1119 
power1532_output = 965.09
power470_output = 123.67 
power530_output = 48.07 
power650_output = 330.67


plt.yscale('log')
plt.xlim((-0.1,1.1))
plt.xlabel('distance /mm')

'''
print(scatter_980)
print(scatter_808)
print(scatter_1532)
'''
plt.plot(distance, power980_output / (3.1415926*2*2) * transmit(distance, scatter_980),color = 'coral',linewidth=0.8,label ='980 nm')
plt.plot(distance, power808_output / (3.1415926*2*2) * transmit(distance, scatter_808),color = 'crimson',linewidth=0.8,label ='808 nm')
plt.plot(distance, power1532_output / (3.1415926*2*2) * transmit(distance, scatter_1532),color = 'red',linewidth=0.8,label ='1532 nm')
#plt.plot(distance, power470_output  * transmit(distance, scatter_450),'b--',linewidth=0.8,label ='470 nm')
#plt.plot(distance, power530_output  * transmit(distance, scatter_510),'g--',linewidth=0.8,label ='510 nm')
#plt.plot(distance, power650_output  * transmit(distance, scatter_630),'r--',linewidth=0.8,label ='630 nm')

plt.legend(['980 nm','808 nm','1532 nm'], loc = 'upper right')
plt.savefig('scatter_NIR.eps',format='eps')
plt.show()
