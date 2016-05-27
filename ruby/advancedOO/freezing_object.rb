str = "This is a test."
str.freeze

begin
  str << " Don't be alarmed."
rescue => err
  puts "#{err.class} #{err}"
end

arr = [1, 2, 3]
arr.freeze

begin
  arr << 4
rescue => err
  puts "#{err.class} #{err}"
end
