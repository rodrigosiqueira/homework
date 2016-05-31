b = "goodbye"

class << b
  def upcase
    gsub(/(.)(.)/) { $1.upcase + $2 }
  end

  def upcase!
    gsub!(/(.)(.)/) { $1.upcase + $2 }
  end

end

puts b.upcase
puts b
b.upcase!
puts b
