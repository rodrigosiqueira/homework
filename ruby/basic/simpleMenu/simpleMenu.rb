default_box = "precise64"
if $stdin.isatty
  if Dir.glob(File.join(File.dirname("__FILE__"), '.vagrant/**/id')).empty?
    options = ["precise64", "trusty64", "chec/centos-7.0"]

    puts "Bases boxes available locally:"
    puts '------------------------------'
    system('vagrant', 'box', 'list')
    puts
    puts 'Base boxes we can provide you:'
    puts '------------------------------'
    options.each_with_index do |value, i|
      puts "[#{i + 1}] #{value}"
    end

    print "Which box to use [#{default_box}]: "
    choice = $stdin.gets.strip
    options.each_with_index do |option, i|
      if option == choice || choice.to_i == (i + 1)
        default_box = option
        puts default_box
        break
      end
    end
   end
end
