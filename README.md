# Astrosim
Astrodynamics library where I will be implementing all my learnings in the field.

## How to install 

1. Clone the repository
```{code}
git clone https://github.com/gabri-aero/astrosim
```

2. Build the C++ library
```{code}
mkdir build
cd build
cmake ..
make
```

3. Build the python wheel file. 
```{code}
python3 setup.py bdist_wheel
```

4. Library .whl file is in dist/ folder.
```{code}
cd dist
```

5. Install the .whl file in your environment.
```{code}
pip install astrosimpy*.whl
```