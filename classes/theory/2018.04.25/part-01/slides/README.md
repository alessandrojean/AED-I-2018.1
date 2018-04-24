# Heap Sort (slides)

This folder contains all the TeX files for the slides.

All the images are in the `/img` folder, as vector `.pdf`.

## Build instructions

Use the following commands to compile any `.tex` file.

```bash
# Assuming you have an TeX installation in your path.
# Can be TeX Live or MiKTeX if you are using Windows.

# Compile the TeX file and create the pdf.
xelatex -shell-escape -synctex=1 -interaction=nonstopmode file.tex
```