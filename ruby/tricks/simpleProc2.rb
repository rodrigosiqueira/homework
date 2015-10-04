# The only difference between blocks and Procs is that a block is a Proc that
# cannot be saved, and as such, is a one time use solution.

def callbacks(procs)
  procs[:starting].call

  puts " ===> keep going..."

  procs[:finishing].call
end

callbacks(:starting => Proc.new {puts "Starting..."},
          :finishing => Proc.new {puts "Finishing..."})
