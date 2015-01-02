#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file handleCommand.py
#		@author Rodrigo Siqueira de Melo
#		@brief File that handle linux command

import sys
import os
from os.path import exists, isfile, expanduser 
from subprocess import Popen, PIPE

from handleFile import *

cpCommand 		= ["cp"]
mkdirCommand	= ["mkdir", "-p"]
lnCommand			= ["ln", "-s"]
fileCommand		= ["file"]
cutCommand		= ["cut", "-d"]
tarCommand		= ["tar"]
chmodCommand	= ["chmod"]
exportCommand	= ["export"]
aptGetCommand = ["apt-get"]

children = {}
##	@param _command Command that wants to fireup in parallel.
#		@return Pid of the process.
#		@brief Launch a process, but don't wait for it. Store the PID of the process.
def spawnCommand(_command):
	pid = None
	pid = Popen(_command).pid
	children[pid] = {'pid':pid}
	return pid

##	@param _commandList List with all the commands that wants to lauch in parallel.
#		@param _totalAmountOfProcess Max number of parallel process. 
#		@brief Launch many process in parallel based in a list of commands.
#		@bug	If the _commandList isn't empty 
def launchManyProcess(_commandList, _totalAmountOfProcess = 10):
	if (not _commandList):
		return None

	#Spawn all the jobs
	while len(_commandList) > 0 and len(children) < _totalAmountOfProcess:
		command = _commandList[0]
		if spawnCommand(command):
			del _commandList[0]

	#Verify process
	while len(_commandList) > 0 or len(children):
		(pid, status) = os.wait()
		del children[pid]
				
		if len(_commandList) < _totalAmountOfProcess and len(_commandList):
			command = _commandList[0]
			if spawnCommand(command):
				del _commandList[0]

##	@param
#		@return
#		@brief
def executeCommand(_command, _shell = False):
	if (_command == None):
		return None
	
	if (_shell):
		processExecute = Popen(_command, shell=True)
	else:
		processExecute = Popen(_command)

	output, err = processExecute.communicate()
	if err:
		print ("Error: " + err)
		return None
	 
	return output

##	@param _command The main command that wants to execute.
#		@param _list List of parameters that wants to add to the list.
#		@return In case of successful return the new command with all the 
#			element in the list, if 
#		@brief This function is useful to create a list of commands fallowed 
#			by the list of its parameters in a safety way.
def concatenateCommand(_command, _list):
	if (not _command):
		raise ValueError
	
	concatenateFinal = []

	if (type(_command) is list):
		concatenateFinal.extend(_command)
	else:
		concatenateFinal.append(_command)

	if ((not _list) or (not (type(_list) is list))):
		return concatenateFinal
	
	concatenateFinal.extend(_list)

	return concatenateFinal

##	@param _source File that wants to copy.
#		@param _destination Place that wants to past the file.
#		@return Return None if something is wrong, otherwise return a list 
#			with the command.
#		@brief Create one list that will encapsulate the cp command
def copyFile(_source, _destination):
	if ((not exists(_destination)) or (not isfile(_source))):
		raise ValueError
	
	cpCommandFinal = list(cpCommand)
	cpCommandFinal.append(_source)
	cpCommandFinal.append(_destination)
	return cpCommandFinal

##	@param _name Name of the folder. It must to be a String.
#		@param _path Where do you want to create folder.
#		@return Return a list with the command mkdir build inside.
#		@exception Raise ValueError in the case of the parameter are invalid.
#		@brief Creates the command mkdir in the proper way, and in case 
#			of error raise ValueError.
def createFolder(_name, _path = "./"):
	if ((not exists(_path)) or _name == "" or exists(_name)):
		raise ValueError 

	mkdirCommandFinal = list(mkdirCommand)
	if (_path == "./"):
		mkdirCommandFinal.append(_path + _name)
	else:
		mkdirCommandFinal.append(_path + "/" + _name)
	return mkdirCommandFinal

##	@param _from Target that we wants to create a link. 
#		@param _to Where we want to create the link.
#		@param _linkName Name of the link.
#		@return Return a list with the command build.
#		@exception ValueError Check if the origin, destination, and name are valid.
#		@brief Build the command for link. 
def createLink(_from, _to, _linkName):
	if((not exists(_from)) or (not exists(_to)) or isfile(_linkName)):
		raise ValueError

	lnFinal = list(lnCommand)
	lnFinal.append(_from)
	lnFinal.append(_to + _linkName)
	return lnFinal

