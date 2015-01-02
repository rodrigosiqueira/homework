#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file handleString.py
#		@author Rodrigo Siqueira de Melo
#		@brief This file keep some functions related to handle String.

from os.path import exists, isfile
import re
from handleFile import readFileLineByLine

BEGIN = "begin"
END		= "end"

##	@param _string String that wants to find.
#		@param _list List with all the lines of a file.
#		@return	Return a list with all line number that 
#			the string match.
#		@brief Find a string in the line.
def findStringInList(_list, _string):
	if (not _list):
		raise ValueError

	stringToFind = '\\b' + _string + '\\b'
	countLines = 0
	linesThatMatch = []
	for line in _list:
		listOfMatch = re.findall(stringToFind, line)
		if listOfMatch:
			linesThatMatch.append(countLines)
		countLines += 1

	return linesThatMatch

##	@param _file Indicate the path of the file.
#		@param _string String that wants to find in the file.
#		@return One list with all lines that the string were found.
#		@brief Open a file and try to find the string line by line. In
#			the end return a list with all lines that match.
def findStringInFile(_file, _string):
	if (not (isfile(_file))):
		raise ValueError

	try:
		listOfLines = readFileLineByLine(_file)
	except IOError:
		#Lauch a raise sounds better
		return None

	lineStringMatch = findStringInList(listOfLines, _string)

	return lineStringMatch

##	@param _targetString String that this function will change.
#		@param _stringToAdd String to add in _targetString.
#		@param _position Can be BEGIN or END. Indicate the position in 
#			_targetString for add _stringToAdd.
#		@param _stringRef Character used for reference. 
#		@return Return the new string in case of successful, otherwise 
#			return None.
#		@exception ValueError If the parametter _targetString is empty.
#		@brief Add string in a target.
def insertStringInTarget(_targetString, _stringToAdd, _position, _stringRef = ""):
	if (not _targetString):
		raise ValueError

	#If no _stringRef is defined
	if (_stringRef == ""):
		if (_position == BEGIN):
			_targetString = _stringToAdd.strip('\n') + _targetString + "\n"
		else:
			_targetString = _targetString.strip('\n') + _stringToAdd + "\n"
	#The case of stringRef was defined
	else:
	 	index = _targetString.find(_stringRef)
		if (index == -1):
			return None
		if (_position == BEGIN):
			_targetString = (_targetString[0 : index] + _stringToAdd +  
				_targetString[index - 1 : len(_targetString)])
		else:
			_targetString = (_targetString[0:index + 2] + _stringToAdd + 
				_targetString[index + 1 : len(_targetString)])
	
	return _targetString	

##
#
#
def replaceString(_list, _findPattern, _replace):
	if (not _list):
		raise ValueError
	
	stringToFind = '(' + _findPattern + ')'
	newList = []

	for line in _list:
		line = re.sub(stringToFind, _replace, line)
		newList.append(line)

	return newList


