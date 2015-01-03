#-*- coding: utf-8 -*-
##@author Rodrigo
# @file ClubControl.py

import sys
sys.path.append("../model")
sys.path.append("../view")
from RssModel import RssModel
from TerminalView import TerminalView

##@class ClubControl
# @brief Classe controladora do aplicativo
class ClubControl:
	__model	= None
	__view 	= None
	
	def __init__(self, rssModel):
		self.__model = rssModel
		self.__view = TerminalView(self.__model)
