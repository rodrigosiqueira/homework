hash = {1 => 1, 2 => 4, 3 => 9}
hash.freeze

arr = hash.to_a
puts hash.frozen?
puts arr.frozen?
hash2 = hash
puts hash2.frozen?
