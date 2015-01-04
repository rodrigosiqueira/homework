require_relative 'apply_regex'

executeRegexUnderFile("classRuby.txt", /\bclass\b\b[ |\t]+\s*(.*)\b/)
