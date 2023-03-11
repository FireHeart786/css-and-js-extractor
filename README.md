# css-and-js-extractor
This is a simple program whixh extract the css and js files of the given website and stores them. 

The code will retrieve the HTML content of the specified URL, extract all the JavaScript and CSS files referenced in the HTML, and write the URLs of those files to two separate text files named javascript_files.txt and css_files.txt.

# Installation of required libraries
This code uses the libcurl and libxml2 libraries, which need to be installed on your system

    sudo apt-get install libcurl4-openssl-dev libxml2-dev

# Compiling the Code

    g++ -std=c++11 -o extract_files.cpp -lcurl -lxml2

# Execution
execute the file

    ./extract_files <URL>

# Warning
This program is purely for educational purpose only. 
The Owner of the Repo or code is not responsible for any of its misuse. 
