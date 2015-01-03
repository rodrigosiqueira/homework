#-*- coding: utf-8 -*-
##@author Rodrigo
# @file TerminalView.py

import sys
sys.path.append("../model")
from RssModel import RssModel

##@class TerminalView
# @brief Classe responsável por realizar impressões via terminal
class TerminalView:
	
	##@var __model Contém um objeto para o pacote de modelo
	__model = None
	
	def __init__(self, model):
		self.__model = model
		self.showRssList()
		self.showRssTitleNews()
	
	##@brief Método especializado em verificar se o objeto de modelo está ativo
	# @return Retorna True ou False
	def __verifyModel(self):
		if self.__model != None:
			return True
		else:
			return False
		
	##@brief Função responsável por imprimir os RSS contidos no arquivo.
	def showRssList(self):
		if self.__verifyModel() != True:
			return
		
		listOfRss = self.__model.rssModel.getRssList()
		for value in listOfRss:
			print value
		
	##@brief Mostra os títulos das notícias
	def showRssTitleNews(self):
		if self.__verifyModel() != True:
			return
		
		listTitle = self.__model.rssModel.dataRss
		for title in listTitle:
			if title != '':
				print title		
