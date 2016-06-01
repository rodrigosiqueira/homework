def xpto
  puts "Ahhhhh"
end

tax = 0.08
PI = 3

xpto
puts "PI=#{PI} TAX=#{tax}"

undef xpto

p "We expect an error now"
xpto
