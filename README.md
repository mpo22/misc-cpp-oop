# modern cpp sandbox / object-oriented programming

## setup (fedora)

```commandline
sudo dnf -y group install --with-optional "C Development Tools and Libraries"
sudo dnf -y install python3
```

```commandline
python3 -m venv .venv
source .venv/bin/activate
```

```bash
python -m pip install -r requirements.txt
```

update requirements.txt (optional)

```bash
pip-review -a
pip-chill > requirements.txt
```

## run

## build

### CLion + conan plugin

### Cli Release

```
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=conan_provider.cmake -G Ninja -S . -B cmake-build-release
cmake --build cmake-build-release -j "$(nproc)" --verbose
```

### Cli Debug

```
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=conan_provider.cmake -G Ninja -S . -B cmake-build-debug
cmake --build cmake-build-debug -j "$(nproc)" --verbose
```

## resources

- https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines
- https://www.fluentcpp.com/
