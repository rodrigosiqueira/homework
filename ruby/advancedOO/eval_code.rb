parameters = {}

ARGF.each do |line|
  break if line == 'exit'
  name, expr = line.split(/\s*=\s*/, 2)
  parameters[name] = eval expr
end
