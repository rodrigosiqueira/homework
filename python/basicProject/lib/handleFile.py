#!/usr/bin/python
#-*- coding: utf-8 -*-

##@file handleFile.py
#	@author Rodrigo Siqueira de Melo

import os
import sys
from os.path import exists, isfile

##	@param _path Receive the path of the file.
#		@param _stripLine Idicate if we want to strip the file or not.
#		@return Return a list with all the lines inside of the file
#		@brief Read a file, and then return a list with each line like 
#			one element of the list.
def readFileLineByLine(_path, _stripLine = True):
	if (not isfile(_path)):
		raise ValueError
	
	lines = []
	try:
		for line in file(_path).readlines():
			if (_stripLine):
				lines.append(line.strip('\r\n'))
			else:
				lines.append(line)

	except IOError:
		raise IOError

	return lines

##	@param _path Indicates the path where is possible to find the list of software.
#		@return Return a list with all the softwares that wants to install.
#		@brief This command is useful for build the apt-get command.
def readListOfSoftware(_path):
	if (not isfile(_path)):
		raise ValueError

	softwareList = []
	try:
		for lineWithSoftware in file(_path).readlines():
			softwareList.extend(lineWithSoftware.strip('\r\n').split(" "))
	
	except IOError:
		raise IOError

	return softwareList

def writeList(_list, _path, _fileName = "easyScriptWrite.txt"):
	if (not _path) or (not _list):
		raise ValueError

	fullPath = _path + "/" + _fileName
	#Check if the file already exist
	if (isfile(fullPath)):
		raise ValueError

	with open(fullPath, 'w') as targetFile:
		for item in _list:
			targetFile.write(item)

	return	

def updateList(_list, _path):
	if (not _path) or (not _list):
		raise ValueError

	(pathName, fileName) = os.path.split(_path)
	if (pathName == ""):
		pathName = "./"
	if (not exists(pathName)) or not (isfile(_path)):
		raise ValueError

	with open(_path, 'w') as targetFile:
		for item in _list:
			targetFile.write(item)

	return
	
