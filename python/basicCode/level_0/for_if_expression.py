from sys import argv

script_name, your_name = argv

print "Hello, %s" % your_name
print "Are you happy? [Y|n]"
answer = raw_input()

if answer == 'n':
    for ask in range(0, 10):
        print "%d - And now? Ary you happy? [Y|n]" % ask
        answer = raw_input()
        if answer == 'Y':
            break
print "Good to know! Now I'm glad too!!! =D"
