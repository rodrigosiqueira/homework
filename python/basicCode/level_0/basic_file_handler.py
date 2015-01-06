from sys import argv

script_name, filename = argv

file_read = open(filename)

prompt = "> "
print "Look at the debbug of file: %r" % file_read
print file_read.read()

print "How about open the file again? hehehe" 
file_path = raw_input(prompt)

print "Here we go again, %r" % file_path
file_again = open(file_path)
