#!/usr/bin/env python
# coding=utf-8

# This script is used to compile stand c file by invoke gcc

import sys
import subprocess

print len(sys.argv)
print sys.argv[0]

fileName = sys.argv[1].split('.', 1)[0]
print fileName

# invoke gcc to compile 
# gcc filename.c -g -o filename.exe
# -g to generate lines info in exe

p = subprocess.Popen(['gcc', fileName+'.c', '-g', '-o', fileName+'.exe'],
	stdout = subprocess.PIPE, stderr = subprocess.PIPE)

print "---Here is gcc stdout:"
print p.stdout.read()
print ''
print "---Here is gcc stderr:"
print p.stderr.read()

# excute the exe directly after compile

t = subprocess.Popen(['.\\'+fileName+'.exe'],
	stdout = subprocess.PIPE, stderr = subprocess.PIPE)

print "###------###Here is exe stdout:"
print t.stdout.read()
print ''
print "###------###Here is exe stderr:"
print t.stderr.read()

# gdb debug usage:
# l: list sources
# s: step
# n: next line
# f: print current stack frame
# p: print variable