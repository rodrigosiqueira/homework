from sys import argv

script, path = argv

file_write = open(path, 'w')

print "Hey, what do you want to write in this file?"
string_write = raw_input("> ")

file_write.write("hehehe... written...\n")
file_write.write(string_write)
file_write.write("FINISH!\n")
