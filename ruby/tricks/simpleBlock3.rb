class Array
  def iterator!(&code)
    self.each_with_index do |n, i|
      self[i] = code.call(n)
    end
  end
end

array = [1, 2, 3, 4]

array.iterator! do |n|
  n ** 2
end

puts array.inspect
