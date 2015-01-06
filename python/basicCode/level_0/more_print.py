print "=" * 10

str1 = "a"
str2 = "b"

print str1 + str2

formater = "%r %r %r %r"

print formater % (1, "test", {1,2}, True)
print formater % (formater, formater, formater, formater)

weekdays = "Mon\nTue\nWed\n..."
print "Week: ", weekdays
print """ aahhh
What fu@#... heheh
this is an multiple
line
"""

print "Hexa: \u'12'"
