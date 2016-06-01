#run in this way: ruby -r tracer tracer_test.rb

def meth(n)
  (1..n).each {|i| puts i}
end

meth(3)
