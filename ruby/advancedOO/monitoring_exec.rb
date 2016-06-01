def meth(n)
  sum = 0
  for i in 1..n
    sum += i
  end
  sum
end

set_trace_func(proc do |event, file, line, id, binding, klass, *rest| printf "%8s %s:%d %s/%s\n", event, file, line, klass, id end)

meth(2)
