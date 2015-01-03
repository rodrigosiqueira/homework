#-*- coding: utf-8 -*-

##@author Rodrigo
# @file RssHandler.py

from urllib2 import urlopen
from xml.sax import make_parser, ContentHandler
import sys
import os
from RssModel import RssModel

##@class RssHandler
# @brief Classe responsável por abstrair e manipular dados extraídos da web.
class RssHandler:
	rssModel = None	
	
	def __init__(self):
		self.rssModel = RssModel()
		self.updateDataRss()
		
	##@brief Realiza uma busca sobre os links RSS
	def updateDataRss(self):
		parser = make_parser()
		parser.setContentHandler(RssModel())
		lenList = len(self.rssModel.getRssList())
		countRss = 1
			
		for url in self.rssModel.getRssList():
			if url == '':
				continue
			
			countRss += 1	
			per = 100 * countRss/ lenList
			os.system('clear')
			print "Buscando RSS... Total concluido: ", per, '%'
			try:	x
				infile = urlopen(url)
				parser.parse(infile)
			except:
				print "Falha na conexão"
