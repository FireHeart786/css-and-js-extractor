# css-and-js-extractor
This is a simple program whixh extract the css and js files of the given website and stores them

# Installation of required libraries
This code uses the libcurl and libxml2 libraries, which need to be installed on your system

    sudo apt-get install libcurl4-openssl-dev libxml2-dev

# Compiling the Code

    g++ -std=c++11 -o extract_files.cpp -lcurl -lxml2

# Execution
execute the file

    ./extract_files <URL>
