deps:
	pip install Cython numpy twine

build:
	python setup.py build_ext --inplace

clean:
	rm -rf ./build ./dist \
		   ./src/cybotrade_indicators/*.so ./src/cybotrade_indicators/*.pyc \
		   ./src/cybotrade_indicators/lib/*.c \
		   ./src/*.egg-info

install:
	pip install -e .

test: 
	python tests/test.py

release:
	python setup.py sdist bdist_wheel

upload:
	python -m twine upload --repository pypi dist/*
