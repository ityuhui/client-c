# C API client for kubernetes

## Overview
This API client was generated by the [OpenAPI Generator](https://openapi-generator.tech) and [kubernetes client gen](https://github.com/kubernetes-client/gen) projects. 

- Kubernetes API version: v1.17.0
- OpenAPI Generator Build package: org.openapitools.codegen.languages.CLibcurlClientCodegen

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

## Compile the library:
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

Please refer [sample](https://github.com/ityuhui/client-c/tree/master/sample)


