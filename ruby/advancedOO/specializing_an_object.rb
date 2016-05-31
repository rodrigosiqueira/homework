a = "hello"
b = "goodbye"

def b.upcase
  gsub (/(.)(.)/) { $1.upcase + $2 }
end

puts a.upcase # HELLO
puts b.upcase # GoOdBye
