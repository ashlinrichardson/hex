#!/usr/bin/env python
# test.py: bin2hex / hex2bin test
# 20170203 richardson.ashlin@gmail.com
import os
import sys

# no output from this program if all's well.
def run(cmd):
  a = os.system(cmd)
  assert a == 0
  return a

if not os.path.exists('test_data.txt'):
    f = open('test_data.txt','wb')
    f.write('here is some data.\n')
    f.close()

run("g++ -w bin2hex.cpp -o ~/bin/bin2hex")
run("g++ -w hex2bin.cpp -o ~/bin/hex2bin")
run("chmod 755 ~/bin/bin2hex")
run("chmod 755 ~/bin/hex2bin")
run("~/bin/bin2hex test_data.txt  > hex.dat")
run("~/bin/hex2bin hex.dat test_data_output.txt")
a = os.popen("diff test_data.txt test_data_output.txt").read()
test_passed = (a == '')

run("rm test_data.txt")
run("rm hex.dat")
run("rm test_data_output.txt")

# did everything work?
assert(test_passed)

