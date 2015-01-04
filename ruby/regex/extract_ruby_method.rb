require_relative 'apply_regex'

executeRegexUnderFile("methodRuby.txt", /\bdef\b\b[ |\t]+\s*(.*)\b/)
