class Array

  def iterator!(code)
    self.each_with_index do |n, i|
      self[i] = code.call(n)
    end
  end

end

array1 = [1, 2, 3, 4]
array2 = [2, 3, 4, 5]

# Piece of code
squareProc = Proc.new do |n|
  n ** 2
end

array1.iterator!(squareProc)
array2.iterator!(squareProc)

puts array1.inspect
puts array2.inspect
