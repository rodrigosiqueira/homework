file = File.open("fileComments.txt", "rb")
strFile = file.read
puts("="*50)
puts("\t *** Row file: ***")
puts("")
puts(strFile)
puts("="*50)
puts("One by one")
x = strFile.scan(/^=begin(.*?)^=end/m)
puts(x)
print x
