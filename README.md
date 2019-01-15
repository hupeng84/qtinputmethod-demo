# qtinputmethod-demo
Qt input method demo using qt virtualkeyboard


## Qt virtualboard

### 编译安装  

从Qt源码中拷贝qtvirtualkeyboard文件  

```bash
$ cd qtvirtualkeyboard
$ mkdir build
$ cd build
$ ${QTBINPATH}/qmake
$ make
$ make install
```

### 使用多语言  

编辑```src/config.pri```, 确保```CONFIG += lang-all```有效  

重新编译安装


### 默认启用shift键  

编辑```src/virtualkeyboard/shifthandler.cpp```文件，  

修改为```toggleShiftEnabled(true)```  


## App编译运行  

```bash
$ cd qtinputmethod-demo
$ mkdir build
$ cd build
$ {QTBINPATH}/qmake ../src
$ make
$ ./demo
```

