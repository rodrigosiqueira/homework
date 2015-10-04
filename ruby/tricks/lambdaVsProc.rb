def proc_return
  Proc.new { return "Proc.new"}.call
  return "proc_return method finished."
end

def lambda_return
  lambda { return "lambda"}.call
  return "--> lambda return"
end

puts proc_return
puts lambda_return
