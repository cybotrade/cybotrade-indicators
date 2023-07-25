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