#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file testHandleFile.py
#		@author Rodrigo Siqueira de Melo
#		@brief This file keeps the unit test under the file operations.

import unittest
import os, sys, inspect

currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
parentdir += "/lib/"
sys.path.insert(0, parentdir)
from handleFile import *

##	@class TestHandleFile
#		@brief Class responsable for test some functions related to file operation
class TestHandleFile(unittest.TestCase):

	##	@brief Read the default file for test and create some attribut.
	def setUp(self):
		self.FILE_SUPPORT = "stringFileSupport.txt"
		self.readFile = []
		try:
			for line in file(self.FILE_SUPPORT).readlines():
				self.readFile.append(line)
		except IOError:
			pass
		return
	
	##	@brief Test the operation of read file.
	#<ol>
	#	<li> Try to open the wrong path. </li>
	#	<li> Compare the total of element in the list with the number of lines in the file </li>
	# <li> Try compare line by line of the file.</li>
	#</ol>
	def test_readFileLineByLine(self):
		self.assertRaises(ValueError, readFileLineByLine, "wrong/path")
		totalOfElements = readFileLineByLine(self.FILE_SUPPORT)
		self.assertEqual(len(self.readFile), len(totalOfElements))
		for line in totalOfElements:
			self.assertFalse(line in self.readFile)
	
		return

	##	@brief Check if the read of list of software works well.
	#<ol>
	#	<li> Try a wrong path. </li>
	# <li> Compare software by software. </li>
	#</ol>
	def test_readListOfSoftware(self):
		pass

	##	@brief Test the write file.
	#<ol>
	#	<li> Wrong input. </li>
	#	<li> Write a list and compare with the list</li>
	#</ol>
	def test_writeList(self):
		self.assertRaises(ValueError, writeList, self.readFile, "/wrong/path")
		self.assertRaises(ValueError, writeList, self.readFile, "testHandleFile.py")
		writeList(self.readFile, "writeListTest.txt")
		readLines = readFileLineByLine("writeListTest.txt", False)
		for line in readLines:
			self.assertIs(line in self.readFile, True)
		os.system("rm writeListTest.txt")

if __name__ == "__main__":
	unittest.main()
