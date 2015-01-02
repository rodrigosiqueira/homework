#!/usr/bin/python
#-*- coding: utf-8 -*-
##@author Rodrigo
# @file prepareElfEnviroment.py

import sys
import os, errno

#Definitions
HOME_FOLDER =  "~/"
MAIN_FOLDER = HOME_FOLDER + "arm-elf/"
SRC_FOLDER = "src/"
BUILD_FOLDER = "build/"
SRC_SUBFOLDER = ["binutils", "insight", "gcc", "newlib"]

LINK_BINUTILS = "http://ftp.gnu.org/gnu/binutils/binutils-2.23.1.tar.bz2"
LINK_GCC = "http://ftp.gnu.org/gnu/gcc/gcc-4.4.3/gcc-4.4.3.tar.bz2"
LINK_NEWLIB = "http://ufpr.dl.sourceforge.net/project/devkitpro/sources/newlib/newlib-2.0.0.tar.gz"
LINK_INSIGHT = "http://ftp.cs.pu.edu.tw/Linux/sourceware/insight/releases/insight-6.8-1.tar.bz2"

BINUTILS_FILE = "binutils-2.23.1.tar.bz2"
GCC_FILE = "gcc-4.4.3.tar.bz2"
NEWLIB_FILE = "newlib-2.0.0.tar.gz"
INSIGHT_FILE = "insight-6.8-1.tar.bz2"

FINAL_ALTER_GCC_OPTION = "MULTILIB_OPTIONS     = marm/mthumb mno-thumb-interwork/mthumb-interwork\n"
FINAL_ALTER_GCC_DIRNAME = "MULTILIB_DIRNAMES    = arm thumb normal interwork\n"

PATH_COMPILE_BINUTILS = "binutils-2.23.1/configure -target=arm-elf -prefix=/usr/local -enable-interwork -enable-multilib -with-float=soft -disable-werror"

##@brief This function is responsible for create the basics folders to 
# work with libraries and compilation.
def createFolder():
	literalyHome = os.popen("echo " + MAIN_FOLDER).read().rstrip()

	if os.path.exists(literalyHome):
		print "Folders arm-elf was previously created."
		return
		
	try:
		#Create basic string with the name of essential folders.
		folderTrunk = []
		folderTrunk.append(MAIN_FOLDER + SRC_FOLDER)
		folderTrunk.append(MAIN_FOLDER + BUILD_FOLDER)
		#Create internal folder for each library that will be installed
		for sub in SRC_SUBFOLDER:
			folderTrunk.append(folderTrunk[1] + sub)
		
		#Join all in only one string
		command = " ".join(folderTrunk)
		rc = os.system("mkdir -p " + command)
		
	except IOError, e:
		print e.errno
		print e

##@brief This function checks if all necessary files are in the folder
# @return If all files are in the folder True is returned, otherwise False
def checkFile():
	try:
		homeSrc = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER).read().rstrip()
		nameFile = os.listdir(homeSrc)
		count = 0
		#Check one-by-one of files
		for file in nameFile:
			if file == BINUTILS_FILE:
				count += 1
			else: 
				if file == GCC_FILE:
					count += 1
				else: 
					if file == NEWLIB_FILE:
						count += 1
					else: 
						if file == INSIGHT_FILE:
							count += 1

		if count == 4:
			return True
		else:
			return False
	except IOError, e:
		print e.errno
		print e

##@brief Verify if the files were previously downloaded. If the files 
#aren't in the folder, the script starts the download of the necessary 
#files otherwise them just return without do nothing.
def downloadFiles():
	literalySrc = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER).read().rstrip()
	if os.path.exists(literalySrc):
		print "Folders arm-elf/src was previously created."
	else:
		print "Some error happened in the previous steps."
		
	if checkFile():
		print "The files were previously downloaded."
		return
	else:
		print "START DOWNLOADS, PLEASE WAIT..."

	try:
		rc = os.system("wget -O " + MAIN_FOLDER + SRC_FOLDER + "binutils-2.23.1.tar.bz2" + " " + LINK_BINUTILS)
		rc = os.system("wget -O " + MAIN_FOLDER + SRC_FOLDER + "gcc-4.4.3.tar.bz2" + " " + LINK_GCC)
		rc = os.system("wget -O " + MAIN_FOLDER + SRC_FOLDER + "newlib-2.0.0.tar.gz" + " " + LINK_NEWLIB)
		rc = os.system("wget -O " + MAIN_FOLDER + SRC_FOLDER + "insight-6.8-1.tar.bz2" + " " + LINK_INSIGHT)
	except IOError, e:
		print e.errno
		print e
	return

##@brief Verify if the file were previously extracted.
def checkExtractFile():
	srcFile = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER).read().rstrip()
	nameFolder = os.listdir(srcFile)
	count = 0
	for folder in nameFolder:
		if folder == "binutils-2.23.1":
			count += 1
		else:
			if folder == "gcc-4.4.3":
				count += 1
			else:
				if folder == "newlib-2.0.0":
					count += 1
				else:
					if folder == "insight-6.8-1":
						count += 1
	if count == 4:
		return True
	else:
		return False
	
