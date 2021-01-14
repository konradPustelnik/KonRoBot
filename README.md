# KonRoBot #

### After the first clone to your RPI, run to configure systemd:
* ./utils/init.sh

### To cleanup systemd, run:
* ./utils/clean.sh

### To start make compilation, run:
* make

### To start Cmake compilation, run:
* cmake -H. -Bbuild && cmake --build build

### To run Unit Test:
* cd tests && cmake -H. -Bbuild && cmake --build build && ./build/runTests && cd -

