#!/bin/sh -e

rm web3c
gcc -o web3c main.c src/util.c src/db.c src/eth.c src/net.c src/personal.c src/request.c src/shh.c src/web3.c -lcurl -ljson-c