##@brief Extract specific files, however first verify if the file was extracted
def extractFiles():
	try:
		#Check files
		if checkFile():
			print "Check if files were created."
		else:
			print "Error..."
			return
		#Check if files was extracted
		if checkExtractFile():
			print "Files were extracted..."
			return
		else:
			print "Start the extraction of files."
		
		literalPath = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER).read().rstrip()
		rc = os.system("tar -C " + literalPath + " -xvjf " + literalPath + BINUTILS_FILE)
		rc = os.system("tar -C " + literalPath + " -xvjf " + literalPath + GCC_FILE)
		rc = os.system("tar -C " + literalPath + " -xvzf " + literalPath + NEWLIB_FILE)
		rc = os.system("tar -C " + literalPath + " -xvjf " + literalPath + INSIGHT_FILE)
			
	except IOError, e:
		print e.errno
		print e
		
	return;

##@brief Verify if the file t-arm-elf was altered
def checkAlterGccFile(_list, _str):
	for strLine in _list:
		if _str in strLine:
			return False
	return True

##@param _list List with all lines from file.
# @param _str String that shall trys to find in list.
# @return Return the number of line. If doesn't find string in the file, 
#	the total number of line in file will be returned
# @brief Try to find the number line of string in file.
def searchStringInFile(_list, _str):
	numberLine = 0
	for strLine in _list:
		numberLine += 1
		if _str in strLine:
			break
	return numberLine

##@brief Alter file t-arm-elf
def alterFileGcc():
	armFilePath = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER + 
				"gcc-4.4.3/gcc/config/arm/t-arm-elf").read().rstrip()

	f = open(armFilePath, 'r')
	lines = f.readlines()
	totalSize = len(lines)
	if checkAlterGccFile(lines, FINAL_ALTER_GCC_OPTION) or checkAlterGccFile(lines, FINAL_ALTER_GCC_DIRNAME):
		print "All right"
	else:
		print "The file were altered"
		f.close()
		return

	firstLineToAlter = 0
	secondLineToAlter = 0
	totalSize = 0
	
	f.close()

	firstLineToAlter = searchStringInFile(lines, "MULTILIB_OPTIONS") - 1
	if firstLineToAlter == totalSize:
		print "Some error occurs..."
		sys.exit(0)

	secondLineToAlter = searchStringInFile(lines, "MULTILIB_DIRNAMES") - 1
	if secondLineToAlter == totalSize:
		print "Some error occurs..."
		sys.exit(0)

	lines[firstLineToAlter] = lines[firstLineToAlter].rstrip() + " mno-thumb-interwork/mthumb-interwork\n"
	lines[secondLineToAlter] = lines[secondLineToAlter].rstrip() + " normal interwork\n"
	
	with open(armFilePath, 'w') as f:
		f.writelines(("%s" % l for l in lines))
		
	f.close()
	
	return
	
def installBinutils():
	try:
		literalyBuild = os.popen("echo " + MAIN_FOLDER + BUILD_FOLDER).read().rstrip()
		literalySrc = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER).read().rstrip()
		os.system("cd " + literalyBuild + "binutils && " + literalySrc + PATH_COMPILE_BINUTILS)

		os.system("sudo make --directory=" + literalyBuild + "binutils all install")
	except IOError, e:
		print e.errno
		print e
		
def installGccPart1():
	try:
		literalyBuild = os.popen("echo " + MAIN_FOLDER + BUILD_FOLDER).read().rstrip()
		literalySrc = os.popen("echo " + MAIN_FOLDER + SRC_FOLDER).read().rstrip()
		#os.system("cd " + literalyBuild + "gcc && " + literalySrc + PATH_COMPILE_BINUTILS)
		print "cd " + literalyBuild + "gcc && " + literalySrc + PATH_COMPILE_BINUTILS
		print "su && make --directory=" + literalyBuild + "gcc all install"
		#os.system("sudo make --directory=" + literalyBuild + "binutils all install")
	except IOError, e:
		print e.errno
		print e	
		#	cd ∼/arm-elf/build/gcc-4.4.3
		#$ ∼/arm-elf/src/gcc-4.4.3/configure -target=arm-elf -prefix=/usr/local -enable-interwork -enable-multilib -with-float=soft -disable-werror -enable-languages=c,c++ -with-newlib -with-
		#headers=∼/arm-elf/src/newlib-1.18.0/newlib/libc/include
		#$ sudo make all-gcc install-gcc


##@brief In the main function was implemented the algorithm for 
#	configuration of enviroment.
def main():
	#Parse command line option
	#...
	
	#Create the basic folder 
	createFolder()
	#Download files
	downloadFiles()
	#extract files
	extractFiles()
	#Alter file gcc-4.4.3/gcc/config/arm/t-arm-elf
	alterFileGcc()
	#Compile and install binutils
	installBinutils()
	
if __name__ == "__main__":
	main()
