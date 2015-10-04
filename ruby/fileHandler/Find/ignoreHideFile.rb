require 'find'

total_size = 0

Find.find(ENV["HOME"] + "/Documents/Code") do |path|

  if FileTest.directory?(path)
    if File.basename(path)[0] == "."
      Find.prune
    else
      next
    end
  else
    total_size += FileTest.size(path)
  end

  puts "Total: #{total_size}"

end
