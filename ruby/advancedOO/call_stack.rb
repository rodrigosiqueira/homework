def func1
  puts caller[0]
end

def func2
  puts func1
end

func2
