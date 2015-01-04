
def executeRegexUnderFile(file_name, regex)
  file = File.open(file_name, "rb")
  strFile = file.read

  strFile.scan(regex).each do |t|
    print(t)
  end
  puts("")
end
