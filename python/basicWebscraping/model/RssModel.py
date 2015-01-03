#-*- coding: utf-8 -*-
##@author Rodrigo
# @file RssModel.py

from urllib2 import urlopen
from xml.sax import make_parser, ContentHandler
import sys

class RssModel(ContentHandler):
	
	##@var __rssList Lista contendo os RSS lidos do arquivo
	rssList = []
	##@var data Lista contendo os dados lidos
	dataRss = []
	
	## @brief Construtor padrão 
	def __init__(self):
		ContentHandler.__init__(self)
		self.__inItem = False
		self.__inTitle = False
		self.openRssFile()

	##@brief Abre o arquivo contendo os links rss
	# @param path Indica o local onde o arquivo está.
	def openRssFile(self, path = "support/rssList.txt"):
		try:
			rssFile = open(path, "r")
			listTmp = rssFile.readlines()
			for tmp in listTmp:
				self.rssList.append(tmp.replace('\n',''))
				
		except IOError:
			print "Algum erro ocorreu na abertura"
			
		finally:
			rssFile.close()
			
	##@brief Salva o rss no arquivo
	# @param rss String contendo o rss que será adicionada
	# @param path Indica a localização do arquivo
	def saveRssFile(self, rss, path = "support/rssList.txt"):
		try:
			rssFile = open(path, "rw")
			rssFile.write(rss)
		except IOError:
			print "Algum erro ocorreu na abertura"
		finally:
			rssFile.close()
			
	##@brief Sobreescrita do método que recebe notificações de dados.
	# @param data Dados recebidos após a notificação.
	def characters(self, data):
		if self.__inTitle == True:
			self.dataRss.append(data)
	
	##@brief Sobreescrita do método que busca o início de um elemento.
	# @param tag Tag especifica aberta
	# @param attrs Atributos 
	def startElement(self, tag, attrs):
		if tag == "item":
			self.__inItem = True
		if tag == "title" and self.__inItem:
			self.__inTitle = True
	
	##@brief Sobreescrita do método de busca do fim de um elemento
	# @param tag Verifica se a tag foi fechada.
	def endElement(self, tag):
		if tag == "item":
			self.__inItem = False
		if tag == "title":
			#sys.stdout.write("\n")
			self.__inTitle = False
		
	##@brief Retorna a lista contendo o RSS
	# @return Retorna uma lista
	def getRssList(self):
		return self.rssList
		
	##@brief Retorna a lista contendo os dados coletados
	# @return Retorna uma lista com os dados
	def getDataRss(self):
		return self.dataRss
