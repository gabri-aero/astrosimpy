# Usage

## Installation

1. Clone the repository
```console
git clone https://github.com/gabri-aero/astrosim
```

2. Build the C++ library
```console
mkdir build
cd build
cmake ..
make
```

3. Build the python wheel file. 
```console
python3 setup.py bdist_wheel
```

4. Library .whl file is in dist/ folder.
```console
cd dist
```

5. Install the .whl file in your environment.
```console
pip install astrosimpy*.whl
```