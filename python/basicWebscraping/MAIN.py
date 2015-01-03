#-*- coding: utf-8 -*-
##@author Rodrigo
# @file MAIN.py

import sys
sys.path.append("model")
sys.path.append("view")
sys.path.append("control")
from RssHandler import RssHandler
from TerminalView import TerminalView
from ClubControl import ClubControl

if __name__ == '__main__':
	model = RssHandler()
	control = ClubControl(model)
	model.rssModel.getRssList()
