#!/bin/bash
if [ ! -x "./copy.out" ]; then
    exit
fi

if [ ! -e "test_input.tmp" ]; then
    dd bs=4096 count=4096 if=/dev/zero of=test_input.tmp >/dev/null
fi


for i in {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144}; do
   /usr/bin/test ./copy.out $i < test_input.tmp >/dev/null
done
