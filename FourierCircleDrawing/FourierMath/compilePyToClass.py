#!/usr/bin/python
# -*- coding: utf-8 -*-
"""
Function:
【已解决】找到Jython编译py文件所生成的二进制的class文件
https://www.crifan.com/try_find_where_the_jython_generated_binary_class_files_for_py_file
 
Author:     Crifan Li
Version:    2013-11-07
Contact:    https://www.crifan.com/about/me
"""
 
import os;
import compileall;
curDir = os.getcwd();
compileall.compile_dir(curDir); # compile py file in current dir