require_relative 'apply_regex'

executeRegexUnderFile("fileComments.txt", /^=begin(.*?)^=end/m)
