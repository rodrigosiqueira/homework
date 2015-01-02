#!/usr/bin/python
#-*- coding: utf-8 -*-

import sys
import os, errno, inspect
import getpass

from os.path import expanduser

#Add folder lib to the path
currentDir = os.getcwd()
folderDir = currentDir.split("/")
folderDir.pop()
folderDir.pop()
folderDir.append("lib")
stringDir = '/'.join(folderDir)
sys.path.insert(0, stringDir)

#Library
from handleCommand import *
from handleFile import *
from handleString import *

PACKAGE_LIST 			= "file/exynosRequiredPackages.txt"
CONFIGURE_USB 		= "file/51-android.rules"
TARGET_RULE				= "/etc/udev/rules.d"
LIST_OF_DOWNLOAD	= "file/downloadList.txt"

def installingRequiredSoftware():
	print "=== INSTALL SOME PACKAGES ==="
	installCommand = installFromRepository(PACKAGE_LIST)
	print installCommand
	#executeCommand(installCommand)
	linkToLibGl = createLink("/usr/lib/i386-linux-gnu/mesa/libGL.so.1", "/usr/lib/i386-linux-gnu/", "libGL.so")
	#executeCommand(linkToLibGl)
	print linkToLibGl
	return

def prepareFolder():
	home = getHomePath()
	folder = createFolder("bin", home)
	return

def configureUSB():
	#Read file and replace <username> for the current user
	allLines = readFileLineByLine(CONFIGURE_USB, False)
	allLines = replaceString(allLines, "<username>", getpass.getuser())
	writeList(allLines, TARGET_RULE, "51-android.rules")
	return

def downloadFile():
	allLinks = readFileLineByLine(LIST_OF_DOWNLOAD)
	launchDownloads(allLinks, "download")
	return

def prepareJava():
	pass

def configureMinicom():
	pass

def initializeRepoClient():
	downloadRepo = ["curl", "https://storage.googleapis.com/git-repo-downloads/repo > ~/bin/repo"]

def gettingFiles():
	pass

def downloadExynos5250():
	pass
	
if __name__ == "__main__":
	#installingRequiredSoftware()
	prepareFolder()
	configureUSB()
	downloadFile()
	prepareJava()
	configureMinicom()
	initializeRepoClient()
