from sys import argv

script_name, user_name = argv

prompt = "> "

print "Hello dear %s. My name is %s" % (user_name, script_name)
print "Do like python?"
python_like = raw_input(prompt)

print "Hey, do you have a notebook?"
notebook = raw_input(prompt)

