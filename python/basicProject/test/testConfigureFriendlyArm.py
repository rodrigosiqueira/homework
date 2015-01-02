#!/usr/bin/python
#-*- coding: utf-8 -*-

##	@file testHandleCommand.py
#		@brief

import unittest
import os, sys, inspect
currentdir = os.path.dirname(os.path.abspath(inspect.getfile(inspect.currentframe())))
parentdir = os.path.dirname(currentdir)
sys.path.insert(0, parentdir)
from configureFriendlyArm import *

class TestConfigureFriendlyArm(unittest.TestCase):
	def test_updateSystem(self):
		pass
	
	def test_installPack(self):
		pass

	def test_createBasicFolder(self):
		pass
