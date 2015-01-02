#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file handleDownload.py
#		@brief 

import os
from os.path import exists
from handleCommand import spawnCommand, launchManyProcess

totalAmountOfJobs = 10
wgetCommand = ["wget","-q", "-nd", "-np", "-c", "-r", "-P"]
children = {}

##	@param _links list with all the links that wants to download.
#		@return Return a list with the wget command ready for execute.
#		@brief Create a list of commands.
def listOfWget(_links, _destination):
	if (not exists(_destination)):
		raise ValueError
	
	listOfWget = []

	for link in _links:
		listOfWget.append(wgetCommand + [_destination] + [link])

	return listOfWget

##	@param _links List of all links for build the download list.
#		@param _destination Destination for sabe the downloads.
#		@brief Launch all the downloads in the list.
#		@attention: You can improve thet total of download that can occur in parallel.
#			Try to do some calculation based on the internet speed... 
def launchDownloads(_links, _destination = "downloads/"):
	jobs = listOfWget(_links, _destination)
	print jobs
	launchManyProcess(jobs)	
