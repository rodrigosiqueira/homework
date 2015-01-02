#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file testHandleString.py
#		@author Rodrigo Siqueira de Melo

import unittest
import os, sys, inspect
#Add folder lib to the path
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
parentdir += "/lib/"
sys.path.insert(0, parentdir)
from handleString import *

#findStringInFile(_string, _file)
##	@class TestHandleString
#		@brief 
class TestHandleString(unittest.TestCase):
	##	@brief
	def setUp(self):
		pass

	##	@brief 
	#<ol>
	#	<li> Try a wrong path.</li>
	# <li> Try to find all references in the file.</li>
	#</ol>
	def test_findStringInFile(self):
		self.assertRaises(ValueError, findStringInFile, "/wrong/path", "xsltproc")
		referencesInFile = findStringInFile("installSoftwareTest.txt", "xsltproc")
		self.assertEqual(4, referencesInFile[0])

		realFileList = findStringInFile("stringFileSupport.txt", "MULTILIB_OPTIONS")
		self.assertEqual(31, realFileList[0])

	##	@brief test the function of add string.
	#<ol>
	#	<li> Empty string for change and for add. </li>
	#	<li> Try to add a string at the begin. </li>
	# <li> Try to add a string at the end of the target. </li>
	# <li> Try to add the string after another string </li>
	#</ol>
	def test_addString(self):
		lineValue = "MULTILIB_OPTIONS = marm/mthumb"
		self.assertRaises(ValueError, addString, "", "mno", END)

		self.assertEqual("mno " + lineValue, insertStringInTarget(lineValue, "mno ", BEGIN))
		self.assertEqual(lineValue + " mno", insertStringInTarget(lineValue, " mno", END))
		self.assertEqual("MULTILIB_OPTIONS = mno marm/mthumb", insertStringInTarget(lineValue, "mno", END, "="))
		self.assertEqual("MULTILIB_OPTIONS mno = marm/mthumb", insertStringInTarget(lineValue, "mno", BEGIN, "="))

if __name__ == "__main__":
	unittest.main()
