# Remember, in ruby class are always open.
class Array
  # Added new method to Array class
  def iterate!
    self.each_with_index do |n, i|
      self[i] = yield (n)
    end
  end
end

array = [1, 2, 3, 4]

array.iterate! do |n|
  n ** 2
end

puts array.inspect
