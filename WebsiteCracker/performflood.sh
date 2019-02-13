#!/bin/bash
# if [ "x$1" != x ] ; then
    ua="Mozilla/5.0 (Linux; Android 7.1.2; MI 5C Build/N2G47J) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.87 Mobile Safari/537.36" 
    
    while true
    do
        curl --connect-timeout 1 -A "$ua" "$1" > /dev/null
    done
# fi