##	@param _file Reference to the file that wants to discover the extension.
#		@return Return one String with the extension, otherwise return None. In the
#			case of this function, I chose return None because I think that rise a exception
#			is to much for this case.
#		@brief For make easy the management of the extention, this function return 
#			the extension of the file like: <b> .[extenstion] </b>
def getExtensionLinux(_file):
	if (not isfile(_file)):
		return None

	(pathName, fileName) = os.path.split(_file)
	(justFileName, extension) = os.path.splitext(fileName)
	return extension.lower()

##	@param _path Zipped file that wants to extract.
#		@param _dest Place for extract file.
#		@return Return a list with the tar command build inside.
#		@exception ValueError If the path or destination is invalid, raise the exception
#		@brief Check for the extention of the file, and based on that
#			extract the file. 
def unzipFile(_path, _dest = "./"):
	if ((not isfile(_path)) or (not exists(_dest))):
		raise ValueError

	#Check the correct extension
	extension = getExtensionLinux(_path)

	if (extension is None):
		raise ValueError
	
	extractCommand = list(tarCommand)
	#Use the correct option for build the command
	if (extension == ".gz" or extension == ".tgz"):
		extractCommand.append("-xzf")
	elif (extension == ".xz" or extension == ".bz2"):
		extractCommand.append("-xjf")
	else:
		raise ValueError

	extractCommand.append(_path)
	extractCommand.append("-C")
	extractCommand.append(_dest)
	return extractCommand

def unzipAllFileInFolder(_path, _destination = "./"):
	if (not exists(_path) or (not exists(_destination))):
		raise ValueError

	filesToExtract = []
	for elementInFolder in os.listdir(_path):
		if (isfile(_path + "/" + elementInFolder)):
			#get the extention
			extention = (os.path.splitext(_path + "/" + elementInFolder)[1]).lower()
			if (extention == ".gz" or extention == ".tgz" or extention == ".xz" or extention == ".bz2"):
				filesToExtract.append(_path + "/" + elementInFolder)

	#Build all the commands before launch it
	unzipList = []
	for commandToUnzip in filesToExtract:
		unzipList.append(unzipFile(commandToUnzip, _path))

	launchManyProcess(unzipList)

##	@param _listOfSoftware List with all the software that want to install.
#		@return Return the apt-get command build for the list.
#		@exception ValueError Raise an exception in the case of the list is invalid.
#		@brief Build the command responsable for install new softwares via apt-get.
def installFromRepository(_listOfSoftware):
	if (not isfile(_listOfSoftware)):
		raise ValueError

	installCommand = list(aptGetCommand)
	installCommand.append("install")
	installCommand.append("-y")

	softwareToInstall = readListOfSoftware(_listOfSoftware)
	
	installCommand.extend(softwareToInstall)
	return installCommand

def updateSystem():
	status = Popen("apt-get update", shell = True).wait()
	return status

##	@param _mode Specify the mode that wants to assing to the file. It can be
#			a string or a number.
#		@param _file File that wants to change the mode.
#		@return Return the build command in a list or raise ValueError
#		@brief This method build the command chmod, notice that you can 
#			pass the mode in a String way or number.
def changeMode(_mode, _file):
	if (not isfile(_file)):
		raise ValueError
	
	if (type(_mode) is str):
		validStringMode = "+-xrw"
		checkList = [err for err in _mode if not(err in validStringMode)]
		if (checkList):
			raise ValueError

		if (_mode[0] == "+" or _mode[0] == "-"):
			pass
		else:
			_mode = "+" + _mode
	elif (type(_mode) is int):
		#Check the range for mode - Now is wrong, fix it!
		if (_mode >= 0 or _mode <= 999):
			pass
	else:
		raise ValueError
	
	changeModCommand = list(chmodCommand)
	changeModCommand.append(_mode)
	changeModCommand.append(_file)
	return changeModCommand

##	@return Return a string with the home path.
#		@brief Just get the home path
def getHomePath():
	homePath = expanduser("~")
	return homePath

##	@param _variable Name of the variable.
#		@param _value Value to assign to the variable.
#		@return Return the build string for export.
#		@brief Export a variable.
def exportVariable(_variable, _value):
	if (not _variable) or (' ' in _variable):
		raise ValueError

	export = list(exportCommand)
	if (type(_value) is int):
		_value = str(_value)
	export.append(_variable + "=" + _value)
	return export

##	@param _value Value that wants to add to the path. Should be a string.
#		@return Return the build command or raise expection.
#		@brief This command add one string to the path.
def addToPath(_value):
	if (not _value):
		return ValueError

	exportPath = exportVariable("PATH", _value + ":$PATH")
	return exportPath

