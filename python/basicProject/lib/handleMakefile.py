#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file handleMakefile.py
#		@author Rodrigo Siqueira de Melo
#		@brief This file handle makefile

import os
from os.path import exists
from handleCommand import executeCommand

#makeCommand = ["make"]

##	@param 
#		@param 
#		@return 
#		@brief 
def compileWithMake(_pathOfMake, _parameter = []):
	if (not exists(_pathOfMake)):
		return None

	makeCommand = "make"
	currentDirectory = os.getcwd()
	#Go to Makefile directory
	os.chdir(_pathOfMake)	
	
	if (_parameter):
		parameters = ' '.join(_parameter)
		makeCommand = makeCommand + " " + parameters

	print ("=== EXECUTING MAKE COMMAND ===")
	os.system(makeCommand)
	
	#Return to the first folder
	os.chdir(currentDirectory)

	return

##
#
#
def configureCommand(_pathOfConfigureFile, _parameters):
	if (not exists(_pathOfConfigureFile)):
		return None

	configureCommand = "./configure"

	#Go to configure directory
	currentDirectory = os.getcwd()
	os.chdir(_pathOfConfigureFile)
	
	if(_parameters):
		configureCommand = configureCommand + " " + _parameters

	print configureCommand
	print ("=== EXECUTING CONFIGURE COMMAND ===")
	os.system(configureCommand)

	#Return to the first folder
	os.chdir(currentDirectory)

	return
