 Dictionary




# color perception
* [wikipedia](https://en.wikipedia.org/wiki/Color_vision)
 
## Paradox / illusions
 * [Checker shadow illusion](https://commons.wikimedia.org/wiki/File:Checker_shadow_illusion.svg) and [Grey square optical illusion proof2](https://commons.wikimedia.org/wiki/File:Grey_square_optical_illusion_proof2.svg)
 

## gamma correction

# gamut
 

# gradient/colourmap/palette
* [color gradient](https://en.wikipedia.org/wiki/Color_gradient) is a set of colors arranged in a [linear order](https://en.wikipedia.org/wiki/Total_order) ( ordered)
* palette : [In computer graphics, a palette is a finite set of colors](https://en.wikipedia.org/wiki/Palette_(computing)) [in no particular order](https://docs.gimp.org/en/gimp-palette-dialog.html) 
* Colorbar is a bar ( = broad shaft, or band, or stripe) that display the current colormap and indicate the mapping of data values into the colormap
* Color transfer function
  * [a path](https://en.wikipedia.org/wiki/Path_(topology)) through [colour space](https://en.wikipedia.org/wiki/Color_space)  
  * [Color mapping](https://en.wikipedia.org/wiki/Color_mapping) ( map) is a function that maps (transforms) the colors of one (source) image to the colors of another (target) image

![](./images/17_3d_60_75_v.png "Continous gradient as a path through RGB colour space ")  



# hue (dull to bright),
* single hue = [monochromatic](https://en.wikipedia.org/wiki/Monochromatic_color) for the value of one numeric variable
* multiple hue (polichromatic ) for the data that aren’t based on the value of a single number ( categories)
* [two hue = divergent](https://learnui.design/blog/picking-colors-for-your-data-visualizations.html) 



# saturation ( chroma)


# Lightness ( from black to white)
* [How to Determine Lightness by Reda Lemeden](https://thoughtbot.com/blog/closer-look-color-lightness#how-to-determine-lightness)
* [stackoverflow question: formula-to-determine-brightness-of-rgb-color](https://stackoverflow.com/questions/596216/formula-to-determine-brightness-of-rgb-color)
* desaturation = Converting color to [grayscale](https://en.wikipedia.org/wiki/Grayscale)
  * [Three algorithms for converting color to grayscale by John D. Cook](https://www.johndcook.com/blog/2009/08/24/algorithms-convert-color-grayscale/)          
  * [gimp 2.6 doc](https://docs.gimp.org/2.6/en/gimp-tool-desaturate.html)
  * [stackoverflow question : Standard-rgb-to-grayscale-conversion](https://stackoverflow.com/questions/17615963/standard-rgb-to-grayscale-conversion)
  * [Conversion to grayscale by Jason Summers](https://entropymine.com/imageworsener/grayscale/)

[Relative luminance is formed as a weighted sum of linear RGB components](https://en.wikipedia.org/wiki/Luma_(video))


```c
//from function test_palette_subcommand from the file gnuplot/src/command.c
ntsc = 0.299 * rgb.r + 0.587 * rgb.g + 0.114 * rgb.b;
```

[Photoshop](https://github.com/XiaoXiaoLui/photoshop_hsl_plugin)
```
y = 0.30 * r + 0.59 * g + 0.11 * b;
```

Perceived brightness ( P from HSP ) by [Darel Rex Finley](http://alienryderflex.com/hsp.html) 
>>>
By playing around with Photoshop’s RGB-to-Greyscale mode conversion, I determined that it is doing something very close to this:

  brightness  =  sqrt( .299 R^2 + .587 G^2 + .114 B^2 )
>>>



## Cielab lightness
* RGB -> XYZ -> Celab
  * [easyrgb](http://www.easyrgb.com/en/math.php#text2)
  * in OpenCV source /src/cv/cvcolor.cpp there are functions for color space conversions: [icvBGRx2Lab_32f_CnC3R](https://github.com/cybertk/opencv/blob/master/opencv/cv/src/cvcolor.cpp)
  * [python code by Manoj Pandey](https://gist.github.com/manojpandey/f5ece715132c572c80421febebaf66ae)



# Contrast
* https://en.wikipedia.org/wiki/Contrast_(vision)
* [LUMINANCE CONTRAST IN COLOR GRAPHICS by NASA](https://colorusage.arc.nasa.gov/design_lum_1.php)



# colour spaces
* [perceptualu uniform](https://programmingdesignsystems.com/color/perceptually-uniform-color-spaces/): 
  * CIELAB color space for the characterization of colored surfaces and dyes 
  * CIELUV color space for the characterization of color displays 
    * [HSLUV](http://www.hsluv.org/)
  * [Kodak ProPhoto RGB, Adobe RGB (1998) and sRGB are examples of gray balanced and perceptually uniform RGB working color space ](http://colormanaging.blogspot.com/2010/12/ideal-color-space.html)
* [Gray balanced means that equal RGB numbers always produce a neutral gray ](http://colormanaging.blogspot.com/2010/12/ideal-color-space.html)
* [HSP by Darel Rex Finley](http://alienryderflex.com/hsp.html) 

  
  
  

# data types
* qualitative/quantitative
* ordered/non-ordered
* numerical/categorical(=non-numerical)
  * numerical data subtypes: discrete, continuous, interval, ratio
  

## Qualitative/Quantitative
* [Qualitative = can not be measured with a numerical result](https://en.wikipedia.org/wiki/Qualitative_property), needs discrete palette with distinctive colors
* Quantitative = can be measured with a numerical result. Needs continous palette ( sequential)

see also :
* descriptive like [descriptive color palettes](https://colors.lol/)



## ordered/not-ordered data
* ordered  
  * continous ( numerical , real numbers)
  * sequential = discrete ( numerical,  integer). See sequential palettes from Color Brewer
* not ordered = qualitative, discrete not ordered

## Data and gradient relation:
* continous gradient for numeric real type data
* [Sequential](https://carto.com/carto-colors/) (discrete)  color gradient for orderable or numeric integer data, like gradients from the Color Brewer library. ["a series of ordered colors to represent ordinal or numerical data."](https://onlinelibrary.wiley.com/doi/abs/10.1002/col.22212)
  * [color scale](https://www.vis4.net/blog/2013/09/mastering-multi-hued-color-scales/)
  * [colour scheme](https://en.wikipedia.org/wiki/Color_scheme) is the choice of colors used in design for a range of media ( www, )
* Qualitative schemes: categorical differences in qualitative data



