file = File.open("classRuby.txt", "rb")
strFile = file.read
puts("="*50)
puts("\t *** Row file: ***")
puts("")
puts(strFile)
puts("="*50)
puts("One by one")
strFile.scan(/\bclass\b\b[ |\t]+\s*(.*)\b/).each do |t|
  print(t)
end

