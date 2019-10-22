# C API client for kubernetes

## Overview
This API client was generated by the [OpenAPI Generator](https://openapi-generator.tech) project. By using the [OpenAPI spec](https://openapis.org) from a remote server, you can easily generate an API client.

- API version: v1.17.0
- Package version: 
- Build package: org.openapitools.codegen.languages.CLibcurlClientCodegen

## Installation
You'll need the `curl 7.58.0` package in order to build the API. To have code formatted nicely you also need to have uncrustify version 0.67.

# Prerequisites

## Install the `curl 7.58.0` package with the following command on Linux.
```bash
sudo apt remove curl
wget http://curl.haxx.se/download/curl-7.58.0.tar.gz
tar -xvf curl-7.58.0.tar.gz
cd curl-7.58.0/
./configure
make
sudo make install
```
## Install the `uncrustify 0.67` package with the following command on Linux.
```bash
git clone https://github.com/uncrustify/uncrustify.git
cd uncrustify
mkdir build
cd build
cmake ..
make
sudo make install
```

## Compile the sample:
This will compile the generated code and create a library in build folder which has to be linked to the codes where API will be used.
```bash
mkdir build
cd build
// To install library to specific location use following command
cmake -DCMAKE_INSTALL_PREFIX=/pathtolocaiton ..
// for normal install use following command
cmake ..
make
sudo make install
```
## How to use compiled library
Considering the test/source code which uses the API is written in main.c(respective api include is written and all objects necessary are defined and created)

To compile main.c(considering the file is present in build folder) use following command
-L - locaiton of the library(not required if cmake with normal installation is performed)
-l library name
```bash
gcc main.c -L. -lpetstore -o main
```
once compile, you can run it with ``` ./main ```

Note: You dont need to specify includes for models and include folder seperately as they are path linked. You just have to import the api.h file in your code, the include linking will work.

## Author



