
template:
	make build_ext
	mkdir -p ../fem_drivers/${target}
	cp -r *.so *.cpp *.hpp *.pyx *file utils.py FEM.py driver.py setup.py Eigen build ../fem_drivers/${target}
build_ext:
	make clean_build
	python3 setup.py build_ext --inplace
python_test:
	make build_ext
	python3 model_test.py
clean_build:
	rm -f *.so
	rm -r -f build
	rm -f *wrapper.cpp
	rm -f *.html