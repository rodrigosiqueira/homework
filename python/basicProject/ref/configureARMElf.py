#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@author Rodrigo
#		@file configureFriendlyArm.py

import sys
from os.path import expanduser
sys.path.append("lib")
from handleCommand import *
from handleDownload import *
from handleString import *
from handleMakefile import *

#All the constants
PACKAGE_LIST = "file/friendlySoftware.txt"
TOOLS_DOWNLOAD = "file/downloadFriendlyTools.txt"
MAIN_WORK_FOLDER = "arm-elf"
BINUTILS_CONF = "-target=arm-elf -prefix=/usr/local -enable-interwork -enable-multilib -with-float=soft -disable-werror"
GCC_CONF = "-target=arm-elf -prefix=/usr/local -enable-interwork -enable-multilib -with-float=soft -disable-werror \
-enable-languages=c -with-newlib -with-headers=∼/arm-elf/src/newlib-1.18.0/newlib/libc/include"

NEWLIB_CONF = "-target=arm-elf -prefix=/usr/local -enable-interwork -enable-multilib -with-float=soft -disable-werror"
INSIGHT_CONF = "-target=arm-elf -prefix=/usr/local -enable-interwork -enable-multilib -with-float=soft -disable-werror"
def firstStep():
	print "== UPDATE SYSTEM =="
	#updateCommand = updateSystem() #-->Uncomment here
	#print updateCommand
	#executeCommand(updateSystem, True) --> I changed it... Popen is launch in updateSystem

	print "== INSTALL PACKAGES =="
	installCommand = installFromRepository(PACKAGE_LIST)
	#print installCommand
	#executeCommand(installCommand)

	#create main folder
	print "== CREATE MAIN FOLDER =="
	home = getHomePath()
	folder = createFolder("arm-elf/src", home)
	#executeCommand(folder)
	#print folder

	#Read a list of tools for download 
	print "== DOWNLOAD TOOLS =="
	print "Wait ..."
	allLinks = readFileLineByLine(TOOLS_DOWNLOAD)	
	print allLinks
	#launchDownloads(allLinks, home + "/arm-elf/src")
	#print wgetReady
	
	#Unzip the download filde
	print "== UNZIP FILE =="
	print "extracting ..."
	path = home + "/arm-elf/src"
	unzipAllFileInFolder(path)
	
	#Change file
	targetFile = home + "/arm-elf/src/gcc-4.4.3/gcc/config/arm/t-arm-elf"
	allLines = readFileLineByLine(targetFile, False)
	linesThatMatch = findStringInList(allLines, "MULTILIB_OPTIONS")
	allLines[linesThatMatch[0]] = insertStringInTarget(allLines[linesThatMatch[0]], " mno-thumb-interwork/mthumb-interwork", END)
	linesThatMatch = findStringInList(allLines, "MULTILIB_DIRNAMES")
	allLines[linesThatMatch[0]] = insertStringInTarget(allLines[linesThatMatch[0]], " normal interwork", END)
	writeList(allLines, targetFile)	

def installBinutils():
	print ("INSTALL BINUTILS")
	pathBinutils = getHomePath() + "/arm-elf/src/binutils-2.23.1"
	print pathBinutils
	configureCommand(pathBinutils, BINUTILS_CONF)
	compileWithMake(pathBinutils, ["all", "install"])

def installGcc1():
	print ("INSTALL GCC 1")
	pathGcc = getHomePath() + "/arm-elf/src/gcc-4.4.3/"
	print pathGcc
	configureCommand(pathGcc, GCC_CONF)
	compileWithMake(pathGcc, ["all-gcc", "install-gcc"])
	return 

def installNewLib():
	print ("INSTALL NEW LIB")
	pathNewLib = getHomePath() + "/arm-elf/src/newlib-2.0.0"
	print pathNewLib
	configureCommand(pathNewLib, NEWLIB_CONF)
	compileWithMake(pathNewLib, ["all", "install"])
	return 

def installGccFinal():
	print ("INSTALL GCC FINAL")
	pathGcc = getHomePath() + "/arm-elf/src/gcc-4.4.3/"
	compileWithMake(pathGcc, ["all", "install"])
	return 

def installInsight():
	print ("INSTALL INSIGHT")
	pathInsight = getHomePath() + "/arm-elf/src/insight-6.8"
	print pathInsight
	configureCommand(pathInsight, INSIGHT_CONF)
	compileWithMake(pathInsight, ["all", "install"])
	return

def cleanDirectory():
	print ("CLEAN DIRECTORY")
	return

if __name__ == "__main__":
	#1) Create default folder and install packs
	#firstStep()
	#2) Install binutils
	#installBinutils()
	#3) Prepare Gcc 1
	installGcc1()
	#4) Prepare newLib
	#installNewLib()
	#5) Install insight 
	#installInsight()
	#6) Remove folders
	#cleanDirectory()
