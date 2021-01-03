FAQ

* [ColorFAQ by Charles Poynton](http://poynton.ca/ColorFAQ.html)


# How to choose gradient for your data?
* find your [data type](https://en.wikipedia.org/wiki/Statistical_data_type)
* choose what feature of data do you wnat to highlight (representation task or goal of the visualisation)
* choose gradient type ( discrete/continous )
* choose your specific gradient
  * [Copy from others](https://blog.datawrapper.de/colorguide/#2)
  * [create your own](https://blog.datawrapper.de/colorguide/#2a) 
* Optimizing colormaps with consideration for
  * [color vision deficiency](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6070163/)
  * [spatial patterns, especially the boundary characteristics](http://www.yunhaiwang.net/SciVis2019/colorProject/index.html) - Data-Driven Colormap optimization


Note that :
* ["the audience, their experience, cultural background, language, names given to colors, personal preferences, aesthetics, and intuitive associations can influence intepretation of a visualization"](https://datascience.dsscale.org/wp-content/uploads/2017/10/TheGoodtheBadandtheUgly.pdf) 



Examples:
* [matplotlib](https://matplotlib.org/tutorials/colors/colormaps.html)
* [seaborn](http://seaborn.pydata.org/tutorial/color_palettes.html)
* [Subtleties of Color by Robert Simmon](https://earthobservatory.nasa.gov/blogs/elegantfigures/2013/08/05/subtleties-of-color-part-1-of-6/)
* [Color Use Guidelines for Mapping and Visualization by Cindy Brewer](http://web.natur.cuni.cz/~langhamr/lectures/vtfg1/mapinfo_2/barvy/colors.html)
* [How to choose a color palette for choropleth maps by Lisa Charlotte Rost ](https://blog.datawrapper.de/how-to-choose-a-color-palette-for-choropleth-maps/)


# How to choose test image for your colormap?
* find colour map / gradient type
* choose (to do !)


# How to convert data to the function ( how to fit curve to the data)?
* Polynomial Regression 
  * [polysolve by Paul Lutus](https://arachnoid.com/polysolve/)- online tool which gives a c function as an output ( click on the output form button to cycle through the available output forms)
  * [simplest_regression.py](./src/simplest_regression.py) - python program (Polynomial solver) by Paul Lutus
  * [numpy polyfit](https://docs.scipy.org/doc/numpy/reference/generated/numpy.polyfit.html)

Tools:
* gedit : replace "," with \t 
* LibreOffice Calc ( opens cvs files, choose columns, remove columns)), see [note about importing scv files for polish settings by Mirosław Zalewski](http://przepis-na-lo.pl/2013/05/poprawne-rozpoznawanie-liczb-skopiowanych-z-internetu/)


# How to convert between gradient files?
* [cptutils by JJ Green](http://soliton.vm.bytemark.co.uk/pub/jjg/en/code/cptutils/)
  * [online](http://soliton.vm.bytemark.co.uk/pub/cptutils-online/select.html)
  * [git](https://gitlab.com/jjg/cptutils)
* [PaletteTool by Daniel Krajzewicz](http://www.krajzewicz.de/palettetool/index.php)



# How to choose colorspace?
* [Choosing your color spaces in Photoshop or for your images: sRGB, Adobe RGB, ProPhoto...? by Arnaud Frich](https://www.color-management-guide.com/how-to-choose-between-srgb-adobe-rgb-prophoto.html)


# How to convert between color spaces?
* [Useful Color Equations by Bruce Justin Lindbloom](http://www.brucelindbloom.com/index.html?WorkingSpaceInfo.html)
* [HSLuv-C: Human-friendly HSL =  C implementation of HSLuv (revision 4)](https://github.com/hsluv/hsluv-c)
* [HSLUV : the necessary mathematical equations are solved in Maxima.](https://github.com/hsluv/hsluv/tree/master/math)
* [coloralgorithm :  js  code from lyft](https://github.com/lyft/coloralgorithm)
* [Color math and programming code examples by easyrgb](http://www.easyrgb.com/en/math.php)
* [elative-colorimetric-and-perceptual-rendering-intent by Arnaud Frich](https://www.color-management-guide.com/relative-colorimetric-and-perceptual-rendering-intent.html)
* [stackoverflow question: algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both](https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both)
* [HSP Color Model — Alternative to HSV (HSB) and HSL by Darel Rex Finley.  ](http://alienryderflex.com/hsp.html)
* [HSV Color Space by  Ronja Böhringer](https://www.ronja-tutorials.com/2019/04/16/hsv-colorspace.html)
* [Paul Bourke: colourspace](http://paulbourke.net/miscellaneous/colourspace/)
* [OpenCV - color conversion](https://docs.opencv.org/4.2.0/de/d25/imgproc_color_conversions.html)
* online
  * [TLBX: COLOR CONVERTER](https://www.tlbx.app/color-converter)
  * [colorizer](http://colorizer.org/)
  * [rapidtables: rgb ](https://www.rapidtables.com/web/color/RGB_Color.html)
  * [rapidtables: hsv-to-rgb](https://www.rapidtables.com/convert/color/hsv-to-rgb.html)
  * [chroma.js](https://github.com/gka/chroma.js) is a small-ish zero-dependency JavaScript library (13.5kB) for all kinds of color conversions and color scales by Gregor Aisch, Example pf [use](https://www.vis4.net/blog/2013/09/mastering-multi-hued-color-scales/) 
  * [Color::TupleEncode | Mapping tuples to colors by Martin Krzywinski ](http://mkweb.bcgsc.ca/tupleencode/)
  * [rgb.to](https://rgb.to/)
  * [colr.org](http://www.colr.org)
  * [thecolorapi](https://www.thecolorapi.com)
  * [encycolorpedia](https://encycolorpedia.com/)
  

#  How to create a gradient?

[colormap generation techniques](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4959790/):
* procedural methods focused on addressing data perception problems
* user-study based methods
* rule-based methods
* data-driven methods;




## continous
* [Interactive Creation of Perceptually Uniform Color Maps by M. Lambers (EUROVIS 2020)](https://diglib.eg.org/bitstream/handle/10.2312/evs20201048/055-059.pdf)
* [CCC-Tool](http://ccctool.com/) - general tool for the creation, export, analyzing and testing of colormaps
* [Interactive web tool to generate custom colormaps for Matplotlib / Matlab  by Jon Herman](http://jdherman.github.io/colormap/)
* [ColorCAT](https://github.com/SebastianMittelstaedt/ColorCAT)
* [gencolormap](https://marlam.de/gencolormap/)
* [palettte app by Gabriel Adorf](https://gabrieladorf.com/palettteapp/)
* [Kenneth Moreland](http://www.kennethmoreland.com/index.html)
  * "interpolate colors in a perceptually designed space (such as CIELAB or one of its derivatives like CIELch) rather than in basic RGB space." 
  * Making a gradient in perceptual space is pretty straightforward. Simply convert the RGB values to a perceptual space (such as CIELAB or CIELch) and interpolate in that space. For each value, convert back to RGB. I would find a convenient library that does these conversions for you. For example, for Python I use the colormath package: https://python-colormath.readthedocs.io/en/latest/. 
* [The Colour Map Design Process by Peter Kovesi](https://peterkovesi.com/papers/ColourMapsForColourBlindIAMG2017.pdf)
* [Good Colour Maps: How to Design Them by Peter Kovesi ( arxiv)](https://arxiv.org/pdf/1509.03700v1.pdf)
* [Good Colour Maps: How to Design Them by Peter Kovesi (page)](https://www.groundai.com/project/good-colour-maps-how-to-design-them/1)
* [How to use viscm to design colormaps for paraview-4-4 by Cory Quammen](https://blog.kitware.com/use-viscm-to-design-color-maps-for-paraview-4-4/)
* [Lyft Design: Javacript function to produce color sets: color lightness-to-darkness consistent across color hues, so that every color 0–50 is accessible (4.5:1) on black, and every color 60–100 is accessible (4.5:1) on white.](https://www.colorbox.io/)
* [mathematica.se question: how-to-calculate-mix-of-4-colors-defined-in-cielab-lab-model](https://mathematica.stackexchange.com/questions/7483/how-to-calculate-mix-of-4-colors-defined-in-cielab-lab-model)
* [Color Sequence Editor Using CIEluv Uniform Color Space by Evan Oliveri and Colin Ware](https://ccom.unh.edu/vislab/projects/ColorSequenceEditor.html)
* [chromatic-sketch: Create good-looking and perceptually uniform gradients and color scales (using Chroma.js and the Lab color space)](https://github.com/petterheterjag/chromatic-sketch)
* [cosine procedural palete by Inigo Quilez](http://www.iquilezles.org/www/articles/palettes/palettes.htm): "Mine cosine based palette generator is mostly designed for small demos where the size of the code matters, but otherwise it's not very powerful nor expressive."

### between 2 colors
* [SO question: color-gradient-algorithm](https://stackoverflow.com/questions/22607043/color-gradient-algorithm)
* [SO question: smooth-color-transition-algorithm](https://stackoverflow.com/questions/21835739/smooth-color-transition-algorithm)

## discrete
* "Translating the creation of quantitative schemes into a multiconstraint optimization problem"[An adaptive approach to create on‐demand color schemes for mapping quantitative geographic data
Mingguang Wu  Taisheng Chen  Hong Wang  Guonian Lv  A‐Xing Zhu](https://onlinelibrary.wiley.com/doi/abs/10.1002/col.22212)
* [data-color-picker](https://learnui.design/tools/data-color-picker.html) 
* [Colour displays for categorical images by  Glasbey et al. (2007)](https://strathprints.strath.ac.uk/30312/1/colorpaper_2006.pdf)
* [stackoverflow question: how-to-generate-a-number-of-most-distinctive-colors-in-r](https://stackoverflow.com/questions/15282580/how-to-generate-a-number-of-most-distinctive-colors-in-r)
* [Chroma.js Color Palette Helper](https://vis4.net/palettes/#/9|s|00429d,96ffea,ffffe0|ffffe0,ff005e,93003a|1|1) - tool for mastering multi-hued, multi-stops color scales by Gregor Aisch 
* [avoid-equidistant-hsv-colors by Gregor Aisch](https://www.vis4.net/blog/2011/12/avoid-equidistant-hsv-colors/)
* [stackoverflow question : how-to-automatically-generate-n-distinct-colors](https://stackoverflow.com/questions/470690/how-to-automatically-generate-n-distinct-colors)


```c
/*
https://stackoverflow.com/questions/470690/how-to-automatically-generate-n-distinct-colors
You can use the HSL color model to create your distinct colors.
If all you want is differing hues (likely), and slight variations on lightness or saturation, you can distribute the hues like so:
assumes hue [0, 360), saturation [0, 100), lightness [0, 100)
*/
for(i = 0; i < 360; i += 360 / num_colors) {
    HSLColor c;
    c.hue = i;
    c.saturation = 90 + randf() * 10;
    c.lightness = 50 + randf() * 10;

    addColor(c);
}

```


# How to test

## colourspace 
* [What-are-some-good-experiments-to-see-that-the-CIE-LAB-color-space-is-a-perceptually-uniform-color-space](https://www.quora.com/What-are-some-good-experiments-to-see-that-the-CIE-LAB-color-space-is-a-perceptually-uniform-color-space)
 * [MacAdam_ellipse](https://en.wikipedia.org/wiki/MacAdam_ellipse)

## colourmap
* tests
  * [CCC-Tool](http://ccctool.com/) - general tool for the creation, export, analyzing and testing of colormaps
  * [colormeasures](https://colormeasures.org/) - only gradients in a json form
  * [pal.test from the ‘pals’ package by Kevin Wright](https://cran.r-project.org/web/packages/pals/vignettes/pals_examples.html)
  * [colormap inxpections from ethplot](https://github.com/liamedeiros/ehtplot/blob/docs/docs/COLORMAPS.ipynb)
  * [How to evaluate and compare colormaps by Matteo Niccoli, MyCarta](https://github.com/seg/tutorials-2014/blob/master/1408_Evaluate_and_compare_colormaps/How_to_evaluate_and_compare_colormaps.ipynb)
  * [colourmap evaluation = assessing colormap quality by Stéfan van der Walt and Nathaniel Smith](https://bids.github.io/colormap/) using [viscm](https://github.com/matplotlib/viscm)
  * [How Bad Is Your Colormap? by Jake VanderPlas](https://jakevdp.github.io/blog/2014/10/16/how-bad-is-your-colormap/)
  * [draw a gradient on the colorwheel](https://theblog.adobe.com/the-power-of-the-palette-why-color-is-key-in-data-visualization-and-how-to-use-it/)
  
* test image or [palette visualisation](http://colorspace.r-forge.r-project.org/articles/palette_visualization.html)
  * [spatial frequency](https://www.cns.nyu.edu/~david/courses/perception/lecturenotes/channels/channels.html) 
    * [CET Perceptually Uniform Colour Maps: The Test Image by Peter Kovesi:A sine wave superimposed on a ramp](https://peterkovesi.com/projects/colourmaps/colourmaptestimage.html)
    * [Colormap Test Image by Steve Eddins, July 24, 2017](https://blogs.mathworks.com/steve/2017/07/24/colormap-test-image/?s_tid=blogs_rc_2)
    * [Campbell-Robson Contrast Sensitivity Chart](https://kwstat.github.io/pals/articles/pals_examples.html)
    * [Campbell-Robson CSF images by Izumi OHZAWA (ohzawa)](https://visiome.neuroinf.jp/database/item/3181) and [his page](http://ohzawa-lab.bpe.es.osaka-u.ac.jp/ohzawa-lab/izumi/CSF/A_JG_RobsonCSFchart.html) 
    * [ a spatial contrast sensitivity function](https://www.paraview.org/ParaView/index.php/Default_Color_Map)
  * [pals test image](https://kwstat.github.io/pals/)
  * [colormanagement : test images](http://www.colormanagement.org/en/testimages.html)
  * [Altona Test Suite from ECI = European Color Initiative](http://www.eci.org/en/downloads)
  *  heatmap based on [the Maunga Whau volcano data](https://stat.ethz.ch/R-manual/R-patched/library/datasets/html/volcano.html)
  * path ( trajectory) 
    * in the color space 
    * on the colorwheel
  * [pyramid](https://riptutorial.com/matplotlib/example/11647/perceptually-uniform-colormaps)
  * [RGB_24bits_palette_color_test_chart](https://commons.wikimedia.org/wiki/File:RGB_24bits_palette_color_test_chart.png)
  * [Color proportions of an image by L. Jégou](http://www.geotests.net/couleurs/frequences_en.html)
  * [pinestrripe image](https://rosettacode.org/wiki/Colour_pinstripe/Display)
  * [Which Blair Project - a quick visual method for evaluating perceptual color maps](https://ieeexplore.ieee.org/document/964510). Users choose gradient with monotically increasing luminance
    * [Face-based Luminance Matching for Perceptual Colormap Generation ](http://www.cs.utah.edu/~gk/papers/vis02/)
  * [ImaTest](http://www.imatest.com/) - Imatest provides customers with software, charts and equipment to meet and exceed image quality testing standards.
  * [The Koren lens test chart](http://www.normankoren.com/Tutorials/MTF5.html)
  
   
  
* spectrum
  * RGB spectrum or gnuplot RGB profiles of current color palette ( do not confuse with [ICC color profiles](https://en.wikipedia.org/wiki/ICC_profile)) or [channels](https://kwstat.github.io/pals/articles/pals_examples.html#pal-channels)
  * [HCL spectrum](http://colorspace.r-forge.r-project.org/articles/colorspace.html)

* 3D plot
  * [a three-dimensional scatterplot in the LUV space](https://kwstat.github.io/pals/articles/pals_examples.html)
  * [3-D visualisation (made with Maple) of how the colour scheme spirals around the diagonal of the colour cube](http://www.mrao.cam.ac.uk/~dag/CUBEHELIX/#Other)
  * [display the colorbar in Lab space in a 3D view](https://mycarta.wordpress.com/2012/12/21/comparing-color-palettes/)
  






# How to apply gradient ?

"separate the calculation phase from the colouring phase" Claude Heiland-Allen
* compute data
* compute choose gradient 
* apply gradient to the data = output image

## Image Magic convert 

[Method by Paul Tol](https://personal.sron.nl/~pault/)
* data in pgm file
* gradient as a clut in ppm file
* use Image magic convert to apply gradient using options:
  * [clut ](https://imagemagick.org/script/command-line-options.php#clut): replace the channel values in the first image using each corresponding channel in the second image as a color lookup table
  * [interpolate](https://imagemagick.org/script/command-line-options.php#interpolate): Set the pixel color interpolation method. Good settings for this are the 'bilinear' and 'bicubic' interpolation settings, which give smooth color gradients, and the 'integer' setting for a direct
  , unsmoothed lookup of color values. 

```
convert input.pgm -level 0,65532 clut.ppm -interpolate integer -clut -depth 8 output.png
```




# Where the gradient can be applied ?
* axial : x or y variable ( horizontal or vertical axis), goes down/up/left/right/diagonally  - see [CSS linear gradient](https://www.w3schools.com/css/css3_gradients.asp) 
* radial: magnitude of the complex variable - see [CSS radiel gradient](https://developer.mozilla.org/en-US/docs/Web/CSS/radial-gradient):  [starts at a single point and emanates outward](https://css-tricks.com/snippets/css/css-radial-gradient/)
* conic : angle of the complex variable - see [CSS conic gradient](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Images/Using_CSS_gradients#Using_conic_gradients), see for example color wheel
* any other real variable in [0,1] range ( or normalized to that range or used as a [repeating gradients](https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Images/Using_CSS_gradients#Using_repeating_gradients))

# How to interpolate between colors?
* [The Secrets of Colour Interpolation in rgb by Alan Zucconi](https://www.alanzucconi.com/2016/01/06/colour-interpolation/)
* [stackoverflow question : interpolate-from-one-color-to-another](https://stackoverflow.com/questions/13488957/interpolate-from-one-color-to-another)
* [Interpolation methods Written by Paul Bourke December 1999](http://paulbourke.net/miscellaneous/interpolation/)

[linear interpolation](https://en.wikipedia.org/wiki/Linear_interpolation)

```c
// Precise method, which guarantees v = v1 when t = 1.
double lerp(double v0, double v1, doublet t) {
  return (1 - t) * v0 + t * v1; 
```

# How to choose color?
* [ColorTool from NASA](https://colorusage.arc.nasa.gov/ColorTool.php)
* 


# How to extract color gradient from image? 
* [WebPlotDigitizer](https://automeris.io/WebPlotDigitizer/)
* [adobe color ](https://color.adobe.com/pl/create/image-gradient)
 

Papers:
* [Extracting and Retargeting Color Mappings from Bitmap Images of Visualizations by Jorge Poco, Angela Mayhua, and Jeffrey Heer](https://idl.cs.washington.edu/files/2018-ExtractingColorMappings-InfoVis.pdf)
* [ChartSense: Interactive Data Extraction from Chart Images](https://www.microsoft.com/en-us/research/wp-content/uploads/2017/02/ChartSense-CHI2017.pdf)





