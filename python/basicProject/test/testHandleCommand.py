#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file testHandleCommand.py
#		@brief This file keep the unit test of the handleCommand.py. Some test uses 
#			some files inside of this folder.
#		@see handleCommand.py

import unittest
import os, sys, inspect
#Add folder lib to the path.
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
parentdir += "/lib/"
sys.path.insert(0, parentdir) 
from handleCommand import *

##	@class TestHandleCommands
#		@brief Class responsable for keep all the test over the file 
#			functions in the file handleCommand.py
class TestHandleCommands(unittest.TestCase):
	
	##	@brief Pre-configuration
	def setUp(self):
		self.defaultCommandForTest = ["ls", "-la", "-R"]
		#Create temporary folder for test
	
	## @brief Test the concatenate command. See below the basic tests:
	#<ol>
	#		<li> Command is empty -> must to raise error </li>
	#		<li> List is empty -> Just return the command </li>
	#		<li> if we have list and parameters -> Return new list with command and paramters</li>
	#		<li> If the paramter _command is a String -> Convert it to a list </li>
	# 	<li> If the paramter _command is a list	-> just concatenate it </li>
	#		<li> If list is a string -> Change it to list and concatenate it </li>
	#</ol>
	#see handleCommand.py
	def test_concatenateCommand(self):
		localCommand = "ls"
		attributes	= ["-la", "-R"]
		#Empty command
		self.assertRaises(ValueError, concatenateCommand, "", attributes)
		#List is empty
		self.assertEqual([localCommand], concatenateCommand(localCommand, []))
		#list and parameters
		newLsCommand = concatenateCommand(localCommand, attributes)
		self.assertEqual(newLsCommand, ["ls", "-la", "-R"])
		#_command is a String:
		self.assertEqual(concatenateCommand("ls", ["-la", "-R"]), newLsCommand)
		#_commans is a list
		self.assertEqual(concatenateCommand(["ls"], ["-la", "-R"]), newLsCommand)
		#Paremeters are a string
		return
	
	## @brief Test the function copy:
	#<ol>
	#	<li> File doesn't exist -> Raise exception  </li>
	#	<li> Destination doesn't exist -> Raise execption </li>
	# <li> Check if the file in the destination exist </li>
	#	<li> Permition doesn't allow the copy </li>
	#</ol>
	def test_copyFile(self):
		#copyFile(_source, _destination):
		#File doesn't exist
		self.assertRaises(ValueError, copyFile, os.getcwd() + "/testHandleCnd.py", os.getcwd())
		#Destination doesn't exist
		self.assertRaises(ValueError, copyFile, os.getcwd() + "/testHandleCommand.py" , "zsdds")
		#Everithing all right
		cpCommandTmp = ["cp", os.getcwd() + "/testHandleCommand.py", "./"]
		self.assertEqual(cpCommandTmp, copyFile(os.getcwd() + "/testHandleCommand.py", "./"))
		return

	##	@brief Test the creation of the folder
	#<ol>
	#	<li> Folder already exist -> Raise exception  </li>
	# <li> Invalid path -> Raise exception </li>
	#	<li> Not allowed to create folder </li>
	#</ol>
	def test_createFolder(self):
		os.system("mkdir testFolder")
		#createFolder(_name, _path = "./"):
		self.assertRaises(ValueError, createFolder, "testFolder/")
		self.assertRaises(ValueError, createFolder, "rightNow", "path/in/wrong/way")
		self.assertRaises(ValueError, createFolder, "")
		self.assertEqual(createFolder("rightNow"), ['mkdir', '-p', './rightNow'])
		os.system("rm -r testFolder")
		return

	##	@brief Test the createLink function.
	#<ol>
	#	<li> Check the wrong origin. </li>
	# <li> Check the wrong destination. </li>
	# <li> Check the name. </li>
	#</ol>
	def test_createLink(self):
		#createLink(_from, _to, _linkName):
		lnTestCommand = ["ln", "-s", "./testHandleCommand.py", "./newLink"]
		self.assertRaises(ValueError, createLink, "./wrong/origin", "./", "newLink")
		self.assertRaises(ValueError, createLink, "./testHandleCommand.py", "/wrong", "newLink")
		self.assertEqual(createLink("./testHandleCommand.py", "./", "newLink"), lnTestCommand)
		return

	##	@brief
	#<ol>
	#	<li> Check if the file exists. </li>
	#	<li> Check if the function returns the correct value. </li>
	#</ol>
	def test_getExtensionLinux(self):	
		#getExtensionLinux(_file):
		self.assertEqual(getExtensionLinux("/file/doesnt/exist"), None)
		self.assertEqual(getExtensionLinux("./testHandleCommand.py"), ".py")
		return

	##	@brief Test the function responsable for unzip file'
	#<ol>
	#	<li> Check if the origin is right. </li>
	# <li> Check if the destination is right. </li>
	# <li> Check with a file that isn't a compacted file. </li>
	# <li> Check if the command was build in the right way. </li>
	#</ol>
	def test_unzipFile(self):
		#unzipFile(_path, _dest = "./"):
		self.assertRaises(ValueError, unzipFile, "/wrong/folder")
		self.assertRaises(ValueError, unzipFile, "./", "/wrong/folder")
		self.assertRaises(ValueError, unzipFile, "./testHandleCommand.py")
		os.system("tar cvzf tmpTest.tgz *.py")
		self.assertEqual(unzipFile("./tmpTest.tgz"), ["tar", "-xzf", "./tmpTest.tgz", "-C", "./"])
		os.system("rm tmpTest.tgz")
		return

	##	@brief Install from repository
	#<ol>
	#	<li> Check if the list exists.</li>
	# <li> Check the result.</li>
	#</ol>
	def test_installFromRepository(self):
		#installFromRepository(_listOfSoftware):
		self.assertRaises(ValueError, installFromRepository, "listOfSoft")
		os.system("echo \"git-core gnupg flex bison gperf build-essential\" > \
			listOfSoftwareTest.txt");
		cmpInstall = ["apt-get", "install", "-y", "git-core", "gnupg", "flex", "bison", 
			"gperf", "build-essential"]
		self.assertEqual(installFromRepository("listOfSoftwareTest.txt"), cmpInstall)
		os.system("rm listOfSoftwareTest.txt")
		return

	##	@brief Check the update command
	#<ol>
	#	<li> Check the return value.</li>
	#</ol>
	def test_updateSystem(self):
		self.assertEqual(["apt-get", "update"], updateSystem())

	## @brief Change the mode of file. Note that command can receive a string or number
	#<ol>
	# <li> Try a invalid file.</li>
	#	<li> Try to pass a string without + or -.</li>
	# <li> Test strings like: +xr or -wrx.</li>
	#	<li> Try numbers.</li>
	#</ol>
	def test_changeMode(self):
		#changeMode(_mode, _file, addOrRemove = "+"):
		FILE_TEST = "./testHandleCommand.py"
		self.assertRaises(ValueError, changeMode, "+xrw", "wrong/path")
		self.assertRaises(ValueError, changeMode, "-wrv", FILE_TEST)
		self.assertRaises(ValueError, changeMode, "+wry", FILE_TEST)
		self.assertRaises(ValueError, changeMode, ["wry"], FILE_TEST)

		chmodTest = ["chmod", "+rwx", FILE_TEST]
		self.assertEqual(changeMode("rwx", FILE_TEST), chmodTest)
		self.assertEqual(changeMode("+rwx", FILE_TEST), chmodTest)
		chmodTest = ["chmod", 775, FILE_TEST]
		self.assertEqual(changeMode(775, FILE_TEST), chmodTest)

		return
	
	##	@brief Test the export command for export variable.
	#<ol>
	# <li> Try to create a variable without name. </li>
	# <li> Try to assign a name with space. </li>
	# <li> Try to assign a name with special character </li>
	#</ol>
	def test_exportVariable(self):
		#exportVariable(_variable, _value):
		self.assertRaises(ValueError, exportVariable, "", "")
		self.assertRaises(ValueError, exportVariable, "INVALID STRING", "Value")
		#self.assertRaises(ValueError, exportVariable, "Inv@lid", "value")

		self.assertEqual(exportVariable("PATH", "THE PATH"), ["export", "PATH=THE PATH"])
		self.assertEqual(exportVariable("VALUE", 12), ["export", "VALUE=12"])
		return

	def test_addToPath(self):
		#addToPath(_value):
		return

	#def tearDown(self):
	#	os.system("rmdir testFolder")

if __name__ == '__main__':
	unittest.main()
