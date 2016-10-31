

##*Graphical rendering pipeline*

-----
**CMake Build instructions**

-----
  - Out-of-source build :
 ```
git clone git@github.com:Modelisation5ETI/TP3_ProjectiveRendering.git && \
mkdir TP3_ProjectiveRendering-build && cd TP3_ProjectiveRendering-build && \
cmake ../TP3_ProjectiveRendering  && \
make -j
 
 ```
  - QtCreator :
 ```
git clone git@github.com:Modelisation5ETI/TP3_ProjectiveRendering.git && \
mkdir TP3_ProjectiveRendering-build && cd TP3_ProjectiveRendering-build && \
qtcreator ../TP3_ProjectiveRendering
 
 ```
  *Then configure project using QtCreator API* : 
   - *Set the build directory to TP3_ProjectiveRendering-build/*
   - *Run CMake and build project*


-----
**Implementation**

-----

This program generates images in the build directory to illustrate the
different steps of the rendering pipeline

 <img src="./Screenshots/dino.png" alt="ProjectiveRendering" width="200" height="200" />

 ```
 ./ProjectiveRendering
 ```