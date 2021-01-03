#!/usr/bin/env python
# -*- coding: utf-8 -*-

# copyright 2012, P. Lutus
# released under the GPL

import scipy 
import matplotlib.pyplot as plt

# these are the sample points from my Web page

xdata = scipy.array([-1,0,1,2,3,5,7,9])
ydata = scipy.array([-1,3,2.5,5,4,2,5,4])

# set the degree of the fit
degree = len(xdata)-1

# compute the coefficient list
coeffs = scipy.polyfit(xdata,ydata,degree).tolist()

# create a function to compute polynomial results
yfit = lambda x: scipy.polyval(coeffs, x)

# create a range for the polynomial fit
x = scipy.arange(-1,9.2,.1)

# show the original data points as red dots
plt.plot(xdata,ydata,'o',color='r')

# show the polynomial fit as a green line
plt.plot(x,yfit(x))

# include a grid
plt.grid(True)

#save the result as a file
plt.savefig('simplest_regression.png')

# show the result
plt.show()
