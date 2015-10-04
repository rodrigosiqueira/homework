array = [1,2,3,4,5]

array.collect! do |n|
  n ** 2
end

array.each do |n|
  n ** 3
end

puts array.inspect
