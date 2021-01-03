

# color
* [Study of Color (draft) by  Wumbo 2020](https://wumbo.net/article/color/)

# human perception of the color
* "Our brain views color in terms of lightness (black to white), saturation (dull to bright), and hue (red, orange, yellow, green, blue, purple.) These three variables, originally defined by Albert H. Munsell, are the foundation of any color theory system based on human perception." [Marisa Krystian](https://infogram.com/blog/color-theory-dos-and-donts-for-data-visualization/)
* [luminance-is-more-important-than-color by Mark S. Abeln](https://therefractedlight.blogspot.com/2010/06/luminance-is-more-important-than-color.html)
* [wikipedia](https://en.wikipedia.org/wiki/Color_vision)






# gradient forms
* numbers aproximating transfer function ( CLUT with control points or [data points](https://en.wikipedia.org/wiki/Interpolation)). Function is approximated by [interpolation](./doc/FAQ.md#how-to-interpolate-between-colors) 
* function ( [transfer functions](https://en.wikibooks.org/wiki/Color_Theory/Color_gradient#Transfer_function)) 
* image 

## numbers aproximating transfer function
* array of numbers 
  * number type: integer in 0-255 range or floating point in 0.0-1.0 range
  * number of values: 
    * 3 values ( RGB): [LUT](https://en.wikipedia.org/wiki/Lookup_table) 
    * 4 values: index and 3 rgb values 
* file with data ( 3 columns) in various formats: txt, cvs and [many others](http://soliton.vm.bytemark.co.uk/pub/cpt-city/notes/formats.html) used by [graphic software](http://soliton.vm.bytemark.co.uk/pub/cpt-city/notes/software.html)
  * [wikibooks](https://en.wikibooks.org/wiki/Color_Theory/Color_gradient#Gradient_files)
  * [Color Schemes Appropriate for Scientific Data Graphics from Department of Geography, University of Oregon](http://geog.uoregon.edu/datagraphics/color_scales.htm)
  * [cpt-city](http://soliton.vm.bytemark.co.uk/pub/cpt-city/) 
  * [Fracting .map files)](http://www.krajzewicz.de/blog/free-color-palettes.php)
  * [automatic-color-palette-creation - Softology's Blog](https://softologyblog.wordpress.com/2019/03/23/automatic-color-palette-creation/)
  * [colorzilla](https://www.colorzilla.com/firefox/palettes.html)
  * [Haim Levkowitz](http://www.cs.uml.edu/~haim/ColorCenter/ColorCenterColormaps.htm)
  * gnuplot 
    * pal files
    * [formule](http://gnuplot.sourceforge.net/demo/pm3dcolors.html)
    
  * [cran](http://cran.fhcrc.org/web/packages/pals/vignettes/pals_examples.html)
  * [gencolormap](https://marlam.de/gencolormap/)
  * [matplotlib](https://matplotlib.org/3.1.0/gallery/color/colormap_reference.html)
* css file
  * [gradient editor from colorzilla](https://www.colorzilla.com/gradient-editor/)
  * [Program do generowania gradientów w formacie Gimpa, css i Inkscape-a](https://www.obliczeniowo.com.pl/156)
* list of numbers in the binary parameter file
* other
  * [color palette tables (CPT)](https://www.moderngmt.cn/GMT_Docs.html#of-colors-and-color-legends) of [GMT](http://geophysics.eas.gatech.edu/classes/Intro_GMT/gmt_www/gmt/doc/html/GMT_Docs/node56.html#9668)
Note that [tables can be discrete or continuous](http://geophysics.eas.gatech.edu/classes/Intro_GMT/gmt_www/gmt/doc/html/GMT_Docs/node187.html) 


[Paraview xml format](https://www.paraview.org/Wiki/Colormaps):
```xml
<ColorMaps>
<ColorMap name="Consistency" space="RGB">
<Point x="-1.000" o="1" r="0.0" g="0.0" b="0.0"/>
<Point x="0.000" o="1" r="0.0" g="1.0" b="0.0"/>
<Point x="1.000" o="1" r="1.0" g="0.0" b="0.0"/>
</ColorMap>
</ColorMaps>
```

where:
* x is a position
* o is opacity
* r,g,b are color channels


[CCC-Tool](http://www.ccctool.com/) xml format 
```xml
<ColorMaps>
<ColorMap name="Custom CMS" space="RGB" interpolationspace="hsv" interpolationtype="linear" creator="CCC-Tool">
<Point x="0" o="1" r="0.999999918662032" g="0.0000017030280962126348" b="0" cms="1" isMoT="true"/>
<Point x="1" o="1" r="0.9999999186904281" g="0.0000017027413356322709" b="0.01666644639528109" cms="1" isMoT="true"/>
<NaN r="0.24999997648523203" g="8.664340746405535e-8" b="0"/>
<Above r="0" g="0" b="0"/>
<Below r="0" g="0" b="0"/>
</ColorMap>
</ColorMaps>

```

where
* h has range [0,360]
* s and v  has range [0,100]



where:
* cms attribute : separate between Keys (less color ) and the Interval Colors (many colors )
* isMoT attribute : is the Middle of Triple Key. For more info see paper  : [P. Nardini, M. Chen, F. Samsel, R. Bujack, M. Böttinger and G. Scheuermann, "The Making of Continuous Colormaps," in IEEE Transactions on Visualization and Computer Graphics.](https://ieeexplore.ieee.org/abstract/document/8939459)



[dat files by Paul Bourke](http://paulbourke.net/miscellaneous/colourspace/): index r g b in 0-255 range


```
0   0   0 255    
1   0   3 255     
2   0   7 255        
3   0  11 255       
```


### CLUT
* [Cube LUT file format specification by Adobe](https://wwwimages2.adobe.com/content/dam/acom/en/products/speedgrade/cc/pdfs/cube-lut-specification-1.0.pdf)
* [CLUTs and colorimetric transformations im G'MIC](https://pixls.us/blog/2017/06/g-mic-2-0/#3-easing-the-work-of-cartoonists-)
* [Hald CLUT](http://www.quelsolaar.com/technology/clut.html)

## function ( 3 transfer functions) = colour map 
* [separateed transfer functions for color and opacity](https://blog.kitware.com/using-the-color-map-editor-in-paraview-the-basics/)

## image
* stripe of colors ( ramp)
* diagram of the function
* CLUT image file
  * [imagemagic](https://imagemagick.org/script/command-line-options.php#clut): image is ordinarily a gradient image containing the histogram mapping of how each channel should be modified. Typically it is a either a single row or column image of replacement color values. If larger than a single row or column, values are taken from a diagonal line from top-left to bottom-right corners.
  * [Paul Tol's Notes](https://personal.sron.nl/~pault/): data in pgm file, clut in ppm file, use Image magic convert to apply gradient
  * [gimp](https://docs.gimp.org/2.10/en/plug-in-gradmap.html)
  * [gmic](https://gmic.eu/color_presets/index.shtml)
  * [darktable](https://www.darktable.org/2019/05/New%20module-lut3d/)










# Features of colormaps:
## general
* discrete/continous
* dimension: 1D / 2D/ 3D ...
* [monotonicy](https://en.wikipedia.org/wiki/Monotonic_function) of the [lightness](README.md#lightness)
  * direction:  increasing/decreasing/constant
* perceptually uniform/nonuniform 
* Spatial Frequency
* [Colour-vision-deficiency (CVD) friendly](http://www.fabiocrameri.ch/resources/%2BREADME_ScientificColourmaps.pdf) = [accessible to those with colourblindness](https://betterfigures.org/2015/06/23/picking-a-colour-scale-for-scientific-graphics/) 
* double ended ( the same color on the both sides )
* single /multi hued
* photocopy safe
* [print friendly](http://www.fabiocrameri.ch/bw-readability.php) 



## technical
* [format](http://www.fabiocrameri.ch/availability.php) 
* number of the gradient segments ( ramps)
* type of interpolation function
* numerical [precision](https://docs.gimp.org/2.10/de/gimp-image-precision.html)

## discrete/continous
* continous gradient is  smooth as [continous function](https://en.wikipedia.org/wiki/Continuous_function). It is [smooth color transition](https://stackoverflow.com/questions/21835739/smooth-color-transition-algorithm) without any [bandings](https://en.wikipedia.org/wiki/Colour_banding) 


Description from [Colorcet](https://colorcet.holoviz.org/)
>>>
* The continuous colormaps are: 
   * perceptually uniform, with each new color equally perceptually distinct from the previous and following colors
   * perceptually nonuniform. That is, small changes in data values result in large changes in the perceptual appearance of the corresponding colors, or vice versa. For instance, the popular matplotlib "hot" and "jet" colormaps have long stretches where the apparent colors  change imperceptibly, such as the yellow region in "hot" and the cyan/green region in "jet":
* The discrete = categorical colormaps are perceptually distinct, but not uniform; each color is meant for a separate category and not as a position on a numerical scale
>>>

## hue
* [no hue](http://web.natur.cuni.cz/~langhamr/lectures/vtfg1/mapinfo_2/barvy/colors.html) = achromatic = gray scale
* single hue = [monochromatic](https://en.wikipedia.org/wiki/Monochromatic_color)
* multihue = polichromatic = rainbow 
  * two (double) hue = divergent

[Description from Vega](https://vega.github.io/vega/docs/schemes/)
>>>
For sequential data, it’s better to use palettes that have at most a relatively subtle shift in hue accompanied by a large shift in brightness and saturation. This approach will naturally draw the eye to the relatively important parts of the data.
* [Sequential Single-Hue Schemes can be used to encode quantitative values. These color ramps are designed to encode increasing numeric values.
* Sequential Multi-Hue Schemes can be used to encode quantitative values. These color ramps are designed to encode increasing numeric values, but use additional hues for more color discrimination, which may be useful for visualizations such as heatmaps. However, beware that using multiple hues may cause viewers to inaccurately see the data range as grouped into color-coded clusters.
>>>

Description by [Gregor Aisch](https://www.vis4.net/blog/2013/09/mastering-multi-hued-color-scales/)
>>>
While a (linear) variation in lightness is the most important quality of a sequential color scale, varying the hue can bring further significant improvements. Hue variation provides a better color contrast and thus makes the colors easier to differentiate. 
>>>



Examples:
* multi hue: viridis, magma, inferno, plasma, rainbow


## perceptual uniformity

[perceptual uniformity](./doc/DICTIONARY.md#colour-spaces) means that all pairs of adjacent colors will look equally different from each other 


## dimensions 
* 1D : for univariate data, see all above gradients  
* 2D : for bivariate data: [bivariate colour map](https://rmets.onlinelibrary.wiley.com/doi/full/10.1002/joc.2153)
* 3D :  trivariate colormaps 

### 2D gradients (mesh gradients)


[Rhino and Grasshopper](https://www.food4rhino.com/app/color-mesh)

svg : 
* [svg](https://graphicdesign.stackexchange.com/questions/105403/svg-gradient-implementation)
* [svg](http://libregraphicsworld.org/blog/entry/gradient-meshes-and-hatching-to-be-removed-from-svg-2-0)
* [haskell](https://twinside.github.io/coon_rendering.html)
* [imscape](https://wiki.inkscape.org/wiki/index.php/Mesh_Gradients)
  * [experiment](http://www.chrishilbig.com/mesh-gradients/)
  * [creating](http://write.flossmanuals.net/start-with-inkscape/creating-a-mesh-gradient/)
* [SVG Mesh Polyfill in js by Tavmjong Bah](http://tavmjong.free.fr/SVG/POLYFILL/MESH/mesh.html)
  * [gitlab](https://gitlab.com/Tavmjong/mesh.js)
  * [blog](http://tavmjong.free.fr/blog/?p=1554)


Formats: .sketch, .png, .ai, .jpg, .eps

Interpolation:
* linear 

## number of the gradient segments ( ramps)
* simple ( 1 segment)
* complex multisegment ( more then 1 segment)
  * 2 segments
    * diverging = ratio, bipolar or double-ended color maps = [a map containing colors with different hues at each end and meeting with a bright neutral color in the middle. Diverging color maps are traditionally designed for displaying scalars that have a value of special significance in the middle (such as sea level for elevation or the freezing point for temperature).](http://www.kennethmoreland.com/color-advice/BadColorMaps.pdf)
  * 4 segments:   Linas
  * 6 segments:  rainbow : should not be used in scientific computing
  * cyclic or [wave colormaps](https://sciviscolor.org/wave-colormaps/)
  
  
## numerical precision
* type and a range of the numbers:  unsigned char and [0 ; 255] or  double and [0.0 ; 1.0 ]
* length of the numbers array ( proportional to precision of nonlinear function approximation. for linear function 2 points are enough)
* function of color channel and the gradient segment: linear / nonlinear ( related what function is used for the interpolation between nodes)



# Taxonomy of color gradients
* [Alan Wilson](https://theblog.adobe.com/the-power-of-the-palette-why-color-is-key-in-data-visualization-and-how-to-use-it/)
* [hcl wizard](http://hclwizard.org/color-scheme/)



## data
* qualitative or categorical (discrete data = qualitative, unordered data )
* quantitative (ordered data )
  * continous 
  * Sequential for [ordered data that progress from low to high](http://colorbrewer2.org/learnmore/schemes_full.html) (level sets = ranges )
  * Diverging : [can be used to encode quantitative values with a meaningful mid-point, such as zero or the average value. Color ramps with different hues diverge with increasing saturation to highlight the values below and above the mid-point.](https://vega.github.io/vega/docs/schemes/). It cen be symmetrical or not, when critical value ( mid-point)  is not in the middle
  * Cyclical : [Cyclical color schemes may be used to highlight periodic patterns in continuous data. However, these schemes are not well suited to accurately convey value differences](https://vega.github.io/vega/docs/schemes/)
     

Description: 
* [A good discrete palette has distinct colors. A good continuous colormap does not show boundaries between colors.](https://cran.r-project.org/web/packages/pals/vignettes/pals_examples.html)
* [ Categorical data can also be represented as numbers, but each number is then distinct, with the numerical value important only to distinguish from other values. When categorical data is plotted as colors, each category should have a color visibly distinct from all the other colors, not nearby in color space, to make each category separately visible.](https://colorcet.holoviz.org/user_guide/Categorical.html)




## lightness 

[Taxonomy of Colour Maps by Peter Kovesi](http://arxiv.org/abs/1509.03700)


Taxonomy of contionus 1D colour maps according to the lightness:
* [monotone ( monotonic)](https://en.wikipedia.org/wiki/Monotonic_function) with monotonic brightness (lightness)
  * linear  = have colour lightness values that increase or decrease linearly over the colour map's range. Are intended for general use and have colour lightness values that increase or decrease linearly over the colour map's range
  * nonlinear
* isoluminant:  constant lightness and low contrast colour maps can be useful when displaying data with [relief shading](https://en.wikipedia.org/wiki/Terrain_cartography#Shaded_relief)
* non monotone or multisegment or [complex ](http://www.cs.utah.edu/~gk/papers/vis02/talk/index.html)
    
 Names:   
* [Perceptually Uniform Colour Maps](https://peterkovesi.com/projects/colourmaps/) = uniform perceptual contrast over their whole range
* [perceptual colormap](https://github.com/mycarta/rainbowbot) = ordered, strictly monotonic lightness
  * [cubehelix](https://ifweassume.blogspot.com/2013/05/cubehelix-or-how-i-learned-to-love.html)
* [qualitative, sequential, and diverging](http://colorspace.r-forge.r-project.org/articles/hcl_palettes.html#qualitative-palettes)


Description
* [A Comparison of Linear Gradients in Different Colourspaces by Billy Biggs](http://scanline.ca/gradients/)
* [Perceptually-linear gradients by Jesse L. Silverberg](http://blogs.nature.com/onyourwavelength/2018/07/18/heuristics-for-better-figures/)


## hue
* [no hue](http://web.natur.cuni.cz/~langhamr/lectures/vtfg1/mapinfo_2/barvy/colors.html) = achromatic = gray scale
* Single-Hue
* Multi-Hue
    






# Gradient goals (tasks) = goals of scientific visualisation
* encode scalar values in univariate map data 
* Categorization task: visually categorize data 


What features of data you want to highlight usung gradient ? 

[goals for 1D colormaps](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC4959790/)
* metric: enable users to accurately read absolute values in data = Value reading tasks
* form: gradient should enables users to correctly perceive the shape = [Pattern Perception](https://www.osti.gov/pages/biblio/1463498)
* order: colormaps must preserve the order in data
* separation:  different data must be perceived differently
* uniformity: perceived differences in color must accurately reflect numerical data differences





# Gradient metrics 
* lightnes 
* Color difference 
  * [the CAM02-UCS color difference metric](https://www.spiedigitallibrary.org/journals/optical-engineering/volume-58/issue-08/082414/Review-of-visualization-methods-for-passive-polarization-imaging/10.1117/1.OE.58.8.082414.full)
  * [ciede2000](http://www2.ece.rochester.edu/~gsharma/ciede2000/ciede2000noteCRNA.pdf)
* [stress  ](https://colormeasures.org/colormeasures_viewer/test.html)
* [arc-lengths in the L*A*B* color space]()
* [contrast-ratio between 2 colors](https://contrast-ratio.com/#%23000-on-%23fff) for measure [color contrast](http://www.colorsontheweb.com/Color-Theory/Color-Contrast) (distinct colors )
* []()


# Gradient aplications 
* scientific : [scientific visualization](https://en.wikipedia.org/wiki/Scientific_visualization)
  * visualisations of scalar fields
* [design](https://en.wikipedia.org/wiki/Applied_arts), usualy color scheme like for [www design ](https://visualcomposer.com/blog/ultimate-guide-to-colors-and-color-palettes/) or [UI](https://visualcomposer.com/blog/ultimate-guide-to-colors-and-color-palettes/)
* artistic




# Gradient complexity
* simple ( one segment)
* complex ( multisegment)
  * cyclic
  * divergent
  * [Reflected Gradient = Mirrors the same linear gradient on either side of the starting point.](https://helpx.adobe.com/photoshop/using/gradients.html)















