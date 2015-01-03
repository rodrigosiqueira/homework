#-*- coding: utf-8 -*-

##@author Rodrigo
# @file BaseHTMLProcessor.py

from sgmllib import SGMLParser
from urllib2 import urlopen
import htmlentitydefs

##@class BaseHTMLProcessor
# @brief Realiza o processamento de páginas HTML
class BaseHTMLProcessor(SGMLParser):
	
	##@brief Qualquer inicialização necessária deve ser feita aqui.
	def reset(self):
		#Herdou (Chamado por SGMLParser.__init__)
		self.pieces = []
		SGMLParser.reset(self)
	
	##@brief Esta função é chamada para cada início de tag
	# @param tag A tag html lida.
	# @param attrs é uma lista de (attr, valor), ex.: <pre class="screen">, attrs=[("class","screen")]
	def unknown_starttag(self, tag, attrs):
		#Atenção a sintaxe especial utilizada para lidar com locals()
		strattrs = "".join([' %s="%s"' % (key, value) for (key, value) in attrs])
		self.pieces.append("<%(tag)s%(strattrs)s>" % locals())
	
	##@brief Chamado para cada final de tag, ex.: </pre>
	# @param tag Tag html que será fechada
	def unknown_endtag(self, tag):
		self.pieces.append("</%(tag)s>" % locals())
	
	##@brief Chamada para cada caracter de referência, ex.: "&#160"
	# @param ref Caracter
	def handle_charref(self, ref):
		self.pieces.append("&#%(ref)s;" % locals())
		
	##@brief Chamado para cada entidade referência, ex.: "&copy"
	# @param ref Referência
	def handle_entityref(self, ref):
		self.pieces.append("&%(ref)s" % locals())
		#Entidades padrão HTML são fechadas com uma semicoluna
		if htmlentitydefs.entitydefs.has_key(ref):
			self.pieces.append(";")
			
	##@brief Chamado para cada bloco de texto, não contém verbatim
	# @param text Recebe o texto
	def handle_data(self, text):
		self.pieces.append(text)

	##@brief Chamado para cada comentário HTML
	# @param text Comentário
	def handle_comment(self, text):
		self.pieces.append("<!--%(text)s-->" % locals())

	##@brief Chamado para cada instrução processada
	# @param text Instrução original 
	def handle_pi(self, text):
		self.pieces.append("<?%(text)s>" % locals())

	##@brief Chamado para o DOCTYPE, se present
	# @param text O que será processado
	def handle_decl(self, text):
		self.pieces.append("<!%(text)s>" % locals())
		
	##@brief Retorna um HTML processado em uma úncia string
	# @return Retorna uma string contendo o html processado
	def output(self):
		return "".join(self.pieces)
		
	def getTitle(self):
		opTitle = self.pieces.index("<title>")
		clTitle = self.pieces.index("</title>")				
		return "".join(self.pieces[opTitle + 1 : clTitle])
