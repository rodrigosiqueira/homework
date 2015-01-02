puts("This is a simple file, for test the comment syntax for ruby")
puts("="*50)
puts("\tSimple comments")
puts("="*50)
# Comment: White space + string
puts("# Comment: White space + string")
#Comment: No White space
puts("#Comment: No White space")
#   Comment: X white space + string
puts("#       Comment: Tab + string")
#       Comment: Tab + string
puts("#$ special char")
#$ special char
puts("#$ special char")
#
puts("#")
#                               
puts("#                               ")
# Comment inside #comment?
puts("# Comment inside #comment?")

puts("="*50)
puts("Multiple line comments")
puts("="*50)

=begin
This is ok.
=end
puts("=begin\n This is ok.\n=end")

=begin  
Tab after =begin ok
=end

=begin 
Space after =begin ok
=end

=begin
Tab after begin
=end
puts("After =begin you can have any space or tab that you want")

=begin comment here ...
comment here too
=end
puts("=begin Comments...\nComments...\n=end")

puts("-"*50)
puts("ERRORS")
puts("-"*50)
puts("fail:=begin\nComment...\n        =end")
puts(">>>>>ERROR: embedded document meets end of file")
puts("")
puts("fail:   =begin\nComment...\n=end")
puts(">>>>>ERROR: syntax error, unexpected '=', expecting end-of-input")
puts("")
puts("fail: =begin one line comment =end")
puts(">>>>>ERROR: embedded document meets end of file)")
puts("")
