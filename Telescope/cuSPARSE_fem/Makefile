
template:
	make build_ext
	mkdir -p ../../fem_drivers/${target}
	cp -r *.cpp *.cu *.h *.pyx *file utils.py FEM.py driver.py setup.py pytest lib build ../../fem_drivers/${target}
build_ext:
	make clean_build
	python3 setup.py install
	make library target=./lib
python_test:
	make build_ext
	make library target=./pytest/lib
library:
	mkdir -p ${target}
	cp ./build/lib*/*.so ${target}
clean_build:
	rm -f *.so *wrapper.cpp *.html  
	rm -r -f build lib dist *egg-info*